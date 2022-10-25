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

#include "InfInt.h"


class RSA {
private:
    double n;
    double e;
    double d;

    static const std::map<int, std::string> symbolCode;
    InfInt Pow(int number, int toPow) const;

    bool isPrime(int number) const;

    double encryptPublic(const double &msg) const;
    double encryptPrivate(const double &msg) const;

    double decryptPrivate(const double &msg) const;
    double decryptPublic(const double &msg) const;

public:
    RSA();

    double getN() const;
    double getE() const;

    std::vector<int> encryptPublicMsg(const std::string &msg) const;
    std::vector<int> encryptPrivateMsg(const std::string &msg) const;

    std::string decryptPrivateMsg(const std::vector<int> &msg) const;

    double getSecret() const;
    void setSecret(double d_secret);
};


#endif //RSA_RSA_H
