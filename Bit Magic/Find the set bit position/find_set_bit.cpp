#include <iostream>

using namespace std;

int power_of_two(unsigned n) {
    //!...n & (n-1) will be zero for a number that is a power of 2!! :D
    //!...for the case of n = 0 we add n && to this... 0 ANDed with anything makes zero
    return n && (!(n & (n-1)));
}

int set_bit(unsigned n) {

    if(!power_of_two(n))
        return -1;

    unsigned i = 1, pos = 1;

    //!...when n is ANDed with itself it becomes a number other than 0 :D and comes outside the loop
    while((i & n) == 0) {   //!(i & n) is the same thing...
        i = i << 1;
        pos++;
    }
    return pos;
}


int main() {

    int N,num,pos;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        pos = set_bit(num);
        cout << "Position set: " << pos << endl;
    }

}
