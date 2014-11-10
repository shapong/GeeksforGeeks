#include <iostream>

using namespace std;

void segregate_even_odd(int* a, int n) {

    int storeInd=0;
    for(int i=0;i<n;i++) {
        if(a[i]%2==0) {
            if(i!=storeInd) swap(a[i],a[storeInd]);
            storeInd++;
        }
    }
}

int main() {

    int N;
    cout << "Enter the array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "After segregating the even(first) and odd numbers the array is:" << endl;
    segregate_even_odd(a,N);

    for(int i=0;i<N;i++)
        cout << a[i] << " ";
    cout << endl;

}
