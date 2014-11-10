#include <iostream>
#include <stack>

using namespace std;

int kadane(int* a,int n) {

    int max_so_far=0,max_ending_here=0;

    for(int i=0;i<n;i++) {
        max_ending_here += a[i];
        if(max_ending_here < 0)
            max_ending_here = 0;
        else if(max_ending_here > max_so_far)
            max_so_far = max_ending_here;
    }

    return max_so_far;
}

int kadane2DP(int* a, int n) {

    int max_so_far=a[0],max_ending_here=a[0];
    for(int i=1;i<n;i++) {
        max_ending_here = max(a[i]+max_ending_here,a[i]);
        max_so_far = max(max_so_far,max_ending_here);
    }

    return max_so_far;

}

int main() {

    int N;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "The maximum sum contiguous subarray's sum is:" << endl;
    cout << kadane(a,N) << endl;

    ///Handles the case when there are all negative values...
    cout << "Again the maximum sum contiguous subarray sum is:" << endl;
    cout << kadane2DP(a,N);

    /// -3 - 6 -1 2 5 -9 10 -4 14 -8

}
