#include "hashpassword.h"


QString HashPassword::HashCode(QString password) {
    int hashLength = 10;
    QByteArray data = password.toUtf8();
    QByteArray hash = QCryptographicHash::hash(data, QCryptographicHash::Sha256);

    QByteArray shortenedHash = hash.left(hashLength / 2);
    return shortenedHash.toHex();
}
