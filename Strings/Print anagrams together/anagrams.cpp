#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main() {

    //N words to enter...
    int N;
    cout << "How many strings?" << endl;
    cin >> N;
    string buf;
    vector<string> w;
    multimap<string,int, less<string> > words;
    for(int i=0;i<N;i++) {
        cin >> buf;
        w.push_back(buf);
        sort(buf.begin(),buf.end());
        words.insert(make_pair(buf,i));
    }

    //sort(words.begin(),words.end());

    cout << "THe anagrams are:" << endl;
    multimap<string,int, less<string> >::iterator it;
    for(it=words.begin();it!=words.end();it++) {
        //cout << it->first << " " << it->second << endl;
        cout << w[it->second] << endl;
    }
}
