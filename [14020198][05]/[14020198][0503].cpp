#include <iostream>
#include <fstream>
#include <conio.h>

#define MAX 50000
using namespace std;
void readFile(const char* fileName, int a[], int &size);
void quickSort(int a[], int left, int right);
void showResult(int a[], int size);



void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


//int partition(int a[], int left, int right){
////    swap(a[left], a[(left + right)/2]);
//    int pivot = a[left];
//    int i = left + 1;
//    int j = right;
//    do{
//        while(i <= j && a[i] < pivot) i++;
//        while(i <= j && a[j] >= pivot) j--;
//        if(i < j){
//            swap(a[i], a[j]);
//            i++;
//            j--;
//        }
//    }while(i <= j);
//    swap(a[left], a[j]);
//    return j;
//}
//void quickSort(int a[], int left, int right){
//    if(left < right){
//        int k = partition(a, left, right);
//        quickSort(a, left, k - 1);
//        quickSort(a, k + 1, right);
//    }
//}


int partition(int a[], int left, int right){
    int pivot = a[left];
    int i = left + 1;
    int j = right;
    while(i <= j){
        while(i <= j && a[i] <= pivot) i++;
        while(i <= j && a[j] > pivot) j--;
        if(i < j){
            swap(a[i], a[j]);
                i++;
                j--;
        }
    }
    swap(a[left], a[j]);
    return j;
}

void quickSort(int a[], int left, int right){
    if(left < right){
        int k = partition(a, left, right);
        quickSort(a, left, k - 1);
        quickSort(a, k + 1, right);
    }
}




int main()
{
    int *a = new int[MAX];
    int size;
    readFile("numbers.txt", a, size);
    quickSort(a, 0, size -1);
    showResult(a, size);
}

//void quickSort(int a[], int left, int right) {
//      int i = left, j = right;
//      float temp;
//      float pivot = a[(left + right) / 2];
//
//      while (i <= j) {
//            while (a[i] < pivot)
//                  i++;
//            while (a[j] > pivot)
//                  j--;
//            if (i <= j) {
//                  temp = a[i];
//                  a[i] = a[j];
//                  a[j] = temp;
//                  i++;
//                  j--;
//            }
//      };
//      if (left < j)
//            quickSort(a, left, j);
//      if (i < right)
//            quickSort(a, i, right);
//}


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
