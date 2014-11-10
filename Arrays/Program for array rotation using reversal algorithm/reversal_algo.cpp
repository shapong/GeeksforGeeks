#include <iostream>

using namespace std;

void reverse(int* a, int start, int end) {

    while(start < end) {
        swap(a[start],a[end]);
        start++;
        end--;
    }

}

void reversal(int* a, int n, int rotate) {

    if(rotate > n) rotate = rotate%n;
    if(rotate<=0 || rotate==n) return;
    reverse(a,0,rotate-1);
    reverse(a,rotate,n-1);
    reverse(a,0,n-1);
}

int main() {

    int N,R;
    cout << "Enter an array:" << endl;
    cin >> N;
    int* a = new int[N];
    int* b = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "By how many units do you want to rotate left?" << endl;
    cin >> R;

    reversal(a,N,R);
    cout << "After reversing the array..." << endl;
    for(int i=0;i<N;i++)
        cout << a[i] << " ";
    cout << endl;

}
