#include <iostream>

using namespace std;

int find_one(int* m, int low, int high) {

    if(low > high) return -1;
    int mid = (low+high)/2;

    if(mid==0 && m[mid]==1) return mid;
    else if(mid!=0 && m[mid]==1 && m[mid-1]==0) return mid;

    if(m[mid]==0)
        return find_one(m,mid+1,high);
    else if(m[mid]==1)
        return find_one(m,low,mid-1);


}

int find_max_ones(int** mat, int n, int m) {

    int first_one=find_one(mat[0],0,m-1),max=first_one,row=-1;
    max = (max==-1) ? 0 : max;
    for(int i=1;i<n;i++) {
        if(max!=-1 && mat[i][m-max-1]==1) {
            first_one = find_one(mat[i],0,m-1);
            if(first_one!=-1 && m-first_one > max) {
                max = m-first_one;
                row = i;
            }
        }
    }
    cout << "The maximum number of ones is: " << max << endl;
    return row;

}

int find_max_again(int** mat, int n, int m) {

    int first_row = find_one(mat[0],0,m-1),row=0;
    row = (first_row==-1) ? -1 : row;
    first_row = (first_row==-1) ? m-1 : first_row;

    for(int i=1;i<n;i++) {
        if(mat[i][first_row]==1) {
            while(mat[i][first_row]==1 && first_row >=0)
                first_row--;
            row = i;
        }
    }
    cout << "The maximum number of ones is: " << m-first_row-1 << endl;
    return row;

}

int main() {

    int N,M;
    cout << "Enter NxM matrix dimensions:" << endl;
    cin >> N >> M;

    int** mat = new int*[N];
    for(int i=0;i<N;i++)
        mat[i] = new int[M];

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> mat[i][j];
        }
    }

    int row = find_max_ones(mat,N,M);
    cout << "The row with the maximum number of ones is: " << row << endl;
    cout << "Again...the row with the maximum number of ones is: " << find_max_again(mat,N,M) << endl;

}
