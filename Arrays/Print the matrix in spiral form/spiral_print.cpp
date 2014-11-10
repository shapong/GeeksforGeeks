#include <iostream>

using namespace std;

void spiral_print(int** mat, int n, int m) {

    int row=0,col=0;
    while(row < n && col < m) {
        //print topmost row
        for(int i=col;i<m;i++)
            cout << mat[row][i] << " ";
        row++;

        //print rightmost col
        for(int i=row;i<n;i++)
            cout << mat[i][m-1] << " ";
        m--;

        //print bottomost row
        ///IF condition since ROW changed in this run...
        if(row < n) {
            for(int i=m-1;i>=col;i--)
                cout << mat[n-1][i] << " ";
            n--;
        }

        //print leftmost col
        ///IF condition since M changed in this run...
        if(col < m) {
            for(int i=n-1;i>=row;i--)
                cout << mat[i][col] << " ";
            col++;
        }
    }

}

int main() {

    int N,M;
    cout << "Enter NxM dimensions:" << endl;
    cin >> N >> M;
    int** mat = new int*[N];

    for(int i=0;i<N;i++)
        mat[i] = new int[M];

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> mat[i][j];
        }
    }

    cout << "The spiral print of the matrix is:" << endl;
    spiral_print(mat,N,M);

}
