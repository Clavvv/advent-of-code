#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<int> readData() {

    //init string vector
    vector<string> data;
    // creating the file stream using input.txt in current dir
    ifstream file("input.txt");
    string input_str;

    //defining parsing rules (splitting at the "," and casting as integer
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

    //reading in the op commands as a int vector
    vector<int> program= readData();

    // init VALUE as immutable int representing the desired value
    const int VALUE= 19690720;
    int answser;

    // loop for brute forcing noun values
    for (int noun= 0; noun < 100; noun++) {

        // loop for brute forcing verb values
        for (int verb= 0; verb < 100; verb++) {

            vector<int> mem(program);
            mem[1]= noun;
            mem[2]= verb;

            // running the op commands
            size_t index= 0;
            while (mem[index] != 99) {

                if (mem[index] == 1) {

                    mem[mem[index+3]]= mem[mem[index+1]] + mem[mem[index+2]];

                } else if (mem[index] == 2) {

                    mem[mem[index+3]]= mem[mem[index+1]] * mem[mem[index+2]];

                }

                index+= 4;
            }
            // Conditional to check is desired value has been found
            if (mem[0] == VALUE) {

                int answer= 100*noun+verb;
                cout << answer << "  <-- ANSWER";
            }

        }

    }

    return 0;

}
