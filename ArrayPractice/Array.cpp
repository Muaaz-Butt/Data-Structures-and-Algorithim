#include <iostream>
#include "Array.h"

using namespace std;

int Array::currentIndex = 0;

Array::Array() {
	maxSize = 50;
}

int Array::getCurrentIndex() {
	return currentIndex;
}

int Array::getMaxSize()const {
	return maxSize;
}

void Array::displayArray() {
	cout << "[";
	for (int i = 0; i < currentIndex; i++) {
		cout << array[i] << ", ";
	}
	cout << "\b\b]\n";
}

bool Array::insertAtBeginningOfArray(int value) {
	if (currentIndex == 0) {
		array[0] = value;
		currentIndex++;
		return true;
	}
	else if (currentIndex  == maxSize) {
		array[0] = value;
		return true;
	}
	else {
		for (int i = currentIndex; i > 0; i--) {
			array[i] = array[i - 1];
		}
		array[0] = value;
		currentIndex++;
		return true;
	}
	return false;
}

bool Array::insertAtEndOfArray(int value) {
	if (currentIndex == maxSize) {
		array[currentIndex - 1] = value;
		return true;
	}
	else {
		array[currentIndex] = value;
		currentIndex++;
		return true;
	}
	return false;
}

int Array::searchValueInArray(int value) {
	for (int i = 0; i < currentIndex; i++) {
		if (array[i] == value) {
			return i;
		}
	}
	return -1;
}

bool Array::removeValueFromArray(int value) {
	int searchedIndexOfValue = searchValueInArray(value);
	if (searchedIndexOfValue == -1) {
		return false;
	}
	else if (searchedIndexOfValue == currentIndex - 1) {
		currentIndex--;
		return true;
	}
	else {
		currentIndex--;
		for (int i = searchedIndexOfValue; i < currentIndex; i++) {
			array[i] = array[i + 1];
		}
		return true;
	}
}

bool Array::updateValueInArray(int index, int value) {
	if (index < 0 || index > currentIndex) {
		return false;
	}
	else {
		array[index] = value;
		return true;
	}
}

int Array::indexAt() {
	return currentIndex;
}