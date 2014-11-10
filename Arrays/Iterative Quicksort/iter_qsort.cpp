#include <iostream>
#include <stack>

using namespace std;

int partition(int* a, int low, int high) {

    //cout << "Low: " << low << " High: " << high << endl;
    int Index = low, val = a[high];
    for(int i=low;i<high;i++) {
        if(a[i] <= val) {
            swap(a[i],a[Index]);
            Index++;
        }
    }
    swap(a[high],a[Index]);
    return Index;
}

void iter_quicksort(int* a, int low, int high) {

    stack<int> s;
    s.push(high);
    s.push(low);

    int p;
    while(!s.empty()) {
        low = s.top(); s.pop();
        high = s.top(); s.pop();

        p = partition(a,low,high);
        //cout << "P: " << p << endl;
        if(p-1 > low) {
            s.push(p-1);
            s.push(low);
        }
        if(p+1 < high) {
            s.push(high);
            s.push(p+1);
        }
    }
}

int main() {

    int N;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    iter_quicksort(a,0,N-1);

    for(int i=0;i<N;i++)
        cout << a[i] << " ";
    cout << endl;

}
