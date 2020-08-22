#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t=0;t<T;t++) {
		int N, A, B;
		cin >> N >> A >> B;

		int tree[N];

		tree[0] = -1;

		double Aprobs[N];
		double Bprobs[N];

		for(int n = 1;n<N;n++) {
			int cnum;
			cin >> cnum;	
			cnum -= 1;
			tree[n] = cnum;
		}

		for(int n = 0;n<N;n++) {
			Aprobs[n] = 1;
			int parent = tree[n];
			int acount = 0;
			while(true) {
				if(acount == A) {
					Aprobs[n] += 1;
					acount = 0;
				}	
				if(parent != -1) parent = tree[parent];
				else break;
				acount++;
			}
		}

		for(int n = 0;n<N;n++) {
			Bprobs[n] += 1;
			int parent = tree[n];
			int bcount = 0;
			while(true) {
				if(bcount == B) {
					Bprobs[n] += 1;
					bcount = 0;
				}	
				if(parent != -1) parent = tree[parent];
				else break;
				bcount++;
			}
		}

		for(int n = 0;n<N;n++) {
			Aprobs[n] /= N;
			cout << Aprobs[n] << " ";
		}
		cout << endl;
		for(int n = 0;n<N;n++) {
			Bprobs[n] /= N;
			cout << Bprobs[n] << " ";
		}
		cout << endl;

	}
}
