#include <iostream>
using namespace std;


int arr[20]					//array of integers tp hold velues
int cmp_count = 0;			//number of comparasion
int mov_count = 0;			//number of data movement
int n;

void inout() {
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
		cout << "<"
	}
}