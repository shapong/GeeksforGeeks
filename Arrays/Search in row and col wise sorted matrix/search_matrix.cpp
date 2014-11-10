#include <iostream>

using namespace std;

bool find_num(int** mat, int n, int m, int num) {

    int elem,i=0,j=m-1;
    while(1) {
        elem = mat[i][j];
        if(num == elem) { cout << "Element at [" << i << "," << j << "]" << endl; return true; }
        else if(num < elem) j--;
        else if(num > elem) i++;
        if(i >= n || j < 0) return false;
    }
}

int main() {

    int N,M,num;
    cout << "Enter a NxM matrix:" << endl;
    cin >> N >> M;
    int** mat = new int*[N];

    for(int i=0;i<N;i++)
        mat[i] = new int[M];

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Enter a number to find in this matrix:" << endl;
    cin >> num;

    (find_num(mat,N,M,num)) ? cout << "Found it" << endl : cout << "Couldn't find it" << endl;

}
