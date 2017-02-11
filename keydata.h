#ifndef KEYDATA_H
#define KEYDATA_H

#include <QString>
#include <QDateTime>

class KeyData
{
public:
    // cstor & dstor
    KeyData();  // default
    KeyData(const QString &keyName, int keyRunCount,
            int keyFocusTime, const QDateTime &keyLDT);
    //~KeyData();

    // set
    void setName(const QString &keyName);
    void setRunCount(int keyRunCount);
    void setFocusTime(int keyFocusTime);
    void setLastDateTime(const QDateTime &keyFocusTime);

    // get
    QString getName() const { return name; }
    int getRunCount() const { return runCount; }
    int getFocusTime() const { return focusTime; }
    QDateTime getLastDateTime() const { return lastDateTime; }

private:
    QString name;       // name of key
    int runCount;       // program(key) run count
    int focusTime;      // time in focus
    QDateTime lastDateTime;   // last run date

    // service
    QString rot13(const QString &input) const;
    QString rewriteName(const QString &input);

};

#endif // KEYDATA_H
