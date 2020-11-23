//
//  main.cpp
//  function_demo
//
//  Created by Chunyou SU on 2020/11/23.
//  Copyright © 2020 Chunyou SU. All rights reserved.
//

#include <iostream>
#include <cstring>

const int SLEN = 30;
struct student {
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student * ps);
void display3(const student pa[], int n);

double add(double, double);
double sub(double, double);
double mul(double, double);
double div(double, double);
void InvokeOperation();

int main(int argc, const char * argv[]) {
    using namespace std;
    
    /*
    cout << "Enter class size:";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;
    
    student * ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete [] ptr_stu;
    cout << "Done\n";
    */
    InvokeOperation();
    
    return 0;
}

int getinfo(student pa[], int n)
{
    using namespace std;
    int i;
    for (i=0; i<n; i++)
    {
        cout << "Input the student's full name: ";
        cin.getline(pa[i].fullname, SLEN);
        if (!strcmp(pa[i].fullname, ""))
            break; //terminate in advance
        cout << "Input the student's hobby: ";
        cin.getline(pa[i].hobby, SLEN);
        cout << "Input the student's ooplevel: ";
        cin >> pa[i].ooplevel;
        cin.get(); //handle the newline character
    }
    return i;
}

void display1(student st)
{
    using namespace std;
    cout << "Full Name:\t" << st.fullname << endl;
    cout << "Hobby:\t" << st.hobby << endl;
    cout << "OOP Level:\t" << st.ooplevel << endl;
}

void display2(const student* ps)
{
    using namespace std;
    cout << "Full Name:\t" << ps->fullname << endl;
    cout << "Hobby:\t" << ps->hobby << endl;
    cout << "OOP Level:\t" << ps->ooplevel << endl;
}

void display3(const student pa[], int n)
{
    using namespace std;
    for (int i=0; i<n; i++)
    {
        cout << "--- " << i+1 << "th student ---" << endl;
        cout << "Full Name:\t" << pa[i].fullname << endl;
        cout << "Hobby:\t" << pa[i].hobby << endl;
        cout << "OOP Level:\t" << pa[i].ooplevel << endl;
    }
}

void InvokeOperation(void)
{
    using namespace std;
    double (*pf[4])(double, double) = {add, sub, mul, div};
    const char OpName[4][4] = {
        "Add",
        "Sub",
        "Mul",
        "Div"
    };
    double op1, op2;
    cout << "Input two operands for operation: \n";
    cin >> op1 >> op2;
    for (int i=0; i<4; i++)
    {
        cout << "Operation: " << OpName[i] << endl;
        cout << "\tans: " << pf[i](op1, op2) << endl;
    }
}

double add(double op1, double op2)
{
    return op1+op2;
}

double sub(double op1, double op2)
{
    return op1-op2;
}

double mul(double op1, double op2)
{
    return op1*op2;
}

double div(double op1, double op2)
{
    if (op2 == 0)
    {
        std::cout << "Illegal Operand 2";
        return 0;
    }
    return op1/op2;
}
