// Joseph Smith
// Driver.cpp
// CIS-2207
// November 17, 2024

#include <iostream>
#include <sstream>
#include <iomanip>
#include <memory>
#include "MatrixGraph.h"
#include "ListGraph.h"
using namespace std;

// Utility constants
const int FLOAT_PRECISION = 4;
const int SPACING = 24;
const int PAGE_WIDTH = 74;
const int MARGIN_LEFT = 4;
const int MAX_SIZE = 21;
const int MIN_SIZE = 6;

/** Create a line of text with a left margin determined by the
		constant MARGIN_LEFT, and a new line at the end.
	@param text The string of text to format.
	@returns The string of text formatted accordingly. */
template <class ItemType>
string makeLine(ItemType text)
{
	stringstream sStream;
	sStream << left << setw(MARGIN_LEFT) << "" << setw(SPACING) << text;
	return sStream.str();
}

/** Create a line of text with a label, and left margin
		determined by the constant MARGIN_LEFT, and a new line
		at the end.
	@param label The line's label.
	@param text The line's context.
		of the line and the text content.
	@returns The string of text formatted accordingly. */
template <class ItemType>
string makeLine(string label, ItemType text)
{
	stringstream sStream;
	sStream << left << setw(MARGIN_LEFT) << ""
		<< setw(SPACING) << label << text;
	return sStream.str();
}

/** Create a formatted menu header with an underline of length PAGE_WIDTH.
	@param text The header title.
	@returns The string of text formatted as a header. */
template <class ItemType>
string makeHeader(ItemType text)
{
	stringstream sStream;
	sStream << left << setw(MARGIN_LEFT) << "" << text
		<< endl << left << setw(MARGIN_LEFT / 2) << ""
		<< string(PAGE_WIDTH, '-') << endl;
	return sStream.str();
}

/** Create a formatted menu subheader.
	@param text The header title.
	@returns The string of text formatted as a header. */
template <class ItemType>
string makeSubHeader(ItemType text)
{
	stringstream sStream;
	sStream << text;

	int dashesAmnt = PAGE_WIDTH - MARGIN_LEFT / 2 - (int)sStream.str().length();

	return makeLine(sStream.str() + ": " + string(dashesAmnt, '-'));
}

/** Format a string inside of quotes.
	@param text The line's context.
	@returns The string of text formatted accordingly. */
template <class ItemType>
string makeQuote(ItemType text)
{
	stringstream sStream;
	sStream << text;
	return "\"" + sStream.str() + "\"";
}

/** Converts a bool into a string ("True" or "False").
	@param b The bool to evaluate.
	@return "True" or "False" depending on outcome of
		argument evaluation. */
string boolToString(bool b, std::string success, std::string fail)
{
	return b ? success : fail;
}


/* Main. */
int main(void)
{
	cout << setprecision(FLOAT_PRECISION) << endl; // Setup



	auto numbers = std::make_unique<int[]>(25);
	numbers[4] = 5;

	auto matrix = std::make_unique<MatrixGraph<int>>();

	// Form graph
	matrix->add(4, 6, 1);		// 0-1
	matrix->add(4, 2, 1);		// 2
	matrix->add(6, 34, 1);		// 3
	matrix->add(34, 21, 1);		// 4
	matrix->add(2, 21, 1);
	matrix->add(21, 56, 1);		// 5
	matrix->add(34, 56, 1);
	matrix->add(21, 11, 1);		// 6
	matrix->add(56, 7, 1);		// 7
	matrix->add(56, 11, 1);
	matrix->add(11, 20, 1);		//8
	matrix->add(7, 61, 1);		// 9
	matrix->add(34, 5, 1);		// 10
	matrix->add(2, 5, 1);
	matrix->add(2, 30, 1);		// 11
	matrix->add(30, 27, 1);		// 12
	matrix->add(27, 78, 1);		// 13
	matrix->add(78, 82, 1);		// 14

	cout << endl << makeLine("Graph Num Vertices: ", matrix->getNumVertices()) << endl;
	cout << makeLine("Depth-First Ordering: ");

	matrix->depthFirstTraversal(20, [](int& i) {
		std::cout << i << " ";
		});


	// cout << endl << makeLine("Removing 7: ", boolToString(matrix->removeVertex(7), "Success", "Failed"));
	// cout << endl << makeLine("Removing 11: ", boolToString(matrix->removeVertex(11), "Success", "Failed"));
	// cout << endl << makeLine("Removing 5: ", boolToString(matrix->removeVertex(5), "Success", "Failed"));
	cout << endl << makeLine("Removing 34: ", boolToString(matrix->removeVertex(34), "Success", "Failed")) << endl;



	cout << makeLine("Depth-First Ordering: ");
	matrix->depthFirstTraversal(20, [](int& i) {
		std::cout << i << " ";
		});

	cout << endl << makeLine("Removing 5: ", boolToString(matrix->removeVertex(5), "Success", "Failed")) << endl;
	cout << makeLine("Depth-First Ordering: ");
	matrix->depthFirstTraversal(20, [](int& i) {
		std::cout << i << " ";
		});

	cout << endl << makeLine("Removing 1: ", boolToString(matrix->removeVertex(34), "Success", "Failed")) << endl;



	cout << endl << endl << endl << endl;
	return 0;
}



