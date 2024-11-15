#include "AstrologyInfo.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// template <class T>
// AstrologyInfo<T>::AstrologyInfo()
// {

// }

template <class T>
void AstrologyInfo<T>::setPersonalityTraits(string pt)
{
    personalityTraits = pt;

    if (UserData.sign == "Aries")
    {
        personalityTraits = "Confident, energetic, determined";
    }

    if (UserData.sign == "Taurus")
    {
        personalityTraits = "Sensual, loyal, ambitious";
    }

    if (UserData.sign == "Gemini")
    {
        personalityTraits = "Intelligent, curious, social";
    }

    if (UserData.sign == "Cancer")
    {
        personalityTraits = "Nurturing, creative, benevolent";
    }
    
    if (UserData.sign == "Leo")
    {
        personalityTraits = "Generous, flamboyant, bold";
    }
    
    if (UserData.sign == "Virgo")
    {
        personalityTraits = "Hardworking, kind, reliable";
    }
    
    if (UserData.sign == "Libra")
    {
        personalityTraits = "Charming, artistic, compassionate";
    }

    if (UserData.sign == "Scorpio")
    {
        personalityTraits = "Brave, intuitive, honest";
    }

    if (UserData.sign == "Sagittarius")
    {
        personalityTraits = "Adventurous, idealistic, funny";
    }

    if (UserData.sign == "Capricorn")
    {
        personalityTraits = "Disciplined, organized, persistent";
    }
    
    if (UserData.sign == "Aquarius")
    {
        personalityTraits = "Open-minded, intellectual, independent";
    }
    
    if (UserData.sign == "Pisces")
    {
        personalityTraits = "Empathetic, adaptable, spiritual";
    }
}

template <class T>
string AstrologyInfo<T>::getPersonalityTraits()
{
    return personalityTraits;
}

template <class T>
void AstrologyInfo<T>::setCompatibility(string c)
{
    compatibility = c;

    if (UserData.sign == "Aries")
    {
        compatibility = "Leo, Sagittarius, Gemini, Libra, Aquarius";
    }

    if (UserData.sign == "Taurus")
    {
        compatibility = "Scorpio, Cancer, Pisces, Virgo, Capricorn";
    }

    if (UserData.sign == "Gemini")
    {
        compatibility = "Aries, Leo, Sagittarius, Libra, Aquarius";
    }

    if (UserData.sign == "Cancer")
    {
        compatibility = "Pisces, Scorpio, Taurus, Virgo, Capricorn";
    }
    
    if (UserData.sign == "Leo")
    {
        compatibility = "Aries, Sagittarius, Gemini, Libra, Aquarius";
    }
    
    if (UserData.sign == "Virgo")
    {
        compatibility = "Taurus, Capricorn, Cancer, Scorpio, Pisces";
    }
    
    if (UserData.sign == "Libra")
    {
        compatibility = "Gemini, Aquarius, Aries, Leo, Sagittarius";
    }

    if (UserData.sign == "Scorpio")
    {
        compatibility = "Cancer, Pisces, Taurus, Virgo, Capricorn";
    }

    if (UserData.sign == "Sagittarius")
    {
        compatibility = "Aries, Leo, Aquarius, Libra, Gemini";
    }

    if (UserData.sign == "Capricorn")
    {
        compatibility = "Taurus, Virgo, Cancer, Scorpio, Pisces";
    }
    
    if (UserData.sign == "Aquarius")
    {
        compatibility = "Gemini, Libra, Sagittarius, Aries, Leo";
    }
    
    if (UserData.sign == "Pisces")
    {
        compatibility = "Cancer, Scorpio, Taurus, Virgo, Capricorn";
    }
}

template <class T>
string AstrologyInfo<T>::getCompatibility()
{
    return compatibility;
}

template <class T>
void AstrologyInfo<T>::setLuckyNumbers(int ln)
{
    luckyNumbers = ln;

    if (UserData.sign == "Aries")
    {
        luckyNumbers = 9, 7, 17;
    }

    if (UserData.sign == "Taurus")
    {
        luckyNumbers = 6, 5, 33;
    }

    if (UserData.sign == "Gemini")
    {
        luckyNumbers = 5, 3, 22;
    }

    if (UserData.sign == "Cancer")
    {
        luckyNumbers = 2, 6, 11;
    }
    
    if (UserData.sign == "Leo")
    {
        luckyNumbers = 1, 14, 23;
    }
    
    if (UserData.sign == "Virgo")
    {
        luckyNumbers = 3, 7, 58;
    }
    
    if (UserData.sign == "Libra")
    {
        luckyNumbers = 7, 5, 64;
    }

    if (UserData.sign == "Scorpio")
    {
        luckyNumbers = 9, 18, 45;
    }

    if (UserData.sign == "Sagittarius")
    {
        luckyNumbers = 3, 12, 39;
    }

    if (UserData.sign == "Capricorn")
    {
        luckyNumbers = 8, 25, 51;
    }
    
    if (UserData.sign == "Aquarius")
    {
        luckyNumbers = 11, 29, 31;
    }
    
    if (UserData.sign == "Pisces")
    {
        luckyNumbers = 14, 24, 60;
    }
    
}

template <class T>
int AstrologyInfo<T>::getLuckyNumbers()
{
    return luckyNumbers;
}

template <class T>
AstrologyInfo<T>::~AstrologyInfo()
{
    delete AstrologyInfo;
}

template <class T>
void AstrologyInfo<T>::printInfo()
{
    cout << "Astrology Information for " << UserData.sign << ":" << endl;
    cout << "Personality Traits: " << personalityTraits << endl;
    cout << "Most compatible with: " << compatibility << endl;
    cout << "Lucky Numbers: " << luckyNumbers << endl;  
}