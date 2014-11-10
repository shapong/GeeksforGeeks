#include <iostream>

using namespace std;

void find_peaks(int* a, int l, int r, int n) {

    if(l>r) return;
    int mid = (l+r) / 2;

    if((a[mid] >= a[mid-1] || mid==0) && (a[mid] >= a[mid+1] || mid==n-1)) {
        cout << "Peak: " << a[mid] << " at index " << mid << endl;
        return;
    }


    if(a[mid] < a[mid-1] && mid > 0)
        find_peaks(a,l,mid-1,n);

    else
        find_peaks(a,mid+1,r,n);

}

int main () {

    int N;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    find_peaks(a,0,N-1,N);

}
