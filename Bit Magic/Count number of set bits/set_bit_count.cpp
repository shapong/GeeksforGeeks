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

int count_set(unsigned int num) {

    int count = 0;
    while(num!=0) {
        count += num & 1;
        num = num >> 1;
    }
    return count;
}

int main() {

    int N;
    cout << "Enter a number:" << endl;
    cin >> N;

    cout << "The number of set bits in " << N << " is:" << endl;
    cout << count_bits_set(N) << endl;
    cout << "And again... " << count_set(N) << endl;

}
