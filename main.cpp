/*
CS211 Assignment 4

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

void initialize(bool gridA[][m]) {
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

void initializeRandom(bool gridA[][m]) {
	srand(time(0));

	int den;
	cout << "What is the density?" << endl;
	cin >> den;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			gridA[i][j] = false;
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
*/
int calcN(const int a, const int b, bool gridA[][m]) {
	int sum = 0;
	int overA = 100, underA = 100;
	int overB = 100, underB = 100;

	if (a + 1 == 10) {
		overA = 0;
	}
	else if (a - 1 == -1) {
		underA = 9;
	}
	else if (b + 1 == 10) {
		overB = 0;
	}
	else if (b - 1 == -1) {
		underB = 9;
	}

	if (overA == 100 && underA == 100 && overB == 100 && underB == 100) {
		for (int i = a - 1; i <= a + 1; i++) {
			for (int j = b - 1; j <= b + 1; j++) {
				if (gridA[i][j] == true && i != a && j != b) {
					sum++;
				}
			}
		}
	}
	else if (overA == 0 && underA == 100 && overB == 100 && underB == 100) {
		//1000
		//8,9,0->a
		for (int i = a - 1; i <= a; i++) {
			for (int j = b - 1; j <= b + 1; j++) {
				if (gridA[i][j] == true && i != a && j != b) {
					sum++;
				}
			}
		}
		for (int j = b - 1; j <= b + 1; j++) {
			int i = 0;
			if (gridA[i][j] == true && i != a && j != b) {
				sum++;
			}
		}
	}
	else if (overA == 100 && underA == 9 && overB == 100 && underB == 100) {
		//0100
		//9,0,1->a
		for (int i = a; i <= a + 1; i++) {
			for (int j = b - 1; j <= b + 1; j++) {
				if (gridA[i][j] == true && i != a && j != b) {
					sum++;
				}
			}
		}
		for (int j = b - 1; j <= b + 1; j++) {
			int i = 9;
			if (gridA[i][j] == true && i != a && j != b) {
				sum++;
			}
		}
	}
	else if (overA == 100 && underA == 100 && overB == 0 && underB == 100) {
		//0010
		//8,9,0->b
		for (int i = a - 1; i <= a + 1; i++) {
			for (int j = b - 1; j <= b; j++) {
				if (gridA[i][j] == true && i != a && j != b) {
					sum++;
				}
			}
		}
		for (int i = a - 1; i <= a + 1; i++) {
			int j = 0;
			if (gridA[i][j] == true && i != a && j != b) {
				sum++;
			}
		}
	}
	else if (overA == 100 && underA == 100 && overB == 100 && underB == 9) {
		//0001
		//9,0,1
		for (int i = a - 1; i <= a + 1; i++) {
			for (int j = b; j <= b + 1; j++) {
				if (gridA[i][j] == true && i != a && j != b) {
					sum++;
				}
			}
		}
		for (int i = a - 1; i <= a + 1; i++) {
			int j = 9;
			if (gridA[i][j] == true && i != a && j != b) {
				sum++;
			}
		}
	}
	else if (overA == 0 && underA == 100 && overB == 0 && underB == 100) {
		//1010
	}

	else if (overA == 0 && underA == 100 && overB == 100 && underB == 9) {
		//1001
	}
	else if (overA == 100 && underA == 9 && overB == 100 && underB == 9) {
		//0101
	}
	else if (overA == 100 && underA == 9 && overB == 0 && underB == 100) {
		//0110
	}

	/*
	in a normal case were 0 > a--/a++ or b--/b++ > 10
	if(gridAlive[a-1][b-1] == true)
	sum++;
	else if(gridAlive[a-1][b] == true)
	sum++;
	a--,b
	else if(gridAlive[a-1][b+1] == true)
	sum++;
	a--,b++
	else if(gridAlive[a][b-1] == true)
	sum++;
	a,b--
	a,b-> no need to check
	else if(gridAlive[a][b+1] == true)
	sum++;
	a,b++
	else if(gridAlive[a+1][b-1] == true)
	sum++;
	a++,b--
	else if(gridAlive[a+1][b] == true)
	sum++;
	a++,b
	else if(gridAlive[a+1][b+1] == true)
	sum++;
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
void generateCell(int gridN[][m], bool gridA[][m]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int neighbor = calcN(i, j, gridA);
			/*
			reset gridN[i][j]= 0;

			if gridAlive[i][j] == true
			gridN[i][j] = neighbor;
			else // when gridAlive = false
			grid[i][j] = neighbor + 100;
			*/

		}
	}
}

//
void newGen(int gridN[][m], bool gridA[][m]) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			/*
			reset gridAlive[i][j] = false
			if(gridN[i][j]== 103 || gridN[i][j] == 2 || gridN[i][j] == 3)
			gridAlive[i][j] = true;

			*/
		}
	}


}

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

int main() {

	bool gridAlive[m][n];
	int gridN[m][n];

	bool valid = false;

	char inp;
	cout << "How do you want to setup the grid?" << endl;
	cout << "A. manual input" << endl;
	cout << "B. random generation" << endl;
	cout << "Enter your choice:" << endl;
	cin >> inp;

	switch (inp)
	{
	case 'A': case 'a':
		initialize(gridAlive);
		valid = true;
		break;
	case 'B': case 'b':
		initializeRandom(gridAlive);
		valid = true;
		break;
	default:
		cout << "Wrong choice\nGood Bye" << endl;
		break;
	}

	if (valid) {
		print(gridAlive);
		cout << "Total population is " << population(gridAlive) << endl;
	}


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

