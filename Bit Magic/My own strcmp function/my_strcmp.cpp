#include <iostream>

using namespace std;

int my_strcmp(char* s1, char* s2) {

    int i=0;
    while(s1[i] != '\0' && s2[i] !='\0') {
        if(s1[i]==s2[i] || (s1[i] ^ 32)==s2[i])
            i++;
        else
            break;
    }
    ///if same length and are same return 0
    ///if string 1 is greater than string 2 return 1
    ///if string 1 is smaller than string 2 return -1

    if(s1[i]==s2[i])
        return 0;
    if((s1[i]|32) < (s2[i]|32))
        return -1;
    //Two strings are different length
    return 1;

}

int main() {

    char* s1 = new char[100],*s2 = new char[100];
    cin >> s1 >> s2;

    cout << "Strcmp: " << my_strcmp(s1,s2) << endl;
}
