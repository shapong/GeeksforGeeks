#include <iostream>
#include <cstdlib>

using namespace std;

void shuffle(int* a, int n) {
    int ind;
    for(int i=n-1;i>=0;i--) {
        /// we use i+1 so that the curr index can also be the rand() index
        ind = rand() % (i+1);
        swap(a[ind],a[i]);
    }
    return;
}

int main() {
    int N;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    shuffle(a,N);
    //shuffle(a,N);
    //shuffle(a,N);

    for(int i=0;i<N;i++)
        cout << a[i] << " ";
    cout << endl;

}
