#include <iostream>
#include <sstream>
#include <string>
#include <istream>
#include <cstdio>

using namespace std;

int main() {

	string str;
	getline(cin,str);

	istringstream iss(str);

	int count=0;
	string word;
	while(iss >> word) {
		cout << word << endl;
		count++;
	}

	cout << "The number of words in the sentence is: " << count << endl;

	int count1 = 0;
	char st[] = "One two          three\n  four\nfive  ";
	istringstream is(st);
	while(is >> word) {
		cout << word << endl;
		count1++;
	}

	cout << "The number of words in the sentence is: " << count1 << endl;

}
