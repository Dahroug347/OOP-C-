#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

template <class T>
class  Stack {

	int top;
	int size;
	T *ptr;
	static int counter;

public:
	int isFull();
	int isEmpty();
	static int getCounter (void)
	{
		return counter;
	}

	Stack <T>()
	{
		top = 0;
		size = 10;
		ptr = new T[size];
		counter ++;
		cout << "\nThis is the default constructor" << endl;
	}

		Stack<T> (Stack<T> &n)
	{
		top = n.top;
		size = n.size;
		ptr = new T[size];
		for (int i = 0; i <top; i++)
			ptr[i]= n.ptr[i];

			counter ++;
	}

	Stack<T>(T n)

	{
		top = 0;
		size = n;
		ptr = new T[size];
		counter ++;
		counter ++;
		cout << "\nThis is a constructor with one parameter"<<endl;
	}

	~Stack<T>()
	{
		delete[] ptr;
		counter --;
		size = 0;
		cout << "\nThis is the destructor" << endl;
		cout << "\n the number of objects created is now = "<<getCounter()<<endl;
	}

	int push(T n);
	int pop(T &n);
	Stack<T>& operator= (Stack<T>& s);
	friend void viewContent (Stack<T> m);
};

template <class T>
int Stack<T>:: counter = 0;

template <class T>
int Stack <T>::isFull()
{
	return (top == size);
}

template <class T>
int Stack <T>::isEmpty()
{
	return (top == 0);
}

template <class T>
int Stack<T>::push(T n)
{


	if (isFull())
		return 0;
	ptr[top] = n;
	top++;
	return 1;
}
template <class T>
int Stack<T>::pop(T &n)
{
	if (isEmpty())
		return 0;
	top--;
	n = ptr[top];
	return 1;
}

template <class T>
void viewContent (Stack<T> m)
{
	for (int i = 0; i<m.top;i++)
		cout <<endl<< "element no." << i+1 <<" = " <<m.ptr[i]<<endl;
}

Stack<T>& Stack<T>::operator= (Stack<T>& s)
{
	if (ptr)
	delete [] ptr;
	 top = s.top;
	 size = s.size;
	 ptr = new T[size];
	 for (int i - 0; i<top; i++)
	 ptr[i] = s.ptr[i];

	 return *this;
}

int main()
{
	clrscr();
	int n;
	Stack<int> s1(5);
	cout<<"\nNo of Int stacks is: "<<Stack<int>::getCounter();
	s1.push(10);
	s1.push(3);
	s1.push(2);
	s1.pop(n);
	cout<<"\n1st integer: "<<n;
	s1.pop(n);
	cout<<"\n2nd integer: "<<n;
	Stack<char> s2;
	char x;
	cout<<"\nNo of char stacks is: "<<Stack<char>::getCounter();

	s2.push('q');
	s2.push('r');
	s2.push('s');
	viewContent(s2);
	s2.pop(x);
	cout<<"\n1st char: "<<x;
	s2.pop(x);
	cout<<"\n2nd char: "<<x;
	getch();
	return 0;
}