#include "bits/stdc++.h"
using namespace std;


void SolveCode(){
    // Solve Code
    // n -> No of Total Questions
    // m -> No of Total Question Papers (Each with n-1 questions)
    // k -> No of Total Known Questions 
    // Q[k] -> List of Known Questions
    // A[m] -> List of Question Papers (Each with n-1 questions) ->> (Return for each Question Papers)

    int n, m, k;
    cin >> n >> m >> k;
    int A[m], Q[k];
    for (int i=0; i<m; i++){    cin >> A[i];    }
    for (int i=0; i<k; i++){    cin >> Q[i];    }

    if (k < n-1){
        for (int i=0; i<m; i++){    cout << "0";    }
        cout << endl;
        return;
    }
    if (k > n-1){
        for (int i=0; i<m; i++){    cout << "1";    }
        cout << endl;
        return;
    }

    vector<int> not_q;
    int not_q_count = 0;
    for (int i=1; i<=n; i++){
        if (Q[not_q_count] != i){
            not_q.push_back(i);
        }
        else{
            not_q_count++;
        }
        // cout << "Count: " << not_q_count << endl;
    }



    // for (auto v: not_q){    cout << v << " ";   }

    for (int i=0; i<m; i++){
        auto it = lower_bound(not_q.begin(), not_q.end(), A[i]);
        if ((it != not_q.end()) && (*it == A[i])){
            cout << "1";
        }
        else{
            cout << "0";
        }
    }

    cout << endl;

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
