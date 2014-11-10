#include <iostream>

using namespace std;

bool isPowerFour(int num) {

    if(num==0) return false;
    while(num!=1) {
        if(num%4!=0)
            return false;
        num = num/4;
    }
    return true;

}

int main() {

    int N;
    cout << "Enter a number:" << endl;
    cin >> N;

    cout << "Is " << N << " a power of 4?" << endl;
    (isPowerFour(N)) ? cout << "Yes" << endl : cout << "No" << endl;

}
