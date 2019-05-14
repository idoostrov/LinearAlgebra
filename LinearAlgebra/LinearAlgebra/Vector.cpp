#include "Vector.h"

Array_Vector::Array_Vector(const int length)
{
	this->norm_squared = -1;//Unintialized
	this->length = length;
	this->scalar = 1;
	this->elements = vector<type>(length, 0);
}
Array_Vector::Array_Vector(const vector<type>& elements)
{
	this->norm_squared = -1;//Unintialized
	this->scalar = 1;
	this->length = elements.size();
	this->elements = vector<type>(elements);
}
Array_Vector::Array_Vector(const Array_Vector& other)
{
	this->norm_squared = other.norm_squared;
	this->scalar = other.scalar;
	this->length = other.length;
	this->elements = vector<type>(other.elements);
}

int Array_Vector::len() const
{
	return this->length;
}
type Array_Vector::operator[](int index) const
{
	return this->elements[index];
}
type& Array_Vector::operator[](int index)
{
	return this->elements[index];
}
void Array_Vector::set(int index, type value)
{
	this->norm_squared = -1;
	if (this->scalar != 1 && value != 0)
	{
		for (int i = 0; i < length; i++)
		{
			this->elements[i] *= this->scalar;
		}
		this->scalar = 1;
	}
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
		vec.elements[i] = this->elements[i] * this->scalar + other.elements[i] * other.scalar;
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
type Array_Vector:: operator*(const Array_Vector& other)
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
Array_Vector Array_Vector:: operator*(const type scalar)
{
	Array_Vector vec(this->elements);
	vec.scalar = this->scalar*scalar;
	return vec;
}
type Array_Vector::norm()
{
	if (this->norm_squared >= 0)
	{
		return this->norm_squared * this->scalar*this->scalar;
	}
	this->norm_squared = 0;
	for (int i = 0; i < length; i++)
	{
		this->norm_squared += this->elements[i] * this->elements[i];
	}
	return this->norm_squared * this->scalar*this->scalar;
}
ostream& operator<<(ostream& os, const Array_Vector& p)
{
	os << "[";
	int length = p.len();
	if (length != 0)
	{
		os << p[0];
	}
	for(int i=1; i < length; i++)
	{
		os << ", ";
		os << p[i];
	}
	os << "]\n";
	return os;
}


