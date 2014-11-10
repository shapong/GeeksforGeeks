#include <iostream>
#include <vector>

using namespace std;

bool stronger_pref(int new_man, int old_man, int woman, int n, int** pref) {

    int ind_new,ind_old;
    for(int i=0;i<n;i++) {
        if(pref[woman][i]==new_man) ind_new=i;
        else if(pref[woman][i]==old_man) ind_old = i;
    }

    return (ind_new < ind_old) ? true : false;
}

void stable_marriage(int** pref, int n) {

    vector<bool> men_free (n,true);
    vector<int> woman_free (2*n,-1);
    vector<int> pair (n,-1);
    vector<int> not_yet_proposed (n,0);

    int i=0,w;
    bool flag = false;
    /// 'i' is the current man
    while(men_free[i]) {
        w = pref[i][not_yet_proposed[i]];
        if(woman_free[w]==-1) {
            pair[i]=w;
            woman_free[w]=i;
            men_free[i]=false;
            flag = true;
        }
        else {
            ///woman w is with woman_free[w] (man)...and find i in pref[][]...
            if(stronger_pref(i,woman_free[w],w,n,pref)) {  ///then change partners...
                men_free[woman_free[w]] = true;
                pair[woman_free[w]] = -1;
                woman_free[w] = i;
                men_free[i] = false;
                pair[i] = w;
                flag = true;
            }
        }
        ///i++ if we finished this man otherwise next++;
        int temp =i;
        if(flag) {
            for(int j=0;j<n;j++) {
                if(men_free[j]) {
                    i = j;
                    break;
                }
            }
        }
        not_yet_proposed[temp]++;
        flag = false;
    }

    cout << "Men    Women" << endl;
    for(int j=0;j<n;j++) {
        cout << j << "      " << pair[j] << endl;
    }
}

int main() {

    int N;
    cout << "Enter the number of women/men(same).." << endl;
    cin >> N;
    int** pref = new int*[2*N];
    for(int i=0;i<2*N;i++)
        pref[i] = new int[N];

    for(int i=0;i<2*N;i++) {
        for(int j=0;j<N;j++) {
            cin >> pref[i][j];
        }
    }

    stable_marriage(pref,N);

}
