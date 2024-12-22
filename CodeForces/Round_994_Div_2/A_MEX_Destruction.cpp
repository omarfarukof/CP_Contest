#include "bits/stdc++.h"
using namespace std;

int mex_deletion(vector<int> v , int start , int end) {
    if (start >= end) {
        if (v[start] == 0) {
            return 0;
        }
        else {
            return 1;
        }
    }
    int no_zeros=0 , no_non_zeros=0 ;
    int zero_trancat=0 , non_zero_trancat=0;
    for (int i = start; i <= end; i++){
        bool first_zero = (v[start] == 0);
        bool last_zero = (v[end] == 0);
        // Trancate the First and Last Zeroes
        if (first_zero || last_zero) {
            return mex_deletion(v, start + first_zero, end - last_zero);
        }

        if (v[i] == 0) {
            no_zeros++;
            if (no_zeros == i+1) {
                zero_trancat++;
            }
        }
        else {
            no_non_zeros++;
            if (no_non_zeros == i+1) {
                non_zero_trancat++;
            }

        }



    }
    
    if ((no_zeros == end-start)) {
        return 0;   // For All Zeroes
    }
    else if ((no_zeros == zero_trancat)||(no_non_zeros == non_zero_trancat)) {
        return 1;
    }
    else if (no_zeros == 0) {
        return 1;   // For All Non-Zeros
    }
    else {
        return 2;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {    
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        cout << mex_deletion(v,0,n-1) << endl;
        

    }
    return 0;
}