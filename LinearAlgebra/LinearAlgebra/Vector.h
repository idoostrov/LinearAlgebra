#include <vector>
#include <iostream>

#define type int
using namespace std;

class Array_Vector
{
private:
	int length;
	vector<type> elements;
	type scalar;
	type norm_squared;
public:
	Array_Vector(const int length);
	Array_Vector(const vector<type>& elements);
	Array_Vector(const Array_Vector& other);

	int len() const;
	type operator[] (int index) const;
	void set(int index, type value);
	Array_Vector operator+ (const Array_Vector& other);
	Array_Vector operator- (const Array_Vector& other);
	type operator* (const Array_Vector& other);
	Array_Vector operator*(const type scalar);
	int norm();
};
ostream& operator<<(ostream& os, const Array_Vector& p);