#include <iostream>

using namespace std;

bool check_sign(int n, int m) {

    return ((n ^ m) < 0);

}

int main() {

    int n,m;
    cin >> n >> m;

    ///Note: XOR outputs 1 when inputs differ
    ///Sign bit is 1 in negative numbers & 0 in positive numbers

    (check_sign(n,m)) ? cout << "Opposite signs" << endl : cout << "Same signs" << endl;


}
