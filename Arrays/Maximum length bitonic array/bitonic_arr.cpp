#include <iostream>

using namespace std;

int get_bitonic_length(int* a, int n) {

    int* inc = new int[n];
    int* dec = new int[n];

    inc[0] = 1; dec[n-1] = 1;
    for(int i=1;i<n;i++) {
        if(a[i] >= a[i-1]) inc[i] = inc[i-1] + 1;
        else inc[i] = 1;
    }

    for(int i=n-2;i>=0;i--) {
        if(a[i] >= a[i+1]) dec[i] = dec[i+1] + 1;
        else dec[i] = 1;
    }

    int max = inc[0] + dec[0] - 1;
    for(int i=1;i<n;i++) {
        if(inc[i]+dec[i]-1 > max) max = inc[i]+dec[i]-1;
        ///at index i...
    }

    delete inc,dec;

    return max;
}

int main() {

    int N;
    cout << "Enter the array:" << endl;
    cin >> N;
    int* a = new int[N];

    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "The maximum length of the bitonic array is:" << endl;
    cout << get_bitonic_length(a,N) << endl;

}
