#ifndef ASTROLOGYINFO_H
#define ASTROLOGYINFO_H

#include "userData.h"
#include <string>

using namespace std;

template <class T>
class AstrologyInfo
{
    private:
        AstrologyInfo personalityTraits;
        AstrologyInfo compatibility;
        AstrologyInfo *luckyNumbers;

    public:
        // AstrologyInfo();

        void setPersonalityTraits(string pt);

        string getPersonalityTraits();

        void setCompatibility(string c);

        string getCompatibility();

        void setLuckyNumbers(int ln);

        int getLuckyNumbers();

        ~AstrologyInfo();

        void printInfo();
};

#endif