#include <iostream>

using namespace std;

void get_max_to_right(int* a, int n) {
    int max = a[n-1],temp;
    a[n-1] = -1;
    for(int i=n-2;i>=0;i--) {
        temp = a[i];
        a[i] = max;
        if(temp > max) max = temp;
    }

    return;
}

int main() {

    int N;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    get_max_to_right(a,N);

    for(int i=0;i<N;i++) cout << a[i] << " ";
    cout << endl;

}
