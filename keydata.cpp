#include "keydata.h"

KeyData::KeyData()
    : name(""),
      runCount(0),
      focusTime(0),
      lastDateTime(QDateTime::currentDateTime())
{}

KeyData::KeyData(const QString &keyName, int keyRunCount,
        int keyFocusTime, const QDateTime &keyLDT)
{
    setName(keyName);
    setRunCount(keyRunCount);
    setFocusTime(keyFocusTime);
    setLastDateTime(keyLDT);
}

void KeyData::setName(const QString &keyName)
{
    if(!keyName.isEmpty())
        name = rewriteName(rot13(keyName));
    else
        name = "";
}

void KeyData::setRunCount(int keyRunCount)
{
    runCount = (keyRunCount >= 0 ? keyRunCount : 0);
}

void KeyData::setFocusTime(int keyFocusTime)
{
    focusTime = (keyFocusTime >= 0 ? keyFocusTime : 0);
}

void KeyData::setLastDateTime(const QDateTime &keyLDT)
{
    if(!keyLDT.isNull())
        lastDateTime = keyLDT;
    else
        lastDateTime = QDateTime::currentDateTime();
}

QString KeyData::rot13(const QString &input) const
{
    QString r = input;
    int i = r.length();
    while( i-- ) {
        if (r[i] >= QChar('A') && r[i] <= QChar('M') ||
            r[i] >= QChar('a') && r[i] <= QChar('m'))
           r[i] = (QChar)(QChar(r[i]).unicode() + 13);
        else if  (r[i] >= QChar('N') && r[i] <= QChar('Z') ||
                  r[i] >= QChar('n') && r[i] <= QChar('z'))
                 r[i] = (QChar)(QChar(r[i]).unicode() - 13);
    }
    return r;
}

QString KeyData::rewriteName(const QString &input)
{
    QString out;
    QStringList outList = input.split('\\');
    out = outList.at(outList.size() - 1);

    return out;
}
