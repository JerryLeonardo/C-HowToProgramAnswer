#include <iostream>
using namespace std;

const int SIZE = 12;
enum Directions {DOWN, RIGHT, UP, LEFT};

void mazeTraversal(char[][SIZE], const int, const int, int, int, int);
void printMaze(const char[][SIZE]);
bool validMove(const char[][SIZE], int, int);
bool coordsAreEdge(int, int);

int main(){
	char maze[SIZE][SIZE] = 
	{ {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
      {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
      {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
      {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
      {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
      {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
      {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
      {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
      {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
      {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
      {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
      {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };
	
	int startX = 2;
	int startY = 0;
	int x= startX;
	int y= startY;
	
	mazeTraversal(maze, startX, startY, x, y, RIGHT);
}

void mazeTraversal(char maze[][SIZE] , const int startX, const int startY, 
					int coordX, int coordY, int direction){
						
	static bool flag = false;	//record wether we can move
	maze[coordX][coordY] = 'X';
	printMaze(maze);
	
	if(coordsAreEdge(coordX, coordY) && coordX != startX && coordY != startY){
		cout << "We find the exit!" << endl;
		return;
	}else if(coordX == startX && coordY == startY && flag == true){
		cout << "we return to the starting point, seem we can not find the exit!" << endl;
		return;
	}else{
		flag = true;
		
		for(int move = direction, count = 0; count < 4; ++move, ++count, move %= 4){
			switch(move){
				case DOWN:
					if(validMove(maze,coordX+1,coordY)){
						mazeTraversal(maze, startX,startY, coordX+1, coordY, LEFT);
						return;
					}
					break;
				case RIGHT:
					if(validMove(maze,coordX,coordY+1) == true){
						mazeTraversal(maze, startX,startY, coordX, coordY+1, DOWN);
						return;
					}
					break;
				case UP:
					if(validMove(maze,coordX-1,coordY) == true){
						mazeTraversal(maze, startX,startY, coordX-1, coordY, RIGHT);
						return;
					}
					break;
				case LEFT:
					if(validMove(maze,coordX,coordY-1) == true){
						mazeTraversal(maze, startX,startY, coordX, coordY-1, UP);
						return;
					}
					break;
			}
		}
	}
}

void printMaze(const char maze[][SIZE]){
	for(int i=0; i < SIZE;++i){
		for(int j=0; j<SIZE;++j){
			cout << maze[i][j] << ' ';
		}
		cout << "\n";
	}
	cout << "\nHit return to see next move\n";
	cin.get();
}

bool validMove(const char maze[][SIZE] , int x,int y){
	if(maze[x][y] != '#' && x>=0 && x <= SIZE-1 && y >= 0 && y <= SIZE -1){
		return true;
	}else
		return false;
}

bool coordsAreEdge(int x, int y){
	if(x == 0 || x == SIZE-1 || y == 0 || y == SIZE-1){
		return true;
	}else
		return false;
}