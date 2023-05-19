#include <iostream>
#include <fstream>
#include <cmath>
#include <typeinfo>
#include <string>
using namespace std;

int getFuel(int num) {

        int fuel= floor(num / 3) - 2;

        if (fuel > 0) {

            return fuel + getFuel(fuel);

        } else {

            return 0;

        }

    }

int main() {

    ifstream inFile;
    int sum;

    inFile.open("day1.txt");

    if (inFile.is_open()) {

        string content;

        while (getline(inFile, content)) {

            int line= stoi(content);

            sum+= getFuel(line);

        }

    cout << "THE ANSWER IS : " << sum;

    inFile.close();


    }







}
