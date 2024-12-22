#include "bits/stdc++.h"
using namespace std;


void SolveCode(){
    // Solve Code
    int n = 0;
    int abc[3];
    cin >> n >> abc[0] >> abc[1] >> abc[2];

    int three_day_path = abc[0] + abc[1] + abc[2];
    int Total_day = (n / three_day_path)*3;
    int remaining_path = n % three_day_path;
    for (int i=0; i<3; i++){
        if (remaining_path > 0){
            remaining_path -= abc[i];
            Total_day++;
        }
        else{
            break;
        }
    }
    cout << Total_day << endl;


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
