#include<string>
#include<iostream>
#include<vector>

std::string CeaserCipher(std::string& inputText, const size_t key, bool encrypt){
    //
    std::string encryptedText{""};
    int wrapShift{};
    char inputChar{'x'};
    size_t modKey = key % 26; //Ensure given key is between 0 - 26

    //Define constant vector to store alphabet
    const std::vector<char> alphabet{'A', 'B', 'C', 'D', 'E', 'F', 'G',
                                            'H', 'I', 'J', 'K', 'L', 'M', 'N',
                                            'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                                            'V', 'W', 'X', 'Y', 'Z'};
    const std::size_t len{inputText.size()};

    if (encrypt) { //Encryption Procedure
        for (std::size_t i{0}; i < len; i++) {
            inputChar = inputText[i];
            for (std::size_t j{0}; j < 26; j++) {
                wrapShift = (j+modKey) % 26;
                if (inputChar == alphabet[j]) {
                    encryptedText += alphabet[wrapShift];
                }
            }
        }
    } else { //Decryption Procedure
        for (std::size_t i{0}; i < len; i++) {
            inputChar = inputText[i];
            for (std::size_t j{0}; j < 26; j++) {
                wrapShift = (j+26-modKey) % 26; //Ensure wrapShift is positive before modulo is taken
                if (inputChar == alphabet[j]) {
                    encryptedText += alphabet[wrapShift];
                }
            }
        }
    }

    // if (encrypt) {
    //     std::cout << "Encrypting" << std::endl;
    //     //std::cout << len << std::endl;
    //     for (std::size_t i{0}; i < len; i++) {
    //         wrapShift = (i + key) % 26;
    //         inputChar = inputText[i];
    //         encryptedText += int(inputChar + wrapShift);
    //     }
    // } else {
    //     std::cout << "Decrypting" << std::endl;
    //     for (std::size_t i{0}; i < len; i++) {
    //         wrapShift = (i - key) % 26;
    //         inputChar = inputText[i];
    //         encryptedText += int(inputChar + wrapShift);
    //     }
    // }

    return encryptedText;
}