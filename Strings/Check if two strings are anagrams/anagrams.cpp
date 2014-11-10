#include <iostream>
#include <algorithm>

using namespace std;

bool check_anagrams(char* a, char* b) {

    int count1[256] = {0}, count2[256] = {0};

    int i;
    for(i=0;a[i]&&b[i];i++) {
        count1[a[i]]++;
        count2[b[i]]++;
    }

    if(a[i]||b[i])
        return false;

    for(int i=0;i<256;i++)
        if(count1[i]!=count2[i])
            return false;

    return true;

}

bool check_anagrams_again(char* a, char* b) {

    int len=0,len1=0;
    while(a[len]!='\0') len++;
    while(b[len1]!='\0') len1++;

    if(len1 != len) return false;

    sort(a,a+len);
    sort(b,b+len);

    for(int i=0;i<len;i++) {
        if(a[i]!=b[i])  return false;
    }

    return true;

}


int main() {

    char* a = new char[100];
    char* b = new char[100];

    cout << "Enter two strings:" << endl;
    cin >> a >> b;

    (check_anagrams(a,b)) ? cout << "They are anagrams" << endl : cout << "They are not anagrams" << endl;
    (check_anagrams_again(a,b)) ? cout << "They are anagrams" << endl : cout << "They are not anagrams" << endl;

}
