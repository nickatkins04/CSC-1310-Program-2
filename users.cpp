#include "users.h"

#include <iostream>
#include <fstream>

using namespace std;

UserStorage::UserStorage(int MAXSIZE)
{
    numProfiles = 0;

    users = new UserData*[MAXSIZE];
    for (int i = 0; i < MAXSIZE; i++)
        users[i] = nullptr;
}

UserStorage::~UserStorage()
{
    for (int i = 0; i < numProfiles; i++)
        delete users[i];

    delete[] users;
}

void UserStorage::readData(const string &filename)
{
    ifstream infile(filename);
    if (!infile)
    {
        cout << "Unable to open file " << filename << endl;
        return;
    }

     string name, sign;
    int month, day, year;
    while (infile >> name >> month >> day >> year >> sign)
    {
        addUser(new UserData(name, day, month, year, sign));
    }
    

    infile.close();
}

void UserStorage::printAllUsers()
{
    string name;
    string sign;

    for (int i = 0; i < numProfiles; i++)
    {
        cout << "Profile " << (i + 1) << ":" << endl;
        users[i]->displayInfo();

    }
    
}

void UserStorage::addUser(UserData* user)
{
    if (numProfiles < MAXSIZE)
        users[numProfiles++] = user;
    else
        cout << "Storage is full. Cannot add more users." << endl;
}

int UserStorage::getNumUsers() const
{
    return numProfiles;
}

UserData* UserStorage::getUser(int index) const
{
    if (index >= 0 && index < numProfiles)
        return users[index];
    else
    {
        cout << "Invalid index: " << index << ". Returning nullptr." << endl;
        return nullptr;
    }
}