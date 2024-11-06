#ifndef ASTROLOGYINFO_H
#define ASTROLOGYINFO_H

#include "AstrologyInfo.cpp"
#include <string>

using namespace std;

template <class T>
class AstrologyInfo
{
    private:
        string sign;
        string personalityTraits;
        string compatibility;
        T *luckyNumbers;
        int numLuckyNumbers;

    public:
        AstrologyInfo(string& sign);

        ~AstrologyInfo();

        void printInfo();
};

#endif