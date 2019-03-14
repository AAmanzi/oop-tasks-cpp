#include<iostream>
#include<iomanip>

using namespace std;

struct Vector
{
	int* Elements;
	int Size;
	int Capacity;
};

Vector NewVector(int capacity)
{
	Vector newVector;
	newVector.Elements = new int[capacity];
	newVector.Size = 0;
	newVector.Capacity = capacity;

	return newVector;
}

Vector NewVector(int* arrayToCopyStart, int* arrayToCopyEnd)
{
	Vector newVector;
	newVector.Elements = arrayToCopyStart;
	newVector.Size = arrayToCopyEnd - arrayToCopyStart + 1;
	newVector.Capacity = newVector.Size;

	return newVector;
}

void DeleteVector(Vector *toDelete)
{
	delete [] toDelete->Elements;
	toDelete->Elements = nullptr;
	toDelete->Size = NULL;
	toDelete->Capacity = NULL;
}

void VectorPushBack(Vector *toUpdate, int value)
{
	if(toUpdate->Size == toUpdate->Capacity)
	{
		toUpdate->Capacity *= 2;
	}

	toUpdate->Elements[toUpdate->Size++] = value;
}

void VectorPopBack(Vector *toUpdate)
{
	toUpdate->Elements[toUpdate->Size--] = NULL;
}

int& VectorFront(Vector toGetFront)
{
	return toGetFront.Elements[0];
}

int& VectorBack(Vector toGetBack)
{
	return toGetBack.Elements[toGetBack.Size-1];
}

int main()
{
	int arraySize;

	cin >> arraySize;

	int* newArray = new int[arraySize];

	for (int i = 0; i < arraySize; ++i)
	{
		cin >> newArray[i];
	}

	Vector newVector = NewVector(newArray, &newArray[arraySize-1]);

	VectorPushBack(&newVector, 20);
	VectorPopBack(&newVector);

	VectorFront(newVector)++;
	VectorBack(newVector)++;

	system("pause");
}
