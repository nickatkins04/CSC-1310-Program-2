#ifndef ASTROLOGYINFO_H
#define ASTROLOGYINFO_H

#include "userData.h"
#include <string>

using namespace std;

template <typename T>
class AstrologyInfo
{
    private:
        AstrologyInfo<T>* personalityTraits;
        AstrologyInfo<T>* compatibility;
        AstrologyInfo<T>* luckyNumbers;

    public:
        T data;

        AstrologyInfo() : data() {};

        AstrologyInfo(T value): data(value) {};

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