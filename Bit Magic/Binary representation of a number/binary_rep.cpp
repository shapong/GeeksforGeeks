#include <iostream>

using namespace std;

void binary(int n) {

    for(unsigned i=(1<<31);i>0;i=i/2) {
        cout << ((n & i) ? "1" : "0");
    }
    cout << endl;

}

void binary_recur(unsigned n) {
    if(n > 1)
        binary_recur(n/2);

    cout << n%2;

}

int main() {

    int num;
    cin >> num;

    binary(num);
    binary_recur(num);

}
