#include <iostream>

#include "RSA.h"


int main() {
    RSA a, b;
    std::string msg = "Hello world!";

    std::vector<int> encr1 = a.encryptPublicMsg("HELLO");

    std::cout << "Encryption: ";
    for (auto el: encr1)
        std::cout << el << " ";
    std::cout << std::endl;
//
    std::cout << "-Decrypted message good = " << a.decryptPrivateMsg(encr1) << std::endl;
//    std::cout << "-Decrypted message bad = " << b.decryptPrivateMsg(encr1) << std::endl;

//    std::cout << "-Decrypted message = " << a.decryptPrivateMsg(encr1) << std::endl;

    return 0;
}