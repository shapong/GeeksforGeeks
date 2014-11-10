#include <iostream>

using namespace std;

int missing_num(int* a, int n) {

    int sum = (n+2)*(n+1)/2;

    for(int i=0;i<n;i++) {
        sum = sum - a[i];
    }
    return sum;

}

int missing_num2(int* a, int n) {

    int x1=1,x2=a[0];
    for(int i=2;i<=n+1;i++)
        x1 = x1^i;
    for(int i=1;i<n;i++)
        x2 = x2^a[i];
    return x2^x1;

}

int main() {

    int N;
    cout << "Enter an array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "The missing element in the array with range 1:" << N+1 << " is:" << endl;
    cout << missing_num(a,N) << endl;

    cout << "The missing element in the array with range 1:" << N+1 << " is:" << endl;
    cout << missing_num2(a,N) << endl;
}
