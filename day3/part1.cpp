#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <set>
#include <map>

using namespace std;
vector<string> parseInput(const string some_str) {

    const string delimiter= ",";
    size_t start= 0;
    size_t end= some_str.find(delimiter);
    vector<string> string_vector;

    while (end != string::npos) {

        string_vector.emplace_back(some_str.substr(start, end - start ));
        start= end + delimiter.size();
        end= some_str.find(delimiter, start);

    }
    string_vector.emplace_back(some_str.substr(start, end - start));

    return string_vector;

}
pair<string, string> readInput(){

        ifstream file("input.txt");

        if (!file.is_open())
            {  return make_pair("", "");   }

        string input;
        string wireOne;
        string wireTwo;

        getline(file, wireOne);
        getline(file, wireTwo);

        return make_pair(wireOne, wireTwo);
}

int main ()
{

    pair<string, string> input= readInput();
    vector<string> wireOne= parseInput(input.first);
    vector<string> wireTwo= parseInput(input.second);

    for (size_t i; i < wireOne.size(); i++){

    // need to generate the points into a set and then take the intersection of the two sets
    // then calculate Manhattan Distance abs(X1- X2) + (abs(Y1- Y2) for each and return the smallest

    }





    return 0;



}
