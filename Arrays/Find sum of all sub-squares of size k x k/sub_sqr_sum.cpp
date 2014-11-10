#include <iostream>

using namespace std;

void sub_sum(int** mat, int n, int k) {

    int** pp = new int*[n-k+1];
    for(int i=0;i<=n-k;i++) {
        pp[i] = new int[n];
    }

    for(int i=0;i<=n-k;i++)
        for(int j=0;j<n;j++)
            pp[i][j] = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<=n-k;j++) {
            for(int m=0;m<k;m++) {
                pp[j][i] += mat[j+m][i];
            }
        }
    }
    /*for(int i=0;i<=n-k;i++) {
        for(int j=0;j<n;j++) {
            cout << pp[i][j] << " ";
        }
        cout << endl;
    }*/

    int temp = n-k+1;
    int** result = new int*[temp];
    for(int i=0;i<temp;i++) {
        result[i] = new int[temp];
    }

    for(int i=0;i<=n-k;i++) {
        for(int j=0;j<=n-k;j++) {
            result[i][j] = 0;
        }
    }

    for(int i=0;i<=n-k;i++) {
        for(int j=0;j<=n-k;j++) {
            for(int l=0;l<k;l++) {
                result[i][j] += pp[i][j+l];
            }
        }
    }

    for(int i=0;i<=n-k;i++) {
        for(int j=0;j<=n-k;j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    int n,k;
    cout << "Enter a NxN matrix:" << endl;
    cin >> n;
    int** mat = new int*[n];
    for(int i=0;i<n;i++) {
        mat[i] = new int[n];
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Enter K the size of sub-matrices" << endl;
    cin >> k;
    cout << "The sum of the all KxK sub matrices are:" << endl;
    sub_sum(mat,n,k);

}
