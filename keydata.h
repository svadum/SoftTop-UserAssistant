#ifndef KEYINFO_H
#define KEYINFO_H

#include <QString>
#include <QSettings>
#include <QDateTime>
#include <ctime>
#include <Windows.h>

class KeyData
{
public:
    // cstor & dstor
    KeyData();  // default
    KeyData(QString keyName, int keyRunCount, int keyFocusTime, QDateTime keyLastDateTime);
    KeyData(const KeyData &); // copy
    ~KeyData();

    // set
    void setName(QString keyName);
    void setRunCount(int keyRunCount);
    void setFocusTime(int keyFocusTime);
    void setLastDateTime(QDateTime keyFocusTime);

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
    QString rewriteName(const QString input);

};

#endif // KEYINFO_H
