#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

long long int concat(string s1, string s2) {
    s1.append(s2);
    long long int n = 0;
    char* s = new char[s1.length()+1];
    strcpy(s,s1.c_str());
    for(int i=0;i<s1.length();i++){
        n += s1[i] - '0';
        n = n*10;
    }
    n = n/10;
    //cout << n << endl;
    return n;
}

bool mycompare(string string1, string string2) {

    string s1s2 = string1.append(string2);
    string s2s1 = string2.append(string1);

    return (s1s2.compare(s2s1) > 0) ? true : false;
    //if (concat(string1, string2) > concat(string2, string1)) return true;
    //else return false;
}

int main() {

    int N;
    string s;
    cin >> N;
    vector<string> a;
    for(int i=0;i<N;i++) {
        cin >> s;
        a.push_back(s);
    }

    sort(a.begin(),a.end(),mycompare);


    for(int i=0;i<a.size();i++) cout << a[i];
    cout << endl;

}
