#include <iostream>
#include <cmath>

#include "RSA.h"


int main() {
    double message = 9;
    RSA a;

    std::cout << "Encrypted message = "<< a.encryptMsg(message) << std::endl;

    double secret_d = a.getSecret();

    // -- True secret decryption
    std::cout << "Decrypted with set secret message = "<< a.decryptMsg(message, secret_d) << std::endl;
    std::cout <<"Decrypted with secret message = "<< a.decryptMsg(message) << std::endl;

    // - False secret decryption
    secret_d += 1;
    a.setSecret(secret_d);

    std::cout << "Decrypted with set secret message = "<< a.decryptMsg(message, secret_d) << std::endl;
    std::cout <<"Decrypted with secret message = "<< a.decryptMsg(message) << std::endl;

    return 0;
}