#include <iostream>
#include <string>

std::string transformChar(const char inputChar) {

     // Uppercase alphabetic characters
    if (std::isalpha(inputChar)) {
        std::string upperChar{""};
        upperChar += std::toupper(inputChar);
        return upperChar;
    }

    // Transliterate digits to English words
    switch (inputChar) {
        case '0':
            return "ZERO";
            break;
        case '1':
            return "ONE";
            break;
        case '2':
            return "TWO";
            break;
        case '3':
            return "THREE";
            break;
        case '4':
            return "FOUR";
            break;
        case '5':
            return "FIVE";
            break;
        case '6':
            return "SIX";
            break;
        case '7':
            return "SEVEN";
            break;
        case '8':
            return "EIGHT";
            break;
        case '9':
            return "NINE";
            break;
    }

        // If the character isn't alphabetic or numeric, DONT add it
    return 0;
};