#include <iostream>

using namespace std;

int find_ceil(int* a, int n, float x) {

    for(int i=0;i<n;i++) {
        if(x <= float(a[i]))
            return a[i];
    }
    return -1;
}

int find_floor(int* a, int n, float x) {

    for(int i=0;i<n-1;i++) {
        if(x >= float(a[i]) && x <= float(a[i+1]))
            return a[i];
    }
    if(x >= float(a[n-1])) return a[n-1];
    return -1;

}

int main() {

    int N,sum;
    float x;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "Enter a number to find the ceiling and floor of: " << endl;
    cin >> x;

    ///Assuming the array is already sorted...
    ///sort(a,a+N);
    cout << "The ceiling is: " << find_ceil(a,N,x) << endl;
    cout << "The floor is: " << find_floor(a,N,x) << endl;

}
