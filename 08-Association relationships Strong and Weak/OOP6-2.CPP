#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>


class point
{

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

		line (point x1, point y1) : start(x1), end(y1)
		{
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

		rect (point m, point n) : UL(m), LR(n)
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



class picture
{
	int nc;
	int nr;
	int nl;

	circle  * pcircle;
	rect    * prect;
	line    * pline;

	circle  * cir;
	rect    * rec;
	line    * lin;

	public:
		picture() 
		{

			nc = 0;
			nr = 0;
			nl = 0;

			pcircle = NULL;
			prect = NULL;
			pline = NULL;
		}

		picture (circle* c, rect* r, line* l, int x, int y, int z)  // strong association (composition)
		{
			nc = x;
			nr = y;
			nl = z;

			cir = new circle[nc];
			rec = new rect[nr];
			lin = new line[nl];

			for (int i = 0; i<nc; i++)
			cir[i] = c[i];

			for ( i = 0; i<nr; i++)
			rec[i] = r[i];

			for ( i = 0; i<nl; i++)
			lin[i] = l[i];

		}

		/*picture (int cn, int rn, int ln, circle * pC, rect* pR, line* pL)  // weak association (aggregation)
		{
			cout<<"\npicture 6p constructor is calling\n";
			nc = cn;
			nr = rn;
			nl = ln;

			pcircle = pC;
			prect = pR;
			pline = pL;
		}*/


			void setCircles (int q, circle* cptr)
			{
				nc = q;
				pcircle = cptr;
			}
			void setRects (int, rect*);
			void setLines (int, line*);
			void print();


		~picture()
		{
			delete [] cir;
			delete [] rec;
			delete [] lin;
			
			cout<<"\npicture destructor is calling\n";
		}

};


void picture:: setRects (int x, rect* rptr)
{
	nr = x;
	prect = rptr;
}

void picture:: setLines (int x, line* lptr)
{
	nl = x;
	pline = lptr;
}

void picture:: print()
{
	int i;
	for (i = 0; i<nc; i++)
	cir[i].print();

	for (i = 0; i<nr; i++)
	rec[i].print();

	getch();
	clrscr();

	for (i = 0; i<nl; i++)
	lin[i].print();
}

int main ()
{
	clrscr();

	picture myPic;

	circle cArr[3] = {circle(50,50,50), circle(100,100,100), circle(200,200,200)}; //static allocation

	rect rArr[2];    /* on fly */

	rArr[0] = rect(30,20,40,50);

	point myP1(300,300);
	point myP2(500,500);

	rArr[1] = rect(myP1, myP2);

	line *lArr;		// dynamic allocation
	
	lArr = new line[2];

	lArr[0] = line (point(80,90), point(1,2));
	lArr[1] = line (10,10,10,10);

	picture myPic1(cArr, rArr, lArr, 3, 2, 2);

	myPic1.print();

	delete [] lArr;
	getch();
	return 0;
}
