#include"drob_.h"
#include"string_.h"
#include"vector_.h"

void main()
{
	drob_ dr(3, 4);
	dr.print();

	string_ str("Hello World");
	str.print();

	vector_ vec(5, 5);
	vec.print();

	cout << dr;
	cin >> dr;
	cout << dr;


	system("pause");
}