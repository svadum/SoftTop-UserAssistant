#ifndef USERASSISTANT_H
#define USERASSISTANT_H

#include <QObject>
#include <QVector>
#include <Windows.h>
#include "keydata.h"

class UserAssistant : public QObject
{
    Q_OBJECT
public:
    // enum for sorting check
    enum SortType
    {
        ByHour,
        ByDays,
        ByAllTime
    };

    UserAssistant(QObject *parent = nullptr);

    inline QVector<KeyData> values() const { return m_values; }

    void setSortType(const SortType &st);
    inline SortType sortType() const { return m_sortType; }

public slots:
    void updateList();

private:
    SortType m_sortType;
    QVector<KeyData> m_values;

    // Registry helpers
    ULONG queryInfoKey(HKEY hKey, LPDWORD countSubKeys, LPDWORD countValues);
    KeyData enumValue(HKEY hKey, DWORD index);
    QVector<KeyData> getKeyValues(const QString &key);

    // Helpers
    void sortList(const UserAssistant::SortType &st);
};
#endif // USERASSISTANT_H
