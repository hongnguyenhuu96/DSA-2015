#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Write a C++ program to read a list of real numbers from the text file “numbers.txt”
// and output to the file “numbers.out” the list of numbers after increasingly sorted.
void readNumber(const char* fileName, vector<float> &num);
void writeFile(const char* fileName, vector<float>& num);
void quickSort(vector<float> &a, int left, int right);

int main()
{
    vector<float> a;
    readNumber("numbers.txt", a);
    quickSort(a, 0, a.size() - 1);
    writeFile("numbers.out", a);
}

void readNumber(const char* fileName, vector<float> &num){
    ifstream file;
    file.open(fileName);
    while(!file.eof()){
        float temp;
        file >> temp;
        if(file){
            num.push_back(temp);
        }
    }
    file.close();
}

void writeFile(const char* fileName, vector<float>& num){
    ofstream file(fileName);
    for(int i = 0 ; i < num.size(); i++){
        file << num[i];
        if(i != (num.size() - 1)) file << " ";
    }
    file.close();
}

void quickSort(vector<float> &a, int left, int right) {
      int i = left, j = right;
      int tmp;
      int pivot = a[(left + right) / 2];

      while (i <= j) {
            while (a[i] < pivot)
                  i++;
            while (a[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = a[i];
                  a[i] = a[j];
                  a[j] = tmp;
                  i++;
                  j--;
            }
      };

      if (left < j)
            quickSort(a, left, j);
      if (i < right)
            quickSort(a, i, right);
}
