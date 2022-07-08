#include <iostream.h>
#include <alloc.h>
#include <math.h>
#include <conio.h>


struct Complex
{
    private:
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
        void print();
};

Complex :: Complex()
{
    real = imag = 0;
	cout<<"\n construct is taking place now"<<endl;
}

Complex :: Complex(float r, float i)
{
   real = r;
   imag = i;
   cout<<"\n construct with 2 input parameters is taking place now"<<endl;
}

Complex :: Complex(float r)
{
   real = imag = r;
   cout<<"\n construct with 1 input parameter is taking place now"<<endl;
}

Complex :: ~Complex()
{
	cout << "destructor is taking place..."<<endl;
}

void Complex :: setReal(float r)
{
	real = r;
}

void Complex :: setImag (float i)
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

Complex add (Complex c1, Complex c2)
{
	Complex temp;

	temp.setReal(c1.getReal() + c2.getReal());
	temp.setImag(c1.getImag() + c2.getImag());

	return temp;
}

Complex sub (Complex c1, Complex c2)
{
	Complex temp;

	temp.setReal(c1.getReal() - c2.getReal());
	temp.setImag(c1.getImag() - c2.getImag());

	return temp;
}

void swapp (int& c1, int& c2)

{
	int temp = c1;
	c1 = c2;
	c2 = temp;
}

int main()
{
	int x = 4, y = 7;


	clrscr();
	Complex num1, num2(5.5, 8.5), CresultNum (5);

	num1.setReal(7);
	num1.setImag(4);

	CresultNum = add(num1,num2);
	CresultNum.print();

	CresultNum = sub(num1,num2);
	CresultNum.print();

	cout<<endl<<" x and y values are: " <<x<<"  "<<y<<endl;

	swapp (x, y);
	cout<<endl<<" x and y values after swapping are: " <<x<<"  "<<y<<endl;


	getch();

	return 0;
}
