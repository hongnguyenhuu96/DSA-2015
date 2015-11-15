#include <iostream>
#include <fstream>

#define MAX 5000
using namespace std;
void readFile(const char* fileName, int a[], int &size);
void insertionSort(int a[], int size);
void showResult(int a[], int size);

int main()
{
    int *a = new int[MAX];
    int size;
    readFile("numbers.txt", a, size);
    insertionSort(a, size);
    showResult(a, size);
}

void insertionSort(int a[], int size){
    for(int i = 1; i < size; i++){
        int j = i - 1;
        int temp = a[i];
        while(j >= 0 && temp < a[j]){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void readFile(const char* fileName, int a[], int &size){
    ifstream file(fileName);
    int i = 0;
    while(!file.eof()){
        file >> a[i];
        if(file){
            i++;
        }
    }
    size = i;
}

void showResult(int a[], int size){
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}
