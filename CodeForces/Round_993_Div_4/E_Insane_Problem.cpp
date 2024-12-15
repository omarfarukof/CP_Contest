#include "bits/stdc++.h"
#include <cmath>
using namespace std;
typedef long long int ll;

ll max(ll a, ll b){
    if (a > b) return a;
    return b;
}
ll min(ll a, ll b){
    if (a < b) return a;
    return b;
}
double log(ll base, double num){
    return (double)log(num)/log(base);
}

ll div_ceil(ll a, ll b){
    //ceil(a/b)
    return (a+b-1)/b;
}

int main(){
    int t;
    cin >> t;
    for (int tc=0; tc<t; tc++){
        ll k;
        ll x_min, x_max, y_min, y_max;
        cin >> k >> x_min >> x_max >> y_min >> y_max;

        // Solve
        // y/x = k^n
        // y = x*k^n
        // y_max = x_min*k^n_max => n_max = log(y_max/x_min)/log(k)
        // y_min = x_min*k^n_min => n_min = log(y_min/x_min)/log(k)
        // n_max = log(y_max/x_min)/log(k);
        // n_min = log(y_min/x_min)/log(k);
        // Kn_max = div_ceil(y_max, x_min);
        // Kn_min = div_ceil(y_min, x_min);
        // ll n_max = log(k,Kn_max);
        // ll n_min = log(k,Kn_min);
        
        int min_n = 0;
        ll n_max = log(k, div_ceil(y_max, x_min));
        ll n_min = log(k, div_ceil(y_min, x_max));
        // ll n_min = log(k, div_ceil(y_min, x_max));
        n_max = max( n_max , min_n);
        n_min = max( n_min , min_n);
        
        ll count = 0;

        // // Debugging
        // cout << endl <<"Case: " << tc+1 << endl;
        // cout << "Y range: [" << y_min << ", " << y_max << "]" << endl;
        // cout << "X range: [" << x_min << ", " << x_max << "]" << endl;
        // cout << "K: " << k << endl;
        // cout << "N range: [" << n_min << ", " << n_max << "]" << endl;
        // //

        ll Kn = pow(k,n_min-1);
        for (ll i=n_min; i<=n_max; i++){
            Kn = pow(k, i);
            ll k_min = max(y_min, x_min*Kn);
            ll k_max = min(y_max, x_max*Kn);
            k_min = div_ceil(k_min, Kn);
            k_max = (k_max / Kn);
            count += max(0, k_max-k_min+1);

            // // Debugging
            // cout << "Kn: " << Kn << endl;
            // cout << "X*Kn Range: [" << x_min*Kn << ", " << x_max*Kn << "]" << endl;
            // cout << "Common Y Range: [" << max(y_min, x_min*Kn) << ", " << min(y_max, x_max*Kn) << "]" << endl;
            // cout << "Common X Range: [" << k_min << ", " << k_max << "]" << endl;
            // cout << "Count: " << k_max-k_min+1 << endl;
            // //


        } 
        cout << count << endl;

    }
    return 0;
}
