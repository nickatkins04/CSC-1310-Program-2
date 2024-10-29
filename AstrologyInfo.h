#ifndef ASTROLOGYINFO_H
#define ASTROLOGYINFO_H

#include "AstrologyInfo.cpp"
#include <string>

using namespace std;

class AstrologyInfo
{
    private:
        string sign;
        string personalityTraits;
        string compatibility;
        string *luckyNumbers;
        int numLuckyNumbers;

    public:
        AstrologyInfo (string& sign);

        ~AstrologyInfo();

        void printInfo();
};

#endif