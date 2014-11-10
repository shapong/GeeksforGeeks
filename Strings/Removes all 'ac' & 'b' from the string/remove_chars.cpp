#include <iostream>

using namespace std;

char* remove_ac_b(char* s, int len) {

    char* revised_copy = new char[len+1];
    int pt=0,ind=0,state=1;
    while(pt < len) {

        if(state==1 && s[pt]!='b' && s[pt]!='a') {
            revised_copy[ind] = s[pt];
            ind++;
        }

        else if (state==2) {
            if(s[pt]!='c') {
                revised_copy[ind] = 'a';
                ind++;
            }
            if(s[pt]!='b' && s[pt]!='a' && s[pt]!='c') {
                revised_copy[ind] = s[pt];
                ind++;
            }
        }

        state = (s[pt]=='a') ? 2 : 1;
        pt++;
    }
    if(state==2) {
        revised_copy[ind] = s[pt-1];
        ind++;
    }
    revised_copy[ind] = '\0';
    return revised_copy;

}

int main() {

    char* s = new char[100],*new_str;
    cout << "Enter a string" << endl;
    cin >> s;

    int i=0;
    while(s[i]!='\0') {
        i++;
    }
    ///Removes all 'ac' and 'b' from the string...
    new_str = remove_ac_b(s,i);
    i=0;
    while(new_str[i]!='\0') {
        i++;
    }

    for(int j=0;j<i;j++)
        cout << new_str[j];
    cout << endl;

}
