#ifndef ASTROLOGYINFO_H
#define ASTROLOGYINFO_H

#include "userData.h"
#include <string>

using namespace std;

template <class T>
class AstrologyInfo
{
    private:
        AstrologyInfo sign;
        AstrologyInfo personalityTraits;
        AstrologyInfo compatibility;
        AstrologyInfo *luckyNumbers;
        AstrologyInfo numLuckyNumbers;

    public:
        AstrologyInfo(string& sign);

        ~AstrologyInfo();

        void printInfo();
};

#endif