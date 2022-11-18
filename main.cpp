#include <iostream>

#include "RSA.h"


int main() {
    RSA a(13, 11);
    RSA b(11, 17);

    std::string msg = "Hello Pavlo!";
    byteArray arrA = a.encryptPublicMsg(msg);

    std::cout << "-Encrypt public view: ";
    for (auto byte: arrA)
        std::cout << byte.to_string();
    std::cout << std::endl;

    std::cout << "-Decrypted private message good = " << a.decryptPrivateMsg(arrA) << std::endl;
    std::cout << "-Decrypted private message bad = " << b.decryptPrivateMsg(arrA) << std::endl;

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "-Encrypt private view: ";
    arrA = a.encryptPrivateMsg(msg);
    for (auto byte: arrA)
        std::cout << byte.to_string();
    std::cout << std::endl;

    std::cout << "-Decrypted public message good = " << a.decryptPublicMsg(arrA) << std::endl;
    std::cout << "-Decrypted public message bad = " << b.decryptPublicMsg(arrA) << std::endl;

    return 0;
}