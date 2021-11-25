/*
CS211 Assignment 4
Dec 12 2021

Program simulates Conway's Game of Life

All cells should have 8 neighbours, even the ones on the border. For this purpose, the 2-dim array is considered as if it was wrapped around, or a sort of sphere.

bool gridAlive to determine the living cells
int gridN to determine the neighbours
if(gridN[i][j] == 2 or 3) -> populate gridAlive[i][j] = 1
else gridN[i][j] == 1 or 4 -> gridAlive[i][j] = 0

*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// Global constants
const int MAXGEN = 3; // maximum no. of generations
const int n = 10;    // no. of rows 
const int m = 10;    // no. of colums

void initialize() {

}

void initializeRandom() {
	srand(time(0));

	int den;
	cout << "What is the density?" << endl;
	cin >> den;	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int randN = (rand() % 100) + 1;
			if (randN <= den) {
				//populate cell
			}
		}
	}
	
}


/*
check the 9 tile for a given cell location
returns the number of neighbors
*/
int calcN(int a, int b) {
	int sum = 0;
	
	/*
	in a normal case were 0 > a--/a++ or b--/b++ > 10
	a--,b--
	a--,b
	a--,b++
	a,b--
	a,b-> no need to check
	a,b++
	a++,b--
	a++,b
	a++,b++
	
	if a-- or b-- < 0
	set a,b = 9

	if a++ or b++ == 10
	set a,b = 0

	after each condition, if gridAlive == true sum++	
	*/
	
	return sum;
}

//
void generateCell() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {			
			int neighbor = calcN(i, j);
			/*
			if gridAlive[i][j] == true 
				if neigbhor == 1 ||  > 3
					gridAlive[i][j] = false
			else // when gridAlive = false
				if neigbhor == 3			
					gridAlive[i][j] = true
			*/

		}		
	}


}

int population() {
	int pop = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//if(gridA == true)
				pop++;

		}
		
	}

	return pop;
}


void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << " ";

		}
		cout << endl;
	}
}

int main() {
	
	bool gridAlive[n][m];	
	
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
