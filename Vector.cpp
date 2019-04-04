#include <vector>

template <class T>
class line_vector
{
private:
    int length;
public:
    virtual double norm();
    virtual T operator* (line_vector<T> other);
    virtual T operator[] (int index);
};

template <class T>
class array_vector : line_vector
{
private:
    int length;
    Vector<T> arr;
public:
    array_vector(int length) : length(length)
    {
        this.length = length;
        arr = new Vector<T>(length, 0);
    }

    T operator[] (int index)
    {
        return arr[index];
    }

    T operator*(line_vector<T> other)
    {
        if(this.legnth != other.length)
            return 0; //illegal input
        T sum = 0;
        for(int i=0; i<length; i++)
            sum += this.arr[i] * other[i];
        return sum;
    }
    int main()
    {
        array_vector<int> vec = new array_vector<int>(5);
        return 0;
    }
};
