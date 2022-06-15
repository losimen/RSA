# RSA

## Description 
RSA (Rivest–Shamir–Adleman) is a public-key cryptosystem that is widely used for secure data transmission. It is also one of the oldest. The acronym "RSA" comes from the surnames of Ron Rivest, Adi Shamir and Leonard Adleman, who publicly described the algorithm in 1977. An equivalent system was developed secretly in 1973 at GCHQ (the British signals intelligence agency) by the English mathematician Clifford Cocks. That system was declassified in 1997.

## Usage 
- Include `RSA.h`to your project
- Create `RSA` object 
- Use method `.encryptMsg(message)` to encrypt yor message
- There is 2 methods for decryption message. First `.decryptMsg(message)` you use to decrypt message with auto-generated secret key and the second `.decryptMsg(message, secret_d)`  you use with your own secret key
- Instead of using auto-generated key you can set your own with method `.setSecret(secret_d);`
- To get current secret key use `.getSecret()` method