#include <iostream>

using namespace std;

void printArray(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
}

int* bubbleSort(int* arr, int size) {
	printArray(arr, size);
	int j = size - 1;
	while (j > 0) {
		for (int i = 0; i < j; i++) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
		printArray(arr, size);
		j--;
	}
	return arr;
}

int* insertionSort(int* arr, int size){
	printArray(arr, size);
	for (int i = 1; i < size; i++) {
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
		}
		printArray(arr, size);
	}
	return arr;
}

int* selectionSort(int* arr, int size) {
	printArray(arr, size);
	for (int i = 0; i < size - 1; i++) {
		int min = arr[i];
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[i]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		printArray(arr, size);
	}
	return arr;
}

void merge(int arr[], int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int* leftArray = new int[n1];
	int* rightArray = new int[n2];
	for (int i = 0; i < n1; i++)
		leftArray[i] = arr[left + i];
	for (int i = 0; i < n2; i++)
		rightArray[i] = arr[mid + 1 + i];
	int i = 0;
	int j = 0;
	int k = left;
	while (i < n1 && j < n2) {
		if (leftArray[i] <= rightArray[j]) {
			arr[k] = leftArray[i];
			i++;
		}
		else {
			arr[k] = rightArray[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = leftArray[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = rightArray[j];
		j++;
		k++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int partition(int arr[], int low, int high) {
	int pivot = arr[high]; 
	int i = low - 1; 
	for (int j = low; j < high; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivotIndex = partition(arr, low, high);
		quickSort(arr, low, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, high);
	}
}

void heapify(int* arr, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < n && arr[left] > arr[largest])
		largest = left;
	if (right < n && arr[right] > arr[largest])
		largest = right;
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int* arr, int size) {
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(arr, size, i);
	for (int i = size - 1; i > 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

int main() {
	int arr[] = { 3,1,9,2,0,7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, size);
	printArray(arr, size);
}