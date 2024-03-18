#pragma once
#include <iostream>
#include "BillReminder.h"
#include "DoublyLinkedList.h"
//#include "Month.h"
#include<fstream>
#include<string>

using namespace std;

int select_2, select_3, yr, Date, transport, food, Bills, Clothing, Shopping,
Education, Health, Social, Beauty, Other, tot_daily_expense;
char choice;

Month dll1;
BillManager bm;

int dysofm(int, int);
class Singly_Linked_List {
public:
    Month* head;
    Month* tail;

    int size;

    Singly_Linked_List() {
        head = NULL;
        tail = NULL;
        size = 0;

    }

    void firstMonth() {
        string mon;
        Month* temp = new Month(select_3);
        temp->CreateNodes(dysofm(yr, select_3));
        head = temp;
        size++;
    }

    void continueMonth() {
        Month* temp = new Month(select_3);
        temp->CreateNodes(dysofm(yr, select_3));

        Month* current = head;
        for (int i = 0; i < size - 1; i++) {
            current = current->next;
        }
        current->next = temp;
        size++;
    }
    Month* finalMonth() {
        Month* current = head;
        for (int i = 0; i < size - 1; i++) {
            current = current->next;
        }
        return current;
    }


};
Singly_Linked_List Year;

void billingReminder();
void createNewAccount();
void Login();
void LogInData();
void InsertData();
int ExpenseData();
void addDataToPrevDay(int seleOp, int dayy);
void Editdata();
void InsertDataTocategory();
void savingData();


int select_4, daysOfMonth = 0;
double daily_exp; //Extern variable that is used in DoublyLinkedList

void LogInData() {
    int select_1;
    cout << "|=======================================|" << endl;
    cout << "|==============BUDGET TRACKER===========|" << endl;
    cout << "|=======================================|" << endl;
    cout << "| 1\t|\tLOG IN \t\t\t|" << endl;
    cout << "| 2\t|\tCREATE A NEW ACCOUNT\t|" << endl;
    cout << "|=======================================|" << endl;
    cout << "Insert 1 or 2: ";
    cin >> select_1;
    system("cls");
    switch (select_1)
    {
    case 1:
        Login();
        break;

    case 2:
        createNewAccount();
        break;

    default:
        system("cls");
        cout << "Enter a valid option" << endl;
        LogInData();
    }
}
void Login() {
    int count = 0;
    string username, password, uName, uPass;
    cout << "|=======================================|" << endl;
    cout << "|=================LOG IN================|" << endl;
    cout << "|=======================================|" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    system("cls");

    ifstream read("records.txt"); //ifstream is used to read the data from the file

    while (read >> uName >> uPass) //read is the object name
    {
        if (uName == username && uPass == password)
        {
            count = 1;
        }
    }
    read.close();
    if (count == 1)
    {
        cout << "Login Successfull!" << endl;
        InsertData();
    }
    else
    {
        cout << "Login Failed!" << endl;
        cout << "Please check again your username or password" << endl;

        LogInData();
    }
}
void createNewAccount() {
    string uGoodName, uGender, uOccupation, uUsername, uPassword;
    int uAge;
    cout << "===========================================" << endl;
    cout << "|----------CREATE A NEW ACCOUNT-----------|" << endl;
    cout << "===========================================" << endl;
    cout << "|----------PERSONAL INFORMATION-----------|" << endl;
    cout << "===========================================" << endl;
    cout << " " << endl;
    cout << "Enter your Good name: ";
    cin >> uGoodName;
    cout << "Enter your age: ";
    cin >> uAge;
    cout << "Enter your gender (Male/Female): ";
    cin >> uGender;
    cout << "Enter your occupation: ";
    cin >> uOccupation;
    system("cls");

    cout << "===========================================" << endl;
    cout << "|--------------ACCOUNT SETUP--------------|" << endl;
    cout << "===========================================" << endl;
    cout << " " << endl;
    cout << "Enter a Username: ";
    cin >> uUsername;
    cout << "Create a Password: ";
    cin >> uPassword;

    ofstream input("records.txt", ios::app);
    input << uGoodName << " " << uAge << " " << uGender << " " << uOccupation << " " << uUsername << " " << uPassword << endl;
    system("cls");

    cout << "===========================================" << endl;
    cout << "|-----------------SET DATE----------------|" << endl;
    cout << "===========================================" << endl;
    cout << " " << endl;
    cout << "Enter the year: ";
    cin >> yr;
    cout << " " << endl;
    cout << "---------------------------------" << endl;
    cout << "| 1\t|\tJanuary\t\t|" << endl;
    cout << "| 2\t|\tFebruary\t|" << endl;
    cout << "| 3\t|\tMarch\t\t|" << endl;
    cout << "| 4\t|\tApril\t\t|" << endl;
    cout << "| 5\t|\tMay\t\t|" << endl;
    cout << "| 6\t|\tJune\t\t|" << endl;
    cout << "| 7\t|\tJuly\t\t|" << endl;
    cout << "| 8\t|\tAugust\t\t|" << endl;
    cout << "| 9\t|\tSeptember\t|" << endl;
    cout << "| 10\t|\tOctober\t\t|" << endl;
    cout << "| 11\t|\tNovember\t|" << endl;
    cout << "| 12\t|\tDecember\t|" << endl;
    cout << "---------------------------------" << endl;
    cout << "|Insert the current month(1-12) |" << endl;
    cout << "---------------------------------" << endl;
    cin >> select_3;

    Year.firstMonth();
    dll1 = *Year.finalMonth();

    daysOfMonth = dysofm(yr, select_3);
    dll1.CreateNodes(daysOfMonth); //Creating a LinkedList with size of daysOfMonth
    dll1.getdaysofmonth(daysOfMonth); //Passing days of month into DoublyLinkedList
    cout << "Registration Successfull!" << endl;
    system("cls");
    LogInData();
}

