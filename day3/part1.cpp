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

    // need to generate the points into a set and then take the intersection of the two sets
    // then calculate Manhattan Distance abs(X1- X2) + (abs(Y1- Y2) for each and return the smallest

    const vector<pair<char, int>> wireOne= input.first;
    const vector<pair<char, int>> wireTwo= input.second;

    map<char, pair<int, int>> directions=
    {{'R', {1,0}}, {'L', {-1, 0}}, {'U', {0, 1}}, {'D', {0, -1}}};

    int x= 0, y= 0;

    set<pair<int, int>> visited;

    for (pair<char, int> command: wireOne) {

        pair<int, int> d= directions[command.first];

        for (int i = command.second; i > 0; i--) {

            x+= d.first;
            y+= d.second;

            visited.insert({x, y});

        }

    }

    int answer= INT_MAX;

    x= 0, y= 0;

    for (pair<char, int> command: wireTwo) {

        pair<int, int> d= directions[command.first];

        for (int i = command.second; i > 0; i--) {

            x+= d.first;
            y+= d.second;

            pair<int, int> p= {x, y};

            if (visited.find(p) != visited.end()) {

                answer= min(answer, abs(x)+ abs(y));

            }

        }


    }

    cout << answer << "\n";

    return 0;
}
