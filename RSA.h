//
// Created by Павло Коваль on 15.06.2022.
//

#ifndef RSA_RSA_H
#define RSA_RSA_H

#include<cmath>


class RSA {
private:
    double p;
    double q;
    double n;
    double e;
    double d;

    static int gcd(int a, int b);

public:
    RSA();

    double encryptMsg(const double &msg) const;
    double decryptMsg(const double &msg) const;

    double decryptMsg(const double &msg, const double secret_d) const;
    double getSecret() const;

    void setSecret(double d_secret);
};


#endif //RSA_RSA_H
