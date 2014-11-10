#include <iostream>

using namespace std;

char* run_length_encoding(char* s, int len) {

    int count = 0,ind=0;
    char curr_char = s[0];

    char* new_str = new char[2*len+1];

    for(int i=0;i<len;i++) {
        if(s[i]!=curr_char) {
            //cout << curr_char << '0'+count;
            new_str[ind] = curr_char; ind++;
            new_str[ind] = '0'+count; ind++;
            count=0;
            curr_char = s[i];
        }
        count++;
    }
    //cout << curr_char << count;
    new_str[ind] = curr_char; ind++;
    new_str[ind] = '0'+count; ind++;
    new_str[ind] = '\0';

    return new_str;
}

int main() {

    char* s = new char[100],*new_s;
    cin >> s;

    int i=0;
    while(s[i]!='\0') i++;
    new_s = run_length_encoding(s,i);

    cout << "The run-length encoding is:" << endl;
    cout << new_s << endl;

}
