#include "bits/stdc++.h"
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;

        int max_seat;
        max_seat = min( a , m );
        max_seat += min( b , m );
        max_seat = min(max_seat+c , 2*m);
        cout << max_seat << endl;
    }
    return 0;
}