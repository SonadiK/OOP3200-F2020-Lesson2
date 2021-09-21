#include "CartesianPoint.h";

#include <sstream> 			// stringstream
#include <cmath>			// sqrt()
#include <limits>			// INT_MAX

// Class definition section

//constructor - cartesianPoint (this calls SetPoint [SetX and SetY])
CartesianPoint::CartesianPoint(int x, int y)
{
	SetPoint(x, y);
}

//definition for destructor.
CartesianPoint::~CartesianPoint()
= default;

double CartesianPoint::operator-(const CartesianPoint& point_to) const
{
	// difference between x values
	const int xDelta = point_to.myX - myX;

	// difference between y values
	const int yDelta = point_to.myY - myY;

	// return the formula (based on Pythagorean theorem)
	return sqrt((xDelta * xDelta) + (yDelta * yDelta));
}

//use set x and set y
void CartesianPoint::SetPoint(int x, int y)
{
	SetX(x);
	SetY(y);
}

//Defining SetX and SetY
//Getting input from the function and modifying the data member.
void CartesianPoint::SetX(int x)
{
	myX = x;
}

void CartesianPoint::SetY(int y)
{
	myY = y;
}

// Defining accessors (GetX and GetY)
int CartesianPoint::GetX() const
{
	return myX;
}

int CartesianPoint::GetY() const
{
	return myY;
}


/* GetDistanceTo Method for CartesianPoint class
*	Determines the distance between this point and a second point.
*	@param	pointTo: CartesianPoint
*	@return	the distance as a double
*/

double CartesianPoint::GetDistance(const CartesianPoint& point_to) const
{
	// difference between x values
	const int xDelta = point_to.myX - myX;

	// difference between y values
	const int yDelta = point_to.myY - myY;

	// return the formula (based on Pythagorean theorem)
	return sqrt((xDelta * xDelta) + (yDelta * yDelta));

	/*double distance = sqrt((xDelta * xDelta) + (yDelta * yDelta));
	return distance;*/

}

/* ToString Method for CartesianPoint class
*	Converts the obj to a string.
*	@return	the obj state as a string
*/

std::string CartesianPoint::ToString() const
{
	// declare a stringstream object
	std::stringstream strOut;
	// build the string
	strOut << "(" << myX << ", " << myY << ")";
	// return the string
	return strOut.str();
}