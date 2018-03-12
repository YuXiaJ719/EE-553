#include <iostream>
using namespace std;


class PointerPractice{
private:
	char a[40][50];

public:
	PointerPractice(){		
	}

	void fillWithZero(){
		for(int i = 0;i < 40; i++){
			for(int j = 0; j < 50; j++)
				a[i][j] = '0';
		}
	}

	void print(){
		char (*p)[50];
		p = a;
		for(;p < a + 40; p++){
			for(int j = 0; j < 50; j++)
				cout << (*p)[j] << " ";
			cout << '\n';
		}
	}

	void setRow(int rowIndex, char c){
		char *p = a[rowIndex];
		for(; p < a[rowIndex] + 50; p++)
			*p = c;
	}
};


int main() {
  PointerPractice p; // create the object containing the 2d array
  p.fillWithZero();
  p.print();
  p.setRow(4, '1'); // set every element in row 4 to the letter 1
  p.print(); // print again.
}