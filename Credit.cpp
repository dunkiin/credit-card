#include "Credit.h"
#include <iostream>
#include <string>

// Given an int, return the sum of its individual digits
// hint: an easy way to parse an int into digits is by isolating
// the ��ones�� column (via %10), and reducing the number (via /10)
// in a loop until it is 0.
// - params: int - a number to analyze (eg: 123)
// - return an int representing the sum of digits (eg: 123 returns 6)

// return the sum of digits of an integer
int getSumOfDigits(int analyzeNumber) {
    
    int sum = 0;

    while (analyzeNumber != 0) {
        sum += analyzeNumber % 10;
        analyzeNumber /= 10;    // remove the last digit

    }

    return sum;

}

// Determine if a given card number starts with a given prefix
// Hint: research how the string.substr() function works.
// - param 1: a string representing the card number
// - param 2: a string representing the prefix
// - return: true if cardNumber starts with prefix (false otherwise)

// check if cardNumber starts by given prefix
bool startsWith(std::string cardNumber, std::string prefix) {
    // use substr to check the first string match the prefix string or not
    if (cardNumber.substr(0, prefix.size()) == prefix) {
        return true;
    }
    return false;
}


// Determine if a cardNum has a valid prefix.
// - param 1: a string representing the cardNumber
// - return: true if cardNumber starts with string literals:
// "4", "5", "6" or "37" (false otherwise)
// You could use string literals in this function, but it would
// much be cleaner to create a "Constants" namespace in your header
// file and create a const array of strings there (validPrefixes).
// that you can reference in this function.
// hint: you can make use of startsWith() in this function.

// check if the cardNumber include any prefix
bool hasValidPrefix(std::string cardNumber) {
    for (int i = 0; i < Constants::validPrefixes->size(); i++) {
        if (startsWith(cardNumber, Constants::validPrefixes[i])) {
            return true;    // return true, if valid prefixes is found
        }
    }
    return false;
}


// Add up the odd-place digits from right to left
// - param 1: a string to represent the cardNumber
// - return: the sum of odd-place digits from right to left in the card
// number (step 1, part 3).
// Eg: "34567" returns 15. (7+5+3)
// 
int sumOddDigitsRightToLeft(std::string& cardNumber) {
    int sum = 0;
    int card = static_cast<int>(cardNumber.size());
    //std::cout << card << '\n';

    for (int i = card; i >= 0; i--) {
        if (cardNumber[i] % 2) {
            sum += cardNumber[i] - '0';
            //std::cout << sum << '\n';
        }
    }
    return sum;
}


// Add up the even-place digits from right to left
// - param 1: a string to represent the cardNumber
// - return: the sum of the (even-place digits * 2) from right to left
// in the card number (step 1, part 1 & 2).
// Special rule: multi digit #'s need to be converted by adding
// their digits together before being added into the sequence.
// Eg: "34567" returns 11. ((6*2 = 12, converted to 1+2 = 3) + (4*2)) equals 11
// hint: make use of getSumOfDigits(std::string cardNumber)
int sumEvenDigitsRightToLeft(std::string& cardNumber) {
    int sum = 0;
    int card = static_cast<int>(cardNumber.size());
    
    for (int i = card - 2; i >= 0; i -= 2) {
        if (cardNumber[i] / 2) {
            sum += getSumOfDigits((cardNumber[i] - '0') * 2);
        }
    }

    return sum;
}


// Determine if a card # is valid. Valid if:
// - between 13 & 16 digits
// - has a valid prefix
// - sum of digits according to formula results in a number
// evenly divisible by 10
// This is the "workhorse" function that co - ordinates
// all the others.
// - param 1: a string to represent the cardNumber
// - return: true if the card number is valid (false otherwise)
bool isCardValid(std::string cardNumber) {
    // between 13 & 16
    if (cardNumber.size() < 13 || cardNumber.size() > 16) {
        return false;
    }

    // valid prefix
    if (!hasValidPrefix(cardNumber)) {
        return false;
    }

    // calculate the sum of digits
    int sum = sumOddDigitsRightToLeft(cardNumber) + sumEvenDigitsRightToLeft(cardNumber);
    
    if (sum % 10) {
        return false;
    }
    else {
        return true;
    }
}
