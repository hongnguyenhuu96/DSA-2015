#include <iostream>
#include <fstream>

using namespace std;
void checkCross(const char* fileName);

int main(){
    checkCross("points.txt");
}

void checkCross(const char* fileName){
    ifstream file(fileName);
    float x1, y1, x2, y2, x3, y3, x4, y4;
    while(!file.eof()){
        file >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    }
//    float a1 = y1 - y2;
//    float a2 = y3 - y4;
//    float b1 = x2 - x1;
//    float b2 = x4 - x3;
    float c1 = -x1*(y1 - y2) - y1*(x2 - x1);
    float c2 = -x3*(y3 - y4) - y3*(x4 - x3);
//    cout << "d1 = " << a1 << "x + " << b1 << "y + " << c1 << " = 0" << endl;
//    cout << "d2 = " << a2 << "x + " << b2 << "y + " << c2 << " = 0" << endl;

    if((y1 - y2)*(x4 - x3) == (y3 - y4)*(x2 - x1)){
        if(!(c1*(x4 - x3) == c2*(x2 - x1) && c1*(y3 - y4) == c2*(y1 - y2))){
            cout << "no";
            return;
        }
    }
    cout << "yes";
    return;
}
