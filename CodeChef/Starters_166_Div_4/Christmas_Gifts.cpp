#include <bits/stdc++.h>
using namespace std;

#define total_paper 1000
#define s_area(h, l, w) (2*(h*l + l*w + w*h))


int main() {
	// your code goes here
    int t;
    cin >> t;
    int h, l, w;
    while(t--) {
        cin >> h >> l >> w;
        cout << total_paper / s_area(h, l, w) << endl;
    }    

    return 0;
}
