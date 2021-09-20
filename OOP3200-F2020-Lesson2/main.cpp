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
		distance = origin.GetDistance(destination);


		// Output 
		// Show the points and the distance
		std::cout << fixed << setprecision(3); // formatting
		std::cout << "\nThe Distance between " << origin.ToString() << " and " << destination.ToString() << " is " << distance << "." << endl;

	}

	catch (exception& ex)
	{
		cerr << ex.what() << " Ending the program." << endl;
	}

	// done.
	std::cout << endl << endl;
	return 0;
} // end of main()



