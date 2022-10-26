//
// Created by Павло Коваль on 15.06.2022.
//

#include "RSA.h"
#include "InfInt.h"


InfInt RSA::Pow(int number, int toPow) const
{
    InfInt result = 1;
    for(; toPow != 0; toPow -= 1)
        result *= number;
    return result;
}


bool RSA::isPrime(int number) const {
    if (number <= 1)
        return false;
    if (number <= 3)
        return true;

    if (number % 2 == 0 || number % 3 == 0)
        return false;

    for (int i = 5; i * i <= number; i = i + 6)
        if (number % i == 0 || number % (i + 2) == 0)
            return false;

    return true;
}


RSA::RSA(unsigned long long p, unsigned long long q) {
    e = 7;
    n = p*q;

    double phi = (p-1)*(q-1);
    double track;

    // find tack by this statement: d * e = 1 mod phi && d < phi
    for (int i = 1; i < phi; ++i) {
        track = int(i * e) % int(phi);
        if (track == 1) {
            d = i;
            break;
        }
    }

//    std::cout << "secret d = "<< d << std::endl;
//    std::cout << "public e = " << e << std::endl;
//    std::cout << "both n = " << n << std::endl;
}


unsigned long long RSA::encryptPublic(const unsigned long long &msg) const {
    InfInt m = Pow(msg, e);
    return (m%long(n)).toInt();
}


unsigned long long RSA::encryptPrivate(const unsigned long long &msg) const {
    InfInt m = Pow(msg, d);
    return (m%long(n)).toInt();
}


unsigned long long RSA::decryptPrivate(const unsigned long long &msg) const {
    InfInt m = Pow(int(msg), int(d));
    return (m%long(n)).toInt();
}


unsigned long long RSA::decryptPublic(const unsigned long long &msg) const {
    InfInt m = Pow(int(msg), int(e));
    return (m%long(n)).toInt();
}


byteArray RSA::encryptPublicMsg(const std::string &msg) const {
    byteArray bytes;

    for (auto& it : msg)
        bytes.push_back(byteWord(encryptPublic(it)));

    return bytes;
}


byteArray RSA::encryptPrivateMsg(const std::string &msg) const {
    byteArray bytes;

    for (auto& it : msg)
        bytes.push_back(byteWord(encryptPrivate(it)));

    return bytes;
}


std::string RSA::decryptPrivateMsg(const byteArray &bytes) const {
    std::string decryptedMsg;

    for (auto& it : bytes)
        decryptedMsg += char(decryptPrivate(it.to_ulong()));

    return decryptedMsg;
}

std::string RSA::decryptPublicMsg(const byteArray &bytes) const {
    std::string decryptedMsg;

    for (auto& it : bytes)
        decryptedMsg += char(decryptPublic(it.to_ulong()));

    return decryptedMsg;
}
