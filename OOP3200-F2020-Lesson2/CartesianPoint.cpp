#include "CartesianPoint.h";

#include <sstream> 			// stringstream
#include <cmath>			// sqrt()
#include <limits>			// INT_MAX

// Class definition section

//constructor - cartesianPoint (this calls SetPoint [SetX and SetY])
CartesianPoint::CartesianPoint(const int x, const int y):m_x(x), m_y(y)
{
	//SetPoint(x, y);
}

//definition for destructor.
CartesianPoint::~CartesianPoint()
= default;

CartesianPoint::CartesianPoint(const CartesianPoint& point_two)
{
	SetPoint(point_two.GetX(), point_two.GetY());
}

CartesianPoint CartesianPoint::operator+(const CartesianPoint& point_two) const
{
	CartesianPoint tempPoint;
	//tempPoint.SetX(GetX() + point_two.GetX());
	//tempPoint.SetY(GetY() + point_two.GetY());
	//explicit way of accessing getters.
	tempPoint.SetX((*this).GetX() + point_two.GetX());
	tempPoint.SetY((*this).GetY() + point_two.GetY());
	return tempPoint;
}

double CartesianPoint::operator-(const CartesianPoint& point_to) const
{
	// difference between x values
	const int xDelta = point_to.GetX() - m_x;

	// difference between y values
	const int yDelta = point_to.GetY() - m_y;

	// return the formula (based on Pythagorean theorem)
	return sqrt((xDelta * xDelta) + (yDelta * yDelta));
}

bool CartesianPoint::operator==(const CartesianPoint& other_point) const
{
	return ((GetX() == other_point.GetX()) && (GetY() == other_point.GetY()));
}

//friend func def
std::ostream& operator<<(std::ostream& out, const CartesianPoint& point)
{
	out << point.ToString();
	return out;
}

std::istream& operator>>(std::istream& in, CartesianPoint& point)
{
	in >> point.m_x;
	in.ignore();
	in >> point.m_y;

	return in;
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
	m_x = x;
}

void CartesianPoint::SetY(int y)
{
	m_y = y;
}

// Defining accessors (GetX and GetY)
int CartesianPoint::GetX() const
{
	return m_x;
}

int CartesianPoint::GetY() const
{
	return m_y;
}


/* GetDistanceTo Method for CartesianPoint class
*	Determines the distance between this point and a second point.
*	@param	pointTo: CartesianPoint
*	@return	the distance as a double
*/

double CartesianPoint::GetDistance(const CartesianPoint& point_to) const
{
	// difference between x values
	const int xDelta = point_to.GetX() - m_x;

	// difference between y values
	const int yDelta = point_to.GetY() - m_y;

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
	strOut << "(" << m_x << ", " << m_y << ")";
	// return the string
	return strOut.str();
}

