#include "toptenlist.h"

static const int ACCESS_ERROR = 1;
static const int MAX_KEY_LENGTH = 255;
static const int MAX_VALUE_NAME = 16383;


TopTenList::TopTenList()
{
    firstUserAssPath =
            "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\UserAssist\\{F4E57C4B-2036-45F0-A9AB-443BCFE33D9F}\\Count";
    secondUsetAssPath =
            "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\UserAssist\\{CEBFF5CD-ACE2-4F4F-9178-9926F41749EA}\\Count";

    updateList(SortType::ByHour);
    sortByHour();
}

ULONG TopTenList::QueryInfoKey(HKEY hKey, LPDWORD countSubKeys, LPDWORD countValues)
{
    TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name
    DWORD    cchClassName = MAX_PATH;        // size of class string
    DWORD    cbMaxSubKey;                    // longest subkey size
    DWORD    cchMaxClass;                    // longest class string
    DWORD    cchMaxValue;                    // longest value name
    DWORD    cbMaxValueData;                 // longest value data
    DWORD    cbSecurityDescriptor;           // size of security descriptor
    FILETIME ftLastWriteTime;                // last write time

    // Get the class name and the value count.
    DWORD retCode = RegQueryInfoKey(
        hKey,                    // key handle
        achClass,                // buffer for class name
        &cchClassName,           // size of class string
        NULL,                    // reserved
        countSubKeys,            // number of subkeys
        &cbMaxSubKey,            // longest subkey size
        &cchMaxClass,            // longest class string
        countValues,             // number of values for this key
        &cchMaxValue,            // longest value name
        &cbMaxValueData,         // longest value data
        &cbSecurityDescriptor,   // security descriptor
        &ftLastWriteTime);       // last write time

     return retCode;
}

ULONG TopTenList::GetKeyValues(QString keyPath)
{   
    HKEY USHKey;
    ULONG errOpenCode = RegOpenKeyExA(HKEY_CURRENT_USER,
                                      keyPath.toUtf8().constData(), NULL, KEY_READ, &USHKey);

    // check open key status
    if(errOpenCode == ERROR_SUCCESS)
    {
        DWORD countSubKeys = 0;
        DWORD countValues = 0;

        LONG errInfoCode = QueryInfoKey(USHKey, &countSubKeys, &countValues);

        if(errInfoCode == ERROR_SUCCESS)
        {
            QString valueName;   // buff for value name
            vTopList.clear();   // prevents the creation of duplicate

            for(DWORD i = 0; i < countValues; i++)
            { // get key values
                EnumValue(USHKey, i, valueName, vTopList);
            }
        }
        else
            return ACCESS_ERROR;
    }
    else
        return ACCESS_ERROR;

    RegCloseKey(USHKey);

    return ERROR_SUCCESS;
}

ULONG TopTenList::EnumKey(HKEY hKey, DWORD index, QString &keyName)
{
    char keyNameBuf[MAX_KEY_LENGTH] = { '\0' };

    // Enumerate the subkeys
    LONG errorKey = RegEnumKeyA(hKey, index, keyNameBuf, MAX_KEY_LENGTH);

    if (ERROR_SUCCESS == errorKey) {
        auto lenKeyName = strlen(keyNameBuf);
        keyName.reserve(lenKeyName);
        keyName = keyNameBuf;
    }

    return errorKey;
}

void TopTenList::EnumValue(HKEY hKey, DWORD index,
                               QString &valueName, QVector<KeyData> &vKeyValueData)
{
        // buff for name
        DWORD lenFileName = MAX_VALUE_NAME;
        char valueNameBuf[MAX_VALUE_NAME] = { '\0' };

        // for data
        byte *achData = new byte[MAX_KEY_LENGTH];
        DWORD dataSize = MAX_KEY_LENGTH;

        // for key values
        int runCount = 0, focusTime = 0;
        unsigned long long winDate = 0, noNano = 0, unix = 0;
        tm timeInfo;
        time_t t;

        // check enum status
        LONG errorValue = RegEnumValueA(hKey, index, valueNameBuf, &lenFileName, NULL, NULL, achData, &dataSize);

        if (ERROR_SUCCESS == errorValue && lenFileName > 0) {
            valueName.reserve(lenFileName);
            valueName = valueNameBuf;

            // count (int)
            for (int i = 7; i >= 4; i--)
                runCount = (runCount <<= 8) + achData[i];

            // focus time (int)
            for (int i = 15; i >= 12; i--)
                focusTime = (focusTime <<= 8) + achData[i];

            // last start (long long)
            for (int i = 67; i >= 60; i--)
                winDate = (winDate <<= 8) + achData[i];

            // convert nanosec. in unix seconds since epoch (1970)
            // and in normal date
            if (winDate)
            {
                noNano = winDate / 10000000;
                unix = noNano - 11644473600;

                t = unix;
                timeInfo = tm{ 0,0,0,0,0,0,0,0,0 };
                localtime_s(&timeInfo, &t);
            }

            vKeyValueData.push_back(KeyData(valueName,runCount,focusTime,
                                                QDateTime::fromTime_t(t)));
        }
        // extra test
        //else
        //     vKeyValueData.push_back(KeyData("undefined", 0, 0, QDateTime()));

        delete[] achData;
}

void TopTenList::updateList(SortType st)
{
    // get values and set vector
    int fErrCode = GetKeyValues(firstUserAssPath);
    int sErrCode = GetKeyValues(secondUsetAssPath);

    if(fErrCode == ERROR_SUCCESS && sErrCode == ERROR_SUCCESS)
    {
        switch (st) {
        case SortType::ByDays:
            sortByDays();
            break;

        case SortType::ByAllTime:
            sortByAllTime();
            break;

        default:
            sortByHour();
            break;
        }
    }
}

void TopTenList::sortList(bool (*f)(KeyData &right, KeyData &left))
{
    qSort(vTopList.begin(), vTopList.end(), f);
}

void TopTenList::sortByHour()
{
    sortList([](KeyData &left, KeyData &right){
        return left.getLastDateTime() > right.getLastDateTime();
    });
}

void TopTenList::sortByDays()
{
    sortList([](KeyData &right, KeyData &left){
        return left.getRunCount() < right.getRunCount();
    });
}

void TopTenList::sortByAllTime()
{
    sortList([](KeyData &right, KeyData &left){
        return left.getFocusTime() < right.getFocusTime();
    });
}
