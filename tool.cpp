#include <cstdio>
#include <cstring>
#include <QString>
#include "tool.h"
using namespace std;

typedef __int128 ll;

bool TransQStringToLL (QString s, ll &Rt) {
    char *RtStr;
    QByteArray str = s.toLatin1();
    RtStr = str.data();
    Rt = 0;
    int pos = 0;
    while (RtStr[pos]) {
        if (RtStr[pos] < '0' || RtStr[pos] > '9') return false;
        Rt = Rt * 10LL + (ll)(RtStr[pos] - '0');
        ++pos;
    }
    if (pos == 0 && !RtStr[pos]) return false;
    return true;
}

QString TransLLToQString (ll Rt) {
    char AnsStr[1300], pos = 0;
    memset(AnsStr, 0, sizeof(AnsStr));
    while (Rt)
        AnsStr[pos++] = (int)(Rt % 10LL) + '0', Rt /= 10LL;
    reverse(AnsStr, AnsStr + pos);
    QString qstr = QString(QLatin1String(AnsStr));
    return qstr;
}
