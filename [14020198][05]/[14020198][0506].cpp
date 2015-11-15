#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
#define MAX_SIZE 1000000
#define MAX_VALUE 10000
using namespace std;

int main(){
	int *a = new int[MAX_VALUE];
	for(int i = 0; i < MAX_VALUE; i++){
		a[i] = 0;
	}
	for(int i = 0; i < MAX_SIZE; i++){
		int temp;
		cin >> temp;
		a[temp - 1]++;
	}
	for(int i = 0; i < MAX_VALUE; i++){
		for(int j = 0; j < a[i]; j++){
			cout << i + 1 << " ";
		}
	}
}

