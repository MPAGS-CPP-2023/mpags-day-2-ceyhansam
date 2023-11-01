#include<string>
#include<iostream>
#include<vector>

std::string CeaserCipher(std::string& inputText, const size_t key, bool encrypt){
    //
    std::string encrytedText{""};
    int wrapShift{};
    char inputChar{'x'};
    std::cout << "INSIDE CIPHER" << std::endl;
    std::cout << inputText << std::endl;

    //Define constant vector to store alphabet
    const std::vector<char> alphabet{'A', 'B', 'C', 'D', 'E', 'F', 'G',
                                            'H', 'I', 'J', 'K', 'L', 'M', 'N',
                                            'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                                            'V', 'W', 'X', 'Y', 'Z'};
    const std::size_t len{inputText.size()};

    // for (std::size_t i{0}; i<len; i++) {
    //     std::cout << "INSIDE FOR LOOP" << std::endl;
    //     inputChar = inputText[i];
    //     std::cout << inputChar << std::endl;
    //     if (encrypt) {
    //         shift = i + key;
    //         wrapShift = shift % 26;
    //         encrytedText += int(inputChar + wrapShift);
    //         std::cout << encrytedText << std::endl;
    //         return encrytedText;
    //     } else {
    //         shift = i - key;
    //         if (shift < 0) {
    //             encrytedText += alphabet[(i - key) % 26];
    //             return encrytedText;
    //         } else {
    //             encrytedText += alphabet[i - key];
    //             return encrytedText;
    //         }
    //     }
    // }

    if (encrypt) {
        std::cout << "Encrypting" << std::endl;
        std::cout << len << std::endl;
        for (std::size_t i{0}; i < len; i++) {
            wrapShift = (i + key) % 26;
            inputChar = inputText[i];
            encrytedText += int(inputChar + wrapShift);
            std::cout << i << std::endl;
            return encrytedText;
        }
    } else {
        std::cout << "Decrypting" << std::endl;
        for (std::size_t i{0}; i < len; i++) {
            wrapShift = (i - key) % 26;
            inputChar = inputText[i];
            encrytedText += int(inputChar + wrapShift);
            return encrytedText;
        }
    }

    return encrytedText;
}