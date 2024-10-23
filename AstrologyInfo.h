#ifndef ASTROLOGYINFO_H
#define ASTROLOGYINFO_H

#include "AstrologyInfo.cpp"
#include <string>

class AstrologyInfo
{
    private:
        std::string sign;
        std::string personalityTraits;
        std::string compatibility;
        std::string *luckyNumbers;
        int numLuckyNumbers;

    public:
        AstrologyInfo (std::string& sign);

        ~AstrologyInfo();

        void printInfo();
};

#endif