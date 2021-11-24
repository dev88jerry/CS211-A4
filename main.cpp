/*
CS211 Assignment 4
Program simulates Conway's Game of Life
All cells should have 8 neighbours, even the ones on the border. For this purpose, the 2-dim array is considered as if it was wrapped around, or a sort of sphere.
*/

#include <iostream>
#include <string>

using namespace std;

// Global constants
const int MAXGEN = 3; // maximum no. of generations
const int n = 10;    // no. of rows 
const int m = 10;    // no. of colums

int main() {
	int grid[n][m];
	
	/*
	initialize(grid);     // you should call either initialize, or initialize2
	cout << "Initial population = \n";
	print(grid);
	gen = 1;
	print(grid);
	while (gen <= MAXGEN && !allDead(grid)) {
		cout << "gen = " << gen;
		reproduce(grid);    // will call the function countNeighbours for each cell
		print(grid);
		gen++;
	}
	*/


	system("Pause");

	return 0;
}
