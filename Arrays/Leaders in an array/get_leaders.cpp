#include <iostream>

using namespace std;

void get_leaders(int* a, int n) {

    int max = a[n-1];
    cout << "Leader: " << a[n-1] << endl;
    for(int i=n-2;i>=0;i--) {
        if(a[i] > max) {
            cout << "Leader: " << a[i] << endl;
            max = a[i];
        }
    }
    return;

}

int main() {
    int N;
    cin >> N;
    int* a = new int[N];

    for(int i=0;i<N;i++)
        cin >> a[i];

    get_leaders(a,N);

}
