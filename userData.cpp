#include "userData.h"
#include <fstream>
#include <string>
#include <iostream>

const short MAXUSERS = 5;

std::string horoscopes[12] = 
        {
            "Changes taking place at home could lead to more income, Whatever it is, it may not seem like much,\nbut it should make a difference in your financial situation in the long run.", // Aries
            "A walk through your neighborhood could put you in the middle of an unexpected, interesting event.\nWhatever it is, you could be transfixed by it. Make mental notes and then write down your impressions later.", // Taurus
            "Some books you've been reading lately might excite your desire to study astrology, numerology, alchemy,\nor some other occult science. Your values have been shaken up lately anyway, so make the most of the\nimpulse now. It could transform you in a subtle way.", // Gemini
            "Boredom might stimulate your rebellious streak today, Cancer. You could decide to forego your usual tasks\nand do something unusual or unexpected, such as skydiving or horseback riding. Don't feel guilty if\nyou decide to do this. We all need to throw caution to the wind and go for some excitement occasionally.", // Cancer
            "New information could keep your mind buzzing for hours. Make the effort to take a walk and clear your head\nat some point during the day or else you might be too mentally charged up to sleep.", // Leo
            "A future journey may be in the works right now. Your energy, enthusiasm, and excitement are high. ", // Virgo
            "A change in career could be in the works for you. It might be within the scope of your current job or an\nentirely new one. Don't let insecurity or an attachment to your current circumstances hold you back.\nWhatever opportunities appear at this time may not come around again for a long while. Think about it carefully and then follow your heart.", // Libra
            "An unexpected opportunity to go on a long journey, perhaps business-related, could come to you soon.\nA partner might be involved. Your enthusiasm may be almost boundless but remember that your physical energy\nisn't. If you choose to travel right now, make sure you take necessary precautions. ", // Scorpio
            "Too much hard work and stress could be taking a physical toll on you today. But it isn't likely to stop\nyou from working intently and energetically on a project that fascinates you. This enterprise could be\npersonal or job related, but whatever it is, the turn it takes is apt to surprise you. It might not be anything like what you'd planned!", // Sagittarius
            "If you're single, today you could fall in love at first sight. A friend could send you someone's contact\ninformation who shares your interests and with whom you'll talk for hours. This could make you feel\nhappy. You'll certainly enjoy your day. If you want to stay in touch, don't be afraid to say so. Otherwise, you might lose track of your new friend.", // Capricorn
            "Have you been considering working more at home? If so, today you might decide to do just that.\nAn opportunity could pave the way for new jobs you could do at home, in your own space, among your own belongings.\nThis could add to your sense of security. The only downside could be if you don't make the effort, you might never leave the house. Be sure to get your workout in!" // Aquarius
            "A conversation with a sibling or neighbor could lead to you making a new friend today, probably someone\nwho works in a creative profession. If you're currently romantically involved, this person could become\nyour best friend. If you're unattached, sparks could fly between you and him or her. You could talk for hours and part unwillingly. Exchange contact information. You'll be glad you did!" //Picses
        }; // All horoscopes are from Horoscope.com (9/25/2024)
        

UserData::UserData(std::string n, short d, short m, short y, std::string s)
{
    name = n;
    month = m;
    day = d;
    year = y;
    sign = s;

    sign = determineSign(month, day);
    astrologyInfo = new AstrologyInfo(sign);
}

UserData::~UserData()
{
    delete astrologyInfo;
}

// Getters
std::string UserData::getName()
{
    return name;
}
short UserData::getMonth()
{
    return month;
}
short UserData::getDay()
{
    return day;
}
short UserData::getYear()
{
    return year;
}
std::string UserData::getSign()
{
    return sign;
}

// Setters
void UserData::setName(std::string &name)
{
    this->name = name;
}

void UserData::setDay(short day)
{
    this->day = day;
}

void UserData::setMonth(short month)
{
    this->month = month;
}

void UserData::setYear(short year)
{
    this->year = year;
}

void UserData::setSign(std::string &sign)
{
    this->sign = sign;
    if (astrologyInfo != nullptr)
        delete astrologyInfo;
    astrologyInfo = new AstrologyInfo(sign);
}

