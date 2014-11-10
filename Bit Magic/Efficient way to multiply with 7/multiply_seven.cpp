#include <iostream>

using namespace std;

int multiply7(int num) {

    return ((num << 3) - num);

}

int main (){

    int N;
    cout << "Enter a number:" << endl;
    cin >> N;

    cout << "The number efficiently multiplied by 7 is:" << endl;
    cout << multiply7(N) << endl;

}
