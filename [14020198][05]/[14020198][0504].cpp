#include <iostream>
#include <fstream>

#define MAX 50000
using namespace std;
void readFile(const char* fileName, int a[], int &size);
void showResult(int a[], int size);
void heapSort(int a[], int size);
void buildHeap(int a[], int size);
void heapify(int a[], int size, int parent);
void swap(int &a, int &b);

int main()
{
    int *a = new int[MAX];
    int size;
    readFile("numbers.txt", a, size);
    heapSort(a, size);
    showResult(a, size);
}


//void heapSort(int a[], int size){
//    buildHeap(a, size);
//    for(int i = size - 1; i > 0 ; i--){
//        swap(a[0], a[i]);
//        heapify(a, i, 0);
//    }
//}
//
//void buildHeap(int a[], int size){
//    for(int i = size/2 - 1; i >= 0; i--){
//        heapify(a, size, i);
//    }
//}
//void heapify(int a[], int size, int parent){
//    int child = parent*2 + 1;
//    while(child < size){
//        if(child + 1 < size && a[child + 1] > a[child]){
//            child++;
//        }
//        if(a[child] > a[parent]){
//            swap(a[child], a[parent]);
//        }
//        parent = child;
//        child = 2*parent + 1;
//    }
//}


void heapSort(int a[], int size){
    buildHeap(a, size);
    for(int i = size -1; i > 0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}


void buildHeap(int a[], int size){
    for(int i = size/2 - 1; i >=0; i--){
        heapify(a, size, i);
    }
}

void heapify(int a[], int size, int parent){
    int child = 2*parent + 1;
    while(child < size){
        if(child + 1 < size && a[child + 1] > a[child]) child ++;
        if(a[child] > a[parent]) swap(a[child], a[parent]);
        parent = child;
        child = 2*parent + 1;
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
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
