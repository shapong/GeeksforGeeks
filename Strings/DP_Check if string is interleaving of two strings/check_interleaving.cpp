#include <iostream>
#include <string>

using namespace std;

int memo[100000];
bool check_interleaving(const char* a, const char* b, const char* c, int ci) {

    if(memo[ci] != -1)
        return (memo[ci]==1) ? true : false;

    bool a1;
    if(*c) {
        if(*c == *a && *c == *b)
            a1 = (check_interleaving(++a,b,++c,ci+1) || check_interleaving(a,++b,++c,ci+1));

        else if(*c == *a)
            a1 = check_interleaving(++a,b,++c,ci+1);
        else if(*c == *b)
            a1 = check_interleaving(a,++b,++c,ci+1);
        else
            a1 = false;
    }

    else
        a1 = (*a || *b) ? false : true;
    memo[ci] = (a1) ? 1 : 0;
    return a1;
}

int main() {

    string sa,sb,sc;
    cout << "Enter 3 strings" << endl;
    cin >> sa >> sb >> sc;

    for(int i=0;i<100000;i++) memo[i] = -1;
    cout << "Is " << sc << " an interleaving of " << sa << " and " << sb << "?" << endl;
    (check_interleaving(sa.c_str(),sb.c_str(),sc.c_str(),0)) ? cout << "Yes\n" : cout << "No\n";

}
