#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

class base
{
   //	protected:

	int x,y;
	public:
		base()
		{
			x=0;
			y=0;
		}
		base (int a)
		{
			x=y=a;
		}
		base (int a, int b)
		{
			x=a;
			y=b;
		}

		~base(){}

		void setX(int a)
		{
			x = a;
		}

		void setY(int b)
		{
			y = b;
		}

		int getX()
		{
			return x;
		}
		int getY()
		{
			return y;
		}

		int calcSum ()
		{
			return x+y;
		}
};

class derived : public base
{
	int z;
	public:

		derived () : base() { z= 0;}
		derived (int a) : base(a) { z= a;}
		derived (int a, int b, int c) : base(a,b) { z= c;}
		~derived () {}

		void setZ(int b)
		{
			z = b;
		}

		int getZ()
		{
			return z;
		}

		int calcSum ()
		{
			return base::calcSum()+z;
		//	 return x+y+z ;
		}
};



int main ()
{
	clrscr();

	base b(5,4);
	cout <<"using object b from class base: "<<b.calcSum()<<endl;
	derived obj1;
	obj1.setX(3);
	obj1.setY(7);
	obj1.setZ(1);

	derived obj2(20);
	derived obj3 (4,5,6);

	cout<<"obj1: "<<obj1.calcSum()<<endl;
	cout<<"obj2: "<<obj2.calcSum()<<endl;
	cout<<"obj3: "<<obj3.calcSum()<<endl;

	cout<<"obj1 in parent scope sum: "<<obj1.base::calcSum()<<endl;

	getch();
	return 0;
}
