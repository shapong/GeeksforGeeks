#include <iostream>

using namespace std;

int max_diff(int* a, int n) {

    int min_elem=a[0],max_diff=a[1]-a[0],first = 0,second=1;
    for(int i=1;i<n;i++) {
        if(a[i] - min_elem > max_diff) {
            max_diff = a[i] - min_elem;
            second = i;
            cout << a[i] << " minus " << min_elem << " equals " << max_diff << endl;
        }
        if(a[i] < min_elem) {
            min_elem = a[i];
            first = i;
        }
    }
    return max_diff;

}

int main() {

    int N;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    ///Max difference is between two numbers where the greater number is to the right...
    ///of the the smaller number...

    cout << "The max difference between two elements in the array is: " << max_diff(a,N) << endl;

}
