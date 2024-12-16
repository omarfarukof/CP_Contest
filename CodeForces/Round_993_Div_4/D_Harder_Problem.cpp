#include "bits/stdc++.h"
using namespace std;

void cout_arr(int* arr, int size){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}
void cin_arr(int* arr, int size){
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int main(){
    int t;
    cin >> t;
    for (int test_no = 0; test_no < t; test_no++) {
        int size_arr;
        cin >> size_arr;
        int A[size_arr];
        int absent[size_arr];
        for (int i = 0; i < size_arr; i++) {
            absent[i] = i+1;
        }

        // Read input Array A
        cin_arr(A, size_arr);

        for (int i = 0; i < size_arr; i++) {
            if (absent[A[i]-1] != 0){
                absent[A[i]-1] = 0;
            }
            else{
                A[i] = 0;
            }
        }

        int abs_i = 0;
        for (int i = 0; i < size_arr; i++) {
            if (A[i] == 0){
                while(absent[abs_i] == 0){
                    abs_i++;    
                }
                A[i] = absent[abs_i];
                abs_i++;
            }
        }
        cout_arr(A, size_arr);
        cout << endl;
    }

    return 0;
}