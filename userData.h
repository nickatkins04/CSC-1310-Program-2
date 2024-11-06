#ifndef USERDATA_H
#define USERDATA_H  

#include "AstrologyInfo.h"
#include <iostream>
#include <string>


using namespace std;


class UserData
{
    private:
        
        string name;
        string sign;
        int day;
        int month;
        int year;
        int signNum;
        AstrologyInfo* astrologyInfo;
        
    public:
        UserData(){}

        UserData(string n, int d, int m, int y, string s);

        ~UserData();

        // Getters
        string getName();

        int getMonth();

        int getDay();

        int getYear();

        string getSign();

        // Setters
        void setName(string &name);

        void setDay(int day);

        void setMonth(int month);

        void setYear(int year);

        void setSign(string &sign);

        // Optional: A method to display user information
        void displayInfo();

        int determineSignNum(int month, int day);

        string determineSign(int month, int day);
        
        // Loads user info from profiles.txt 
        bool loadProfiles(UserData **user, bool canShowProfiles);

        int showProfiles(UserData **user, int selection, bool canShowProfiles);

        void saveToFile(UserData **user);

        void printOut(UserData **user, int profileNum);

        string dailyHoroscope(int signNum);

        //Prints astrology info
        void printAstrologyInfo();

        //Overloaded operations
        void
};

#endif