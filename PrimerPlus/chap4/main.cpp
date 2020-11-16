#include <iostream>
#include <cstring>
#include <string>

void AskGrade(); //1
void NameDessert(); //2
void CatenateName(); //3
void CatenateNameV2(); //4
void CandyBarInfo(); //5-6
void PizzaAnalysis(); //7-8
void CandyBarInfoV2(); //9


int main(int argc, const char* argv[])
{
    //AskGrade();
    //NameDessert();
    //CatenateNameV2();
    //CandyBarInfo();
    //PizzaAnalysis();
    CandyBarInfoV2();
}

void AskGrade(void)
{
    using namespace std;
    cout << "What is your first name? ";
    string valFstName;
    getline(cin, valFstName);

    cout << "What is your last name? ";
    string valLstName;
    cin >> valLstName;

    cout << "What letter grade do you deserve? ";
    char valGrade;
    cin >> valGrade;

    cout << "What is your age? ";
    int valAge;
    cin >> valAge;

    cout << "Name: " << valLstName << ", " << valFstName << endl;
    cout << "Grade: " << (char)(valGrade+1) << endl;
    cout << "Age: " << valAge << endl;
}

void NameDessert(void)
{
    using namespace std;
    string name, dessert;
    cout << "Enter your name:\n";
    getline(cin, name);
    cout << "Enter your favorite dessert:\n";
    getline(cin, dessert);

    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
}

void CatenateName(void)
{
    char fstname[20];
    char lstname[20];
    char fullname[40];
    using namespace std;

    cout << "Enter your first name: ";
    cin >> fstname;
    cout << "Enter your last name: ";
    cin >> lstname;
    strcpy(fullname, lstname);
    strcat(fullname, ", ");
    strcat(fullname, fstname);
    cout << "Here's the information in a single string: " << fullname << endl;
}

void CatenateNameV2(void)
{
	using namespace std;
	string fstname, lstname, fullname;
	
	cout << "Enter your first name: ";
    cin >> fstname;
    cout << "Enter your last name: ";
    cin >> lstname;
    fullname = lstname + ", " + fstname;
    cout << "Here's the information in a single string: " << fullname << endl;
}

void CandyBarInfo(void)
{
	using namespace std;
	struct CandyBar{
		string brandName;
		double weight;
		int calories;
	};
	
	CandyBar snack[3] = {
		{"Mocha Munch", 2.3, 350},
		{"Jack Jill", 4.6, 560},
		{"Mac Fies", 6.5, 850}
	};
	cout << "Here's the CandyBar Info: \n";
	for (int i=0; i<3; i++)
	{
		cout << "Brand:\t" << snack[i].brandName << endl;
		cout << "Weight:\t" << snack[i].weight << endl;
		cout << "Heat:\t" << snack[i].calories << endl;
	}	
}

void CandyBarInfoV2(void)
{
    using namespace std;
	struct CandyBar{
		string brandName;
		double weight;
		int calories;
	};

    CandyBar* snack = new CandyBar[3];
    snack[0].brandName = "Mocha Munch";
    snack[0].weight = 2.3;
    snack[0].calories = 350;

    snack[1].brandName = "Jack Jill";
    snack[1].weight = 3.3;
    snack[1].calories = 550;

    snack[2].brandName = "Mac Fies";
    snack[2].weight = 4.3;
    snack[2].calories = 890;

	cout << "Here's the CandyBar Info: \n";
	for (int i=0; i<3; i++)
	{
		cout << "Brand:\t" << snack[i].brandName << endl;
		cout << "Weight:\t" << snack[i].weight << endl;
		cout << "Heat:\t" << snack[i].calories << endl;
	}	
}

void PizzaAnalysis(void)
{
    using namespace std;
    struct PizzaInfo{
        string CompanyName;
        int diameter;
        double weight; 
    };
    PizzaInfo valPizza;
    // cout << "Input Company Name: ";
    // cin >> valPizza.CompanyName;
    // cout << "Input Diameter: ";
    // cin >> valPizza.diameter;
    // cout << "Input Weight: ";
    // cin >> valPizza.weight;

    // cout << "Here's the pizza info you entered:\n";
    // cout << "Company Name: " << valPizza.CompanyName << endl;
    // cout << "Diameter: " << valPizza.diameter << endl;
    // cout << "Weight: " << valPizza.weight << endl;

    PizzaInfo* pt = new PizzaInfo;
    cout << "Input Diameter: ";
    cin >> pt->diameter;
    cout << "Input Company Name: ";
    cin >> pt->CompanyName;
    cout << "Input Weight: ";
    cin >> pt->weight;

    cout << "Here's the pizza info you entered:\n";
    cout << "Company Name: " << pt->CompanyName << endl;
    cout << "Diameter: " << pt->diameter << endl;
    cout << "Weight: " << pt->weight << endl;
}

