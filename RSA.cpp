//
// Created by Павло Коваль on 15.06.2022.
//

#include "RSA.h"
#include "InfInt.h"


const std::map<int, std::string> RSA::symbolCode {
        {10, "A"},
        {11, "B"},
        {12, "C"},
        {13, "D"},
        {14, "E"},
        {15, "F"},
        {16, "G"},
        {17, "H"},
        {18, "I"},
        {19, "J"},
        {20, "K"},
        {21, "L"},
        {22, "M"},
        {23, "N"},
        {24, "O"},
        {25, "P"},
        {26, "Q"},
        {27, "R"},
        {28, "S"},
        {29, "T"},
        {30, "U"},
        {31, "V"},
        {32, "W"},
        {33, "X"},
        {34, "Y"},
        {35, "Z"},
        {36, "a"},
        {37, "b"},
        {38, "c"},
        {39, "d"},
        {40, "e"},
        {41, "f"},
        {42, "g"},
        {43, "h"},
        {44, "i"},
        {45, "j"},
        {46, "k"},
        {47, "l"},
        {48, "m"},
        {49, "n"},
        {50, "o"},
        {51, "p"},
        {52, "q"},
        {53, "r"},
        {54, "s"},
        {55, "t"},
        {56, "u"},
        {57, "v"},
        {58, "w"},
        {59, "x"},
        {60, "y"},
        {61, "z"},
        {62, "0"},
        {63, "1"},
        {64, "2"},
        {65, "3"},
        {66, "4"},
        {67, "5"},
        {68, "6"},
        {69, "7"},
        {70, "8"},
        {71, "9"},
        {72, " "},
        {73, "."},
        {74, ","},
        {75, ";"},
        {76, ":"},
        {77, "-"},
        {78, "_"},
        {79, "+"},
        {80, "="},
        {81, "*"},
        {82, "/"},
        {83, "\\"},
        {84, "|"},
        {85, "("},
        {86, ")"},
        {87, "["},
        {88, "]"},
        {89, "{"},
};


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


RSA::RSA() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 100);

    long long p = 0, q = 0;

    while (!isPrime(p))
        p = dist6(rng);

    while(!isPrime(q))
        q = dist6(rng);

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

//    std::cout << "secret n = " << n << std::endl;
//    std::cout << "secret d = "<< d << std::endl;
//
//    std::cout << "public e = " << e << std::endl;
//    std::cout << "public n = " << n << std::endl;
}


double RSA::encryptPublic(const double &msg) const {
    double c = pow(msg,e);
    return fmod(c,n);
}


double RSA::encryptPrivate(const double &msg) const {
    double c = pow(msg,d);
    return fmod(c,n);
}


double RSA::decryptPrivate(const double &msg) const {
    InfInt m = Pow(int(msg), int(d));
    return (m%long(n)).toInt();
}


double RSA::decryptPublic(const double &msg) const {
    InfInt m = Pow(int(msg), int(e));
    return (m%long(n)).toInt();
}


double RSA::getSecret() const {
    return d;
}


void RSA::setSecret(double d_secret) {
    d = d_secret;
}


double RSA::getN() const {
    return n;
}


double RSA::getE() const {
    return e;
}


std::vector<int> RSA::encryptPublicMsg(const std::string &msg) const {
    std::vector<int> encryptedMsg;
    for (auto& it : msg) {
        for (auto& it2 : symbolCode) {
            if (it2.second == std::string(1, it)) {
                encryptedMsg.push_back(int(encryptPublic(double(it2.first))));
            }
        }
    }

    return encryptedMsg;
}


std::string RSA::decryptPrivateMsg(const std::vector<int> &msg) const {
    std::string decryptedMsg;

    for (auto& it : msg)
    {
        try
        {
            std::cout << int(decryptPrivate(double(it))) << " ";
            decryptedMsg += symbolCode.at(int(decryptPrivate(double(it))));
        } catch (std::out_of_range& e) {
            decryptedMsg += it;
        }
    }
    std::cout << std::endl;

    return decryptedMsg;
}


std::vector<int> RSA::encryptPrivateMsg(const std::string &msg) const {
    std::vector<int> encryptedMsg;

    for (auto& it : msg) {
        for (auto& it2 : symbolCode) {
            if (it2.second == std::string(1, it)) {
                encryptedMsg.push_back(int(encryptPublic(double(it2.first))));
            }
        }
    }

    return encryptedMsg;
}
