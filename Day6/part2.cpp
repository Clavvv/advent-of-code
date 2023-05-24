#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, vector<string>>readInput()
{
    string strBuff;
    ifstream file("input.txt");
    std::string input_str;

    map<string, vector<string>> cleanData;

    while (getline(file, strBuff)) {

        size_t index= strBuff.find(')');
        string key= strBuff.substr(0, index);
        string value= strBuff.substr(index+1);

        cleanData[key].push_back(value);
    }

    return cleanData;
}

int countOrbits(map<string, vector<string>>& some_tree, map<string, int>& visited, string currNode, int depth, vector<pair<string, int>> &depthArr) {

    depthArr.push_back({currNode, depth});

    int orbits= depth;

    if (visited.find(currNode) != visited.end()) {
        return depth;
    }

    visited.insert({currNode, orbits});

    if (some_tree.find(currNode) != some_tree.end()) {
        for (auto const &node : some_tree[currNode]) {
            orbits+= countOrbits(some_tree, visited, node, depth + 1, depthArr);
        }
    }

    return orbits;
}

int findNode(vector<pair<string, int>> vec,const string &item) {

    for (size_t i = 0; i < vec.size(); i++) {

        if (vec[i].first == item) return i;


    }

    return -1;
}

int main()
{

    map<string, vector<string>> input= readInput();
    map<string, int> v;
    vector<pair<string, int>> tree_array;

    int start; int finish;

    cout << countOrbits(input, v, "COM", 0, tree_array) << endl;

    int minDistance= INT_MAX;

    start= min(findNode(tree_array, "YOU"), findNode(tree_array, "SAN"));
    finish= max(findNode(tree_array, "YOU"), findNode(tree_array, "SAN"));

    for (int i = start; i < finish + 1; i++) {


        if (tree_array[i].second < minDistance) {

            minDistance= tree_array[i].second;
        }
    }

    int depthA= tree_array[start].second;
    int depthB= tree_array[finish].second;

    cout << depthA << endl;
    cout << depthB << endl;
    cout << minDistance;

    cout << endl << endl << (depthA + depthB) - (2* minDistance);



    return 0;
}

