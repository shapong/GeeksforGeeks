#include <iostream>

using namespace std;

bool isInterleaved(char* a, char* b, char* c) {

    while(*c!='\0') {
        if(*a == *c)
            a++;

        else if(*b == *c)
            b++;

        else
            return false;
        c++;
    }

    if(*a || *b) return false;
    return true;

}

int main() {

    char* a = new char[100];
    char* b = new char[100];
    char* c = new char[100];

    cin >> a >> b >> c;

    ///ab..cd...acbd...
    cout << "Are strings " << a << " and " << b << " interleaved?" << endl;
    (isInterleaved(a,b,c)) ? cout << "Yes" << endl : cout << "No" << endl;

}
