#include <iostream>
#include <random>
#include <fstream>
using namespace std;

int main(){
	ofstream f("gamefile.txt");

	f << 1000 << ' ' << 3;
	default_random_engine gen;
	uniform_int_distribution<int> seed(50, 60);
	bernoulli_distribution decisionDist(0.6);

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
}