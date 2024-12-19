#include "bits/stdc++.h"
using namespace std;

void print(int* arr , int arr_size);
void print(vector<int> vec);
int ceil_div(int a, int b) { return (a + b - 1) / b; }

void min_permutation(int n, int k , int arr[]) {
    // int min_n = ceil_div(n, k);
    // // DEBUG
    // cout << "Case : >>>" << endl;
    //
    int max_num = n;
    for (int i = 0; i < n; i++) {
        if ( k == 1) {
            arr[i] = n - i;
        }
        else if ( (i-k+1)%(k) == 0 ) {
            // // DEBUG
            // cout << "  Value : " << (i-k+1)/(2*k-2) +1 << "" << endl;
            //
            arr[i] = ((i-k+1)/(k)) +1;
            // arr[i] = 0;
            // min_n--;
        }
        else{
            arr[i] = max_num;
            max_num--;
        }
        // arr[i] = n - i;
    }
}


int main() {
    int t;
    cin >> t;
    for (int TEST_CASE_NO = 0; TEST_CASE_NO < t; TEST_CASE_NO++) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        // // // DEBUG
        // cout << "n , k : >>>" << n << " " << k << endl;
        // //
        min_permutation(n, k , arr);
        print(arr , n);


    }
    return 0;
}


void print(int* arr , int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void print(vector<int> vec) {
    for (auto v: vec) {
        cout << v << " ";
    }
    cout << endl;
}
