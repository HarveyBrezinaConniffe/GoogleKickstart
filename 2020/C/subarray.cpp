#include <iostream>
#include <cmath>

using namespace std;
int main() {
	int t, n;
	cin >> t;
	for(int i = 0;i<t;i++) {
		cin >> n;
		int nums[n];
		for(int k=0;k<n;k++) {
			cin >> nums[k];	
		}	

		int smallestsum = 9999999;
		int largestsum = 0;
		int total = 0;
		int largestnum = 0;
		for(int l = 0;l<n;l++) {
			int num = nums[l];
			total += num;
			largestnum = max(largestnum, num);
			smallestsum = min(smallestsum, total);
			largestsum += max(0, num);	
		}
		
		int ps[int(sqrt(n*largestnum))];
		int cnum = 0;
		int csquare = 0;
		int k = 0;
		while(csquare <= n*largestnum) {
			csquare = cnum*cnum;	
			ps[k] = csquare;
			k++;
			cnum++;
		}

		int offset = abs(min(0, smallestsum));	
		int totals[largestsum+offset+1] = {};
		totals[0+offset] = 1;
		long long perfectsubarrays = 0;
		total = 0;
		for(int l = 0; l < n; l++) {
			int N = nums[l];
			total += N;
			for(int s = 0;s<k;s++) {
				int remainder = total-ps[s];
				if(remainder+offset < 0) {
					break;
				}	
				perfectsubarrays += totals[remainder+offset];
			}	
			totals[total+offset] += 1;
		}
		cout << "Case #" << i+1 << ": " << perfectsubarrays << endl;
	}
}
