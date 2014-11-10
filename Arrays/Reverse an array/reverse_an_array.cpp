#include <iostream>

using namespace std;

void reverse(int* a, int n) {

    int start=0,end=n-1;
    while(start < end) {
        swap(a[start],a[end]);
        start++;
        end--;
    }

}

void reverse_recur(int* a, int start, int end, int n) {

    if(n==1) return;
    if(start>=end) return;

    reverse_recur(a,start+1,end-1,n);

    swap(a[start],a[end]);

}

int main() {

    int N;
    cout << "Enter an array:" << endl;
    cin >> N;
    int* a = new int[N];
    int* b = new int[N];
    for(int i=0;i<N;i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    reverse(a,N);
    cout << "After reversing the array..." << endl;
    for(int i=0;i<N;i++)
        cout << a[i] << " ";
    cout << endl;

    reverse_recur(b,0,N-1,N);
    cout << "Again after reversing the array recursively..." << endl;
    for(int i=0;i<N;i++)
        cout << b[i] << " ";
    cout << endl;

}