int dysofm(int yr, int select_3) {
    if (select_3 == 1 || select_3 == 3 || select_3 == 5 || select_3 == 7 || select_3 == 8 || select_3 == 10 || select_3 == 12)
        daysOfMonth = 31;
    else if (select_3 == 4 || select_3 == 6 || select_3 == 9 || select_3 == 11)
        daysOfMonth = 30;
    else if (select_3 == 2) {
        if ((yr % 4 == 0 && yr % 100 != 0) || (yr % 400 == 0))
            daysOfMonth = 29;
        else
            daysOfMonth = 28;
    }
    return daysOfMonth;
}

double monthly_exp;
void savingData() {
    double mon_Salary; //Monthly salary of the user
    double save_Money; //Amount of money does user want to save
    double d_Income; //mon_Salary + ot_Income
    double ot_Income; //Other incomes instead of the salary    
    string goal_description; //Description of the goal set by the user
    char goal_response; //yes or no

    cout << " " << endl;
    cout << "What is your goal? (How much money do you want to save for the month): ";
    cin >> save_Money;
    cout << "Add a description about your goal: ";
    cin >> goal_description;
    cout << "Enter your current monthly salary: ";
    cin >> mon_Salary;
    cout << "General income of the month except the monthly salary:";
    cin >> ot_Income;
    d_Income = mon_Salary + ot_Income;
    monthly_exp = d_Income - save_Money;
    daily_exp = monthly_exp / daysOfMonth;
    cout << " " << endl;
    cout << "Amount of money you can spend for a day to achieve your goal: " << daily_exp << endl;
    cout << "Do you want to set the goal(yes - y / no - n): ";
    cin >> goal_response;

    if (goal_response == 'y' || goal_response == 'Y') {
        system("cls");
    }
    else if (goal_response == 'n' || goal_response == 'N') {
        system("cls");
    }InsertData();
}

int ExpenseData() {
    cout << "===========================================" << endl;
    cout << "|---------------EXPENSE DATA--------------|" << endl;
    cout << "===========================================" << endl;
    cout << "| 1\t|\tFood                      |" << endl;
    cout << "| 2\t|\tTransport                 |" << endl;
    cout << "| 3\t|\tBills                     |" << endl;
    cout << "| 4\t|\tClothing                  |" << endl;
    cout << "| 5\t|\tShopping                  |" << endl;
    cout << "| 6\t|\tEducation                 |" << endl;
    cout << "| 7\t|\tHealth                    |" << endl;
    cout << "| 8\t|\tSocial                    |" << endl;
    cout << "| 9\t|\tBeauty                    |" << endl;
    cout << "| 10\t|\tOther                     |" << endl;
    cout << "| 11\t|\tExit                      |" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "|Insert an option between(1-11)           |" << endl;
    cout << "-------------------------------------------" << endl;
    cin >> select_4;

    return select_4;
    system("cls");
}


