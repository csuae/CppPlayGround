#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>

void EchoNumLetter(); //1
void ReptDonation(); //2
void Menu(); //3
void BOPDisplay(); //4
void DisplayImpl(int, int); //4 util
void TaxClac(); //5
void PatronRepr(); //6
void WordCategoryCnt(); //7
void ReptNumCh(); //8
void PatronReprV2(); //9

const int Strsize = 30;
struct bop {
    char fullname[Strsize]; // real name
    char title[Strsize];    // job title
    char bponame[Strsize];  // secret bop name
    int preference; // 0 = fullname, 1 = title, 2 = bopname
};
    
bop memberList[5] = {
    {"Wimp Macho", "Boss", "Wiki", 0},
    {"Raki Rhodes", "Junior Programmer", "Rookie", 1},
    {"Celia Laiter", "Accountant", "MIPS", 2},
    {"Hoppy Hipman", "Analyst Trainee", "UHHHA", 1},
    {"Pat Hand", "Assistant Programmer", "LOOPY", 2}
};


int main(int argc, const char* argv[])
{
    //EchoNumLetter();
    //ReptDonation();
    //Menu();
    //BOPDisplay();
    //TaxClac();
    //PatronRepr();
    //WordCategoryCnt();
    //ReptNumCh();
    PatronReprV2();
}


void EchoNumLetter(void)
{
    using namespace std;
    char tmpChar;
    cin >> tmpChar;
    while (tmpChar != '@')
    {
        if (!isdigit(tmpChar))
        {
            if (isupper(tmpChar))
                tmpChar = tolower(tmpChar);
            else if (islower(tmpChar))
                tmpChar = toupper(tmpChar);
            cout << tmpChar;
        }
        cin >> tmpChar;
    }
}

void ReptDonation(void)
{
    using namespace std;
    const int MaxSize = 10;
    double donationVal[MaxSize];
    double avg = 0, sum = 0;

    int i = 0;
    cout << "Input a donation number: ";
    while (i<MaxSize && cin>>donationVal[i])
    {
        sum += donationVal[i];
        ++i;
        cout << "Input next donation number: ";
    }
    avg = sum / i;
    int cnt = 0;
    for (int j=0; j<i; j++)
        if (donationVal[j] > avg)
            ++cnt;

    cout << "Average of the input " << i << " numbers is: " << avg << endl;
    cout << "There is(are) " << cnt << " number(s) greater than the average.\n";
}

void Menu(void)
{
    using namespace std;
    char optionCh;
    string ansStr;
    bool menuPass = false;
    cout << "Please enter one of the following choices:\n";
    cout << "c) carnivore\tp) pianist\n";
    cout << "t) tree\t\tg) game\n";

    while (cin >> optionCh)
    {
        switch (optionCh)
        {
            case 'c':
                ansStr = "carnivore.";
                menuPass = true;
                break;
            case 'p':
                ansStr = "pianist.";
                menuPass = true;
                break;
            case 't':
                ansStr = "tree.";
                menuPass = true;
                break;
            case 'g':
                ansStr = "game.";
                menuPass = true;
                break;
        }
        if (menuPass) {
            cout << "A maple is a " << ansStr << endl;
            break;
        } else
            cout << "Please enter a c, p, t, or g: ";
    }
}

void DisplayImpl(int index, int option)
{
    using namespace std;
    switch (option)
    {
        // fullname
        case 0:
            cout << memberList[index].fullname << endl;
            break;
        // title
        case 1:
            cout << memberList[index].title << endl;
            break;
        // bopname
        case 2:
            cout << memberList[index].bponame << endl;
            break;
    }
}

void BOPDisplay(void)
{
    using namespace std;

    cout << "Benevolent Order of Programmers Report\n"
    "a. display by name\tb. display by title\n"
    "c. display by bopname\td. display by preference\n"
    "q. quit\n";

    int tmpOption = 0;
    char choiceCh;
    cout << "Enter your choice: ";
    cin >> choiceCh;
    while (choiceCh != 'q')
    {
        switch (choiceCh)
        {
            case 'a':
                for (int i=0; i<5; i++)
                    DisplayImpl(i, 0);
                break;
            case 'b':
                for (int i=0; i<5; i++)
                    DisplayImpl(i, 1);
                break;
            case 'c':
                for (int i=0; i<5; i++)
                    DisplayImpl(i, 2);
                break;
            case 'd':
                for (int i=0; i<5; i++)
                {
                    tmpOption = memberList[i].preference;
                    DisplayImpl(i, tmpOption);
                }
                break;
            default:
                cout << "Illegal option. Try again.\n";
        }
        cout << "Next choice: ";
        cin >> choiceCh;
    }
    cout << "Bye!\n";
}

