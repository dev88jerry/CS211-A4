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
			//gridAlive[i][j] = false;
			int randN = (rand() % 100) + 1;
			if (randN <= den) {
				//populate cell
				/*
				gridAlive[i][j] = true;
				*/
				
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
void generateCell() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {			
			int neighbor = calcN(i, j);
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
void newGen(){
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			/*
			reset gridAlive[i][j] = false
			if(gridN[i][j]== 103 || gridN[i][j] == 2 || gridN[i][j] == 3)
				gridAlive[i][j] = true;
			
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
	int gridN[n][m];
	
	
	
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
