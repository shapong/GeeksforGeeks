#include <iostream>

using namespace std;

int unset_rightmost_bit(unsigned int n) {
    return n&(n-1);
}

int main() {

    int N;
    cin >> N;

    cout << N << " after flipping the rightmost set bit becomes: " << unset_rightmost_bit(N) << endl;

}
