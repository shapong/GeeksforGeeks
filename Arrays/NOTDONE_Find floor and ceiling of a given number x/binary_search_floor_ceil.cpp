#include <iostream>

using namespace std;

int bin_ceil(int *a, int low, int high, float x) {

    if(low==high && x <= a[low]) return a[low];
    else if(low==high && x > a[low]) return -1;

    int mid = (low+high)/2;
    if(x == a[mid]) return a[mid];

    if(x < a[mid]) return bin_ceil(a,low,mid,x);
    else if(x > a[mid]) return bin_ceil(a,mid+1,high,x);

}

int bin_floor(int *a, int low, int high, float x) {

    if(low==high && x >= a[low]) return a[low];
    else if(low==high && x < a[low]) return -1;

    int mid = (low+high)/2;
    if(x == a[mid]) return a[mid];

    if(x < a[mid]) return bin_floor(a,low,mid-1,x);
    else if(x > a[mid]) return bin_floor(a,mid,high,x);

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

    cout << "The ceiling is: " << bin_ceil(a,0,N-1,x) << endl;
    //cout << "The floor is: " << bin_floor(a,0,N-1,x) << endl;

}
