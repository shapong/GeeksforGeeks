#include <iostream>

using namespace std;

//Kadanes algo that takes care of the case of all negative numbers...
int kadane2(int* a, int n) {

    int max_so_far=a[0],max_ending_here=a[0];
    for(int i=1;i<n;i++) {
        max_ending_here = max(a[i]+max_ending_here,a[i]);
        max_so_far = max(max_so_far,max_ending_here);
    }

    return max_so_far;

}

int max_circ_subarray(int* a, int n) {

    int max_kadanes = kadane2(a,n);

    int sum=0;
    for(int i=0;i<n;i++) {
        sum += a[i];
        a[i] = a[i]*-1;
    }

    int max_inverted_kadanes = kadane2(a,n);

    //cout << max_inverted_kadanes << endl;
    //cout << max_kadanes << endl;

    if(max_kadanes < 0) return max_kadanes;
    return max(max_kadanes,sum-(max_inverted_kadanes*-1));

}

int main() {

    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    int* a = new int[N];

    for(int i=0;i<N;i++)
        cin >> a[i];


    cout << "The maximum subarray sum of the circular array is:" << endl;
    cout << max_circ_subarray(a,N) << endl;

}
