#include <iostream>

using namespace std;

int moores_voting(int* a, int n) {

    ///get candidate element...
    int maj_ind = 0,count=1;
    for(int i=1;i<n;i++) {
        if(a[maj_ind]==a[i]) count++;
        else count--;
        if(count==0) {
            maj_ind = i;
            count = 1;
        }
    }

    ///check if candidate element is majority or not...
    int final_count = 0;
    for(int i=0;i<n;i++) {
        if(a[i]==a[maj_ind]) final_count++;
    }

    if(final_count <= n/2) cout << "There is no majority element in the array" << endl;
    return (final_count > n/2) ? a[maj_ind] : -1;

}

int main() {

    int N;
    cout << "Enter an array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "The majority element in the array is:" << endl;
    cout << moores_voting(a,N) << endl;
}
