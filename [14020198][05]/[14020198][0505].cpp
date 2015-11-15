#include <iostream>
#include <fstream>

#define MAX 50000

using namespace std;

void readFile(const char* fileName, int a[], int &size);
void showResult(int a[], int size);
void mergeSort(int a[], int left, int right);
void merge(int a[], int left, int mid, int right);

int main()
{
    int *a = new int[MAX];
    int size;
    readFile("numbers.txt", a, size);
    mergeSort(a, 0, size - 1);
    showResult(a, size);
}


//void mergeSort(int a[], int left, int right){
//    int mid = (left + right)/2;
//    if(left < right){
//        mergeSort(a, left, mid);
//        mergeSort(a, mid + 1, right);
//        merge(a, left, mid, right);
//    }
//}
//
//void merge(int a[], int left, int mid, int right){
//    int left1 = left, right1 = mid, left2 = mid + 1, right2 = right;
//    int *p = new int[right - left + 1];
//    int k = 0;
//    while(left1 <= right1 && left2 <= right2){
//        if(a[left1] < a[left2]){
//            p[k++] = a[left1++];
//        }else{
//            p[k++] = a[left2++];
//        }
//    }
//    while(left2 <= right2){
//        p[k++] = a[left2++];
//    }
//    while(left1 <= right1){
//        p[k++] = a[left1++];
//    }
//    k = 0;
//    for(int i = left; i <= right; i++){
//        a[i] = p[k++];
//    }
//}

void mergeSort(int a[], int left, int right){
    int mid = (left + right)/2;
    if(left < right){
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}


void merge(int a[], int left, int mid, int right){
    int left1 = left;
    int right1 = mid;
    int left2 = mid + 1;
    int right2 = right;
    int *p = new int[right - left + 1];
    int k = 0;
    while(left1 <= right1 && left2 <= right2){
        if(a[left1] < a[left2]){
            p[k] = a[left1];
            k++;
            left1++;
        } else{
            p[k] = a[left2];
            left2++;
            k++;
        }
    }
    while(left1 <= right1){
        p[k] = a[left1];
        left1++;
        k++;
    }
    while(left2 <= right2){
        p[k] = a[left2];
        left2++;
        k++;
    }
    k = 0;
    for(int i = left; i<= right; i++){
        a[i] = p[k];
        k++;
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
