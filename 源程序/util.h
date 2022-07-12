#ifndef UTIL_H
#define UTIL_H

#include <QString>
#include <QByteArray>

class util
{
public:
    util();
    bool fileread(QString url,QByteArray& data);
    bool filewrite(QString url,unsigned char* data,int len);
};

#endif // UTIL_H
