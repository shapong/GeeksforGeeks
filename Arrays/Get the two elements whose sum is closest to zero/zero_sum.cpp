#include <iostream>
#include <cstdlib>

using namespace std;

void min_sum(int* a, int n) {

    sort(a,a+n);
    int l=0,r=n-1,e1,e2;
    int sum = a[l]+a[r];
    while(l<r) {
        if(abs(a[l]+a[r]) < abs(sum)) {
            sum = a[l]+a[r];
            e1=l; e2 = r;
        }
        if(a[l]+a[r]<0) l++;
        else if(a[l]+a[r]>=0) r--;
    }
    cout << a[e1] << " plus " << a[e2] << " equals " << sum << endl;
}

int main() {

    int N;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    min_sum(a,N);
}
