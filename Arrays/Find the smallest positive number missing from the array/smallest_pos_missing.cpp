#include <iostream>
#include <cstdlib>

using namespace std;

void segregate(int* a, int n) {

    int index = 0;
    for(int i=0;i<n;i++) {
        if(a[i] <= 0) {
            if(i!=index) swap(a[i],a[index]);
            index++;
        }
    }
}

int find_small_pos(int* a, int n) {

    segregate(a,n);

    int i,startIndex=0,ind;
    for(i=0;i<n;i++)
        if(a[i] > 0) break;

    ///0 is not a positve number so we return startIndex+1
    startIndex = i;
    if(startIndex==n) return 1;

    for(int i=startIndex;i<n;i++) {
        ind = startIndex-1+abs(a[i]);
        if(ind < n && a[ind] > 0) a[ind] = a[ind]*-1;
    }

    for(int i=startIndex;i<n;i++) {
        if(a[i] > 0) return i-startIndex+1;
    }
    return -1;
}

int main() {

    int N;
    cout << "Enter the number of elements:" << endl;
    cin >> N;
    int* a = new int[N];

    for(int i=0;i<N;i++)
        cin >> a[i];


    ///We can use sorting or hashing...but here we take O(n) time & use O(1) extra space
    cout << "The smallest postive number missing from the array is:" << endl;
    cout << find_small_pos(a,N) << endl;

}
