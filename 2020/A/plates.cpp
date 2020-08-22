#include <iostream>

using namespace std;
int main() {
	int t;
	cin >> t;
	for(int i = 0;i<t;i++) {
		int N, K, P;
		cin >> N >> K >> P;
		int sums[N][K+1];
		int maxscore[N][max(K, P)+1];

		for(int n = 0;n<N;n++) {
			int total = 0;
			sums[n][0] = 0;
			for(int k = 1;k<=K;k++) {
				int cplate;
				cin >> cplate;
				total += cplate;
				sums[n][k] = total;	
			}	
		}


		// Step through each stack
		for(int n = 0;n<N;n++) {
			// For every amount of plates we want to choose
			for(int j = 0;j<=P;j++) {
				int cmax = 0;
				// Check every possibility of plate choices from this stack
				for(int x = 0;x<=min(j, K);x++) {
					// Choose x plates from this stack and j-x plates from all past stacks
					int m = 0;
					if(n > 0) m = sums[n][x]+maxscore[n-1][j-x];	
					else m = sums[n][x];
					cmax = max(cmax, m);
				}		
				maxscore[n][j] = cmax;
			}
		}

		cout << "Case #" << i+1 << ": " << maxscore[N-1][P] << endl;
	}
}
