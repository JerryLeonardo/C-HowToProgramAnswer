#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int SIZE = 12;
 
// void printMap(vector< vector<char> > * const);
void printMap(char [][SIZE] * );

int main(){
	char mMap[SIZE][SIZE] = {
	  {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
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
	
	// vector< vector< char > > vvMap;
	// vvMap.resize(SIZE);
	// for(int i=0;i<SIZE;i++)
		// vvMap[i].resize(SIZE);
	
	// for(int i=0;i<SIZE;i++)
		// for(int j=0;j<SIZE;j++)
			// vvMap[i].push_back(mMap[i][j]);
	
	printMap(&mMap);
}

void printMap(char[][] * mPtr){
	for(int i=0;i<SIZE;i++){
		 for(int j=0;j<SIZE;j++)
			cout << mPtr[i][j];
}

// void printMap(vector< vector< char > > * const vPtr){
	// for(int i=0;i<SIZE;i++){
		// for(int j=0;j<SIZE;j++)
			// cout << (*vPtr).at(i).at(j);
			cout << mMap[i][j];
		// cout << "\n";
	// }
// }
