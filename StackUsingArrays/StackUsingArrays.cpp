#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Stack {
private:
	T* data;
	int capacity;
	int top;
	void reSize(int);
public:
	Stack();
	Stack(const Stack<T>&);
	Stack& operator = (const Stack<T>&);
	~Stack();
	void push(T);
	T pop();
	T stackTop();
	bool isFull();
	bool isEmpty();
	int getCapacity();
	int getNumberOfElements();
};

template <typename T>
Stack<T>::Stack() {
	data = nullptr;
	capacity = 0;
	top = 0;
}

template <typename T>
Stack<T>::~Stack() {
	if (!data)
	{
		return;
	}
	delete[] data;
	data = nullptr;
}

template <typename T>
void Stack<T>::reSize(int n) 
{
	T* temp = new T[n];
	for (int i = 0; i < top; i++) {
		*(temp + i) = data[i];
	}
	this->~Stack();
	data = temp;
	capacity = n;
}

template<typename T>
bool Stack<T>::isEmpty() 
{
	return top == 0;
}

template <typename T>
bool Stack<T>::isFull()
{
	return top == capacity;
}

template <typename T>
T Stack<T>::stackTop() 
{
	if (isEmpty()) {
		throw exception();
	}
	return data[top - 1];
}

template <typename T>
int Stack<T>::getCapacity()
{
	return capacity;
}

template <typename T>
int Stack<T>::getNumberOfElements()
{
	return top;
}

template <typename T>
void Stack<T>::push(T value)
{
	if (isFull()) 
	{
		reSize(capacity == 0 ? 1 : capacity * 2);
	}
	data[top++] = value;
}

template<typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		throw exception();
	}
	T val = data[--top];
	if (top > 0 && top == capacity / 4)
	{
		reSize(capacity / 2);
	}
	return val;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other)
	{
		delete[]data;
		capacity = other.capacity;
		data = new T[capacity];
		for (int i = 0; i < other.top; i++)
		{
			data = other.data[i];
		}
		top = other.top;
	}																		 
	return *this;
}

template <typename T>
Stack<T>::Stack(const Stack<T>& other)
{
	capacity = other.capacity;
	top = other.top;
	data = new T[capacity];
	for (int i = 0; i < top; i++) {
		data[i] = other.data[i];
	}
}

int main() {
	Stack<int> s;
	for (int i = 1; i <= 12; i++) {
		s.push(i);
	}
	while (!s.isEmpty()) {
		cout << s.pop() << "\n";
	}
	return 0;
}