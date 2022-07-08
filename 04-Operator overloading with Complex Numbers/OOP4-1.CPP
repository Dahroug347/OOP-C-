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
		Complex (Complex & obj)
		{
		  real = obj.real;
		  imag = obj.imag;
		}

		~Complex();

		friend istream& operator>> (istream& in, Complex& c);
		friend ostream& operator<< (ostream& out, Complex& c);

		Complex operator+ (Complex &c)
		{
			Complex temp (real+c.real, imag+c.imag);
			return temp;
		}

		Complex operator+ (float num)
		{
			Complex temp(real+num, imag);
			return temp;
		}

		Complex operator- (Complex &c)
		{
			Complex temp(real-c.real, imag-c.imag);
			return temp;
		}

		Complex operator- (float num)
		{
			Complex temp(real-num, imag);
			return temp;
		}

		Complex& operator++ ()
		{

			real  ++;
			imag  ++;
			return *this;
		}

		Complex operator++ (int dummy)
		{
			Complex temp(*this);
			real++;
			imag++;
			return temp;
		}

		  Complex& operator-- ()
		{

			real  --;
			imag  --;

			return *this;
		}

		Complex operator-- (int dummy)
		{
			Complex temp(*this);
			real  --;
			imag  --;
			return temp;
		}

		Complex& operator= (Complex& c)

		{
			real = c.real;
			imag = c.imag;
			return *this;
		}

		Complex & operator+= (Complex& c)
		{
			real += c.real;
			imag += c.imag;
			return *this;
		}

		Complex & operator-= (Complex& c)
		{
			real -= c.real;
			imag -= c.imag;
			return *this;
		}

	   int operator== (Complex& c)
		{
		   if ( (real == c.real) && (imag == c.imag) )
		   {
			   return 1;
		   }
		   else
			return 0;
		}
		operator float()
		{
			return real;
		}

		void setReal (float r);
		void setImag (float i);
		float getReal();
		float getImag();
		void print();
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

class myArray
{
	int size;
	int* ptr;

	public:

	myArray (int size)
	{
		this->size = size;
		ptr = new int[size];
	}

	~myArray()
	{

		delete [] ptr;
	}

	int & operator[] (int index)
	{


		if (index > size)
		{
			cout<<"array out of boundaries exception";
			exit(1);
		}

		return ptr[index];

	}
 };

 class coor
 {

  private:

   int x,y;

   public:

   coor ()
   {}

   coor (int a, int b)
   {
	x = a;
	y = b;
   }

   ~coor (){}

   void operator() (int a, int b)
   {
	x = a;
	y = b;

   }

   void print()
   {
	cout<<"\n point data: x="<<x<<" y= "<<y<<endl;
   }

 };

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


int main()
{
	clrscr();
	Complex  myComp1(7,2) , myComp2(3,4);
	Complex c1, c2, c3, c4, c5,c6, c7, c8,c9, c10(5,5), c11(10,10), c12;
	cout<< "\nnum1 = " ;
	myComp1.print();

	cout<< "\nnum2 = " ;
	myComp2.print();


	c1 = myComp1 + myComp2;

	c2 = myComp1++;

	c3 = ++myComp1;

	myComp1.setReal(7);

	myComp1.setImag(2);

	c4 = myComp1 - myComp2;

	c5 = myComp2--;

	c6 = --myComp2;

	c7 = c1;

	c8 = c9 = c3;

	cout<< "\nc1 = num1 + num2 = " ;
	c1.print();

	cout<< "\nc2 = ++ num1 = " ;
	c2.print();

	cout<< "\nc3 =num1 ++ = " ;
	c3.print();

	cout<< "\nc4 = num1 - num2 =  " ;
	c4.print();

	cout<< "\nc5 = -- num2 =  " ;
	c5.print();

	cout<< "\nc6 = num2-- =  " ;
	c6.print();

	cout<< "\nc7 = c1 =  " ;
	c7.print();

	cout<< "\nc8 = c3 = c9 =  " ;
	c8.print();

	cout<< "\nc9 = c3 = c8 =  " ;
	c9.print();

	getch ();

	clrscr();



	cout<< "\nc5 =  ";
	c5.print();

	cout<< "\nc10 =  " ;
	c10.print();

	cout << "\nc11 = ";
	c11.print();


	c10 += c5;

	c11 -= c5;

	float f = (float)c10;


	cout<< "\nc10 += c5 =  " ;
	c10.print();

	cout << "\nc11 -= c5 =  ";
	c11.print();

	cout<<"\n c1 = c2 ?  "<<(c1==c2)<<endl;
	if (!(c1 == c2))
	cout<< "c1 is not equal to c2"<<endl;

	cout << "\nf = (float)new 10 =  "<<f;

	cout <<"\nplease insert the value of  c12\n";

	cin>>c12;

	cout<<endl<< "value of c12 = ";
	c12.print();

	getch();

	clrscr();

	cout<<c1<<endl<<c2<<endl<<c3;
	myArray arr(5);

	cout<<"\nplease insert array values of 5 elements: "<<endl;

	for (int i= 0; i<5 ;i++)
	{
		cin>> arr[i];
	}

		for (i= 0; i<5 ;i++)
	{
		cout<<" "<< arr[i];
	}

	coor p1(30,40);
	cout<<endl;
	p1.print();
	p1(-5,132);
	cout<<endl;
	p1.print();
	getch();
	return 0;
}
