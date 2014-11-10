#include <iostream>

using namespace std;

int compute_modulo(unsigned int num, unsigned int D) {
    return (num&(D-1));
}

int main() {

    int N,D;
    cout << "Enter a number:" << endl;
    cin >> N;
    cout << "Enter a power of 2 to compute modulo: " << N << " % with..." << endl;
    cin >> D;

    cout << N << " % " << D << " is:" << endl;
    cout << compute_modulo(N,D) << endl;


}
