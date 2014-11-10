#include <iostream>
#include <string>
#include <stack>

using namespace std;

void removeAdj(string& s) {

    stack<char> st;

    int len = s.length();
    bool flag;
    char last_rem;
    int i=0;
    while(i < len) {
        flag = true;
        if(!st.empty()) last_rem = st.top();
        while(!st.empty() && s[i]==last_rem) {
            if(flag) st.pop();
            flag = false;
            i++;
        }
        if(flag) {
            st.push(s[i]);
            i++;
        }

    }

    s.clear();
    while(!st.empty()) {
        s.insert(s.begin(),st.top());
        st.pop();
    }

}

int main() {

    string s;
    cin >> s;

    cout << "After removing all adjacent characters" << endl;
    removeAdj(s);
    cout << s << endl;


}
