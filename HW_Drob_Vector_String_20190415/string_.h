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
	~string_();


	string_(const string_&obj);
};