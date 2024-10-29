#ifndef USERS_H
#define USERS_H

#include "userData.h"
#include <string>

using namespace std;

class UserStorage
{
    private:
        UserData** users;
        int MAXSIZE;
        int numProfiles;

    public:
        UserStorage(int MAXSIZE);

        ~UserStorage();

        void readData(const string& userData);
        void printAllUsers();
        void addUser(UserData* user);
        
        int getNumUsers() const;
        UserData* getUser(int index) const;

};

#endif