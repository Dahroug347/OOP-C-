#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

class GeoShape
{
	protected:

		float d1, d2;

	public:

		GeoShape(){d1=d2=0;}
		GeoShape(float x){d1=d2=x;}
		GeoShape(float x, float y){d1=x; d2=y;}
		~GeoShape(){}

		void setD1(float b)
		{
			d1 = b;
		}

		float getD1()
		{
			return d1;
		}

		void setD2(float b)
		{
			d2 = b;
		}

		float getD2()
		{
			return d2;
		}

		virtual float calcArea() = 0;
		
};

class rect : public GeoShape
{

	public:
		 rect(){}
		rect (float a, float b) : GeoShape (a, b) {}
		~rect () {}

		float calcArea()
		{
			return d1*d2;
		}
};

class square : public rect
{
	public:
		square (){}
		square (float a) : rect (a, a) {}
		~square () {}

		void setSide(float x)   // to avoid settiing sqare side differently and so it was inherited from a protected version of rect
		{
			d1=d2=x;
		}

		float calcArea()
		{
			return d1*d2;
		}
};

class triangle : public GeoShape
{
	public:

		triangle (float a, float b) : GeoShape (a, b) {}
		~triangle () {}

		float calcArea()
		{
			return  0.5*d1*d2;
		}
};

class circle : public GeoShape
{
	public:
		circle (){}
		circle (float r) : GeoShape (r) {}
		~circle () {}

		void setRad(float r)   // same as sqare and so it was inherited from a protected version of GeoShape
		{
			d1 = d2= r;
		}

		float calcArea()
		{
			return (22.0/7) * d1 *d2;
		}
};


float sumOfAreas (GeoShape &c, GeoShape &t, GeoShape &r, GeoShape&s)
{
	return c.calcArea()+t.calcArea()+r.calcArea()+s.calcArea();
}

int main ()
{
	clrscr();
	
   //	GeoShape a;
	GeoShape *g;

	triangle myTrio(20,10);
	cout<<" area of triangle (20,10) = "<< myTrio.calcArea() <<endl;

	circle myCir(7);
	cout<<" area of circle (7) = "<< myCir.calcArea() <<endl;

	rect myRect (4,6);
	cout<< " area of rectangle (4,6) = "<<myRect.calcArea()<<endl;

	square mySqu(5);
	cout<< " area of square (5) = "<< mySqu.calcArea()<<endl;


	// mySqu.setD2(5);  // that will cause error but if the child square was inherited from public rectangle it will cause nothing
	// myCir.setD2(3);  // that also will cause error

	circle cir2;
	square sqlol;

	sqlol.setSide(6);
	cout<< "area of sqlol = "<<sqlol.calcArea() <<endl;

	cir2.setRad(10);
	cout<< "area of cir2 = "<<sqlol.calcArea() <<endl;

	cout <<"sum of areas of triangle, circle, rectangle & square = "<<sumOfAreas(myTrio, myCir, myRect, mySqu) <<endl;;
	cout <<"sum of areas of triangle, circle, rectangle & square = "<<sumOfAreas(myTrio, cir2, myRect, sqlol) << endl ;
	getch();
	return 0;
}
