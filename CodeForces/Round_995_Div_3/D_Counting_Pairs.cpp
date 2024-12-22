#include "bits/stdc++.h"
using namespace std;


void SolveCode(){
    // Solve Code
    // n -> No of Elements in Sequence A
    // x -> Lower Bound
    // y -> Upper Bound
    // A[n] -> Sequence

    int n, x, y;
    cin >> n >> x >> y;
    vector<int> A(n);
    for (int i=0; i<n; i++){    cin >> A[i];    }

    sort(A.begin(), A.end());

    int total_sum = 0;
    for (int i: A){    total_sum += i;    }

    int upper = total_sum - x;
    int lower = total_sum - y;

    int count = 0;
    
    cout << "X: " << x << " Y: " << y << endl << "Total Sum: " << total_sum << endl << "Lower: " << lower << " Upper: " << upper << endl;
    for (int i=0; i<n-1; i++){
        auto it_lower = lower_bound(A.begin()+i+1, A.end(), lower - A[i]);
        auto it_upper = lower_bound(A.begin()+i+1, A.end(), upper - A[i]);
        int c;
        if ((it_upper == A.begin()+i+1)&&(A[i+1] > upper-A[i])){
            c = 0;
        }
        else if (it_upper == A.end()){
            c = (distance(A.begin(), it_upper)) - (n-1) + 1 ;
        }
        else{
            c = (distance(A.begin(), it_upper)) - (distance(A.begin(), it_lower)) + 1 ;
        }

        count += max(c , 0);
        cout << "In: " << i << " Lower: " << lower - A[i] << " Upper: " << upper - A[i] << endl << " it_lower: " << distance(A.begin(), it_lower) << " It: " << *it_lower << endl  << " it_upper: " << distance(A.begin(), it_upper) << " It: " << *it_upper << endl;
        cout << "Count: " << max(c , 0) << endl;
    }






    // for(int i=0; i<n; i++){
    //     cout << A[i] << " ";
    // }
    // cout << endl;

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
