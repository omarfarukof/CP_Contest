#include "bits/stdc++.h"
// #include <unordered_map>
using namespace std;

char mirror(char& c){
    if (c == 'q')   return 'p';
    if (c == 'p')   return 'q';
    if (c == 'w')   return 'w';
} 

int main(){
    int t;
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        for (int i = s.size()-1; i >= 0; i--){
            cout << mirror(s[i]);
        }
        cout << endl;
    }
    return 0;
}