#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t=0;t<T;t++) {
		int K;
		cin >> K;
		
		int breaks = 0;

		int ups = 0;
		int downs = 0;
		int last = 0;

		for(int k=0;k<K;k++) {
			int cnum;
			cin >> cnum;
			if(k == 0) {
				last = cnum;
			}
			else if(cnum > last) {
				ups += 1;
				downs = 0;	
			}
			else if(cnum < last) {
				downs += 1;
				ups = 0;	
			}
			if(ups > 3 || downs > 3) {
				ups = 0;
				downs = 0;	
				breaks++;
			}
			last = cnum;
		}

		cout << "Case #" << t+1 << ": " << breaks << endl;
	}
}
