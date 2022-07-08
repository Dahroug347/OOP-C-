#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>


class Complex
{

		float real;
		float imag;

	public:
		Complex();
		Complex(float r);
		Complex (float r, float i);
		~Complex();
		void setReal (float r);
		void setImag (float i);
		float getReal();
		float getImag();
		Complex add (Complex c);
		Complex sub (Complex c);
		void print();
};


Complex :: Complex()
{
	real = imag = 0;
	cout<<"\n construct is taking place now\n" ;
}

Complex :: Complex(float r, float i)
{
   real = r;
   imag = i;
   cout<<"\n construct with 2 input parameters is taking place now\n" ;
}

Complex :: Complex(float r)
{
   real = r;
   cout<<"\n construct with 1 input parameter is taking place now\n" ;
}

Complex :: ~Complex()
{
	cout << "destructor is taking place...\n";
}

void Complex :: setReal(float r)
{
	real = r;
}

void Complex :: setImag(float i)
{
	imag = i;
}

float Complex :: getReal ()
{
	return real;
}

float Complex :: getImag ()
{
	return imag;
}

Complex Complex:: add (Complex c)
{
	Complex temp;
	temp.real = this->real + c.real;
	temp.imag = this->imag + c.imag;
	return temp;
}

Complex Complex:: sub (Complex c)
{
	Complex temp;
	temp.real = real - c.real;
	temp.imag = imag - c.imag;
	return temp;
}

void Complex :: print()
{
	if (imag < 0)
	{
		cout<<real<<" - "<<fabs(imag)<<"i"<<endl;
	}

	else
	{
		cout<<real<<" + "<<imag<<"i"<<endl;
	}
}

int main()
{
	clrscr();

	Complex myComp1, myComp2(3,4), resultComp(5);
	myComp1.setReal(7);
	myComp1.setImag(2);


	resultComp = myComp1.add(myComp2);
	resultComp.print();
	resultComp = myComp1.sub(myComp2);
	resultComp.print();
	getch();

	return 0;
}
