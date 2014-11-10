#include <iostream>

using namespace std;

int make_even_or_odd_set(int e) {
    unsigned n = 0;

    unsigned pos=0,i=1;
    while(pos < 32) {
        if(e) {
            if(pos%2 == 1)
                n = n | i;
        }
        else {
            if(pos%2 == 0)
                n = n | i;
        }
        i = i << 1;
        pos++;
    }
    return n;
}

int swap_odd_even(unsigned n) {
    unsigned even, odd;
    even = make_even_or_odd_set(1);
    odd = make_even_or_odd_set(0);

    //even = 0xAAAAAAAA & n;
    //odd = 0x55555555 & n;

    even = even & n;
    even = even >> 1;

    odd = odd & n;
    odd = odd << 1;

    return (odd | even);

}

int main() {

    int N,num,ans;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> num;
        ans = swap_odd_even(num);
        cout << "The number after swapping is: " << ans << endl;
    }



}
