#include "keydata.h"

KeyData::KeyData()
    : name(""),
      runCount(0),
      focusTime(0)
{}

KeyData::KeyData(QString keyName, int keyRunCount,
        int keyFocusTime, QDateTime keyLastDateTime)
{
    setName(keyName);
    setRunCount(keyRunCount);
    setFocusTime(keyFocusTime);
    setLastDateTime(keyLastDateTime);
}

KeyData::KeyData(const KeyData &keyCopy)
{
    setName(keyCopy.getName());
    setRunCount(keyCopy.getRunCount());
    setFocusTime(keyCopy.getFocusTime());
    setLastDateTime(keyCopy.getLastDateTime());
}

void KeyData::setName(QString keyName)
{
    if(!keyName.isEmpty())
        name = rewriteName(rot13(keyName));
}

void KeyData::setRunCount(int keyRunCount)
{
    runCount = (keyRunCount >= 0 ? keyRunCount : 0);
}

void KeyData::setFocusTime(int keyFocusTime)
{
    focusTime = (keyFocusTime >= 0 ? keyFocusTime : 0);
}

void KeyData::setLastDateTime(QDateTime keyLDT)
{
    if(!keyLDT.isNull())
        lastDateTime = keyLDT;
}

QString KeyData::rot13(const QString &input) const
{
    QString r = input;
    int i = r.length();
    while( i-- ) {
        if ( r[i] >= QChar('A') && r[i] <= QChar('M') ||
            r[i] >= QChar('a') && r[i] <= QChar('m') )
            r[i] = (char)((int)QChar(r[i]).unicode() + 13);
        else if  ( r[i] >= QChar('N') && r[i] <= QChar('Z') ||
            r[i] >= QChar('n') && r[i] <= QChar('z') )
            r[i] = (char)((int)QChar(r[i]).unicode() - 13);
    }
    return r;
}

QString KeyData::rewriteName(const QString input)
{
    QString out;
    QStringList outList = input.split('\\');
    out = outList.at(outList.size() - 1);

    return out;
}
