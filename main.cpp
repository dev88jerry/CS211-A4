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
#include <cmath>

using namespace std;

// Global constants
const int MAXGEN = 100; // maximum no. of generations
const int n = 10;    // no. of rows 
const int m = 10;    // no. of colums

void initialize(bool gridA[][m], bool gridB[][m]) {

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			gridA[i][j] = false;
			gridB[i][j] = false;
		}
	}

	int alive;
	cout << "Enter the total cells that are alive" << endl;
	cin >> alive;

	for (int i = 0; i < alive; i++) {
		int x, y;
		do {
			cout << "The value must be between 0 and 9" << endl;
			cout << "What is the coordinate for the cell in X?" << endl;
			cin >> x;
			cout << "What is the coordinate for the cell in y?" << endl;
			cin >> y;
			cout << i + 1 << " cell entered" << endl;
		} while ((x < 0 || x >= 10) && (y < 0 || y >= 10));
		gridA[x][y] = true;
	}

}

void initializeRandom(bool gridA[][m], bool gridB[][m]) {
	srand(time(0));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			gridA[i][j] = false;
			gridB[i][j] = false;
		}
	}

	int den;
	cout << "What is the density?" << endl;
	cin >> den;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			gridA[i][j] = false;
			gridB[i][j] = false;
			int randN = (rand() % 100) + 1;
			if (randN <= den) {
				//populate cell				
				gridA[i][j] = true;
			}
		}
	}
}


