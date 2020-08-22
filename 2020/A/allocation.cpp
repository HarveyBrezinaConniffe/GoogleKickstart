#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
	int t, n, b, l, cb;
	cin >> t;
	for(int i = 0;i<t;i++) {
		cin >> n >> b;
		int houses[n];
		for(int k = 0;k<n;k++) {
			cin >> houses[k];	
		}	
		sort(houses, houses+n);
		cb = 0;
		l = 0;
		while(b-houses[l] >= 0 && l < n) {
			b -= houses[l];
			cb++;
			l++;	
		}
		cout << "Case #" << i+1 << ": " << cb << endl;
	}
}
