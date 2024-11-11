#include "AstrologyInfo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
AstrologyInfo<T>::AstrologyInfo(string &)
{
    personalityTraits = "Personality traits for " + sign;

    luckyNumbers = new T[numLuckyNumbers];

    srand(time(0));

    for (int count = 0; count < numLuckyNumbers; count++)
        *(luckyNumbers+count) = rand()

    return luckyNumbers;
}

template <class T>
AstrologyInfo<T>::~AstrologyInfo()
{
    delete[] luckyNumbers;
}

template <class T>
void AstrologyInfo<T>::printInfo()
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