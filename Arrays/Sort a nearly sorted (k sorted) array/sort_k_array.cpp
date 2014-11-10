#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

void sort_k_array(int* arr, int n, int k) {

    if(k > n) return;
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i=0;i<=k;i++)
        pq.push(arr[i]);
    int ind = k+1;

    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
        if(ind < n) { pq.push(arr[ind]); ind++; }
    }
    cout << endl;
}

void sort_k_arr(int* arr, int n, int k) {

    int i=0;
    int N = n;
    while(n/k > 0) {
        //cout << "N: " << n << " I: " << i << endl;
        sort(arr+(i*k),arr+(min(N,(i+2)*k)));
        i++;
        n = n-k;
    }

    for(int i=0;i<N;i++)
        cout << arr[i] << " ";
    cout << endl;

}

int main() {

    int N,k;
    cout << "Enter the array:" << endl;
    cin >> N;
    int* a = new int[N];
    int* b = new int[N];

    for(int i=0;i<N;i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    cout << "What is 'k'? (i.e. how far is each element from its sorted location in the array)" << endl;
    cin >> k;

    ///test case: 2 1 3 6 4 5 7 and k = 2
    ///test case: 2 1 3 6 4 8 5 7 and k = 3

    cout << "The sorted array is:" << endl;
    sort_k_array(a,N,k);
    cout << "The sorted array is:" << endl;
    sort_k_arr(b,N,k);

}
