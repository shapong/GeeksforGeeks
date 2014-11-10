#include <iostream>
#include <algorithm>

using namespace std;

int find_ceil_ind(char* s, int start, int size) {

    char c = s[start]; //the fisrt character
    int ceil=start+1;
    for(int i=start+1;i<size;i++) {
        if(s[i] > c && s[i] < s[ceil]) ceil = i;
    }
    return ceil;

}

void reverse(char* s, int start, int size) {

    int left=start+1,right=size-1;
    while(left < right) {
        swap(s[left],s[right]);
        left++;
        right--;
    }

}

void print_permutations(char* s) {

    int len=0,i;
    while(s[len]!='\0') len++;
    sort(s,s+len);

    cout << s << endl;

    while(1) {
        for(i=len-2;i>=0;i--) {
            //cout << s[i] << " " << s[i+1] << endl;
            if(s[i] < s[i+1]) break;
        }

        if(i==-1) break;

        //else cout << s[i] << endl;

        int ind = find_ceil_ind(s,i,len);

        //cout << ind;

        swap(s[i],s[ind]);
        reverse(s,i,len);
        cout << s << endl;
    }

}

int main() {

    char* s = new char[100];
    cin >> s;

    cout << "The permutation in lexicographic order are:" << endl;
    print_permutations(s);

}