void TaxClac(void)
{
    using namespace std;
    double incomeVal;
    double taxVal;
    cout << "Input your earnings: ";
    while (cin >> incomeVal)
    {
        if (incomeVal < 0)
            break;
        if (incomeVal < 5000)
            taxVal = 0;
        else if (incomeVal >= 5000 && incomeVal < 15000)
            taxVal = (incomeVal-5000)*0.1;
        else if (incomeVal >= 15000 && incomeVal <= 35000)
            taxVal = 10000*0.1 + (incomeVal-15000)*0.15;
        else if (incomeVal > 35000)
            taxVal = 10000*0.1 + 20000*0.15 + (incomeVal-35000)*0.2;
        cout << "Your owed tax is " << taxVal << " tvarps.\n";
        cout << "Input your earnings: ";
    }
}

void PatronRepr(void)
{
    using namespace std;
    struct ptrn {
        string name;
        double contribVal;
    };
    int numContributors;
    cout << "Input the number of contributors: ";
    cin >> numContributors;
    ptrn* patronArr = new ptrn[numContributors];
    int* gpIdx = new int[numContributors]; //Grand Patron index list
    int* pIdx = new int[numContributors];  //Patron index list
    int numGP = 0, numP = 0;

    double tmpVal;
    cin.get();
    for (int i=0; i<numContributors; i++)
    {
        cout << "Input the name of the " << i+1 << "th Patron:\n";
        getline(cin, patronArr[i].name);
        cout << "Input the donation amount:\n";
        cin >> tmpVal;
        cin.get();
        if (tmpVal > 0)
        {
            patronArr[i].contribVal = tmpVal;
            if (tmpVal >= 10000)
                gpIdx[numGP++] = i;
            else if (0<tmpVal && tmpVal<10000)
                pIdx[numP++] = i;
        }
    }
    // print Grand Patrons and Patrons
    cout << "Grand Patrons\n";
    if (numGP == 0)
        cout << "none.\n";
    for (int i=0; i<numGP; i++)
        cout << patronArr[gpIdx[i]].name << "\t" << "$" << patronArr[gpIdx[i]].contribVal << endl;
    cout << "Patrons\n";
    if (numP == 0)
        cout << "none.\n";
    for (int i=0; i<numP; i++)
        cout << patronArr[pIdx[i]].name << "\t" << "$" << patronArr[pIdx[i]].contribVal << endl;
}

void WordCategoryCnt(void)
{
    using namespace std;
    int vowelCnt = 0, cstCnt = 0, otherCnt = 0;
    
    cout << "Enter words (q to quit):\n";
    char tmpWord[20];
    cin >> tmpWord;
    while (strcmp(tmpWord, "q"))
    {
        if (isalpha(tmpWord[0])) {
            switch (tmpWord[0])
            {
                case 'A':
				case 'a':
				case 'E':
				case 'e':
				case 'I':
				case 'i':
				case 'O':
				case 'o':
				case 'U':
				case 'u':
                    ++vowelCnt;
                    break;
                default:
                    ++cstCnt;
            }
        } else {
            ++otherCnt;
        }
        cin >> tmpWord;
    }
    cout << vowelCnt << " words beginning with vowels\n";
    cout << cstCnt << " words beginning with consonants\n";
    cout << otherCnt << " others\n";
}

void ReptNumCh(void)
{
    using namespace std;
    ifstream inFile;
    char tmpCh;
    int numCh = 0;

    inFile.open("demo.txt");
    while (inFile.good())
    {
        inFile >> tmpCh;
        ++numCh;
    }
    inFile.close();
    cout << "There are " << numCh << " characters in the file.\n";
}

void PatronReprV2(void)
{
    using namespace std;
    ifstream inFile;
    inFile.open("donator.txt");
    struct ptrn {
        string name;
        double contribVal;
    };
    int numContributors;
    inFile >> numContributors;
    ptrn* patronArr = new ptrn[numContributors];
    int* gpIdx = new int[numContributors]; //Grand Patron index list
    int* pIdx = new int[numContributors];  //Patron index list
    int numGP = 0, numP = 0;
    double tmpVal;

	inFile.get(); //handle newline
    for (int i=0; i<numContributors; i++)
    {
        getline(inFile, patronArr[i].name);
        inFile >> tmpVal;
        inFile.get();
        if (tmpVal > 0)
        {
            patronArr[i].contribVal = tmpVal;
            if (tmpVal >= 10000)
                gpIdx[numGP++] = i;
            else if (0<tmpVal && tmpVal<10000)
                pIdx[numP++] = i;
        }
    }
    inFile.close();

    // print Grand Patrons and Patrons
    cout << "Grand Patrons\n";
    if (numGP == 0)
        cout << "none.\n";
    for (int i=0; i<numGP; i++)
        cout << patronArr[gpIdx[i]].name << "\t" << "$" << patronArr[gpIdx[i]].contribVal << endl;
    cout << "Patrons\n";
    if (numP == 0)
        cout << "none.\n";
    for (int i=0; i<numP; i++)
        cout << patronArr[pIdx[i]].name << "\t" << "$" << patronArr[pIdx[i]].contribVal << endl;
}

