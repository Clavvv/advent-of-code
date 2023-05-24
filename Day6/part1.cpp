#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <stack>

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
        vector<string> childrenNodes;

        if (cleanData.find(key)!= cleanData.end()){

            childrenNodes= cleanData[key];
            childrenNodes.push_back(value);

        } else {

            childrenNodes.push_back(value);


        }


        cleanData[key]= childrenNodes;




    }

    return cleanData;


}

int countOrbits(map<string, vector<string>>& some_tree, map<string, int>& visited, string currNode, int depth) {

    int orbits = depth;

    if (visited.find(currNode) != visited.end()) {
        return depth;
    }

    visited.insert({currNode, orbits});

    if (some_tree.find(currNode) != some_tree.end()) {
        for (auto const &node : some_tree[currNode]) {
            orbits+= countOrbits(some_tree, visited, node, depth + 1);
        }
    }

    return orbits;
}




int main()
{
    // THE INPUT PARSING ISNT MAKING THE vector<string> properly so there are no child nodes

    map<string, vector<string>> input= readInput();
    map<string, int> v;

    cout << countOrbits(input, v, "COM", 0);

    return 0;
}

