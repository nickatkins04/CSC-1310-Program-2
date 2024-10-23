#ifndef USERS_H
#define USERS_H

#include "userData.h"
#include <string>

using namespace std;

class UserStorage
{
    private:
        UserData** users;
        short MAXSIZE;
        short numProfiles;

    public:
        UserStorage(short MAXSIZE);

        ~UserStorage();

        void readData(const std::string& userData);
        void printAllUsers();
        void addUser(UserData* user);
        
        short getNumUsers() const;
        UserData* getUser(short index) const;

};

#endif