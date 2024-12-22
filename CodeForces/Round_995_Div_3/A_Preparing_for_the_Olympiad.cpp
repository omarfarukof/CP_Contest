#include "bits/stdc++.h"
using namespace std;


void SolveCode(){
    // Solve Code

    int n;
    cin >> n;
    int A[n], B[n];
    int count = 0;
    for (int i=0; i<n; i++){    cin >> A[i];    }
    for (int i=0; i<n; i++){    cin >> B[i];    }

    for (int i=0; i<n-1; i++){
        if (A[i] > B[i+1]){
            count += A[i] - B[i+1];
        }
    }
    count += A[n-1];
    cout << count << endl;

}


int main(){
    int t;
    cin >> t;

    for (int TEST_CASE_NO=0; TEST_CASE_NO<t; TEST_CASE_NO++){
        //Solve Code

        SolveCode();

    }


    return 0;
}
