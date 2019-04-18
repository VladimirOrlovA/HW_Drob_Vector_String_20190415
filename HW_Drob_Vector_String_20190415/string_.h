#pragma once
#include<iostream>
using namespace std;

class string_
{
	char *str;
	int length;
public:
	string_();
	string_(const char*s);
	void setString(const char*s);
	const char* getString();
	int getLength();
	void append(const char*s);
	void print();
	void clear();
	bool equal(const char*s);
	void push_back(char z);
	string_(const string_&obj);
	~string_();
	
	
	// объ€вление дружественных функции
	friend ostream& operator<<(ostream &os, const string_ &c);
	friend istream& operator>>(istream &is, string_ &c);
	friend bool operator==(string_ & L, string_ & R);
	friend bool operator!=(string_ & L, string_ & R);
};

// объ€вление глобальных функций операций над строками
ostream& operator<<(ostream &os, const string_ &c);
istream& operator>>(istream &is, string_ &c);
bool operator==(string_ & L, string_ & R);
bool operator!=(string_ & L, string_ & R);