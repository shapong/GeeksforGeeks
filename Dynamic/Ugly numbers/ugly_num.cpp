#include <iostream>

using namespace std;

int ugly_num(int n) {

    int* a = new int[n];
    a[0] = 1;
    int next_mul2=2,next_mul3=3,next_mul5=5;
    int i2=0,i3=0,i5=0;

    for(int i=1;i<n;i++) {
        a[i] = min(min(next_mul2,next_mul3),next_mul5);
        if(a[i] == next_mul2) {
            i2++;
            next_mul2 = 2*a[i2];
        }
        if(a[i] == next_mul3) {
            i3++;
            next_mul3 = 3*a[i3];
        }
        if(a[i] == next_mul5) {
            i5++;
            next_mul5 = 5*a[i5];
        }
    }
    return a[n-1];
}

int main() {

    int N;
    cin >> N;

    cout << "The " << N << " ugly number is:" << endl;
    cout << ugly_num(N) << endl;


}
