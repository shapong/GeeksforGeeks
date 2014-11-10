#include <iostream>

using namespace std;

int get_max(int* a, int low, int high, int n) {

    int mid = (low+high)/2;

    if((mid==0 || a[mid] > a[mid-1]) && (a[mid] > a[mid+1] || mid==n-1)) return a[mid];

    if(a[mid] < a[mid-1] && a[mid] > a[mid+1]) return get_max(a,low,mid-1,n);

    else return get_max(a,mid+1,high,n);

}

int main() {

    int N;
    cout << "Enter the array:" << endl;
    cin >> N;
    int* a = new int[N];

    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "The maximum element in the array is:" << endl;
    cout << get_max(a,0,N-1,N) << endl;

}
