#include <iostream>
#include "Array.h"
#include "Dashboard.h"

using namespace std;

void Dashboard::showMenu() {
	cout << "Enter 1 to add value at the beginning of array\n";
	cout << "Enter 2 to add value at the end of array\n";
	cout << "Enter 3 to remove value from array\n";
	cout << "Enter 4 to search value in array\n";
	cout << "Enter 5 to update value in array\n";
	cout << "Enter 6 to display array\n";
	cout << "Enter 7 to exit\n";
}

void Dashboard::askUserChoiceForFunctionalities(int& choice) {
	cout << "Enter your choice: ";
	cin >> choice;
}

void checksForUserChoice(Array& array, int choice) {
	int value;
	if (choice < 1 || choice > 7) {
		cout << "\n\n*****Invalid Choice*****\n\n";
	}
	else if (choice == 1) {
		cout << "Enter value to add: ";
		cin >> value;
		array.insertAtBeginningOfArray(value);
	}
	else if (choice == 2) {
		cout << "Enter value to add: ";
		cin >> value;
		array.insertAtEndOfArray(value);
	}
	else if (choice == 3) {
		cout << "Enter value to remove from array: ";
		cin >> value;
		if (!array.removeValueFromArray(value)) {
			cout << "\n------------Value not found------------\n";
		}
	}
	else if (choice == 4) {
		cout << "Enter value which you want to search: ";
		cin >> value;
		int indexOfSearchedValue = array.searchValueInArray(value);
		if (indexOfSearchedValue == -1) {
			cout << "\n------------Value not found------------\n";
		}
		else {
			cout << "Value is found at index " << indexOfSearchedValue << "\n";
		}
	}
	else if (choice == 5) {
		int index;
		cout << "Enter index: ";
		cin >> index;
		cout << "Enter updated value: ";
		cin >> value;
		if (!array.updateValueInArray(index,value)) {
			cout << "\n------------Invaid Index------------\n";
		}
	}
	else if (choice == 6) {
		array.displayArray();
	}
}

void Dashboard::performFunctionalitiesOfArrayClass() {
	Array array;
	int choice;
	do {
		showMenu();
		askUserChoiceForFunctionalities(choice);
		checksForUserChoice(array, choice);
	} while (choice != 7);
}