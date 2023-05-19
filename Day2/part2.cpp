#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> readData() {

    vector<string> data;
    ifstream file("input.txt");
    string input_str;

    const string delimiter= ",";
    getline(file, input_str);
    size_t start= 0;
    size_t end= input_str.find(delimiter);
    vector<int> program;

    while (end != string::npos) {

        program.emplace_back(stoi(input_str.substr(start, end - start)));
        start= end + delimiter.size();
        end= input_str.find(delimiter, start);
    }

    program.emplace_back(stoi(input_str.substr(start, end - start)));


    return program;

}


int main() {

    vector<int> program= readData();

    program[1]= 12;
    program[2]= 2;

    size_t index= 0;

    while (program[index] != 99) {

        if (program[index] == 1) {
            program[program[index + 3]]= program[program[index + 2]] + program[program[index + 1]];

    }   else if (program[index] == 2) {

        program[program[index + 3]]= program[program[index + 2]] * program[program[index + 1]];

    }

    index+= 4;

    }

    return program[0];

}
