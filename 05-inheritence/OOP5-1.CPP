#include <iostream.h>
#include <stdlib.h>
#include <conio.h>


class point
{
private:
	int x,y;
public:
	point()
	{
		x=y=0;
	}

	point (int m)
	{
		x=y=m;
	}

	point (int a, int b)
	{
		x = a;
		y = b;
	}

	~point()
	{

	}

	void setX (int a)
	{
		x = a;
	}

	void setY (int b)
	{
		y = b;
	}

	void setXY (int a, int b)
	{
		x= a;
		y = b;
	}

	int getX ()
	{
		return x;
	}

	int getY ()
	{
		return y;
	}

	void print()
	{
		cout<<"\n point data: x = "<<x<<" "<<"y = "<<y<<endl;
	}

};

class line
{
	point start;
	point end;

	public:

		line()
		{
			start.setXY(0,0);
			end.setXY(0,0);
		}

		line (int x1, int y1, int x2, int y2)
		{
			start.setXY (x1,y1);
			end.setXY (x2,y2);
		}

		~line ()
		{
			
		}

		void print ()
		{
			cout<<"\nStart: ";
			start.print();
			cout<<"\nend: ";
			end.print();
		}
};

class circle
{
	point center;
	int rad;

	public:

		circle() :	center(0)
		{
			rad = 0;
		} 

		circle (int x1, int y1,  int r) : center ( x1, y1), rad(r)
		{

		}
		
		~circle()
		{

		}

		void print()
		{
			cout<<"\nCenter: ";
			center.print();
			cout<<"\nRadius = "<<rad<<endl;
		}
};

class rect
{
	point UL;
	point LR;

	public:

		rect() :	UL(), LR()
		{
		} 

		rect (int x1, int y1, int x2, int y2 ) : UL (x1, y1), LR(x2,y2)
		{

		}
		
		~rect()
		{

		}

		void print()
		{
			cout<<"\nupper left: ";
			UL.print();
			cout<<"\nlower right: ";
			LR.print();
		}
};


int main ()
{
	clrscr();

	circle c1(200, 100, 50);
	rect r1 (5,10,80,75);
	line l1 (30,40,60,20);

	c1.print();
	r1.print();
	l1.print();

	getch();
	return 0;
}