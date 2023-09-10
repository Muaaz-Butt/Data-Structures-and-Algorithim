#ifndef ARRAY_H
#define ARRAY_H

class Array {
private:
	int array[50];
	static int currentIndex;
	int maxSize;
public:
	Array();
	static int getCurrentIndex();
	int getMaxSize()const;
	void displayArray();
	bool insertAtBeginningOfArray(int value);
	bool insertAtEndOfArray(int value);
	bool removeValueFromArray(int value);
	bool updateValueInArray(int index, int value);
	int searchValueInArray(int value);
	int indexAt();
};

#endif ARRAY_H
