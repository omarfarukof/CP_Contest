#include "bits/stdc++.h"
using namespace std;


int remove_33(int x) {
    int no_digits = ceil(log10(x));
    int div = 100;
    for (int i = 1; i < no_digits; i++) {
        if ((x % div)/(div/100) == 33) {
            return ( (x/div)*(div/100) ) + ((x % div)%(div/100)) ;
        }
        div *= 10;
    }
    return x;
}

bool check_lock(int x) {
    if (x==0){
        return 1;
    }
    else if (x<33){
        return 0;
    }
    else if (x>=33 && x%33==0){
        return 1;
    }
    else{
        int new_x = remove_33(x);
        if (new_x != x){
            return check_lock(new_x);
        }
        else{
            return check_lock(x-33);
        }
    }
    
}


int main() {
    int t;
    cin>>t;
    string ans[2]={"NO","YES"};
    for (int TEST_CASE_NO=1;TEST_CASE_NO<=t;TEST_CASE_NO++) {
        int x;
        cin >> x;

        cout << ans[check_lock(x)] << endl;


    }
    return 0;
}