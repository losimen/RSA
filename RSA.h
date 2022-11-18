//
// Created by Павло Коваль on 15.06.2022.
//

#ifndef RSA_RSA_H
#define RSA_RSA_H

#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <random>
#include <bitset>

#include "InfInt.h"


typedef std::bitset<8> byteWord;
typedef std::vector<byteWord> byteArray;


class RSA {
private:
    unsigned long long n;
    unsigned long long e;
    unsigned long long d;

    InfInt Pow(int number, int toPow) const;

    bool isPrime(int number) const;

    unsigned long long encryptPublic(const unsigned long long &msg) const;
    unsigned long long encryptPrivate(const unsigned long long &msg) const;

    unsigned long long decryptPrivate(const unsigned long long &msg) const;
    unsigned long long decryptPublic(const unsigned long long &msg) const;

public:
    RSA(unsigned long long p = 13, unsigned long long q = 11);

    byteArray encryptPublicMsg(const std::string &msg) const;
    byteArray encryptPrivateMsg(const std::string &msg) const;

    std::string decryptPrivateMsg(const byteArray &bytes) const;
    std::string decryptPublicMsg(const byteArray &bytes) const;

};


#endif //RSA_RSA_H
