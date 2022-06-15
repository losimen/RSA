//
// Created by Павло Коваль on 15.06.2022.
//

#include "RSA.h"

int RSA::gcd(int a, int b)  {
    int t;

    while(true) {
        t= a%b;
        if(t==0)
            return b;
        a = b;
        b= t;
    }
}

RSA::RSA() {
    p = 13;
    q = 11;
    n = p*q;

    double track;
    double phi= (p-1)*(q-1);

    e=7;

    while(e<phi) {
        track = gcd(int(e),int(phi));
        if(track==1)
            break;
        else
            e++;
    }

    double d1=1/e;
    d = fmod(d1,phi);
}

double RSA::encryptMsg(const double &msg) const {
    double c = pow(msg,e);

    return fmod(c,n);
}

double RSA::decryptMsg(const double &msg) const {
    double c = pow(msg, e);
    double m = pow(c, d);

    return fmod(m, n);
}

double RSA::decryptMsg(const double &msg, const double secret_d) const {
    double c = pow(msg, e);
    double m = pow(c, secret_d);

    return fmod(m, n);
}

double RSA::getSecret() const {
    return d;
}

void RSA::setSecret(double d_secret) {
    d = d_secret;
}

