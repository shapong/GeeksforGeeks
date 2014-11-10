#include <iostream>
#include <algorithm>

using namespace std;

int min(int x, int y, int z) {
    return min(x,min(y,z));
}

int get_max_submatrix(int** m, int x, int y) {

    int** sub = new int*[x];
    for(int i=0;i<x;i++)
        sub[i] = new int[y];

    for(int i=0;i<y;i++)
        sub[0][i] = m[0][i];

    for(int i=0;i<x;i++)
        sub[i][0] = m[i][0];

    int max = 0,ind1,ind2;
    for(int i=1;i<x;i++) {
        for(int j=1;j<y;j++) {
            if(m[i][j]==1)
                sub[i][j] = min(sub[i-1][j-1],sub[i][j-1],sub[i-1][j]) + 1;
            else
                sub[i][j] = 0;
            if(sub[i][j] > max) {
                ind1 = i;
                ind2 = j;
                max = sub[i][j];
            }
        }
    }

    /*for(int i=0;i<x;i++) {
        for(int j=0;j<y;j++) {
            cout << sub[i][j] << " ";
        }
        cout << endl;
    }*/

    //cout << "The max value is " << max << " at " << ind1 << ", " << ind2 << endl;
    cout << "The maximum submatrix is a " << max << " by " << max << " matrix" << endl;
    cout << "Top left starts at: " << ind1-max+1 << ", " << ind2-max+1 << endl;
    return max;

}

int main() {

    int N,M;
    cin >> N >> M;
    int** mat = new int*[N];
    for(int i=0;i<N;i++)
        mat[i] = new int[M];

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> mat[i][j];
        }
    }

    int size = get_max_submatrix(mat,N,M);


}
