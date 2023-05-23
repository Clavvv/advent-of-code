#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

vector<int> readInput() {

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

    vector<int> input= readInput();

    int i= 0;
    int initial_value= 5;

    // REWRITE ALL THIS SHIT USING THE MODULO OPERATOR TO ACCESS THE DIGITS
    // THAT WILL BE $wag :D

    while (input[i] != 99)
    {

        int opcode= input[i] % 10; // GETS THE LAST TWO DIGITS
        int p1= input[i]/100 % 10; // GETS FIRST PARAMETER SETTING (READS R- > L)
        int p2= input[i]/1000 % 10; //GETS THE SECOND PARAMETER SETTING (READS R -> L)

        switch(opcode){

        case(1): {

            int valOne= (p1) ? input[i+1] : input[input[i+1]];
            int valTwo= (p2) ? input[i+2] : input[input[i+2]];
            input[input[i+3]]= valOne + valTwo;
            i+=4;
            break;
        }
        case(2): {
            int valOne= (p1) ? input[i+1] : input[input[i+1]];
            int valTwo= (p2) ? input[i+2] : input[input[i+2]];
            input[input[i+3]]= valOne * valTwo;
            i+=4;
            break;
        }
        case(3): {
            input[input[i+1]]= initial_value;
            i+=2;
            break;
        }
        case(4): {

            int valOne= (p1) ? input[i+1] : input[input[i+1]];
            cout << valOne << endl;
            i+=2;
            break;
        }

        case(5): {

            int valOne= (p1) ? input[i+1] : input[input[i+1]];
            int valTwo= (p2) ? input[i+2] : input[input[i+2]];

            i= (valOne != 0) ? valTwo : i+3;
            break;

        }

        case(6): {

            int valOne= (p1) ? input[i+1] : input[input[i+1]];
            int valTwo= (p2) ? input[i+2] : input[input[i+2]];

            i= (valOne == 0) ? valTwo : i+3;
            break;

        }

        case(7): {



            int valOne= (p1) ? input[i+1] : input[input[i+1]];
            int valTwo= (p2) ? input[i+2] : input[input[i+2]];

            input[input[i+3]]= (valOne < valTwo) ? 1 : 0;
            i+=4;
            break;


        }
        case(8): {

            int valOne= (p1) ? input[i+1] : input[input[i+1]];
            int valTwo= (p2) ? input[i+2] : input[input[i+2]];

            input[input[i+3]]= (valOne == valTwo) ? 1 : 0;
            i+=4;
            break;


        }

    }
    }



    return 0;
}
