// compsci2250 project 1.cpp
// Nicholas Hieb
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
//funciton prototypes
void initialize_array(int[], int);
int *shuffle_array(int*, int);
int print_array(int[]);
int *createOddArray(const int[], int, int &);
int *createEvenArray(const int[], int, int&);
void array_war(int*, int, int*, int);
void sort_array(int*, int);

int main()
{
	//pointers for arrays
	int *firstArray = nullptr;
	int *secondArray = nullptr;
	int *oddArray = nullptr;
	int* evenArray = nullptr;
	int size,oddSize,evenSize;

	cout << "Please enter size of array between 1 and 52. \n";//get size of array
	cin >> size;
	while(size > 52 || size < 1) 
	{
		cout << "Please enter a valid size \n";
		cin >> size;
	}
	firstArray = new int[size];
	initialize_array(firstArray, size); //Run first array 
	secondArray = shuffle_array(firstArray, size); //shuffle first array

	cout << "Original Array is: ";
	print_array(firstArray); //print first array
	cout << "Shuffled Array is: ";
	print_array(secondArray); //print second array

	oddArray = createOddArray(secondArray, size, size);
	cout << "Odd Array is: ";
	oddSize = print_array(oddArray); //print odd array
	evenArray = createEvenArray(secondArray, size, size);
	cout << "Even Array is: ";
	evenSize = print_array(evenArray); //print even array
	array_war(oddArray, oddSize, evenArray, evenSize); //arrayWar
	firstArray,secondArray, oddArray, evenArray = nullptr; //clearing memory
}

//setup array
void initialize_array(int firstArray[], int size) 
{
	for (int index = 0; index <= size - 1; index++) 
	{
		firstArray[index] = index + 1;
	}
}

//shuffle array function
int *shuffle_array(int *secondArray, int size)
{
	int* newArray = nullptr;
	newArray = new int[size];

	int temp = 0;
	int randomIndex = 0;
	unsigned seed = time(0); //setting random number to true random
	srand(seed);

	for (int i = 0; i < size; i++)
	{
		newArray[i] = secondArray[i];
	}
	for(int i = 0; i < size; i++)
	{
		randomIndex = rand() % size;
		temp = newArray[i];
		newArray[i] = newArray[randomIndex];
		newArray[randomIndex] = temp;
	}
	return newArray;

}

//print array function
int print_array(int Array[])
{
	int size = 0;
	for (int index = 0; index < size+1; index++)
	{
		if (Array[index] > 0)
		{
			size++;
			cout << Array[index] << " ";
		}
		
	}
	cout << endl;
	return size;
}
//Odd array function
int* createOddArray(const int secondArray[], int size, int &)
{
	int count = 0;
	//creat new array
	int* newArray = nullptr;
	newArray = new int[size];
	
	for (int index = 0; index < size; index++)
	{	
		if (secondArray[index] % 2 == 1)
		{
				newArray[count++] = secondArray[index];
		}
	}
	return newArray; //return array
}
//Even array function
int* createEvenArray(const int secondArray[], int size, int&)
{
	//creat new array
	int* newArray = nullptr;
	newArray = new int[size];
	int count = 0;
	for (int index = 0; index < size; index++)
	{
		if (secondArray[index] % 2 == 0)
		{
			newArray[count++] = secondArray[index];
		}
	}
	return newArray; //return array
}

void array_war(int*oddArray, int, int*evenArray, int) 
{
	int arraySize = 0;
	for(int index = 0;index<arraySize+1;index++) //what array is bigger
	{
		if (oddArray[index] > 0) 
		{
			arraySize++;
		}
		else if (evenArray[index] > 0) 
		{
			arraySize++;
		}
	}
	
	int* newArray = nullptr;
	newArray = new int[arraySize]; // new array

	for(int index = 0;index < arraySize;index++) //THE FIGHT!
	{
		if(oddArray[index] > evenArray[index])
		{
			newArray[index] = oddArray[index];
		}
		else
		{
			newArray[index] = evenArray[index];
		}
	}
	cout << "ArrayFight Winners were: ";
	print_array(newArray);
	sort_array(newArray, arraySize);
	cout << "Sorted ArrayFight winners were: ";
	print_array(newArray);


}

// selection sort array from textbook
void sort_array(int* array, int size)
{
	int minIndex, minValue;

	for(int start = 0; start < (size -1);start++)
	{
		minIndex = start;
		minValue = array[start];
		for(int index = start +1;index < size;index++)
		{
			if(array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		swap(array[minIndex], array[start]);
	}
}