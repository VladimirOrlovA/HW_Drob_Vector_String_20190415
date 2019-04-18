#include "string_.h"

// конструктор по умолчанию
string_::string_()
{
	str = nullptr;
	length = 0;
}

// конструктор с параметром
string_::string_(const char *s)
{
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length + 1, s);
}

// сеттер для строки
void string_::setString(const char *s)
{
	if (str != nullptr) delete[] str;	// если строка не пустая удаляем строку (массив)
	length = strlen(s);					// получаем длину переданной строки
	str = new char[length + 1];			// выделяем под указатель строки получатель длину строки источника
	strcpy_s(str, length + 1, s);		// устанавливаем в строку назначения длину переданной строки +1 символ для /0 и саму строку источник
}

// геттер для строки
const char *string_::getString()
{
	return str;
}

// геттер для длины строки
int string_::getLength()
{
	return length;
}

// метод append
void string_::append(const char *s)
{
	if (str == nullptr) {
		setString(s);
		return;
	}
	length += strlen(s);				// прибавляем к текущей длине строки длину строки источника
	char* tmp = new char[length + 1];	// объявляем указатель для временной строки
	strcpy_s(tmp, length + 1, str);		// копирование строки str во временную строку tmp
	strcat_s(tmp, length + 1, s);		// во временную строку передаем строку источник s
	delete[]str;
	str = tmp;
}

// вывод строки в консоль
void string_::print()
{
	cout << str << endl;
}

// метод clear
void string_::clear()
{
	this->~string_();
}

// метод сравнения строк 
bool string_::equal(const char * s)
{
	if (strcmp(str, s) == 0)  // strcmp - функция сравнивает символы двух строк, string1 и string2.
		return true;
	return false;
}

// метод puch_back - вставка символа в конец строки
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

// конструктор копирования из объекта в объект
string_::string_(const string_ & obj)
{
	this->length = obj.length;
	// проверка на попытку копирования пустой строки
	if (this->length == 0) 
	{
		this->str = nullptr;
		return;
	}
	//значит есть откуда копировать
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str); // strcpy_s - сам добавляет в конец сторки \0
}

// деструктор
string_::~string_()
{
	delete[] this->str;
	this->length = 0;
	this->str = nullptr;
}

// гл. ф. - перегрузка оператора вывода << для типа данных string_
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

// гл. ф. перегрузка оператора ввода >> для типа данных string_
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

// гл. ф. перегрузка оператора сравнения для типа данных string_
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

// гл. ф. перегрузка оператора сравнения на не равенство для типа данных string_
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

