#include <iostream>
#include <fstream>

using namespace std;
/** \brief program to calculate sum of all complex number in a file
 *  \file main.cpp
 *  \author Nguyen Huu Hong - 14020198
 */

//Write a C++ program to read a list of complex numbers from the text file “complex.txt”
//and write out to the screen the sum of the list.


class Complex{
private:
    float a, b;
public:
    Complex(float a1 = 0, float b1 = 0){
        a = a1;
        b = b1;
    }
    friend ostream& operator << (ostream& os, const Complex& c){
        os << c.a << " " << c.b;
        return os;
    }
};

Complex readFile(const char* fileName);

int main()
{
    cout << readFile("complex.txt");
}

/** \brief read file: fileName
 *
 * \param  fileName: the name of the file want to calculate
 * \return c: the complex save sum of all complex numbers in file
 *
 */

Complex readFile(const char* fileName){
    ifstream file(fileName);
    float aSum = 0, bSum = 0;
    while(!file.eof()){
        float temp;
        file >> temp;
        if(file){
            aSum += temp;
            file >> temp;
            if(file)
                bSum += temp;
        }
    }
    Complex c(aSum, bSum);
    return c;
}
