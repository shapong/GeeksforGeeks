#include <iostream>

using namespace std;

int highest_freq(int* a, int n) {
    int max_ind = 0;
    for(int i=0;i<n;i++){
        a[a[i]%n] += n;
        if (a[a[i]%n] > a[max_ind]) max_ind = a[i]%n;
    }
    return max_ind;

}

int main() {

    int N;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << highest_freq(a,N) << endl;


}
