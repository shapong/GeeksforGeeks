#include <iostream>
#include <deque>

using namespace std;

int get_max_in_subarrs(int* a, int n, int k) {

    deque<int> DQ(k);

    for(int i=0;i<k;i++) {
        while(!DQ.empty() && a[DQ.back()] < a[i]) DQ.pop_back();
        DQ.push_back(i);
    }

    for(int i=k;i<n;i++) {
        cout << "Subarray " << i-k+1 << ": " << a[DQ.front()] << endl;

        ///pop everything outside the window...of i-k...
        while(!DQ.empty() && DQ.front() <= i-k)
            DQ.pop_front();

        ///pop everything less than the element...
        while(!DQ.empty() && a[DQ.back()] < a[i])
            DQ.pop_back();

        DQ.push_back(i);
    }
    cout << "Subarray " << n-k+1 << ": " << a[DQ.front()] << endl;

}

int main() {

    int N,k;
    cout << "Enter the array:" << endl;
    cin >> N;
    int* a = new int[N];

    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "Enter a size of the subarray:" << endl;
    cin >> k;

    cout << "The maximum element in the each of the subarrays is:" << endl;
    get_max_in_subarrs(a,N,k);

}
