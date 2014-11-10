#include <iostream>
#include <map>

using namespace std;

int equal_subarray(int* a, int n) {

    if(n==1) return -1;
    int* sumLeft = new int[n];
    sumLeft[0] = (a[0]==1) ? 1 : -1;
    for(int i=1;i<n;i++) {
        sumLeft[i] = (a[i]==1) ? 1 : -1;
        sumLeft[i] += sumLeft[i-1];
    }

    int startIndex=-1,maxSize=-1;

    map<int,int> m;

    for(int i=0;i<n;i++) {
        if(sumLeft[i]==0) { startIndex=0; maxSize=i+1;}

        if(m.find(sumLeft[i])==m.end())
            m.insert(make_pair(sumLeft[i],i));
        else {
            if(i-m[sumLeft[i]] > maxSize) {
                maxSize = i - m[sumLeft[i]];
                startIndex = m[sumLeft[i]]+1;
            }
        }

    }

    if(maxSize!=-1) cout << startIndex << "...to..." << startIndex+maxSize-1 << endl;
    else cout << "No such subarray possible..." << endl;
    return maxSize;

}

int main() {

    int N;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "The maximum subarray size with equal number of ones and zeros is:" << endl;
    int ans = equal_subarray(a,N);
    (ans==-1) ? cout << "Not possible" << endl : cout << ans << endl;

}
