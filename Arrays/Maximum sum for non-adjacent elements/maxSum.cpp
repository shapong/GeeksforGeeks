#include <iostream>

using namespace std;

int getMaxSum(int* a, int n) {

    int incl=a[0],excl=0,new_excl;
    for(int i=1;i<n;i++) {
        new_excl = max(incl,excl);
        incl = excl + a[i];
        excl = new_excl;
        cout << "Incl: " << incl << endl;
        cout << "Excl: " << excl << endl;
    }
    return max(incl,excl);
}

int main() {

    int N;
    cout << "Enter an array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "The maximum non-adjacent sum is:" << endl;
    cout << getMaxSum(a,N) << endl;

}
