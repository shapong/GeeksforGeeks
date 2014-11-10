#include <iostream>

using namespace std;

bool match(const char *s1, const char* s2) {

    if(s1[0]=='\0' && s2[0] == '\0') return true;
    else if(s1[0]=='\0' && s2[0]!='\0') return false;
    else if(s1[0]!= '\0' && s2[0]=='\0') return false;

    if(s1[0] == s2[0])
        return match(s1+1,s2+1);

    else if(s1[0]=='*') {
        return match(s1+1,s2) || match(s1,s2+1);
    }

    else if(s1[0] == '?')
        return match(s1+1,s2+1);
    else return false;

}

bool improved_match(const char *s1, const char* s2, char mem) {

    if(s1[0]=='\0' && s2[0] == '\0') return true;
    else if(s1[0]=='\0' && s2[0]!='\0') return false;
    else if(s1[0]!= '\0' && s2[0]=='\0') return false;

    if(s1[0] == s2[0]) {
        mem = s1[0];
        return improved_match(s1+1,s2+1,mem);
    }

    else if(s1[0]=='*') {
        if(s2[0]== mem)
            return improved_match(s1+1,s2,mem) || improved_match(s1,s2+1,mem);
        else
            return improved_match(s1+1,s2,mem);
    }

    else if(s1[0] == '?')
        return improved_match(s1+1,s2+1,mem);

    else {mem = s1[0]; return false || improved_match(s1+1,s2,mem);}

}



int main() {

    //match strings with chars such as *(multiple chars) and ?(a single char)...
    //Here improved means that * means that there must be 0 or more occurence of the letter right before it...
    string s1,s2;
    char c;
    cin >> s1;
    cin >> s2;

    cout << ((match(s1.c_str(),s2.c_str())) ? "They match\n" : "They do not match\n");
    cout << ((improved_match(s1.c_str(),s2.c_str(),c)) ? "(Improved) They match\n" : "(Improved) They do not match\n");

}
