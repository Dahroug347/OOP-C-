#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

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
        void print();
		friend istream& operator>> (istream& in, Complex& c);
		friend ostream& operator<< (ostream& out, Complex& c);
};



Complex :: Complex()
{
    real = imag = 0;
}

Complex :: Complex(float r, float i)
{
   real = r;
   imag = i;
}

Complex :: Complex(float r)
{
   real = imag = r;
}

Complex :: ~Complex()
{
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


istream& operator>> (istream&in, Complex& c)
	{
		cout<<"\nplease enter the real part: ";
		in>>c.real;
		cout<<"\nplease enter the imag part: ";
		in>>c.imag;
		return in;
	}

ostream& operator<< (ostream& out, Complex& c)
{
	if (c.imag < 0)
	out<< c.real <<" - "<<fabs(c.imag)<<"j";
	else
	out<< c.real <<" + "<<c.imag<<"j";
	return out;

}

int main ()
{
	int n;

	clrscr();
	Complex carr[10];
	Complex carr2[3]= {Complex (2,4), Complex(), Complex(8)};

	Complex *cptr;

	cout <<"printing for static complex array: \n\n";

	for (int i = 0; i<3; i++)
		carr2[i].print();

	cout <<"please determine the size of  dynamic complex array: ";
	cin>> n;
	cptr = new Complex[n];

	for (i = 0; i<n; i++)
		cin >> cptr[i];

	cout<< "printing for dynamic complex array: \n\n";

	for (i = 0; i<n; i++)
		cptr[i].print();

	getch();
	return 0;
}