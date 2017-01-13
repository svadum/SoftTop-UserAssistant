#ifndef TOPTENLIST_H
#define TOPTENLIST_H

#include <QVector>
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
                               QString &valueName, QVector<KeyData> &vKeyValueData);

    ULONG EnumKey(HKEY hKey, DWORD index, QString &keyName);

    ULONG GetKeyValues(QString keyPath);

    // get
    QVector<KeyData> getTopListVector() const { return vTopList; }

    // service
    void updateList(SortType st);
    void sortList(bool (*f)(KeyData &, KeyData &));
    void sortByHour();
    void sortByDays();
    void sortByAllTime();
private:
    QVector<KeyData> vTopList;
    QString firstUserAssPath,
            secondUsetAssPath;
};
#endif // TOPTENLIST_H
