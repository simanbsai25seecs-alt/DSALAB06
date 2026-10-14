#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

void inputSortedIDs(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Enter registration number " << i + 1 << ": ";
		cin >> arr[i];
	}
}

bool isSorted(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		if (arr[i] < arr[i - 1]) {
			return false;
		}
	}
	return true;
}

int binarySearch(int arr[], int low, int high, int target) {
	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (arr[mid] == target) {
			return mid;
		}

		if (target < arr[mid]) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return -1;
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

	inputSortedIDs(arr, n);

	if (!isSorted(arr, n)) {
		cout << "Error: IDs must be in ascending order." << endl;
		return 1;
	}

	cout << "Enter target registration number: ";
	cin >> target;

	int index = binarySearch(arr, 0, n - 1, target);

	if (index == -1) {
		cout << "Registration number not found." << endl;
	}
	else {
		cout << "Found at index " << index << endl;
	}

	return 0;
}
