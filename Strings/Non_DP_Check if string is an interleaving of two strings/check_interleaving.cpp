#include <iostream>
#include <string>

using namespace std;

bool check_interleaving(const char* a, const char* b, const char* c) {

    if(*c) {
        if(*c == *a && *c == *b)
            return (check_interleaving(++a,b,++c) || check_interleaving(a,++b,++c));

        else if(*c == *a)
            return check_interleaving(++a,b,++c);
        else if(*c == *b)
            return check_interleaving(a,++b,++c);
        else
            return false;
    }

    if(*a || *b) return false;

    return true;

}

int main() {

    string sa,sb,sc;
    cout << "Enter 3 strings" << endl;
    cin >> sa >> sb >> sc;


    cout << "Is " << sc << " an interleaving of " << sa << " and " << sb << "?" << endl;
    (check_interleaving(sa.c_str(),sb.c_str(),sc.c_str())) ? cout << "Yes\n" : cout << "No\n";

}
