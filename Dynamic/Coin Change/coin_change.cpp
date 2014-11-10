#include <iostream>
#include <vector>

using namespace std;

int getChange(vector<int>& v, int n) {

    int* table = new int[n+1];
    for(int i=0;i<=n;i++) table[i] = 0;
    int size = v.size();

    table[0] = 1;
    for(int i=0;i<size;i++) {
        for(int j=v[i];j<=n;j++) {
            table[j] += table[j-v[i]];
        }
    }

    for(int i=0;i<=n;i++) {
        cout << table[i] << " ";
    }
    cout << endl;
    return table[n];

}

int main () {

    int N,num;
    cin >> N;
    vector<int> v;
    for(int i=0;i<N;i++) {
        cin >> num;
        v.push_back(num);
    }

    cout << "How many ways can we get change for N<Enter>?" << endl;
    cin >> num;

    cout << getChange(v,num) << endl;

}
