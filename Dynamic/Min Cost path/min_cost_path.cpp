#include <iostream>
#include <climits>

using namespace std;

int min_cost(int** m, int N, int M) {

    int min;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            min = INT_MAX;
            if(i-1 >= 0 && m[i-1][j] < min) {
                min = m[i-1][j];
            }
            if(j-1 >= 0 && m[i][j-1] < min) {
                min = m[i][j-1];
            }
            if(i-1 >=0 && j-1 >=0 && m[i-1][j-1] < min) {
                min = m[i-1][j-1];
            }
            if(!(i==0 && j==0)) m[i][j] += min;
        }
    }
    return m[N-1][M-1];

}

int main() {


    int n,m;
    cin >> n >> m;

    int** mat = new int*[n];
    for(int i=0;i<n;i++)
        mat[i] = new int[m];

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> mat[i][j];
        }
    }

    cout << "The minimum cost path is:" << endl;
    cout << min_cost(mat,n,m) << endl;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

}
