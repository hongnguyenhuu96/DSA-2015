#include <iostream>
#include <fstream>

#define MAX 5000

using namespace std;
void readFile(const char* fileName, int a[], int &size);
void bubbleSort(int a[], int size);
void showResult(int a[], int size);

int main()
{
    int *a = new int[MAX];
    int size;
    readFile("numbers.txt", a, size);
    bubbleSort(a, size);
    showResult(a, size);
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
//void bubbleSort(int a[], int size){
//    int j = 0;
//    while(j < size){
//        for(int i = size - 1; i > j; i--){
//            if(a[i] < a[i - 1]){
//                int temp = a[i];
//                a[i] = a[i - 1];
//                a[i - 1] = temp;
//            }
//        }
//        j++;
//    }
//}


void bubbleSort(int a[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void showResult(int a[], int size){
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}
