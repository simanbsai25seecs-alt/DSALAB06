#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;

void displayArray(int arr[], int n) {
	cout << "[";
	for (int i = 0; i < n; i++) {
		cout << arr[i];
		if (i < n - 1) {
			cout << ", ";
		}
	}
	cout << "]" << endl;
}

void merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}

	for (int j = 0; j < n2; j++) {
		R[j] = arr[mid + 1 + j];
	}

	int i = 0;
	int j = 0;
	int k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k++] = L[i++];
		}
		else {
			arr[k++] = R[j++];
		}
	}

	while (i < n1) {
		arr[k++] = L[i++];
	}

	while (j < n2) {
		arr[k++] = R[j++];
	}

	delete[] L;
	delete[] R;
}

void mergeSort(int arr[], int left, int right) {
	if (left >= right) {
		return;
	}

	int mid = left + (right - left) / 2;

	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);

	merge(arr, left, mid, right);
}

int main() {
	int arr[MAX_SIZE];
	int n;

	cout << "Enter number of students (0-1000): ";
	cin >> n;

	if (cin.fail() || n < 0 || n > MAX_SIZE) {
		cout << "Invalid array size." << endl;
		return 1;
	}

	for (int i = 0; i < n; i++) {
		cout << "Enter marks of student " << i + 1 << ": ";
		cin >> arr[i];
	}

	cout << "Before sorting: ";
	displayArray(arr, n);

	if (n > 0) {
		mergeSort(arr, 0, n - 1);
	}

	cout << "After sorting: ";
	displayArray(arr, n);

	return 0;
}
