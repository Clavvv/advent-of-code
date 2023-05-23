#include <iostream>

using namespace std;

bool isSixDigits(int password) {

    return (password >= 100000 && password <= 999999);
}

bool matchAdjacent(int password) {

    int sixth= password%10;
    int fifth= password/10%10;
    int fourth= password/100%10;
    int third= password/1000%10;
    int second= password/10000%10;
    int first= password/100000%10;

    return (first == second ||
            second == third ||
            third == fourth ||
            fourth == fifth ||
            fifth == sixth);
}

bool neverDecreases(int password) {

    return (password % 10 >= password/10%10 &&
            password/10%10 >= password/100%10 &&
            password/100%10 >= password/1000%10 &&
            password/1000%10 >= password/10000%10 &&
            password/10000%10 >= password/100000%10);
}






int main() {

    const pair<int, int> password_bounds= {245318, 765747};

    int count= 0;


    for (int i= password_bounds.first; i <= password_bounds.second; i++) {

        if (neverDecreases(i) && matchAdjacent(i) && isSixDigits(i)){

            count++;


        }


    }

    return count;


}
