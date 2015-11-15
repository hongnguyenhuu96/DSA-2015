#include <iostream>
#include <iomanip>
using namespace std;
//Given 5 real numbers, write a C++ program
//to calculate the sum of the greatest and smallest numbers.
float sumGS(float a[], int size);
int main()
{
    float a[5];
    for(int i = 0; i < 5; i++){
        cin >> a[i];
    }
    cout << fixed << setprecision(3) << sumGS(a,5);
}

float sumGS(float a[], int size){
    float greatest, smallest;
    greatest = a[0];
    smallest = a[0];
    for(int i = 1; i < size; i++){
        if(a[i] > greatest){
            greatest = a[i];
        }
        if(a[i] < smallest){
            smallest = a[i];
        }
    }
    return greatest + smallest;
}
