#include "AstrologyInfo.h"
#include <iostream>

AstrologyInfo::AstrologyInfo(std::string &sign)
{
    personalityTraits = "Personality traits for " + sign;

    numLuckyNumbers = 3;
    luckyNumbers = new std::string[numLuckyNumbers];
    luckyNumbers[0] = "7";
    luckyNumbers[1] = "14";
    luckyNumbers[2] = "21";
}

AstrologyInfo::~AstrologyInfo()
{
    delete[] luckyNumbers;
}

void AstrologyInfo::printInfo()
{
    std::cout << "Astrology Information for " << sign << ":" << std::endl;
    std::cout << "Personality Traits: " << personalityTraits << std::endl;
    std::cout << "Compatibility: " << compatibility << std::endl;
    std::cout << "Lucky Numbers: ";

    for (int i = 0; i < numLuckyNumbers; i++)
    {
        std::cout << luckyNumbers[i];
        if (i < numLuckyNumbers - 1)
            std::cout << ", ";
    }
    
    std::cout << std::endl;
    
}