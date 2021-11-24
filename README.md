# CS211-A4

The Game of Life - [John Conway's Game of life](https://playgameoflife.com/info)

## Setup:

A population is represented by a n x m two-dimensional array of cells, each cell being in one of two different states: alive or dead.

Each cell has 8 neighbouring cells surrounding it, and the next generation of cells is generated according to the following rules:

1.	Any live cell with fewer than 2 live neighbours dies, as if caused by under-population.
2.	Any live cell with more than 3 live neighbours dies, as if by overcrowding.
3.	Any live cell with 2 or 3 live neighbours lives on to the next generation.
4.	Any dead cell with exactly 3 live neighbours becomes a live cell, as if by reproduction.

You are asked to write a program to simulate the game of life.

### Biggest change

All cells have 8 neighbours, even the ones on the border. For this purpose, the 2-dim array is considered as if it was wrapped around, or a sort of sphere. 

### Programming 

1.	The actual size of the population (n and m), as well as the maximum number of generations, can either be declared as global constants, or entered by the user and passed as parameters to various functions (in which case the capacity of the array has to be declared as a global constant). 

2.	The array’s entries can be either of type int, char or bool. 

3.	The program has to display the initial population, and the population after each generation (giving the generation number, starting from 1), until either the whole population dies, or until you reach the max number of generations.

4.	Bonus marks will be added if the execution stops if the population reaches a stable state. 

5.	Please include two alternative techniques to initialize the population. In the first one, the cells are entered one after the other by the user, as a sequence of characters (‘0’ for dead and ‘1’ for live). In the second one, the cells are generated randomly, according to a given density. For example, if the required density is 30%, then for each cell a random number between 1..100 is generated. If the number is <=30, the cell is alive, otherwise the cell is dead. When marking the assignments, we will choose one or the other of the initialization techniques.
