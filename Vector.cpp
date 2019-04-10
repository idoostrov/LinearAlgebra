#include <vector>
#include <iostream>
using namespace std;

class Array_Vector
{
private:
	int length;
	vector<int> elements;
	int scalar;
	int norm_squared;
public:
	Array_Vector(const int length);
	Array_Vector(const vector<int>& elements);
	Array_Vector(const Array_Vector& other);

	int len() const;
	int operator[] (int index) const;
	void set(int index, int value);
	Array_Vector operator+ (const Array_Vector& other);
	Array_Vector operator- (const Array_Vector& other);
	int operator* (const Array_Vector& other);
	Array_Vector operator*(const int scalar);
	int norm();
};

Array_Vector::Array_Vector(const int length)
{
	this->norm_squared = -1;//Unintialized
	this->length = length;
	this->scalar = 1;
	this->elements = vector<int>(length, 0);
}
Array_Vector::Array_Vector(const vector<int>& elements)
{
	this->norm_squared = -1;//Unintialized
	this->scalar = 1;
	this->length = elements.size();
	this->elements = vector<int>(elements);
}
Array_Vector::Array_Vector(const Array_Vector& other)
{
	this->norm_squared = other.norm_squared;
	this->scalar = other.scalar;
	this->length = other.length;
	this->elements = vector<int>(other.elements);
}

int Array_Vector::len() const
{
	return this->length;
}
int Array_Vector::operator[](const int index) const
{
	return this->elements[index];
}

void Array_Vector::set(int index, int value)
{
	norm_squared = -1;
	if (scalar != 1 && value != 0)
	{
		for (int i = 0; i < length; i++)
		{
			this->elements[i] *= scalar;
		}
	}
	scalar = 1;
	this->elements[index] = value;
}
Array_Vector Array_Vector:: operator+(const Array_Vector& other)
{
	if (this->length != other.length)
	{
		throw new exception;
	}
	Array_Vector vec(this->length);
	for (int i = 0; i < this->length; i++)
	{
		vec.elements[i] = this->elements[i]*this->scalar + other.elements[i]*other.scalar;
	}
	return vec;
}
Array_Vector Array_Vector:: operator-(const Array_Vector& other)
{
	if (this->length != other.length)
	{
		throw new exception;
	}
	Array_Vector vec(this->length);
	for (int i = 0; i < this->length; i++)
	{
		vec.elements[i] = this->elements[i] * this->scalar - other.elements[i] * other.scalar;
	}
	return vec;
}
int Array_Vector:: operator*(const Array_Vector& other)
{
	if (this->length != other.length)
	{
		throw new exception;
	}
	int sum = 0;
	for (int i = 0; i < this->length; i++)
	{
		sum += this->elements[i] * other.elements[i];
	}
	return sum * this->scalar*other.scalar;
}
Array_Vector Array_Vector:: operator*(const int scalar)
{
	Array_Vector vec(this->elements);
	vec.scalar = this->scalar*scalar;
	return vec;
}
int Array_Vector::norm()
{
	if (norm_squared >= 0)
	{
		return norm_squared * scalar*scalar;
	}
	norm_squared = 0;
	for (int i = 0; i < length; i++)
	{
		norm_squared += elements[i] * elements[i];
	}
	return norm_squared * scalar*scalar;
}


int main()
{
	return 0;
}