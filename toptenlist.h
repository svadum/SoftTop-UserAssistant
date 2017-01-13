#ifndef TOPTENLIST_H
#define TOPTENLIST_H

#define ACCESS_ERROR 1
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

#include <QVector>
#include <QtAlgorithms>
#include <Windows.h>
#include "keydata.h"

class TopTenList
{
public:
    // enum for sorting check
    enum SortType
    {
        ByHour,
        ByDays,
        ByAllTime
    };

    // cstor
    TopTenList();

    // registry work
    ULONG QueryInfoKey(HKEY hKey, LPDWORD countSubKeys, LPDWORD countValues);

    void EnumValue(HKEY hKey, DWORD index,
                               QString &valueName, QVector<KeyData*> &vKeyValueData);

    ULONG EnumKey(HKEY hKey, DWORD index, QString &keyName);

    ULONG GetKeyValues(QString keyPath);

    // get
    QVector<KeyData*> getTopListVector() const { return vTopList; }

    // service
    void updateList(SortType st);
    void sortList(bool (*l)(KeyData* left, KeyData* right));
    void sortByHour();
    void sortByDays();
    void sortByAllTime();
private:
    QVector<KeyData*> vTopList;
    QString firstUserAssPath,
            secondUsetAssPath;
};
#endif // TOPTENLIST_H
