#ifndef USERDATA_H
#define USERDATA_H  

#include "AstrologyInfo.h"
#include <fstream> // Used for save files
#include <iostream>
#include <string>


// using namespace std;

class UserData
{
    private:
        
        std::string name;
        std::string sign;
        short day;
        short month;
        short year;
        short signNum;
        AstrologyInfo* astrologyInfo;
        
    public:
        UserData(){}

        UserData(std::string n, short d, short m, short y, std::string s);

        ~UserData();

        // Getters
        std::string getName();

        short getMonth();

        short getDay();

        short getYear();

        std::string getSign();

        // Setters
        void setName(std::string &name);

        void setDay(short day);

        void setMonth(short month);

        void setYear(short year);

        void setSign(std::string &sign);

        // Optional: A method to display user information
        void displayInfo();

        short determineSignNum(short month, short day);

        std::string determineSign(short month, short day);
        
        // Loads user info from profiles.txt 
        bool loadProfiles(UserData **user, bool canShowProfiles);

        short showProfiles(UserData **user, short selection, bool canShowProfiles);

        void saveToFile(UserData **user);

        void printOut(UserData **user, short profileNum);

        std::string dailyHoroscope(short signNum);

        //Prints astrology info
        void printAstrologyInfo();
};

#endif