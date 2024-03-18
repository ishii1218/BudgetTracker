#pragma once
#include <iostream>

using namespace std;
class Node {
public:
    Node* next;
    Node* prev;
    int date, Food, Transport, Bills, Clothing, Shopping, Education, Health, Social, Beauty, Other, tot_daily_expense;

    Node() {
        date = NULL;
        next = NULL;
        prev = NULL;
        Food = NULL;
        Transport = NULL;
        Bills = NULL;
        Clothing = NULL;
        Shopping = NULL;
        Education = NULL;
        Health = NULL;
        Social = NULL;
        Beauty = NULL;
        Other = NULL;
        tot_daily_expense = NULL;

    }
    Node(int d, int vFood, int vTransport, int vBills, int vClothing, int vShopping,
        int vEducation, int vHealth, int vSocial, int vBeauty, int vOther, int vtot_daily_expense) {
        date = d;
        next = NULL;
        prev = NULL;
        Food = vFood;
        Transport = vTransport;
        Bills = vBills;
        Clothing = vClothing;
        Shopping = vShopping;
        Education = vEducation;
        Health = vHealth;
        Social = vSocial;
        Beauty = vBeauty;
        Other = vOther;
        tot_daily_expense = vtot_daily_expense;
    }
};