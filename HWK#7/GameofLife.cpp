#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

class GameBoard{
private:
	vector<vector<int> > NowBoard;
	vector<vector<int> > FutureBoard;

	int numGenerations, printFrequency, r, c;
public:
	GameBoard(){}

	void loadGame(string path){
		ifstream f(path);

		f >> numGenerations >> printFrequency;
		f.ignore(1);
		int grid_size, zero = 0, one = 1;
		bool done = false;
		vector<int> f_row;
		string str;
		while(!f.eof()){
			vector<int> temp = vector<int>();
			getline(f, str);
			cout << str << endl;

			if(!done){
				grid_size = str.length();
				r = c = grid_size + 2;
				for(int i = 0; i < c; i++){
					f_row.push_back(zero);
				}
				NowBoard.push_back(f_row);
				done = true;
			}
			temp.push_back(0);
			for(int i = 1; i < c - 1; i++){
				if(str[i] == '*')
					temp.push_back(1);
				else
					temp.push_back(0);
			}
			temp.push_back(0);
			NowBoard.push_back(temp);
		}

		f.close();

		NowBoard.push_back(f_row);
		FutureBoard = NowBoard;

	}

	void update(){
		int r = NowBoard.size() - 1;
		int c = NowBoard[0].size() - 1;
		int judge;

		for(int i = 1; i < r; i++){
			for(int j = 1; j < c; j++){
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

} ;


int main(){
	ofstream f("gamefile.txt");
	int generations, freq;
	cout << "Enter total number of generations: ";
	cin >> generations;
	cout << "Enter print frequency: ";
	cin >> freq;
	f << generations << ' ' << freq;

	default_random_engine gen;
	uniform_int_distribution<int> seed(100, 101);
	bernoulli_distribution decisionDist(0.5);

	int size = seed(gen), s = 0;

	while(s < size){
		f << '\n';
		int count = 0;
		while(count < size){
			if(decisionDist(gen))
				f << '*';
			else
				f << '.';
			count++;
		}
		s++;
	}
	f.close();

	GameBoard g;
	g.loadGame("gamefile.txt");
	g.play();
	return 0;
}



