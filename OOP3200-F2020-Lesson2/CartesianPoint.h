#pragma once 

#ifndef __CARTESIAN_POINT__
#define __CARTESIAN_POINT__
#include <string>

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
	~CartesianPoint();

	//Copy Constructor
	CartesianPoint(const CartesianPoint& point_two);

	//Operator overloads

	CartesianPoint operator+(const CartesianPoint& point_two) const;
	
	
	//point_to is the right side (right hand - left hand)
	double operator-(const CartesianPoint& point_to) const;
	bool operator==(const CartesianPoint& other_point) const;

	//Activity 2 - Accessors

	/* Accessors: Used to query the state of the object
	*	- never modifies the object
	*	- should specify const at the end of the prototype/header
	*/

	// get x (return integers)(declaration part))
	int GetX() const;
	// get y
	int GetY() const;


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
	double GetDistance(const CartesianPoint& point_to) const;

	// convert the obj to a string	(this return a string)
	std::string ToString() const;

private:
	// private data members for the dimensions of the point
	int myX{}; // x-axis (horizontal) value
	int myY{};  // y-axis (vertical) value

};

#endif /*Define __CARTESIAN_POINT__*/
