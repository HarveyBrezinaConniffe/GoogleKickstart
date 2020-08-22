#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t=0;t<T;t++) {
		int N;
		cin >> N;

		long long nums[N];

		for(int n=0;n<N;n++) {
			cin >> nums[n];
		}

		long long largest = -1;
		long long records = 0;

		for(int n=0;n<N;n++) {
			long long cnum = nums[n];
			if(cnum > largest) {
				if(n==N-1) {
					records++;	
				}	
				else if(cnum > nums[n+1]) {
					records++;	
				}
			}
			largest = max(largest, cnum);
		}	

		cout << "Case #" << t+1 << ": " << records << endl;
	}
}
