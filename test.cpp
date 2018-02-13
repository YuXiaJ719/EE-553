#include <iostream>
#include <string>
using namespace std;

int main(){
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	
	int (&ref)[10] = arr;

	for(int i = 0; i < 10; i++){
		arr[i] += 1;
	}

	for(auto r: arr){
		cout << r << endl;
	}
}