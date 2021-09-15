/** main.cpp
 *
 *	In this example program, did the following:
 *		- Examined a simple class with 'instance' data-members, a constructor, accessors, mutators.
 *
 *	@author		Sonadi Kannangara
 *	@studentID  100778336
 *	@date       15 September 2021
 *	Activity    ICE 1
*/

#include <iostream> 		// cin, cout
#include <iomanip>			// fixed, setprecision()
#include <sstream> 			// stringstream
#include <cmath>			// sqrt()
#include <limits>			// INT_MAX
#include <stdexcept>		// out_of_range
#include "MyConsoleInput.h" // ConsoleInput::ReadInteger()

using namespace std;

// class declaration section
class CartesianPoint
{
public:

	/* Constructor: Used to initialize objects
	*	- always the same name as the class
	*	- never have a return type
	*	- called automatically when an obj is instantiated
	*	- should set values for each member variable
	*/
	CartesianPoint(int x = 1, int y = 1); //declaration

	//Activity 2 - Accessors

	/* Accessors: Used to query the state of the object
	*	- never modifies the object
	*	- should specify const at the end of the prototype/header
	*/

	// get x (return integers)(declaration part))
	int GetX();
	// get y
	int GetY();


	//Activity 3 - Mutator

	/* Mutator(s): Used to change the state of the object
	*	- should contain logic to ensure object remains in a valid state.
	*	- typically sets a member variable to a parameter
	*/

	// set x (declaration)
	void SetX(int x);
	// set y, 
	// set point (both x and y)
	void SetY(int y);
	// this function not return anything
	void SetPoint(int x, int y);

	// Declaring GetDistance and ToString method
	// get the distance between this point and a second point
	// I used GetDistance in here instead of GetInstanceTo because in DC connect pptx->activity instructions->GetDistance()
	double GetDistance(CartesianPoint pointTo) const;

	// convert the obj to a string	(this return a string)
	string ToString() const;

private:
	// private data members for the dimensions of the point
	int myX; // x-axis (horizontal) value
	int myY;  // y-axis (vertical) value

};

// main() function
int main()
{
	// Declarations
	// a point called 'origin', initialized to 0, 0
	////1st option
	//CartesianPoint origin(0, 0);

	//2nd Option
	CartesianPoint origin = CartesianPoint(0, 0);
	
	// a point called 'destination'
	//declaring object 
	CartesianPoint destination;

	int inputX; // temporary input variable for x
	int inputY; // temporary input variable for y
	
	// to store the distance between two points
	double distance;


	//double myDouble = ConsoleInput::ReadDouble();

	try
	{
		// Input

		// Prompt the user for the coordinates
		cout << "\nEnter coordinates of the destination point: " << endl;
		// prompt for, read, and store x coordinate:
		cout << "X: ";
		inputX = ConsoleInput::ReadInteger();

		//set x variable to destination object
		destination.SetX(inputX);

		// prompt for, read, and store y coordinate:
		cout << "Y: ";
		inputY = ConsoleInput::ReadInteger();

		destination.SetY(inputY);

		// Processing
		// determine the distance between the two points
		distance = origin.GetDistance(destination);


		// Output 
		// Show the points and the distance
		cout << fixed << setprecision(3); // formatting
		cout << "\nThe Distance between " << origin.ToString() << " and " << destination.ToString() << " is " << distance << "." << endl;

	}

	catch (exception& ex)
	{
		cerr << ex.what() << " Ending the program." << endl;
	}

	// done.
	cout << endl << endl;
	return 0;
} // end of main()


// Class definition section

//constructor - cartesianPoint (this calls SetPoint [SetX and SetY])
CartesianPoint::CartesianPoint(int x, int y)
{
	SetPoint(x, y);
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
int CartesianPoint::GetX()
{
	return myX;
}

int CartesianPoint::GetY()
{
	return myY;
}


/* GetDistanceTo Method for CartesianPoint class
*	Determines the distance between this point and a second point.
*	@param	pointTo: CartesianPoint
*	@return	the distance as a double
*/

double CartesianPoint::GetDistance(CartesianPoint pointTo) const
{
	// difference between x values
	int xDelta = pointTo.myX - myX;

	// difference between y values
	int yDelta = pointTo.myY - myY;

	// return the formula (based on Pythagorean theorem)
	return sqrt((xDelta * xDelta) + (yDelta * yDelta));

	/*double distance = sqrt((xDelta * xDelta) + (yDelta * yDelta));
	return distance;*/

}

/* ToString Method for CartesianPoint class
*	Converts the obj to a string.
*	@return	the obj state as a string
*/

string CartesianPoint::ToString() const
{
	// declare a stringstream object
	stringstream strOut;
	// build the string
	strOut << "(" << myX << ", " << myY << ")";
	// return the string
	return strOut.str();
}
