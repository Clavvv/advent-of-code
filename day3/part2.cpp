#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <set>
#include <map>

using namespace std;

pair<vector<pair<char, int>>, vector<pair<char, int>>> readInput(){

        ifstream file("input.txt");

        if (!file.is_open())
            { cout << "FAILED TO READ FILE..."; }


        string testOne, testTwo;

        getline(file, testOne);
        getline(file,testTwo);

        string input;
        string s;
        vector<pair<char, int>> wireOne;
        vector<pair<char, int>> wireTwo;

        istringstream iss(testOne);

        while (getline(iss, s, ',')) {
            wireOne.push_back({s.at(0), stoi(s.substr(1, s.length()-1))});
        }

        istringstream iss2(testTwo);

        while (getline(iss2, s, ',')) {
            wireTwo.push_back({s.at(0), stoi(s.substr(1, s.length()-1))});
        }

        return make_pair(wireOne, wireTwo);






}

int main ()
{
    pair<vector<pair<char, int>>, vector<pair<char, int>>> input= readInput();

    const vector<pair<char, int>> wireOne= input.first;
    const vector<pair<char, int>> wireTwo= input.second;

    map<char, pair<int, int>> directions=
    {{'R', {1,0}}, {'L', {-1, 0}}, {'U', {0, 1}}, {'D', {0, -1}}};

    map<pair<int, int>, long> visited;



    int x= 0, y= 0;
    long steps= 0;
    long answer= LONG_MAX;


    for (pair<char, int> command: wireOne) {

        pair<int, int> d= directions[command.first];

        for (int i = command.second; i > 0; i--) {

            x+= d.first;
            y+= d.second;

            visited.insert({{x, y}, ++steps});

        }

    }

    steps= 0, x= 0, y= 0;

    for (pair<char, int> command: wireTwo) {

        pair<int, int> d= directions[command.first];

        for (int i = command.second; i > 0; i--) {

            x+= d.first;
            y+= d.second;
            steps++;

            pair<int, int> p= {x, y};

            if (visited.find(p) != visited.end()) {

                answer= min(answer, visited.at(p)+steps);




            }

        }


    }

    cout << answer << "\n";

    return 0;
}
