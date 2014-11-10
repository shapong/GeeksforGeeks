#include <iostream>

using namespace std;

///Brian Kernighan's Algo...
int count_bits_set(unsigned int num) {

    int count = 0;
    while(num!=0) {
        num = num & (num-1);
        count++;
    }
    return count;
}

int flips(unsigned int num, unsigned int num2) {

    int xor_ed = num^num2;
    return count_bits_set(xor_ed);

}

int main() {

    int N,M;
    cout << "Enter a number:" << endl;
    cin >> N;
    cout << "Enter a number:" << endl;
    cin >> M;

    cout << "To convert " << N << " to " << M << " the numbers of flips required is:" << endl;
    cout << flips(N,M) << endl;

}
