#include <iostream>

using namespace std;

void list_compare(char* s, int map[256], char** list, int list_size, int slen) {

    int i,length,k;
    for(int j=0;j<list_size;j++) {
        i=0;
        length = slen;
        while(list[j][i]!='\0') {
            if(length==0) { break; }
            if(map[list[j][i]] > 0) {
                map[list[j][i]]=0;
                length--;
            }
            i++;
        }
        if(!length) cout << list[j] << endl;

        ///Set map for next time
        k=0;
        while(s[k]!='\0') {
            map[s[k]]=1;
            k++;
        }
    }

}

int main() {

    char* s = new char[100];
    cout << "Enter a string" << endl;
    cin >> s;

    ///By doing map[]++ we require that repeated chars must have same freq in list word
    ///By doing map[]=1 we require that atleast each unique char is present once in the list word
    int map[256] = {0};
    int i=0,reps=0;
    while(s[i]!='\0') {
        if(map[s[i]]) reps+=1;
        map[s[i]]=1;
        i++;
    }

    int N;
    cout << "Enter the number of words you want to enter:" << endl;
    cin >> N;
    char** list = new char*[N];
    for(int j=0;j<N;j++) {
        list[j] = new char[100];
        cin >> list[j];
    }

    cout << "The words that have the common letters with the word " << s << " are:" << endl;
    list_compare(s,map,list,N,i-reps);

}
