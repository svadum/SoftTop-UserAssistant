#ifndef KEYDATA_H
#define KEYDATA_H

#include <QString>
#include <QDateTime>

class KeyData
{
public:
    KeyData();
    KeyData(const QString &keyName, int keyRunCount,
            int keyFocusTime, const QDateTime &keyLDT);

    void setName(const QString &keyName);
    void setRunCount(int keyRunCount);
    void setFocusTime(int keyFocusTime);
    void setLastDateTime(const QDateTime &keyFocusTime);

    QString getName() const { return name; }
    int getRunCount() const { return runCount; }
    int getFocusTime() const { return focusTime; }
    QDateTime getLastDateTime() const { return lastDateTime; }

    bool isValid() const;

private:
    QString name;       // name of key
    int runCount;       // program(key) run count
    int focusTime;      // time in focus
    QDateTime lastDateTime;   // last run date

    // helpers
    QString rot13(const QString &input) const;
    QString fileName(const QString &path);

};

#endif // KEYDATA_H
