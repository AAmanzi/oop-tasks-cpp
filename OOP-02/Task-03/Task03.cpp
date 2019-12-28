#include<iostream>
#include<iomanip>

using namespace std;

struct Vector
{
	int* Elements;
	int Size;
	int Capacity;

	void NewVector(int capacity)
	{
		Elements = new int[capacity];
		Size = 0;
		Capacity = capacity;
	}

	void NewVector(int* arrayToCopyStart, int* arrayToCopyEnd)
	{
		Elements = arrayToCopyStart;
		Size = arrayToCopyEnd - arrayToCopyStart + 1;
		Capacity = Size;
	}

	void DeleteVector()
	{
		delete [] Elements;
		Elements = nullptr;
		Size = NULL;
		Capacity = NULL;
	}

	
	void VectorPushBack(int value)
	{
		if(Size == Capacity)
		{
			Vector tmp;
			tmp.NewVector(Capacity * 2);
			for (auto i = 0; i < Size; ++i)
			{
				tmp.Elements[i] = Elements[i];
				tmp.Size++;
			}
			tmp.Elements[Size] = value;
			tmp.Size++;
			Elements = tmp.Elements;
			Size = tmp.Size;
			Capacity = tmp.Capacity;

			tmp.DeleteVector();
		}
		else
		{
			Elements[Size] = value;
			Size++;
		}
	}
	
	void VectorPopBack()
	{
		
		Elements[--Size] = NULL;
	}

	int& VectorFront()
	{
		return Elements[0];
	}

	int& VectorBack()
	{
		return Elements[Size-1];
	}
};



int main()
{
	int arraySize;

	cin >> arraySize;

	int* newArray = new int[arraySize];

	for (auto i = 0; i < arraySize; ++i)
	{
		cin >> newArray[i];
	}

	Vector newVector;
	newVector.NewVector(newArray, &newArray[arraySize-1]);

	newVector.VectorPushBack(20);
	newVector.VectorPopBack();

	newVector.VectorFront()++;
	newVector.VectorBack()++;

}
