#include "string_.h"

// ����������� �� ���������
string_::string_()
{
	str = nullptr;
	length = 0;
}

// ����������� � ����������
string_::string_(const char *s)
{
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length + 1, s);
}

// ������ ��� ������
void string_::setString(const char *s)
{
	if (str != nullptr) delete[] str;	// ���� ������ �� ������ ������� ������ (������)
	length = strlen(s);					// �������� ����� ���������� ������
	str = new char[length + 1];			// �������� ��� ��������� ������ ���������� ����� ������ ���������
	strcpy_s(str, length + 1, s);		// ������������� � ������ ���������� ����� ���������� ������ +1 ������ ��� /0 � ���� ������ ��������
}

// ������ ��� ������
const char *string_::getString()
{
	return str;
}

// ������ ��� ����� ������
int string_::getLength()
{
	return length;
}

// ����� append
void string_::append(const char *s)
{
	if (str == nullptr) {
		setString(s);
		return;
	}
	length += strlen(s);				// ���������� � ������� ����� ������ ����� ������ ���������
	char* tmp = new char[length + 1];	// ��������� ��������� ��� ��������� ������
	strcpy_s(tmp, length + 1, str);		// ����������� ������ str �� ��������� ������ tmp
	strcat_s(tmp, length + 1, s);		// �� ��������� ������ �������� ������ �������� s
	delete[]str;
	str = tmp;
}

// ����� ������ � �������
void string_::print()
{
	cout << str << endl;
}

// ����� clear
void string_::clear()
{
	this->~string_();
}

// ����� ��������� ����� 
bool string_::equal(const char * s)
{
	if (strcmp(str, s) == 0)  // strcmp - ������� ���������� ������� ���� �����, string1 � string2.
		return true;
	return false;
}

// ����� puch_back - ������� ������� � ����� ������
void string_::push_back(char z)
{
	length += 1;
	char *tmp = new char[length + 1];
	strcpy_s(tmp, length + 1, str);
	tmp[length - 1] = z;
	tmp[length] = '\0';
	delete[] str;
	str = tmp;
}

// ����������� ����������� �� ������� � ������
string_::string_(const string_ & obj)
{
	this->length = obj.length;
	// �������� �� ������� ����������� ������ ������
	if (this->length == 0) 
	{
		this->str = nullptr;
		return;
	}
	//������ ���� ������ ����������
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str); // strcpy_s - ��� ��������� � ����� ������ \0
}

// ����������
string_::~string_()
{
	delete[] this->str;
	this->length = 0;
	this->str = nullptr;
}

// ��. �. - ���������� ��������� ������ << ��� ���� ������ string_
ostream & operator<<(ostream & os, const string_ & c)
{
	if (c.str == nullptr)
	{
		cout << " is empty \n";
		return os;
	}
		os << c.str;
		return os;
}

// ��. �. ���������� ��������� ����� >> ��� ���� ������ string_
istream & operator>>(istream & is, string_ & c)
{
	cout << "\nEnter string: ";
	char s[1024];
	cin >> s;
	c.clear();
	c.str = new char[strlen(s) + 1];
	c.length = strlen(s);
	strcpy_s(c.str, c.length + 1, s);
	return is;
}

// ��. �. ���������� ��������� ��������� ��� ���� ������ string_
bool operator==(string_ & L, string_ & R)
{
	if (L.length != R.length)
		return false;
	
	for (size_t i = 0; i < L.length; i++)
		{
		if (L.str[i] != R.str[i])
			return false;
		}
	
	return true;

}

// ��. �. ���������� ��������� ��������� �� �� ��������� ��� ���� ������ string_
bool operator!=(string_ & L, string_ & R)
{
	if (L.length != R.length)
		return true;

	for (size_t i = 0; i < L.length; i++)
	{
		if (L.str[i] != R.str[i])
			return true;
	}

	return false;
}

