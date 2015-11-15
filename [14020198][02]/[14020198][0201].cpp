#include <iostream>
#include <fstream>

using namespace std;

int readFile(const char* fileName, int a[]);
long sum(int a[], int size);
int smallest(int a[], int size);
int greatest(int a[], int size);
void deleteOddNum(int a[], int &size);
void deleteOne(int a[], int i, int &size);

int main(){
    int a[1000];
    int size = readFile("numbers.txt", a);
    cout << sum(a, size) << endl;
    cout << smallest(a, size) << endl;
    cout << greatest(a, size) << endl;
    deleteOddNum(a, size);
}

int readFile(const char* fileName, int a[]){
    int i = 0;
    ifstream file(fileName);
    while(!file.eof()){
        file >> a[i];
        if(file){
            i++;
        }
    }
    return i;
}

long sum(int a[], int size){
    int sum = 0;
    for(int i = 0; i< size; i++){
        sum += a[i];
    }
    return sum;
}

int smallest(int a[], int size){
    int smallest = a[0];
    for(int i = 1; i < size; i++){
        if(a[i] < smallest){
            smallest = a[i];
        }
    }
    return smallest;
}

int greatest(int a[], int size){
    int greatest = a[0];
    for(int i = 1; i < size; i++){
        if(a[i] > greatest){
            greatest = a[i];
        }
    }
    return greatest;
}

void deleteOddNum(int a[], int &size){
    for(int i = 0; i< size; i++){
        if(a[i] % 2 != 0){
            deleteOne(a, i, size);
            i--;
        }
    }
    for(int i = 0; i< size; i ++){
        cout << a[i] << " ";
    }
}

void deleteOne(int a[], int i, int &size){
    for(int j = i; j < size - 1; j++){
        a[j] = a[j + 1];
    }
    size --;
}
