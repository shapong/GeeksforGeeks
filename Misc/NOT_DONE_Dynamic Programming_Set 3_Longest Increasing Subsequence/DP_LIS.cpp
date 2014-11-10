#include <iostream>

using namespace std;

//To show overlapping substructure property...
int LIS(int* a, int n, int* max_overall) {

    if(n==1)
        return 1;

    int res,max_ending_here=1;
    for(int i=1;i<n;i++) {
        res = LIS(a,i,max_overall);
        if(a[i-1] < a[n-1] && res + 1 > max_ending_here)
            max_ending_here = res+1;
    }

    if(max_ending_here > *max_overall)
        *max_overall = max_ending_here;

    cout << "Max overall: " << *max_overall << " N: " << n << " Max Ending here: " << max_ending_here << endl;
    return max_ending_here;

}

int main() {

    int N;
    cout << "Enter an array:" << endl;
    cin >> N;
    int* a = new int[N];

    for(int i=0;i<N;i++)
        cin >> a[i];

    int temp = 1;
    cout << "The length of the Longest Increasing Subsequence is:" << endl;
    cout << LIS(a,N,&temp) << endl;

}
