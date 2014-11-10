#include <iostream>

using namespace std;

int longest_substr(string& s) {

    int len = s.length(),tmp_ind=0,curr_len=1,max_len=0,start = 0;

    int* tmp = new int[256];
    for(int i=0;i<256;i++) tmp[i] = -1;

    //int* count = new int[len];
    for(int i=0;i<len;i++) {

        //if its a repeating character....
        //tmp has the index of when the character was last seen....
        if(tmp[s[i]] >= start) {
            curr_len = 1;
            start = i;
        }

        //count[i] = curr_len;
        tmp[s[i]] = i;
        if(curr_len > max_len) max_len = curr_len;
        curr_len++;
    }
    for(int i=0;i<len;i++) {
        //cout << "random " << count[i] << endl;
    }
    return max_len;

}

int main() {

    string s;
    cin >> s;

    cout << "The longest substring without repeating characters is:" << endl;
    cout << longest_substr(s) << endl;

}
