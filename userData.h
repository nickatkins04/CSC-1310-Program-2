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
        int day;
        int month;
        int year;
        int signNum;
        AstrologyInfo* astrologyInfo;
        
    public:
        UserData(){}

        UserData(std::string n, int d, int m, int y, std::string s);

        ~UserData();

        // Getters
        std::string getName();

        int getMonth();

        int getDay();

        int getYear();

        std::string getSign();

        // Setters
        void setName(std::string &name);

        void setDay(int day);

        void setMonth(int month);

        void setYear(int year);

        void setSign(std::string &sign);

        // Optional: A method to display user information
        void displayInfo();

        int determineSignNum(int month, int day);

        std::string determineSign(int month, int day);
        
        // Loads user info from profiles.txt 
        bool loadProfiles(UserData **user, bool canShowProfiles);

        int showProfiles(UserData **user, int selection, bool canShowProfiles);

        void saveToFile(UserData **user);

        void printOut(UserData **user, int profileNum);

        std::string dailyHoroscope(int signNum);

        //Prints astrology info
        void printAstrologyInfo();
};

#endif