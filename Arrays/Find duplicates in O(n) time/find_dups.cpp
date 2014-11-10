#include <iostream>
#include <cstdlib>

using namespace std;

void repeating_elements(int* a, int n) {

    int ind;
    for(int i=0;i<n;i++) {
        ind = abs(a[i]);
        if(a[ind] < 0) {
            cout << ind << " is a repeated element" << endl;
            a[ind] = a[ind]*-1;
        }
        else if(a[ind] > 0)
            a[ind] = a[ind]*-1;
    }
}

int main() {

    int N;
    cout << "Enter the array:" << endl;
    cin >> N;
    cout << "You can only enter in " << N << " numbers between 0 and " << N-1 << " <inclusive>" << endl;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    ///If we have N elements the numbers can only be from 0-->N-1
    cout << "The duplicates in the array are:" << endl;
    repeating_elements(a,N);

}
