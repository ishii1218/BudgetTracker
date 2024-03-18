#pragma once
#include <iostream>
#include "DisplayFunction.h"
#include "Node.h"

using namespace std;
extern double daily_exp;
extern double monthly_exp;

class Month {
public:
	int elem;
	Month* next;
	//Node* top;

	Node* head;
	Node* tail;
	int size;
	int d = 0, vTransport = 0, vFood = 0, vBills = 0, vClothing = 0, vShopping = 0,
		vEducation = 0, vHealth = 0, vSocial = 0, vBeauty = 0, vOther = 0, DOM = 0, vtot_daily_expense = 0;

	Month() {
		head = NULL;
		tail = NULL;
		size = 0;
		elem = -1;
		next = NULL;
	}
	Month(int e) {
		elem = e;
		next = NULL;
	}
	int getdaysofmonth(int dom)
	{
		DOM = dom;
		return DOM;
	}

	void CreateNodes(int DaysOfmonth) {
		for (int i = 0; i < DaysOfmonth; i++) {
			d = i + 1;
			Node* temp = new Node(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther, vtot_daily_expense);
			if (head == NULL) {
				head = temp;
				tail = temp;
				size++;
			}
			else {
				tail->next = temp;
				temp->prev = tail;
				tail = temp;
				tail->next = NULL;
				size++;
			}
		}

	}
	void InsertFirst(int d, int vFood, int vTransport, int vBills, int vClothing, int vShopping, int vEducation, int vHealth, int vSocial, int vBeauty, int vOther, int vtot_daily_expense) {
		Node* temp = new Node(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther, vtot_daily_expense);
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			temp->next = head->next;
			(head->next)->prev = temp;
			head = temp;
		}

	}
	void InsertLast(int d, int vFood, int vTransport, int vBills, int vClothing, int vShopping, int vEducation, int vHealth, int vSocial, int vBeauty, int vOther, int vtot_daily_expense) {
		Node* temp = new Node(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther, vtot_daily_expense);
		if (head == NULL) {
			head = temp;
			tail = temp;
		}
		else {
			temp->next = tail->next;
			//temp->prev = tail->prev;
			(tail->prev)->next = temp;
			temp->prev = tail->prev;
			tail = temp;
			//tail->next = NULL;

		}
	}
	void InsertAt(int d, int vFood, int vTransport, int vBills, int vClothing, int vShopping, int vEducation, int vHealth, int vSocial, int vBeauty, int vOther, int vtot_daily_expense) {

		if (d < 1 || d > size) {
			cout << "Invalid Date!" << endl;
		}
		if (d == 1) {
			InsertFirst(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther, vtot_daily_expense);
		}
		else if (d == DOM) {
			InsertLast(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther, vtot_daily_expense);
		}
		else {
			Node* temp = new Node(d, vFood, vTransport, vBills, vClothing, vShopping, vEducation, vHealth, vSocial, vBeauty, vOther, vtot_daily_expense);
			Node* current = head;
			for (int i = 0; i < d - 2; i++) {
				current = current->next;
			}
			temp->next = (current->next)->next;
			temp->prev = current;
			current->next = temp;
			(temp->next)->prev = temp;
		}
	}
	void AddDatatoPreviousNode(int selOption, int select, int dy)
	{
		Node* current = head;
		for (int i = 0; i < dy - 1; i++) {
			current = current->next;
		}
		char option;
		int fd, trans, bill, cloth, shop, ed, heal, socio, beau, oth;
		if (select == 1)
		{

			if (current->Food != 0)
			{
				cout << "Previous amount for food: ";
				cout << current->Food << endl;
				if (selOption == 2)
				{
					cout << "Add amount for food: ";
					cin >> fd;
					current->Food = current->Food + fd;
				}
				if (selOption == 3)
				{
					cout << "Replace amount for food: ";
					cin >> fd;
					current->Food = fd;
				}
			}
			else if (current->Food == 0)
			{
				cout << "Enter the expense on food: ";
				cin >> fd;
				current->Food = fd;
			}
		}
		if (select == 2)
		{
			if (current->Transport != 0)
			{
				cout << "Previous amount for transport: ";
				cout << current->Transport << endl;
				if (selOption == 2)
				{
					cout << "Add amount for transport: ";
					cin >> trans;
					current->Transport = current->Transport + trans;
				}
				if (selOption == 3)
				{
					cout << "Replace amount for transport: ";
					cin >> trans;
					current->Transport = trans;
				}
			}
			else if (current->Transport == 0)
			{
				cout << "Enter the expense on transport: ";
				cin >> trans;
				current->Transport = trans;
			}
		}
		if (select == 3)
		{
			if (current->Bills != 0)
			{
				cout << "Previous amount for bills: ";
				cout << current->Bills << endl;
				if (selOption == 2)
				{
					cout << "Add amount for bills: ";
					cin >> bill;
					current->Bills = current->Bills + bill;
				}
				if (selOption == 3)
				{
					cout << "Replace amount for bills: ";
					cin >> bill;
					current->Bills = bill;
				}
			}
			else if (current->Bills == 0)
			{
				cout << "Enter the expense on bills: ";
				cin >> bill;
				current->Bills = bill;
			}
		}
		if (select == 4)
		{
			if (current->Clothing != 0)
			{
				cout << "Previous amount for clothing: ";
				cout << current->Clothing << endl;
				if (selOption == 2)
				{
					cout << "Add amount for clothing: ";
					cin >> cloth;
					current->Clothing = current->Clothing + cloth;
				}
				if (selOption == 3)
				{
					cout << "Replace amount for clothing: ";
					cin >> cloth;
					current->Clothing = cloth;
				}
			}
			else if (current->Clothing == 0)
			{
				cout << "Enter the expense on clothing: ";
				cin >> cloth;
				current->Clothing = cloth;
			}
		}
		if (select == 5)
		{

			if (current->Shopping != 0)
			{
				cout << "Previous amount for shopping: ";
				cout << current->Shopping << endl;
				if (selOption == 2)
				{
					cout << "Add amount for shopping: ";
					cin >> shop;
					current->Shopping = current->Shopping + shop;
				}
				if (selOption == 3)
				{
					cout << "Replace amount for shopping: ";
					cin >> shop;
					current->Shopping = shop;
				}
			}
			else if (current->Shopping == 0)
			{
				cout << "Enter the expense on shopping: ";
				cin >> shop;
				current->Shopping = shop;
			}
		}
		if (select == 6)
		{
			if (current->Education != 0)
			{
				cout << "Previous amount for education: ";
				cout << current->Education << endl;
				if (selOption == 2)
				{
					cout << "Add amount for education: ";
					cin >> ed;
					current->Education = current->Education + ed;
				}
				if (selOption == 3)
				{
					cout << "Replace amount for education: ";
					cin >> ed;
					current->Education = ed;
				}
			}
			else if (current->Education == 0)
			{
				cout << "Enter the expense on education: ";
				cin >> ed;
				current->Education = ed;
			}
		}
		if (select == 7)
		{
			if (current->Health != 0)
			{
				cout << "Previous amount for health: ";
				cout << current->Health << endl;
				if (selOption == 2)
				{
					cout << "Add amount for health: ";
					cin >> heal;
					current->Health = current->Health + heal;
				}
				if (selOption == 3)
				{
					cout << "Replace amount for health: ";
					cin >> heal;
					current->Health = heal;
				}
			}
			else if (current->Health == 0)
			{
				cout << "Enter the expense on health: ";
				cin >> heal;
				current->Health = heal;
			}
		}
		if (select == 8)
		{
			if (current->Social != 0)
			{
				cout << "Previous amount for social: ";
				cout << current->Social << endl;
				if (selOption == 2)
				{
					cout << "Add amount for social: ";
					cin >> socio;
					current->Social = current->Social + socio;
				}
				if (selOption == 3)
				{
					cout << "Replace amount for social: ";
					cin >> socio;
					current->Social = socio;
				}
			}
			else if (current->Social == 0)
			{
				cout << "Enter the expense on social: ";
				cin >> socio;
				current->Social = socio;
			}
		}
		if (select == 9)
		{
			if (current->Beauty != 0)
			{
				cout << "Previous amount for beauty: ";
				cout << current->Beauty << endl;
				if (selOption == 2)
				{
					cout << "Add amount for beauty: ";
					cin >> beau;
					current->Beauty = current->Beauty + beau;
				}
				if (selOption == 3)
				{
					cout << "Replace amount for beauty: ";
					cin >> beau;
					current->Beauty = beau;
				}
			}
			else if (current->Beauty == 0)
			{
				cout << "Enter the expense on beauty: ";
				cin >> beau;
				current->Beauty = beau;
			}
		}
		if (select == 10)
		{
			if (current->Other != 0)
			{
				cout << "Previous amount for other: ";
				cout << current->Other << endl;
				if (selOption == 2)
				{
					cout << "Add amount for other: ";
					cin >> oth;
					current->Other = current->Other + oth;
				}
				if (selOption == 3)
				{
					cout << "Replace amount for other: ";
					cin >> oth;
					current->Other = oth;
				}
			}
			else if (current->Other == 0)
			{
				cout << "Enter the expense on other: ";
				cin >> oth;
				current->Other = oth;
			}
		}

	}
	int insertToCurrentDay()
	{
		Node* current = head;
		int maxDay = 0;

		for (int i = 0; i < size; i++)
		{
			if (current->date == size && (current->Food != 0 || current->Transport != 0 || current->Bills != 0 || current->Clothing != 0 || current->Shopping != 0 || current->Education != 0 || current->Health != 0 || current->Social != 0 || current->Beauty != 0 || current->Other != 0))
			{
				maxDay = current->date;
			}


			else if (current->Food != 0 || current->Transport != 0 || current->Bills != 0 || current->Clothing != 0 || current->Shopping != 0 || current->Education != 0 || current->Health != 0 || current->Social != 0 || current->Beauty != 0 || current->Other != 0)
			{
				if (current->date < ((current->next)->date))
				{
					maxDay = current->date;
				}
			}
			current = current->next;
		}

		return maxDay;
	}

	double compareVal;
	string compareStr;
	void PrintDataofoneDate(int Dy) {
		Node* current = head;
		for (int i = 0; i < Dy - 1; i++)
		{
			current = current->next;
		}
		cout << "===========================================" << endl;
		cout << "|----------EXPENSES FOR THE DAY " << current->date << "--------|" << endl;
		cout << "===========================================" << endl;
		cout << "| 1\t|Food     |" << current->Food << endl;
		cout << "| 2\t|Transport|" << current->Transport << endl;
		cout << "| 3\t|Bills    |" << current->Bills << endl;
		cout << "| 4\t|Clothing |" << current->Clothing << endl;
		cout << "| 5\t|Shopping |" << current->Shopping << endl;
		cout << "| 6\t|Education|" << current->Education << endl;
		cout << "| 7\t|Health   |" << current->Health << endl;
		cout << "| 8\t|Social   |" << current->Social << endl;
		cout << "| 9\t|Beauty   |" << current->Beauty << endl;
		cout << "| 10\t|Other    |" << current->Other << endl;
		current->tot_daily_expense = current->Food + current->Transport + current->Bills + current->Clothing + current->Shopping +
			current->Education + current->Health + current->Social + current->Beauty + current->Other;
		cout << "-----------------------------------------" << endl;
		cout << "|Total expense of the day : " << current->tot_daily_expense << endl;



		if (daily_exp > current->tot_daily_expense) {
			cout << "-----------------------------------------" << endl;
			cout << "|You have saved today                   |" << endl;

			compareVal = daily_exp - current->tot_daily_expense;
			compareStr = "Gain";
		}
		else if (daily_exp < current->tot_daily_expense) {
			cout << "-----------------------------------------" << endl;
			cout << "|You have spend too much today        |" << endl;

			compareVal = current->tot_daily_expense - daily_exp;
			compareStr = "Loss";
		}
		else {
			cout << "-----------------------------------------" << endl;
			cout << "|Perfect! You have well managed your finances today|" << endl;

			compareVal = daily_exp - current->tot_daily_expense;
			compareStr = "Perfect";
		}
		cout << "-----------------------------------------" << endl;
		cout << "|How much you can spend today: " << daily_exp << endl;///edited all "|" part deleted
		cout << "-----------------------------------------" << endl;
		cout << "|How much you spent so far   : " << current->tot_daily_expense << endl;
		cout << "-----------------------------------------" << endl;
		cout << "|Status of the day           : " << compareStr << endl;
		cout << "-----------------------------------------" << endl;
		if (daily_exp > current->tot_daily_expense || daily_exp == current->tot_daily_expense) {
			cout << "|Balance of the day          : " << compareVal << endl;
			cout << "-----------------------------------------" << endl;
		}
		else if (daily_exp < current->tot_daily_expense) {
			cout << "|Excess amount spent          : " << compareVal << endl;
			cout << "-----------------------------------------" << endl;
		}
	}


	void PrintAllData() {
		double sumTotal = 0;
		int currentDay = insertToCurrentDay();
		Node* current = head;
		for (int i = 0; i < currentDay; i++)
		{
			cout << "===========================================" << endl;
			cout << "|----------EXPENSES FOR THE DAY " << current->date << "--------|" << endl;
			cout << "===========================================" << endl;
			cout << "| 1\t|\tFood     |" << current->Food << endl;
			cout << "| 2\t|\tTransport|" << current->Transport << endl;
			cout << "| 3\t|\tBills    |" << current->Bills << endl;
			cout << "| 4\t|\tClothing |" << current->Clothing << endl;
			cout << "| 5\t|\tShopping |" << current->Shopping << endl;
			cout << "| 6\t|\tEducation|" << current->Education << endl;
			cout << "| 7\t|\tHealth   |" << current->Health << endl;
			cout << "| 8\t|\tSocial   |" << current->Social << endl;
			cout << "| 9\t|\tBeauty   |" << current->Beauty << endl;
			cout << "| 10\t|\tOther    |" << current->Other << endl; //added a space to |
			current->tot_daily_expense = current->Food + current->Transport + current->Bills + current->Clothing + current->Shopping +
				current->Education + current->Health + current->Social + current->Beauty + current->Other;
			cout << "-----------------------------------------" << endl;
			cout << "|\tTotal expense of the day : " << current->tot_daily_expense << "\t|" << endl;

			cout << " " << endl;
			cout << " " << endl;

			sumTotal = sumTotal + current->tot_daily_expense;
			current = current->next;

		}
		cout << "=====================================================" << endl;
		cout << "|------------------MONTHLY REPORT-------------------|" << endl;
		cout << "=====================================================" << endl;
		if (monthly_exp > sumTotal) {
			cout << " " << endl;

			cout << "-----------------------------------------------------" << endl;
			cout << "|You have saved so far                              |" << endl;

			compareVal = monthly_exp - sumTotal;
			compareStr = "Gain";
		}
		else if (monthly_exp < sumTotal) {
			cout << "---------------------------------------------------" << endl;
			cout << "|You have spend too much so far                   |" << endl;

			compareVal = monthly_exp - sumTotal;
			compareStr = "Loss";
		}
		else {
			cout << "---------------------------------------------------" << endl;
			cout << "|Perfect! You have well managed your finances so far|" << endl;

			compareVal = monthly_exp - sumTotal;
			compareStr = "Perfect";
		}
		cout << "-----------------------------------------------------" << endl;
		cout << "|How much you can spend for a month     : " << monthly_exp << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "|How much you spent so far		: " << sumTotal << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "|Statues so far				: " << compareStr << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << "|Balance so far				: " << compareVal << endl;
		cout << "-----------------------------------------------------" << endl;
		cout << " " << endl;
	}
};