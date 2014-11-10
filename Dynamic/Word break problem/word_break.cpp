#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool dictHas(vector<string>& d, string s) {

    if(find(d.begin(),d.end(),s)==d.end()) return false;
    return true;
}

bool canBreak(vector<string>& d, string s) {

    int len = s.length();
    vector<bool> wb(len+1,false);
    for(int i=1;i<=len;i++) {
        if((!wb[i]) && dictHas(d,s.substr(0,i))) wb[i] = true;

        if(wb[i]) {
            if(i==len) return true;

            for(int j=i+1;j<=len;j++) {
                if((!wb[j]) && dictHas(d,s.substr(i,j-i))) wb[j] = true;

                if(j==len && wb[j]) return true;
            }
        }
    }
    return false;

}

int main() {

    int n;
    cout << "Enter the dictionary:" << endl;
    cin >> n;

    vector<string> dict;
    string s,input;
    for(int i=0;i<n;i++) {
        cin >> s;
        dict.push_back(s);
    }

    cout << "Enter an input:" << endl;
    cin >> input;
    cout << "Can " << input << " be split into words in the dictionary?" << endl;
    (canBreak(dict,input)) ? cout << "Yes\n" : cout << "No\n";

}
