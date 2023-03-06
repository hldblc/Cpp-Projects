#include <iostream>
#include <cstdlib>

using namespace std;

int *getArray(int num);


int main()
{
	int elem;
	int* array;


	cout << "Enter the number of elements in the array:\n" << endl;
	cin >> elem;

	array = getArray(elem);

	for(int i = 0; i < elem; ++i)
	{
		cout << array[i] << endl;
	}

	delete[] array;

	return 0;
}

int *getArray(int num)
{
	int* array = NULL;
	int count, *ptr = array;

	array = new int[num];

	cout << "Enter the intergers to be placed in the array below.\n";

	for (count = 0; count < num; count++)
	{
		cout << " Interger number  " << (count + 1) << " : ";
		cin >> array[count];

	}
	ptr = array;

	return ptr;
}
