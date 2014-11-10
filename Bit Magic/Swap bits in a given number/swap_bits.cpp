#include <iostream>

using namespace std;

int swap_bits(unsigned num, int p1, int p2, int n) {

    ///onlys gets last n bits starting from p1...
    int set1 = (num >> p1) & ((1U << n) -1);
    ///only gets last n bits starting from p2...
    int set2 = (num >> p2) & ((1u << n)-1);

    int xor_n = (set1 ^ set2);
    xor_n  = (xor_n << p1) | (xor_n << p2);
    int res = num ^ xor_n;

    return res;

}

int main() {

    int N,n,p1,p2;
    cout << "Enter a number:" << endl;
    cin >> N;
    cout << "From which postions should we swap:" << endl;
    cin >> p1 >> p2;
    cout << "How many positions should be swapped?" << endl;
    cin >> n;

    cout << "The number after swapping all bits is:" << endl;
    cout << swap_bits(N,p1,p2,n) << endl;

}
