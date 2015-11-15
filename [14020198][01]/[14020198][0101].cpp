/** \file [14020198][0101].cpp (exercise 1)
 * \brief Read a sentence from keyboard and print the sentence in to the file “rev.txt” in reversed order
 * \author Nguyen Huu Hong - 14020198
 */

#include <iostream>
#include <exception>
#include <fstream>

using namespace std;

void writeFile(const char *filename, string str);

int main(){
    string str;
    getline(cin, str);
    writeFile("rev.txt", str);
}
/** \brief write file contain the reversed string
 *
 * \param filename: the name of the file want to create to contain the reversed string
 * \param  str: the string need to reverse
 * \return
 *
 */
void writeFile(const char *filename, string str){
    ofstream file;
    file.open(filename);
    for(int i = str.length() - 1; i >= 0; i--){
        file << str[i];
    }
    file.close();
}