void InsertData() {
    transport = 0; food = 0;Bills = 0;Clothing = 0;Shopping = 0;Education = 0;
    Health = 0;Social = 0;Beauty = 0;Other = 0;tot_daily_expense = 0;

    cout << "=========================================" << endl;
    cout << "|----------------MAIN MENU--------------|" << endl;
    cout << "=========================================" << endl;
    cout << "| 1\t|\tSet a Goal  \t\t|" << endl;
    cout << "| 2\t|\tInsert Data  \t\t|" << endl;
    cout << "| 3\t|\tPrint Data  \t\t|" << endl;
    cout << "| 4\t|\tEdit Data  \t\t|" << endl;
    cout << "| 5\t|\tAdd a Bill Reminder\t|" << endl;
    cout << "| 6\t|\tExit       \t\t|" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "|Insert an option between(1-6)\t\t|" << endl;
    cout << "-----------------------------------------" << endl;
    cin >> select_2;
    system("cls");

    switch (select_2) {
    case 1:
        cout << "===========================================" << endl;
        cout << "|-----------------SET A GOAL--------------|" << endl;
        cout << "===========================================" << endl;
        savingData();
        break;

    case 2:
        int select;
        do
        {
            cout << "===========================================" << endl;
            cout << "|-----------------INSERT DATA-------------|" << endl;
            cout << "===========================================" << endl;
            cout << "| 1\t| Add data to a new date          |" << endl;
            cout << "| 2\t| Continue adding data for today  |" << endl;
            cout << "| 3\t| Create a new month              |" << endl;
            cout << "| 4\t| Exit                            |" << endl;
            cout << "-------------------------------------------" << endl;
            cout << "|Insert an option (1,2,3 or 4)            |" << endl;
            cout << "-------------------------------------------" << endl;
            cin >> select;
            system("cls");

            if (select == 2)
            {
                int maxiday = dll1.insertToCurrentDay();
                addDataToPrevDay(select, maxiday);

            }
            else if (select == 1 || select == 3)
            {
                cout << "Enter the Date: ";
                cin >> Date;
                if (Date<1 || Date> daysOfMonth)
                {
                    cout << "Invalid Date, Enter a valid date" << endl;

                }
                else if (select == 3) {
                    select_3 = (select_3 + 1) % 13;
                    if (select_3 == 0) select_3 = 1;
                    cout << "Month : " << select_3 << endl;
                    Year.continueMonth();
                    dll1 = *Year.finalMonth();
                }
            }
            else if (select == 4) {
                break;
            }

        } while (Date<1 || Date>daysOfMonth);
        if (select == 4) {
            break;
        }
        InsertDataTocategory();

        dll1.InsertAt(Date, food, transport, Bills, Clothing, Shopping, Education, Health, Social, Beauty, Other, tot_daily_expense);
        break;
    case 3:
        int selectPrint;
        cout << "==============================================" << endl;
        cout << "|------------------PRINT DATA----------------|" << endl;
        cout << "==============================================" << endl;
        cout << "| 1\t|Print data of all the previous days |" << endl;
        cout << "| 2\t|Print data of a particular day      |" << endl;
        cout << "| 3\t|Exit                                |" << endl;
        cout << "----------------------------------------------" << endl;
        cout << "|Insert an option (1,2 or 3)                 |" << endl;
        cout << "----------------------------------------------" << endl;
        cin >> selectPrint;
        system("cls");

        if (selectPrint == 1)
        {
            dll1.PrintAllData();
        }
        else if (selectPrint == 2)
        {
            int day;
            cout << "Enter the day that you want to print: ";
            cin >> day;
            dll1.PrintDataofoneDate(day);
        }
        else if (selectPrint == 3) {

        }
        break;
    case 4:
        cout << "==========================================================" << endl;
        cout << "|------------------------EDIT DATA-----------------------|" << endl;
        cout << "==========================================================" << endl;
        Editdata();
        break;
    case 5:
        cout << "==============================================" << endl;
        cout << "|----------------ADD A REMINDER--------------|" << endl;
        cout << "==============================================" << endl;
        cout << "|Now you can add a reminder on your pay bills|" << endl;
        cout << "==============================================" << endl;
        billingReminder();
        break;
    case 6:
        break;
    }

    cout << "Do you want to return to the menu?{yes - y / no - n}" << endl;
    cin >> choice;
    if (choice == 'y') {
        system("cls");
        InsertData();
    }
    else if (choice == 'n') {
        system("cls");
        cout << "Have a nice day!!!" << endl;
        
    }
    else {
        cout << "Enter a valid input y for YES or n for NO" << endl;

    }
}

