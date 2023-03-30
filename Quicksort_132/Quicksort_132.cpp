#include <iostream>
using namespace std;


int arr[20];				//array of integers to hold velues
int cmp_count = 0;			//number of comparasion
int mov_count = 0;			//number of data movement
int n;

void input() {
	while (true)
	{
		cout << "Masukan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum panjang array adalah 20" << endl;
	}

	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
			cin >> arr[i];
	}
}

//swaps the element st index x with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high)		//Langkah Algoritma No. 1
		return;

	//Partition the list into twi parts:
	//one containing elements less that or equal to pivot
	//Outher conntaining elements greather than pivot

	pivot = arr[low];		//Langkah algoritma no 2
	i = low + 1;		//langkah algoritma no 3
	j = high;				//Langkah algoritma no 4



	while (i <= j)		//Langkah algo no 10
	{
		//search for an element greather than pivot
		while ((arr[i] <= pivot) && (i <= high))
		{
			i++;		//Langkah Algoritma no 6
			cmp_count++;
		}
		cmp_count++;

		//search for an element less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low))		//langkah algoritma no 7
		{
			j--;			//Langkah algoritma no 8
			cmp_count++;
		}
		cmp_count++;

		//iff the greather element is on the left of the element
		if (i < j)			//Langkah algoritma no 9
		{
			//swap the element at index 1 with the element at index j
			swap(i, j);
			mov_count++;
		}
	}
	//j now containt the index of the last element in the sorted list
	if (low < j)
	{
		//move the pivot to its correct position in the list
		swap(low, j);
		mov_count++;
	}
	//sort the list on the right of pivot using quick sort
	q_short(low, j - 1);

	//sort the list on the right of pivot using quick sort
	q_short(j + 1, high);
}

void display() {
	cout << "\n---------------------" << endl;
	cout << "Sorted Array" << endl;
	cout << "-----------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n\nNumber of comparisions: " << cmp_count << endl;
	cout << "Number of data movements: " << mov_count << endl;
}

int main()
{
	input();
	q_short(0, n-1);		//sort the array using quick sort
	display();
	system("pause");

	return 0;
}