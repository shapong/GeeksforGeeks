#include <iostream>

using namespace std;

int maxDiff(int* a, int n) {

    int* Lmin = new int[n];
    int* Rmax = new int[n];

    Lmin[0] = a[0];
    for(int i=1;i<n;i++)
        Lmin[i] = min(a[i],Lmin[i-1]);

    Rmax[n-1] = a[n-1];
    for(int i=n-2;i>=0;i--)
        Rmax[i] = max(a[i],Rmax[i+1]);

    int i=0,j=0,maxDiff=-1,start = 1,end=0;
    while(i < n && j < n) {
        if(Lmin[i] >= Rmax[j]) i++;
        else {
            if(j-i > maxDiff) {
                maxDiff = j - i;
                start = i; end = j;
            }
            j++;
        }
    }

    cout << "The distance between indices " << start << " and " << end << " is the greatest" << endl;
    return maxDiff;

}

int main() {

    int N;
    cout << "Enter the array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    int ans = maxDiff(a,N);
    cout << "The max distance between two elements where one(rightmost) is greater is:" << endl;
    cout << ans << endl;

}
