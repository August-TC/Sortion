#ifndef DATALIST_H_INCLUDED
#define DATALIST_H_INCLUDED

#include <iostream>

template<class T>
class Element
{
private:
	T key;
	field otherdata;
	Element<T> & operator = (Element<T>& x)
	{
		key = x.key;
		otherdata = x.otherdata;
		return this
	}
	bool operator ==(Element<T>& x) { return key == x.key; }
	bool operator <=(Element<T>& x) { return key <= x.key; }
	bool operator >=(Element<T>& x) { return key >= x.key; }
	bool operator >(Element<T>& x) { return key > x.key; }
	bool operator <(Element<T>& x) { return key < x.key; }
};

template<class T>
class datalist
{
	friend class Element<T>;
private:
	Element<T>* Vector;
	int MaxSize;
	int CurrentSize;
public:
	datalist(int size = 100) :MaxSize(size), CurrentSize(0) { Vector = new Element<T>[MaxSize]; }
	int Length() { return CurrentSize; }
	Element<T>& operator[](int i) { return Vector[i]; }
	void Swap(Element<T>&x, Element&y)
	{
		Element<T> temp;
		temp = x;x = y;y = temp;
	}
	int Partition(int low, int high);
};

template<class T>
inline int datalist<T>::Partition(int low, int high)
{
	int pivot_position = low;
	Element<T> pivot = Vector[low];
	for (int i = low + 1;i < high;i++)
	{
		if (Vector[i] < pivot)
		{
			pivot_position++
			if (pivot_position != i)
			{
				Swap(Vector[pivot_position], Vector[i]);
			}
		}
	}
	Vector[low] = Vector[pivot_position];
	Vector[pivot_position] = pivot;
	return pivot_position;
}

#endif // DATALIST_H_INCLUDED

