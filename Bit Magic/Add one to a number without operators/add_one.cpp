#include <iostream>

using namespace std;

int add_one(int n) {
    return (-(~n));
}

int add_one_again(int n) {

    int xor_num =1;
    ///XOR with 1 flips the bit...
    while(xor_num & n) {
        n=n^xor_num;
        xor_num<<1;
    }

    n = n^xor_num;
    return n;

}

int main() {

    int num;
    cout << "Enter a number:" << endl;
    cin >> num;

    cout << "The number after adding one is: " << add_one(num) << endl;
    cout << "The number after adding one again is: " << add_one_again(num) << endl;

}
