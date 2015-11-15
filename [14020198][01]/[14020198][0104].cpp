#include <iostream>
#include <limits>
#include <cmath>
using namespace std;


int findGCD(int a, int b){
    if(b == 0) return a;
    else return findGCD(b, a%b);
}

int main()
{
    int a, b;
    cin >> a;
    cin >> b;
    cout << abs(findGCD(a, b));
    return 0;
}

