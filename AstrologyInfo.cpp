#include "AstrologyInfo.h"
#include <iostream>

using namespace std;

AstrologyInfo::AstrologyInfo(string &sign)
{
    personalityTraits = "Personality traits for " + sign;

    numLuckyNumbers = 3;
    luckyNumbers = new string[numLuckyNumbers];
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
    cout << "Astrology Information for " << sign << ":" << endl;
    cout << "Personality Traits: " << personalityTraits << endl;
    cout << "Compatibility: " << compatibility << endl;
    cout << "Lucky Numbers: ";

    for (int i = 0; i < numLuckyNumbers; i++)
    {
        cout << luckyNumbers[i];
        if (i < numLuckyNumbers - 1)
            cout << ", ";
    }
    
    cout << endl;
    
}