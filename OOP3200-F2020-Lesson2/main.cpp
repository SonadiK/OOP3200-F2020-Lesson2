/** main.cpp
 *
 *	In this example program, did the following:
 *		- Examined a simple class with 'instance' data-members, a constructor, accessors, mutators.
 *
 *	@author		Sonadi Kannangara
 *	@studentID  100778336
 *	@date       15 September 2021(Last modified)
 *	Activity    ICE 1 - In Class Exercise 1
*/

#include <iostream> 		// cin, cout
#include <iomanip>			// fixed, setprecision()
#include <stdexcept>		// out_of_range
#include "MyConsoleInput.h" // ConsoleInput::ReadInteger()

#include "CartesianPoint.h";

using namespace std;



// main() function
int main()
{
	// Declarations
	// a point called 'origin', initialized to 0, 0
	////1st option
	//CartesianPoint origin(0, 0);

	//2nd Option
	CartesianPoint origin = CartesianPoint(10, 20);
	
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
		std::cout << "\nEnter coordinates of the destination point: " << endl;
		// prompt for, read, and store x coordinate:
		std::cout << "X: ";
		inputX = ConsoleInput::ReadInteger();

		//set x variable to destination object
		destination.SetX(inputX);

		// prompt for, read, and store y coordinate:
		std::cout << "Y: ";
		inputY = ConsoleInput::ReadInteger();

		destination.SetY(inputY);

		// Processing
		// determine the distance between the two points
		//distance = origin.GetDistance(destination);
		//(below line replace the above line)
		distance = origin - destination;

		std::cout << "origin is equal to destination?: " << std::to_string(origin == destination) << std::endl;

		//Vector
		CartesianPoint newPoint = origin + destination;
		//std::cout << "origin + destination = " << newPoint.ToString() << std::endl;
		std::cout << "origin + destination = " << newPoint << std::endl;

		// Output 
		// Show the points and the distance
		std::cout << fixed << setprecision(3); // formatting
		//std::cout << "\nThe Distance between " << origin.ToString() << " and " << destination.ToString() << " is " << distance << "." << endl;
		std::cout << "\nThe Distance between " << origin << " and " << destination << " is " << distance << "." << endl;

		CartesianPoint anotherPoint;

		std::cout << "\nEnter another point: ";
		std::cin >> anotherPoint;

		std::cout << "You entered: " << anotherPoint << std::endl;
	}

	catch (exception& ex)
	{
		cerr << ex.what() << " Ending the program." << endl;
	}

	// done.
	std::cout << endl << endl;
	return 0;
} // end of main()



