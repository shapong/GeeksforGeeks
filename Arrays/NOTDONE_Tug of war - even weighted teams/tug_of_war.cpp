#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void tug_of_war_teams(int *a , int n) {

    vector<int> A,B;
    int addingA,addingB,sumA=0,sumB=0;
    for(int i=0;i<n;i++) {
        addingA = abs((sumA + a[i]) - sumB);
        addingB = abs((sumB + a[i]) - sumA);
        if(addingA < addingB) {
            A.push_back(a[i]);
            sumA += a[i];
        }
        else {
            B.push_back(a[i]);
            sumB += a[i];
        }

    }

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    int loop = (A.size() > B.size()) ? ((A.size() - B.size())/ 2) : ((B.size() - A.size()) / 2);
    bool biggerA = (A.size() > B.size()) ? true : false;

    for(int i=0;i<loop;i++){
        if(biggerA){
            if(sumA > sumB){
                for(int j=0;j<A.size();j++){
                    if(A[j] > 0 || j==A.size()-1) {
                        B.push_back(A[j]);
                        A.erase(A.begin()+j,A.begin()+(j+1));
                        break;
                    }
                }
            }
            else {
                B.push_back(A[0]);
                A.erase(A.begin(),A.begin()+1);
            }
        }
        else {
            if(sumB > sumA) {
                for(int j=0;j<B.size();j++){
                    if(B[j] > 0 || j==B.size()-1) {
                        A.push_back(B[j]);
                        B.erase(B.begin()+j,B.begin()+(j+1));
                        break;
                    }
                }
            }
            else {
                A.push_back(B[0]);
                B.erase(B.begin(),B.begin()+1);
            }

        }
    }


    for(int i=0;i<A.size();i++) cout << A[i] << " ";
    cout << endl;
    for(int i=0;i<B.size();i++) cout << B[i] << " ";
    cout << endl;

}


int main() {

    int N;
    cin >> N;
    int *a = new int[N];
    for(int i=0;i<N;i++)
        cin >> a[i];

    sort(a,a+N);
    reverse(a,a+N);
    tug_of_war_teams(a,N);


}
