#include <iostream>
#include "Credit.h"

#include <string>
int main() {
    std::string testCard = "34567";

    std::cout << "Hello World!\n";
    //std::cout << getSumOfDigits(123) << '\n';
    //std::cout << startsWith(testCard, "34") << '\n';
    //std::cout << hasValidPrefix(testCard) << '\n';
    //std::cout << sumOddDigitsRightToLeft(testCard) << '\n';
    std::cout << sumEvenDigitsRightToLeft(testCard) << '\n';
    std::cout << isCardValid(testCard) << '\n';
    
}

