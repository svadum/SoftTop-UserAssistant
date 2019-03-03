#include "userassistant.h"
#include <ctime>

#define ACCESS_ERROR 1
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

static const QStringList guides = {
    "F4E57C4B-2036-45F0-A9AB-443BCFE33D9F",
    "CEBFF5CD-ACE2-4F4F-9178-9926F41749EA"
};

UserAssistant::UserAssistant(QObject *parent) : QObject(parent)
{
    setSortType(ByHour);
}

void UserAssistant::setSortType(const SortType &st)
{
    if (m_sortType != st) {
        m_sortType = st;
        updateList();
    }
}

void UserAssistant::updateList()
{
    m_values.clear();
    for (const QString &guid : guides) {
        const QString &path = QString("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Explorer\\UserAssist\\{%1}\\Count").arg(guid);
        m_values << getKeyValues(path);
    }
    sortList(m_sortType);
}

void UserAssistant::sortList(const SortType &st)
{
    switch (st) {
    case SortType::ByDays:
        qSort(m_values.begin(), m_values.end(),[](KeyData &left, KeyData &right){
            return left.getRunCount() < right.getRunCount();
        });
        break;
    case SortType::ByAllTime:
        qSort(m_values.begin(), m_values.end(),[](KeyData &left, KeyData &right){
            return left.getRunCount() < right.getRunCount();
        });
        break;
    default:
        qSort(m_values.begin(), m_values.end(),[](KeyData &left, KeyData &right){
            return left.getLastDateTime() > right.getLastDateTime();
        });
        break;
    }
}

// Registry
ULONG UserAssistant::queryInfoKey(HKEY hKey, LPDWORD countSubKeys, LPDWORD countValues)
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

// More info: https://www.aldeid.com/wiki/Windows-userassist-keys
KeyData UserAssistant::enumValue(HKEY hKey, DWORD index)
{
    // buff for name
    DWORD lenFileName = MAX_VALUE_NAME;
    char valueNameBuf[MAX_VALUE_NAME] = { '\0' };

    // for data
    byte* achData = new byte[MAX_KEY_LENGTH];
    DWORD dataSize = MAX_KEY_LENGTH;

    // for key values
    int runCount = 0, focusTime = 0;
    unsigned long long winDate = 0, noNano = 0;
    tm timeInfo { 0,0,0,0,0,0,0,0,0 };
    time_t t;

    // check enum status
    LONG errorValue = RegEnumValueA(hKey, index, valueNameBuf, &lenFileName, NULL, NULL, achData, &dataSize);
    if (ERROR_SUCCESS == errorValue && lenFileName > 0) {
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
        if (winDate) {
            noNano = winDate / 10000000;
            t = noNano - 11644473600;
            localtime_s(&timeInfo, &t);
        }
    }
    delete[] achData;
    return KeyData(valueNameBuf, runCount, focusTime, QDateTime::fromTime_t(t));
}

QVector<KeyData> UserAssistant::getKeyValues(const QString &key)
{
    QVector<KeyData> values;
    HKEY USHKey;
    ULONG result = RegOpenKeyExA(HKEY_CURRENT_USER, key.toUtf8().constData(), NULL, KEY_READ, &USHKey);

    // check open key status
    if(result == ERROR_SUCCESS) {
        DWORD subKeysCount = 0, valuesCount = 0;
        result = queryInfoKey(USHKey, &subKeysCount, &valuesCount);
        if(result == ERROR_SUCCESS) {
            values.reserve(valuesCount);
            for(DWORD i = 0; i < valuesCount; i++) {
                const KeyData &data = enumValue(USHKey, i);
                if (data.isValid()) {
                    values.push_back(data);
                }
            }
        }
    }
    RegCloseKey(USHKey);
    values.squeeze();

    return values;
}
