#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

int inputIDs(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Enter student ID " << i + 1 << ": ";
		cin >> arr[i];
	}
	return n;
}

int linearSearch(int arr[], int n, int target) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == target) {
			return i;
		}
	}
	return -1;
}

void displayResult(int index) {
	if (index == -1) {
		cout << "Student ID is not registered." << endl;
	}
	else {
		cout << "Student ID found at index " << index << endl;
	}
}

int main() {
	int arr[MAX_SIZE];
	int n, target;

	cout << "Enter number of students (0-1000): ";
	cin >> n;

	if (cin.fail() || n < 0 || n > MAX_SIZE) {
		cout << "Invalid array size." << endl;
		return 1;
	}

	inputIDs(arr, n);

	cout << "Enter target student ID: ";
	cin >> target;

	int index = linearSearch(arr, n, target);
	displayResult(index);

	return 0;
}
