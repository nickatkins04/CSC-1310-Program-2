#include "users.h"

#include <iostream>
#include <fstream>

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

void UserStorage::readData(const std::string &filename)
{
    std::ifstream infile(filename);
    if (!infile)
    {
        std::cout << "Unable to open file " << filename << std::endl;
        return;
    }

    std:: string name, sign;
    int month, day, year;
    while (infile >> name >> month >> day >> year >> sign)
    {
        addUser(new UserData(name, day, month, year, sign));
    }
    

    infile.close();
}

void UserStorage::printAllUsers()
{
    std::string name;
    std::string sign;

    for (int i = 0; i < numProfiles; i++)
    {
        std::cout << "Profile " << (i + 1) << ":" << std::endl;
        users[i]->displayInfo();

    }
    
}

void UserStorage::addUser(UserData* user)
{
    if (numProfiles < MAXSIZE)
        users[numProfiles++] = user;
    else
        std::cout << "Storage is full. Cannot add more users." << std::endl;
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