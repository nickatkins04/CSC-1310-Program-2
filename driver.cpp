#include "userData.h"
#include "LinkedList.h"
#include "AstrologyInfo.h"
//#include "userData.cpp"

using namespace std;

int main()
{
    system("CLS");

    UserStorage<string> storage;


    // main menu function variables
    int selection = 0, profileNum = 0;
    bool mainMenu = true, enteringProfileData = false, selectingProfile = false, viewingProfile = false,mainLoop = true, canShowProfiles;
    // Profile function variables
    int day = 0, month = 0, year = 0, signNum = 0;
    string name, sign, dailyHoroscopePrint;
    char profileDataCheck = 'n';

    while (mainLoop)
    {
        while(mainMenu)
        {
            // This is going to be the code with as few functions as possible (I'll make them later)
            // Perhaps this whole main menu can be a function?
            cout << "Welcome to Horoscope!" << endl;
            cout << "1. Enter your information to find your horoscope!" << endl; 
            cout << "2. Select from profiles." << endl;    
            cout << "3. Quit. " << endl;
            cout << "Choice: ", cin >> selection, cout << endl;
            cin.ignore();
            // return selection + end of function (back in driver)
            switch (selection)
            {
            case 1:
                enteringProfileData = true;
                mainMenu = false;
                break;
            case 2:
                selectingProfile = true;
                mainMenu = false;
                break;
            case 3:
                mainLoop = false;
                mainMenu = false;
                break;
            default:
                cout << "Invalid selection. Please try again." << endl;
            }
            system("CLS");
        }
        
        while (enteringProfileData)
        {
            cout << "Enter your full name: ", getline(cin, name);
            cout << endl;
            getline (cin, name);

            cout << "Enter your birthday in a mt/dy/year format:" << endl;
            cout << "Month: ";
            cin >> month;
            cout << endl;
            cout << "Day: ";
            cin >> day;
            cout << endl;
            cout << "Year: ";
            cin >> year;
            cin.ignore();
            cout << endl;

            //Temporary UserData object to determine sign
            UserData tempUser(name, month, day, year, sign);
            sign = tempUser.getSign();
            signNum = tempUser.determineSignNum(month, day);

            system("CLS");
            
            //Function for printing out profile info
            tempUser.displayInfo();
            cout << "Is this data correct? (y/n): ";
            cin >> profileDataCheck;
            cout << endl;

            if (profileDataCheck == 'y' || profileDataCheck == 'Y')
            {
                //Add new user to storage
                storage.appendNode(tempUser);
                cout << "Zodiac Sign: " << sign << endl;
                enteringProfileData = false;
                viewingProfile = true;
                profileNum = storage.getLength() - 1;
            }
            system("CLS");
        }   

        while (selectingProfile) // Function call to horoscope profile information getter thing (later)
        {
            //Display profiles
            storage.displayList();
            cout << "Select a profile by number (or 0 to go back): ";
            cin >> profileNum;
            cin.ignore();

            if (profileNum == 0)
            {
                selectingProfile = false;
                mainMenu = true;
            }
            else if (profileNum > 0 && profileNum <= storage.getLength())
            {
                selectingProfile = false;
                viewingProfile = true;
                profileNum -= 1;
            }
            else
            {
                cout << "Invalid profile number. Please try again." << endl;
            }

        }
        while (viewingProfile)
        {
            system("CLS");

            UserData currentUser = storage.getNodeValue(profileNum);
            
            cout << "==============================" << endl;
            cout << currentUser.getName() << "'s profile" << endl;
            cout << "==============================" << endl;
            cout << "Sign: " << currentUser.getSign() << endl;
            cout << "------------------------------" << endl;
            cout << "1. View Horoscope" << endl;
            cout << "2. Compare with other profiles" << endl;
            cout << "3. Edit profile" << endl; 
            cout << "4. Go back to main menu" << endl;
            cout << "------------------------------" << endl;
            cout << "Selection: ";
            cin >> selection;
            cin.ignore();
            cout << endl;

            switch (selection)
            {
            case 1:
                currentUser.printAstrologyInfo();
                cout << "Daily Horoscope: " << endl;
                cout << currentUser.dailyHoroscope(signNum) << endl;
                cout << "=========================" << endl;
                cout << "Press enter to continue! " << endl;
                cin.ignore();
                cin.get();
                break;
            case 2:
                cout << "===================================" << endl;
                cout << "No profiles available at this time." << endl;
                cout << "Hit enter to continue. \n===================================" << endl;
                cin.ignore();
                cin.get();
                system("CLS");
                break;
            case 3:
                system("CLS");
                //editing profile
                enteringProfileData = true;
                viewingProfile = false;
                break;
            case 4: 
                system("CLS");
                mainMenu = true;
                viewingProfile = false;
                break;
            default:
                cout << "Invalid selection. Please try again." << endl;
                break;
            }
        }
    }
    return 0;
}