void InsertDataTocategory()
{
    ExpenseData();
    while (select_4 != 11) {
        switch (select_4) {
        case 1:
            cout << "Enter the expense on food:";
            cin >> food;
            system("cls");
            ExpenseData();
            break;
        case 2:
            cout << "Enter the expense on transport:";
            cin >> transport;
            system("cls");
            ExpenseData();
            break;
        case 3:
            cout << "Enter the expense on bills:";
            cin >> Bills;
            system("cls");
            ExpenseData();
            break;
        case 4:
            cout << "Enter the expense on clothing:";
            cin >> Clothing;
            system("cls");
            ExpenseData();
            break;
        case 5:
            cout << "Enter the expense on shopping:";
            cin >> Shopping;
            system("cls");
            ExpenseData();
            break;
        case 6:
            cout << "Enter the expense on education:";
            cin >> Education;
            system("cls");
            ExpenseData();
            break;
        case 7:
            cout << "Enter the expense on health:";
            cin >> Health;
            system("cls");
            ExpenseData();
            break;
        case 8:
            cout << "Enter the expense on social:";
            cin >> Social;
            system("cls");
            ExpenseData();
            break;
        case 9:
            cout << "Enter the expense on beauty:";
            cin >> Beauty;
            system("cls");
            ExpenseData();
            break;
        case 10:
            cout << "Enter the expense on other:";
            cin >> Other;
            system("cls");
            ExpenseData();
            break;
        case 11:
            break;
            system("cls");
        default:
            cout << "Enter a valid number!!" << endl;
            system("cls");
            ExpenseData();
        }
    }


}

void Editdata()
{
    int editDataDate, option;
    cout << "| 1\t|Delete data of a previous day and enter new data|" << endl;
    cout << "| 2\t|Add data to a category that you entered before  |" << endl;
    cout << "| 3\t|Replace data of a category entered before       |" << endl;
    cout << "| 4\t|Exit                                            |" << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "|Insert an option (1,2,3 or 4)                           |" << endl;
    cout << "----------------------------------------------------------" << endl;
    cin >> option;
    system("cls");
    if (option == 2 || option == 3)
    {
        int date;
        cout << "Enter the Date: ";
        cin >> date;
        addDataToPrevDay(option, date);
    }
    else if (option == 1)
    {
        cout << "Enter the day you want to add new data: ";
        cin >> editDataDate;
        InsertDataTocategory();
        dll1.InsertAt(editDataDate, food, transport, Bills, Clothing, Shopping, Education, Health, Social, Beauty, Other, tot_daily_expense);
    }
    else  if (option == 4) {

    }
}

void addDataToPrevDay(int seleOp, int dayy)
{
    ExpenseData();
    while (select_4 != 11) {
        switch (select_4) {
        case 1:
            dll1.AddDatatoPreviousNode(seleOp, select_4, dayy);
            system("cls");
            ExpenseData();
            break;
        case 2:
            dll1.AddDatatoPreviousNode(seleOp, select_4, dayy);
            system("cls");
            ExpenseData();
            break;
        case 3:
            dll1.AddDatatoPreviousNode(seleOp, select_4, dayy);
            system("cls");
            ExpenseData();
            break;
        case 4:
            dll1.AddDatatoPreviousNode(seleOp, select_4, dayy);
            system("cls");
            ExpenseData();
            break;
        case 5:
            dll1.AddDatatoPreviousNode(seleOp, select_4, dayy);
            system("cls");
            ExpenseData();
            break;
        case 6:
            dll1.AddDatatoPreviousNode(seleOp, select_4, dayy);
            system("cls");
            ExpenseData();
            break;
        case 7:
            dll1.AddDatatoPreviousNode(seleOp, select_4, dayy);
            system("cls");
            ExpenseData();
            break;
        case 8:
            dll1.AddDatatoPreviousNode(seleOp, select_4, dayy);
            system("cls");
            ExpenseData();
            break;
        case 9:
            dll1.AddDatatoPreviousNode(seleOp, select_4, dayy);
            system("cls");
            ExpenseData();
            break;
        case 10:
            dll1.AddDatatoPreviousNode(seleOp, select_4, dayy);
            system("cls");
            ExpenseData();
            break;
        case 11:
            break;
        default:
            cout << "Enter a valid number!!" << endl;
            ExpenseData();
        }

    }
    cout << "Do you want to return to the menu?{yes - y / no - n}" << endl;
    cin >> choice;
    if (choice == 'y') {
        system("cls");
        InsertData();
    }
    else if (choice == 'n') {
        system("cls");
        cout << "Have a nice day!!!" << endl;
        terminate();
    }
    else {
        cout << "Enter a valid input y for YES or n for NO" << endl;
    }
}

void billingReminder() {
    bm.billReminder();
}


