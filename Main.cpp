#include <iostream>
#include "Credit.h"
#include <fstream>

#include <string>
int main() {

    std::string inputFile = "cards.txt";
    std::ifstream fin;
    fin.open(inputFile);

    std::string userInput;
    int validSum = 0;
    int invalidSum = 0;

    if (fin.is_open()) {
        std::cout << "--------------------------------" << '\n';
        while (fin >> userInput) {
            
            if (isCardValid(userInput)) {
                std::cout << userInput << "   " << "valid: " << isCardValid(userInput) << '\n';
                validSum++;
            }
            else {
                std::cout << userInput << "   " << "valid: " << isCardValid(userInput) << '\n';
                invalidSum++;
            }
        }
        fin.close();
    }
    else
    {
        std::cout << "Error:Could not open file: \"" << inputFile << '\n';
    }

    std::cout << "--------------------------------" << '\n';
    std::cout << "valid cards: " << validSum << '\n';
    std::cout << "invalid cards: " << invalidSum << '\n';
    
    

    //std::cout << "Hello World!\n";
    //std::cout << getSumOfDigits(123) << '\n';
    //std::cout << startsWith(testCard, "34") << '\n';
    //std::cout << hasValidPrefix(testCard) << '\n';
    //std::cout << sumOddDigitsRightToLeft(testCard) << '\n';
    //std::cout << sumEvenDigitsRightToLeft(testCard) << '\n';
    
    
}