/*
check the 9 tile for a given cell location
returns the number of neighbors

use mod to ensure values are in our conditions
*/
int calcN(const int a, const int b, bool gridA[][m]) {
	int sum = 0;
	
	
	for (int i = a - 1; i <= a + 1; i++) {
		for (int j = b - 1; j <= b + 1; j++) {
			if (i == -1 && j == -1) {
				if (gridA[m - 1][n - 1] == true)
					sum++;
			}
			else if (i == -1) {
				if (gridA[m - 1][j%n] == true)
					sum++;
			}
			else if (j == -1) {
				if (gridA[i%n][n - 1] == true)
					sum++;
			}
			else if (gridA[i%m][j%n] == true && (i != a || j != b)) {
				sum++;
			}
				
		}
	}
	

	/*
	int overA = 100, underA = 100;
	int overB = 100, underB = 100;
	//check overflow condition for a,b
	if (a + 1 == 10) {
		overA = 0;
	}
	else if (a - 1 == -1) {
		underA = 9;
	}
	
	if (b + 1 == 10) {
		overB = 0;
	}
	else if (b - 1 == -1) {
		underB = 9;
	}

	//no overflow option
	if (overA == 100 && underA == 100 && overB == 100 && underB == 100) {
		for (int i = a - 1; i <= a + 1; i++) {
			for (int j = b - 1; j <= b + 1; j++) {
				if (gridA[i][j] == true && (i != a || j != b)) {
					sum++;
				}
			}
		}
	}
	//a over
	else if (overA == 0 && underA == 100 && overB == 100 && underB == 100) {
		//1000
		//8,9,0->a
		for (int i = a - 1; i <= a; i++) {
			for (int j = b - 1; j <= b + 1; j++) {
				if (gridA[i][j] == true && (i != a || j != b)) {
					sum++;
				}
			}
		}
		for (int j = b - 1; j <= b + 1; j++) {
			int i = overA;
			if (gridA[i][j] == true && (i != a || j != b)) {
				sum++;
			}
		}
	}
	//a under
	else if (overA == 100 && underA == 9 && overB == 100 && underB == 100) {
		//0100
		//9,0,1->a
		for (int i = a; i <= a + 1; i++) {
			for (int j = b - 1; j <= b + 1; j++) {
				if (gridA[i][j] == true && (i != a || j != b)) {
					sum++;
				}
			}
		}
		for (int j = b - 1; j <= b + 1; j++) {
			int i = underA;
			if (gridA[i][j] == true && (i != a || j != b)) {
				sum++;
			}
		}
	}
	//b overflow
	else if (overA == 100 && underA == 100 && overB == 0 && underB == 100) {
		//0010
		//8,9,0->b
		for (int i = a - 1; i <= a + 1; i++) {
			for (int j = b - 1; j <= b; j++) {
				if (gridA[i][j] == true && (i != a || j != b)) {
					sum++;
				}
			}
		}
		for (int i = a - 1; i <= a + 1; i++) {
			int j = overB;
			if (gridA[i][j] == true && (i != a || j != b)) {
				sum++;
			}
		}
	}
	//b under
	else if (overA == 100 && underA == 100 && overB == 100 && underB == 9) {
		//0001
		//9,0,1
		for (int i = a - 1; i <= a + 1; i++) {
			for (int j = b; j <= b + 1; j++) {
				if (gridA[i][j] == true && (i != a || j != b)) {
					sum++;
				}
			}
		}
		for (int i = a - 1; i <= a + 1; i++) {
			int j = underB;
			if (gridA[i][j] == true && (i != a || j != b)) {
				sum++;
			}
		}
	}
	// a&b over
	else if (overA == 0 && underA == 100 && overB == 0 && underB == 100) {
		//1010
		//8,9,0->a
		//8,9,0->b

		for (int i = a - 1; i <= a + 1; i++) {
			for (int j = b - 1; j <= b + 1; j++) {
				if (j == 10 && i == 10) {
					if (gridA[overA][overB] == true)
						sum++;
				}
				else if (i == 10 && j != 10) {
					if (gridA[overA][j] == true)
						sum++;
				}
				else if (j == 10 && i != 10) {
					if (gridA[i][overB] == true)
						sum++;
				}
				else {
					if (gridA[i][j] == true && (i != a || j != b))
						sum++;
				}

			}

		}
	}
	//a over, b under
	else if (overA == 0 && underA == 100 && overB == 100 && underB == 9) {
		//1001
		//8,9,0->a
		//9,0,1->b
		for (int i = a - 1; i <= a + 1; i++) {
			if (i == 10) {
				for (int j = b - 1; j <= b + 1; j++) {
					if (j == -1) {
						if (gridA[overA][underB] == true)
							sum++;
					}
					else {
						if (gridA[overA][j] == true)
							sum++;
					}
				}
			}
			else {
				for (int j = b - 1; j <= b + 1; j++) {
					if (j == -1) {
						if (gridA[i][underB] == true)
							sum++;
					}
					else {
						if (gridA[i][j] == true && (i != a || j != b))
							sum++;
					}
				}
			}
		}
	}
	//a&b under
	else if (overA == 100 && underA == 9 && overB == 100 && underB == 9) {
		//0101
		//9,0,1->a
		//9,0,1->b

		//9,9->9,0->9,1
		//0,9->0,0->0,1
		//1,9->1,0->1,1

		for (int i = a - 1; i <= a + 1; i++) {
			if (i == -1) {
				for (int j = b - 1; j <= b + 1; j++) {
					if (j == -1) {
						if (gridA[underA][underB] == true)
							sum++;
					}
					else {
						if (gridA[underA][j] == true)
							sum++;
					}
				}
			}
			else {
				for (int j = b - 1; j <= b + 1; j++) {
					if (j == -1) {
						if (gridA[i][underB] == true)
							sum++;
					}
					else {
						if (gridA[i][j] == true && (i != a || j != b))
							sum++;
					}
				}
			}
		}
	}
	//a under, b over
	else if (overA == 100 && underA == 9 && overB == 0 && underB == 100) {
		//0110
		//9,0,1->a
		//8,9,0->b
		for (int i = a - 1; i <= a + 1; i++) {
			if (i == -1) {
				for (int j = b - 1; j <= b + 1; j++) {
					if (j == 10) {
						if (gridA[underA][overB] == true)
							sum++;
					}
					else {
						if (gridA[underA][j] == true)
							sum++;
					}
				}
			}
			else {
				for (int j = b - 1; j <= b + 1; j++) {
					if (j == 10) {
						if (gridA[i][overB] == true)
							sum++;
					}
					else {
						if (gridA[i][j] == true && (i != a || j != b))
							sum++;
					}
				}
			}
		}
	}
	*/
	return sum;
}

