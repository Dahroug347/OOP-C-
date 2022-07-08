#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

class Stack {

	int top;
	int size;
	int *ptr;
	static int counter;

public:
	int isFull();
	int isEmpty();
	static int getCounter (void)
	{
		return counter;
	}

	Stack()
	{
		top = 0;
		size = 10;
		ptr = new int[size];
		counter ++;
		cout << "\nThis is the default constructor" << endl;
	}

	Stack(int n)

	{
		top = 0;
		size = n;
		ptr = new int[size];
		counter ++;
		cout << "\nThis is a constructor with one parameter"<<endl;
	}
	~Stack()
	{
		delete[] ptr;
		counter --;
		size = 0;
		cout << "\nThis is the destructor" << endl;
		cout << "\n the number of objects created is now = "<<getCounter()<<endl;
	}

	int push(int n);
	int pop(int &n);
	friend void viewContent (Stack& m);
};

int Stack:: counter = 0;

int Stack::isFull()
{
	return (top == size);
}
int Stack::isEmpty()
{
	return (top == 0);
}

int Stack::push(int n)
{


	if (isFull())
		return 0;
	ptr[top] = n;
	top++;
	return 1;
}

int Stack::pop(int &n)
{
	if (isEmpty())
		return 0;
	top--;
	n = ptr[top];
	return 1;
}

void viewContent (Stack&m)
{
	for (int i = 0; i<m.top;i++)
		cout <<endl<< "element no." << i+1 <<" = " <<m.ptr[i]<<endl;
}

int main()
{
	clrscr();
	int num;
	cout << "\n the number of objects created is now = "<< Stack:: getCounter()<<endl;
	Stack s(2);
	cout << "\n the number of objects created is now = "<< Stack:: getCounter()<<endl;
	Stack s1;
	cout << "\n the number of objects created is now = "<< Stack:: getCounter()<<endl;
	s.push(3);
	s.push(4);

	viewContent(s);

  if(s.push(7))
  {
	 viewContent(s);
  }
  else
  {
      cout<<endl<<endl <<" size exceeded cant push "<<endl;
  }

	if (s.pop(num))
	{
		cout << num << endl;
	}
	if (s.pop(num)) {
		cout << num << endl;
	}
	if(s.pop(num))
	{
		cout<<num<<endl;
	}

	else cout << "\n Stack empty";

	getch();
	return 0;
}