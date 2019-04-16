#include "vector_.h"


vector_::vector_()	// конструктор по умолчанию
{
	this->size = 0;			// размер 0
	this->arr = nullptr;	// указатель на массив 0
}

vector_::vector_(int size, int val)
{
	this->size = size;
	this->arr = new int[this->size];
	for (int i = 0; i < this->size; i++)
		this->arr[i] = val + i;
}

vector_::vector_(const vector_ & obj)		// конструктор копирования
{
	this->size = obj.size;
	if (this->size == 0)
		this->arr = nullptr;
	else
	{
		this->arr = new int[this->size];
		for (int i = 0; i < this->size; i++)
			this->arr[i] = obj.arr[i];
	}
}

void vector_::push_back(int num)	// добавление в конец массива  одного элемента
{
	if (this->size == 0)
	{
		this->arr = new int[1];
		this->arr[0] = num;
		this->size++;
		return;
	}
	int *tmp = new int[this->size + 1];

	for (size_t i = 0; i < this->size; i++)
	{
		tmp[i] = this->arr[i];
	}
	tmp[this->size] = num;
	delete[]this->arr;
	this->arr = tmp;
	this->size++;

}

void vector_::pop_back()  // удаление последнего элемента
{
	if (this->size == 0)
	{
		cout << "Array is empty!";
	}
	else
	{
		int *tmp = new int[this->size - 1];
		for (size_t i = 0; i < this->size - 1; i++)
		{
			tmp[i] = this->arr[i];
		}
		delete[]this->arr;
		this->arr = tmp;
		this->size--;
	}

}

void vector_::erase(int pos)	//удаление элемента под индексом pos
{
	if (this->size == 0)
	{
		cout << "Array is empty!";
	}
	else
	{
		int *tmp = new int[this->size];

		int j = 0;
		for (size_t i = 0; i < this->size; i++)
		{
			if (i == pos)
			{
				tmp[i] = this->arr[i + 1];
				i++;
			}
			tmp[j] = this->arr[i];
			j++;
		}
		delete[] this->arr;
		this->arr = tmp;
		this->size--;
	}
}

void vector_::clear()
{
	if (this->arr != nullptr)
	{
		delete[] this->arr;
		this->arr = nullptr;
		this->size = 0;
	}
}

int vector_::getSize()
{
	cout << "Array size is " << this->size << "\n\n";
	return this->size;
}

bool vector_::empty()
{
	if (this->arr == nullptr)
		return true;
	return false;
}

int vector_::getElement(int pos)		// метод получения заданного значения элемента в массиве
{
	if (pos > this->size)
	{
		cout << "Wrong input" << endl;
		return 0;
	}
	else
	{
		cout << "Getting the value of a given element position: pos " << pos << " = value " << this->arr[pos] << "\n\n";
		return this->arr[pos];
	}

}

void vector_::print()
{
	if (this->arr == nullptr)
		cout << "Array is empty!\n";
	else
	{

		for (size_t i = 0; i < this->size; i++)
		{
			cout << this->arr[i] << " ";

		}
	}
	cout << endl;
}



vector_::~vector_()
{
	if (this->arr != nullptr) {
		delete[]this->arr;
		this->size = 0;
	}
}
