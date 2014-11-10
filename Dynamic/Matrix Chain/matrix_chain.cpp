#include <iostream>
#include <vector>

using namespace std;

int matrixChain(vector<int>& v) {

    int size = v.size();
    int** m = new int*[size];
    for(int i=0;i<size;i++) m[i] = new int[size];

    for(int i=0;i<size;i++) m[i][i] = 0;

    int j=0;
    for (int l=2; l<size; l++){
        for (int i=1; i<size-l+1; i++) {
            j = i+l-1;
            cout << "i j: " << i << " " << j << endl;
            for (int k=i; k<=j-1; k++) {
                m[i][j] = m[][] + m[][] + v[i]*v[k]*v[j];
            }
        }
    }

}

int main() {

    int N,dim1,dim2;
    cin >> N;

    vector<int> v;
    for(int i=0;i<N;i++) {
        cin >> dim1 >> dim2;
        v.push_back(dim1);
    }

    cout << "The minimum number of multiplications required is:" << endl;
    cout << matrixChain(v) << endl;

}