// Optional: A method to display user information
void displayInfo()
{
    std::string name;
    std::string sign;
    std::cout << "Here is your profile:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Zodiac Sign: " << sign << std::endl;
}

short determineSignNum(short month, short day)
{
    short monthMin[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    std::string zodiacMonthSigns[12] = {"Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"};
    // Define the zodiac sign ranges
    short zodiacRanges[12][12] = {
        {80, 109},  // Aries
        {110, 140}, // Taurus
        {141, 171}, // Gemini
        {172, 203}, // Cancer
        {204, 234}, // Leo
        {235, 265}, // Virgo
        {266, 295}, // Libra
        {296, 325}, // Scorpio
        {326, 355}, // Sagittarius
        {356, 19},  // Capricorn (wraps around)
        {20, 49},   // Aquarius
        {50, 79}    // Pisces
    };
    std::string sign;
    short daySum;
    short signNum;

    daySum = monthMin[month - 1] + day;

    // Determine zodiac sign based on daySum
    for (int i = 0; i < 12; i++)
    {
        if (daySum >= zodiacRanges[i][0] && daySum <= zodiacRanges[i][1])
        {
            signNum = i;
            break;
        }
    }
    return signNum;
}
std::string determineSign(short month, short day)
{
    short monthMin[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    std::string zodiacMonthSigns[12] = {"Aries", "Taurus", "Gemini", "Cancer", "Leo", "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn", "Aquarius", "Pisces"};
    // Define the zodiac sign ranges
    short zodiacRanges[12][12] = {
        {80, 109},  // Aries
        {110, 140}, // Taurus
        {141, 171}, // Gemini
        {172, 203}, // Cancer
        {204, 234}, // Leo
        {235, 265}, // Virgo
        {266, 295}, // Libra
        {296, 325}, // Scorpio
        {326, 355}, // Sagittarius
        {356, 19},  // Capricorn (wraps around)
        {20, 49},   // Aquarius
        {50, 79}    // Pisces
    };
    std::string sign;
    short daySum;

    daySum = monthMin[month - 1] + day;

    // Determine zodiac sign based on daySum
    for (int i = 0; i < 12; i++)
    {
        if (daySum >= zodiacRanges[i][0] && daySum <= zodiacRanges[i][1])
        {
            sign = zodiacMonthSigns[i];
            break;
        }
    }
    return sign;
}

std::string UserData::dailyHoroscope(short signNum)
{
    return horoscopes[signNum];
};

void UserData::printAstrologyInfo()
{
    if (astrologyInfo != nullptr)
    {
        astrologyInfo->printInfo();
    }
    
}

// Loads user info from profiles.txt
bool loadProfiles(UserData **user, bool canShowProfiles)
{
    std::ifstream inputFile;
    inputFile.open("profiles.txt");
    std::string buffer;

    if (inputFile.is_open())
    {
        std::string name = "", sign;
        for (int i = 0; i < MAXUSERS; i++)
        {
            if (getline(inputFile, name, '#'))
            {
                user[i]->setName(name);
                getline(inputFile, sign, '#');
                user[i]->setSign(sign);
                canShowProfiles = true;
            }
            if (i == 0 && name == "")
            {
                std::cout << "\nNo profiles found in file. Create a profile first to get your horoscope!" << std::endl;
                canShowProfiles = false;
                break;
            }
        }
    }
    inputFile.close();
    return canShowProfiles;
}

short UserData::showProfiles(UserData **user, short selection, bool canShowProfiles)
{
    if (canShowProfiles)
    {
        for (int i = 0; i < MAXUSERS; i++)
        {
            std::cout << "-----------------------------------------------------------------------------" << std::endl;
            std::cout << "----------------------------------Profile " << i + 1 << std::endl;
            std::cout << "Name: " << name << std::endl;
            std::cout << "Sign: " << sign << std::endl;
            std::cout << "-----------------------------------------------------------------------------" << std::endl;
        }
        for (int i = 0; i < MAXUSERS; i++)
        {
            std::cout << i + 1 << ": " << name << std::endl;
        }
        std::cout << "Select a profile: ", std::cin >> selection, std::cout << std::endl;
        return selection;
        system("CLS");
    }
    else
    {
        std::cout << "Cannot display profiles. " << std::endl;
    }
    return 0;
}

void saveToFile(UserData **user)
{
    std::string name, sign;
    std::ofstream outputFile;
    outputFile.open("profiles.txt");
    for (int i = 0; i < MAXUSERS; i++)
    {
        name = user[i]->getName();
        sign = user[i]->getSign();
        if (outputFile.is_open())
        {
            outputFile << user[i]->getName() << '#' << user[i]->getSign() << '#'; // Program stops here
            std::cout << "Success!" << std::endl;
            break;
        }
        else
        {
            std::cout << "There was a problem opening the profiles.txt file.\nYou will be able to continue but your profile will not be saved for later." << std::endl;
        }
        std::cin.get();
    }
    outputFile.close();
}

void printAstrologyInfo()
{
    UserData **user; 
    short profileNum;

    std::string sign = user[profileNum]->getSign();

    if (sign == "Aries")
    {
        std::cout << "You are an Aries!\n"
             << std::endl;

        std::cout << "Aries is the first sign of the zodiac,"
                "and thats pretty much how those born under this sign see themselves: first. \n"
                "Aries are the leaders of the pack, first in line to get things going.\n"
                "Whether or not everything gets done is another question altogether,\n"
                "for an Aries prefers to initiate rather than to complete.\n"
             << std::endl;

        std::cout << "You share the same sign as: Lady Gaga, William Shakespeare, and Thomas Jefferson." << std::endl;
    }

    else if (sign == "Taurus")
    {

        std::cout << "You are a Taurus!\n"
             << std::endl;

        std::cout << "Taurus, the second sign of the zodiac and the ruler of the second house, \n"
                "is all about reward. Unlike the Aries love of the game, \n"
                "the typical Taurus personality loves the rewards of the game. \n"
                "Think physical pleasures and material goods, \n"
                "for those born under this sign revel in delicious excess.\n"
             << std::endl;

        std::cout << "John Cena, George Clooney, and Lizzo." << std::endl;
    }

    else if (sign == "Gemini")
    {

        std::cout << "You are a Gemini!\n"
             << std::endl;

        std::cout << "Gemini is the third sign of the zodiac, \n"
                "and those born under this sign will be quick to tell you all about it. \n"
                "That's because they love to talk! It's not just idle chatter with these folks, either. \n"
                "The driving force behind a Gemini zodiac sign's conversation is their mind. Ruling the third house, \n"
                "the Gemini-born are intellectually inclined, forever probing people and places in search of information.\n"
             << std::endl;

        std::cout << "John F. Kennedy, Kendrick Lamar, and Morgan Freeman." << std::endl;
    }

    else if (sign == "Cancer")
    {

        std::cout << "You are a Cancer!\n"
             << std::endl;

        std::cout << "Cancer, the fourth sign of the zodiac, is all about home. \n"
                "Those born under this horoscope sign are 'roots' kinds of people, \n"
                "and take great pleasure in the comforts of home and family. \n"
                "Cancers are maternal, domestic, and love to nurture others. \n"
                "More than likely, their family will be large, too—the more, the merrier!\n"
                "Cancers will certainly be merry if their home life is serene and harmonious.\n"
             << std::endl;

        std::cout << "Selena Gomez, Lionel Messi, and Elon Musk." << std::endl;
    }

    else if (sign == "Leo")
    {

        std::cout << "You are a Leo!\n";

        std::cout << "Leo is the fifth sign of the zodiac. \n"
                "These folks are impossible to miss since they love being center stage. \n"
                "Making an impression is Job #1 for Leos, and when you consider their personal magnetism, \n"
                "you see the job is quite easy. Leos are an ambitious lot, \n"
                "and their strength of purpose allows them to accomplish a great deal. \n"
                "The fact that this horoscope sign is also creative makes their endeavors fun for them and everyone else.\n"
             << std::endl;

        std::cout << "Barack Obama, Kylie Jenner, and Chris Hemsworth." << std::endl;
    }

    else if (sign == "Virgo")
    {

        std::cout << "You are a Virgo!\n"
             << std::endl;

        std::cout << "Virgo is the sixth sign of the zodiac, to be exact, \n"
                "and that's the way Virgos like it: exacting. \n"
                "Those born under this horoscope sign are forever the butt of jokes for being so picky and critical \n"
                "(and they can be), but their 'attention to detail' is for a reason: to help others. \n"
                "Virgos, more than any other zodiac sign, were born to serve, and it gives them great joy.\n"
             << std::endl;

        std::cout << "Michael Jackson, Adam Sandler, Kobe Bryant." << std::endl;
    }

    else if (sign == "Libra")
    {

        std::cout << "You are a Libra!\n"
             << std::endl;

        std::cout << "Libra is the seventh sign of the zodiac. For a Libra, \n"
                "everything is better if it's done as a pair. \n"
                "Libras are good when paired up, too, since they epitomize balance, harmony, and a sense of fair play. \n"
                "While they are true team players at work, their favorite partnership is at home: marriage. \n"
                "Libras feel most complete when they are coupled up with their lover, forever.\n"
             << std::endl;

        std::cout << "Vladimir Putin, Snoop Dogg, and Mahatma Gandhi." << std::endl;
    }

    else if (sign == "Scorpio")
    {

        std::cout << "You are a Scorpio!\n"
             << std::endl;

        std::cout << "Scorpio is the eighth sign of the zodiac, \n"
                "and that shouldn't be taken lightly—nor should Scorpios! \n"
                "Those born under this sign are dead serious in their mission to learn about others. \n"
                "There's no fluff or chatter for Scorpios, either; \n"
                "these folks will zero-in on the essential questions, gleaning the secrets that lie within.\n"
             << std::endl;

        std::cout << "Leonardo Di'Caprio, Hillary Clinton, and Bill Gates." << std::endl;
    }

    else if (sign == "Sagittarius")
    {

        std::cout << "You are a Sagittarius!\n"
             << std::endl;

        std::cout << "Sagittarius, the ninth sign of the zodiac, \n"
                "is the home of the wanderers of the zodiac. \n"
                "It's not a mindless ramble for these folks, either. Sags are truth-seekers, \n"
                "and the best way for them to do this is to hit the road, talk to others and get some answers.\n"
             << std::endl;

        std::cout << "Taylor Swift, Kai Cenat, and Kylian Mbappe." << std::endl;
    }

    else if (sign == "Capricon")
    {

        std::cout << "You are a Capricon!\n"
             << std::endl;

        std::cout << "Capricorn, the tenth sign and mountain goat of the zodiac, is all about hard work. \n"
                "Those born under this sign are more than happy to put in a full day at the office, \n"
                "realizing that it will likely take a lot of those days to get to the top. That's no problem, \n"
                "since Capricorns are both ambitious and determined: they will get there. \n"
                "Life is one big project for these folks, \n"
                "and they adapt to this by adopting a businesslike approach to most everything they do.\n"
             << std::endl;

        std::cout << "Dezel Washington, Lebron James, and Steve Harvey." << std::endl;
    }

    else if (sign == "Aquarius")
    {

        std::cout << "You are an Aquarius!\n"
             << std::endl;

        std::cout << " Aquarius is the eleventh sign of the zodiac, \n"
                "and Aquarians are the perfect representatives for the Age of Aquarius. \n"
                "Those born under this horoscope sign have the social conscience needed to carry us into the new millennium. \n"
                "Those of the Aquarius zodiac sign are humanitarian, \n"
                "philanthropic, and keenly interested in making the world a better place.\n"
             << std::endl;

        std::cout << "Jennifer Anisten, Dr. Dre, and Chris Rock." << std::endl;
    }

    else if (sign == "Pisces")
    {

        std::cout << "You are a Pisces\n"
             << std::endl;

        std::cout << "Pisces is the twelfth sign of the zodiac, \n"
                "and it is also the final sign in the zodiacal cycle. \n"
                "Hence, this sign brings together many of the characteristics of the eleven signs that have come before it. \n"
                "Pisces, however, are happiest keeping many of these qualities under wraps. \n"
                "These folks are selfless, spiritual, and very focused on their inner journey.\n"
             << std::endl;

        std::cout << "Millie Bobby Brown, Stephen Curry, and George Washington." << std::endl;
    }
}
