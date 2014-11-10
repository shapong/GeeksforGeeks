#include <iostream>

using namespace std;

void segregate(int* a, int n) {

    int temp=0;
    for(int i=0;i<n;i++) {
        if(a[i]==0) {
            if(i!=temp) swap(a[i],a[temp]);
            temp++;
        }
    }

}

void more_complex(int* a, int n) {

    int left=0,right=n-1;
    while(left < right) {

        while(a[left]==0)
            left++;
        while(a[right]==1)
            right--;

        if(left < right) {
            swap(a[left],a[right]);
            left++;
            right--;
        }
    }
}

int main() {

    int N;
    cin >> N;
    int* a = new int[N];
    int* b = new int[N];
    for(int i=0;i<N;i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    segregate(a,N);

    cout << "The segregated array is: " << endl;
    for(int i=0;i<N;i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "A more complex way of doing it: " << endl;
    more_complex(b,N);

    for(int i=0;i<N;i++)
        cout << b[i] << " ";
    cout << endl;

}
