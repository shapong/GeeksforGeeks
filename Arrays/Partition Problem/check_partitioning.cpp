#include <iostream>

using namespace std;

bool check_partition(int* a, int n) {

    int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];
    if(sum%2==1) return false;
    else cout << "Each partitioned array has a sum of " << sum/2 << endl;

    int** table = new int*[(sum/2) + 1];
    for(int i=0;i<=sum/2;i++)
        table[i] = new int[n+1];

    for(int i=0;i<=n;i++) table[0][i] = true;
    for(int i=1;i<=sum/2;i++) table[i][0] = false;

    ///Here 'i' is the partial sum we are looking for...
    for(int i=1;i<=sum/2;i++) {
        for(int j=1;j<=n;j++) {
                table[i][j] = table[i][j-1];
                if(i >= a[j-1])
                    table[i][j] = table[i][j] || table[i - a[j-1]][j-1];
        }
    }

    return table[sum/2][n];
}

int main() {

    int N;
    cout << "Enter an array:" << endl;
    cin >> N;
    int* a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    cout << "Can the array be partitioned into 2 arrays with EQUAL sum?" << endl;
    check_partition(a,N) ? cout << "True\n" : cout << "False\n";
}
