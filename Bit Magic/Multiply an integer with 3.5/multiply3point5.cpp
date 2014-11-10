#include <iostream>

using namespace std;

int multiply3point5(int num) {
    return (num << 1) + (num >> 1) + num;
}

int multiplyAgain(int num) {
    return (((num << 3) - num) >> 1);
}

int main() {

    int N;
    cout << "Enter a number:" << endl;
    cin >> N;

    cout << "After multiplying " << N << " with 3.5...we get:" << endl;
    cout << multiply3point5(N) << endl;
    cout << "And again... " << multiplyAgain(N) << endl;

}
