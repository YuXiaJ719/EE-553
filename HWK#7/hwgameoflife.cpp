/*
	Author: Yu Xia
	Date: 02/27/2018
	Reference: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life (Rules)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

class GameBoard{
private:
	vector<vector<int> > NowBoard; // store current state of board
	vector<vector<int> > FutureBoard; // for updating

	int numGenerations, printFrequency, r, c, grid_size;
public:
	GameBoard(){}

	void loadGame(string path){
		ifstream f(path);
		f >> numGenerations >> printFrequency;
		f.ignore(1);
		bool done = false;
		
		// declare the first row and last row of game board.
		vector<int> f_row;

		// string store the initial layout of board.
		string str;
		
		while(!f.eof()){
			vector<int> temp = vector<int>();
			getline(f, str);

			if(!done){
				grid_size = str.length(); // get the size of board
				r = c = grid_size + 2; // the number of rows and columns of board
				
				for(int i = 0; i < c; i++){
					f_row.push_back(0);
				}
				NowBoard.push_back(f_row);
				done = true;
			}

			for(int i = 0; i < c; i++){
				if(str[i] == '*' && i != 0 && i != c - 1)
					temp.push_back(1);
				else
					temp.push_back(0);
			}
			NowBoard.push_back(temp);
		}

		NowBoard.push_back(f_row);
		FutureBoard = NowBoard;
		f.close();
	}

	void update(){
		int judge;
		for(int i = 1; i < r - 1; i++){
			for(int j = 1; j < c - 1; j++){
				judge = NowBoard[i - 1][j - 1] + NowBoard[i][j - 1] + NowBoard[i - 1][j] + 
						NowBoard[i+1][j+1] + NowBoard[i+1][j] + NowBoard[i][j + 1] 
						+ NowBoard[i - 1][j + 1] + NowBoard[i + 1][j - 1];

				if(NowBoard[i][j] == 1 && judge < 2)
					FutureBoard[i][j] = 0;
				else if(NowBoard[i][j] == 1 && judge > 3)
					FutureBoard[i][j] = 0;
				else if(NowBoard[i][j] == 0 && judge == 3)
					FutureBoard[i][j] = 1;
			}
		}
		NowBoard = FutureBoard;
	}

	void showBoard(){
		for(int i = 1; i < r - 1; i++){
			for(int j = 1; j < c - 1; j++){
				if(NowBoard[i][j] == 1)
					cout << '*';
				else
					cout << '.';
			}
			cout << '\n';
		}
	}

	void play(){
		for(int i = 0; i < numGenerations; i++){
			update();
			if(i % printFrequency == 0){
				system("clear");
				showBoard();
			}
			usleep(20000);
		}
	}

};


int main(){
	GameBoard g;
	g.loadGame("hw3b.dat");
	g.play();
	return 0;
}



