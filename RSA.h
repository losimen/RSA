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
#include "base64.h"


typedef std::vector<std::bitset<8>> byteArray;


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
//    double decryptPublic(const double &msg) const;

public:
    RSA(unsigned long long p = 13, unsigned long long q = 11);

    byteArray encryptPublicMsg(const std::string &msg) const;
    std::string decryptPrivateMsg(const byteArray &msg) const;

};


#endif //RSA_RSA_H