//function to print the neighbor values for grid
//useful for debuging
void printN(int grid[][m]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << grid[i][j] << " , ";
		}
		cout << endl;
	}
}

//function to calculate the neighbor value of each cell
void generateCell(int gridN[][m], bool gridA[][m]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int neighbor = calcN(i, j, gridA);
			gridN[i][j] = 0;
			if (gridA[i][j] == true)
				gridN[i][j] = neighbor;
			else
				gridN[i][j] = neighbor + 100;
		}
	}
	//printN(gridN);
}

//function to create next generation with values of generated cells
void newGen(int gridN[][m], bool gridA[][m]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			gridA[i][j] = false;
			if (gridN[i][j] == 103 || gridN[i][j] == 2 || gridN[i][j] == 3)
				gridA[i][j] = true;

		}
	}
}

//function to calculate the population in the given 2D array
int population(bool gridA[][m]) {
	int pop = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (gridA[i][j] == true)
				pop++;
		}
	}

	return pop;
}

//function to print the grid 
void print(bool gridA[][m]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (gridA[i][j] == true)
				cout << "X ";
			else
				cout << "_ ";
		}
		cout << endl;
	}
}

//function to check if all cells are dead
bool allDead(bool gridA[][m]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (gridA[i][j] == true)
				return false;
		}
	}
	return true;
}

//function to check if prev generation = next generation
bool sameGrid(bool gridGen1[][m], bool gridGen2[][m]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (gridGen1[i][j] != gridGen2[i][j])
				return false;
		}
	}
	return true;
}

//function to copy prev grid to compare
void copyGrid(bool a[][m], bool b[][m]) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			b[i][j] = a[i][j];
		}
	}
}


int main() {

	bool gridAlive[m][n];
	bool gridPrev[m][n];
	int gridN[m][n];
	int gridPop[MAXGEN];

	bool valid = false;

	char inp;
	//prompt user to enter values.
	cout << "How do you want to setup the grid?" << endl;
	cout << "A. manual input" << endl;
	cout << "B. random generation" << endl;
	cout << "Enter your choice:" << endl;
	cin >> inp;

	switch (tolower(inp))
	{
	case 'a':
		initialize(gridAlive, gridPrev);
		valid = true;
		break;
	case 'b':
		initializeRandom(gridAlive, gridPrev);
		valid = true;
		break;
	default:
		cout << "Wrong choice\nGood Bye" << endl;
		break;
	}

	int gen = 0;

	//main loop to run the game
	
	while (valid) {
		cout << "This is generation " << gen << endl;
		print(gridAlive);
		int prevPop = population(gridAlive);
		gridPop[gen] = prevPop;
		cout << "Total population is " << prevPop << endl;
		copyGrid(gridAlive, gridPrev);
		generateCell(gridN, gridAlive);
		newGen(gridN, gridAlive);
		if (gen == MAXGEN) {
			valid = false;
		}
		else if (allDead(gridPrev)) {
			valid = false;
			cout << "All dead at generation " << gen + 1 << endl;
		}
		else if (sameGrid(gridAlive, gridPrev)) {
			valid = false;
			cout << "Grid is stable at " << gen + 1 << endl;
			print(gridAlive);
		}
		else if (gen > 4) {
			if (gridPop[gen - 3] == gridPop[gen - 2] && gridPop[gen - 2] == gridPop[gen - 1] && gridPop[gen - 1] == gridPop[gen]) {
				valid = false;
				cout << "Population stable at generation " << gen - 3 << endl;
				cout << "Population of the previous 3 generations is " << population(gridAlive) << endl;
			}
		}
		
		gen++;
		cout << endl;
	}
		
	system("Pause");

	return 0;
}

