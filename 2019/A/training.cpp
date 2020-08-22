#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    int t;
    cin >> t;
    for(int i = 0;i<t;i++) {
        int N, P;
        cin >> N >> P;
        int skills[N];
        for(int n = 0;n<N;n++) {
            int cskill;
            cin >> cskill;
            skills[n] = cskill;
        }

        sort(skills, skills+N, greater<int>());

	int sums[N];
	int sum = 0;
	for(int n = 0;n<N;n++) {
		sum += skills[n];	
		sums[n] = sum;
	}

	int startpos = 0;
	int diff = 2147483647;

        for(int n = 0;n<(N-(P-1));n++) {
		int cmax = skills[n];

		int a = (P-1)*cmax;
		int b = sums[n+(P-1)]-sums[n];

		int cdiff = a-b;

		if(cdiff < diff) {
			diff = cdiff;	
		}
        }

        cout << "Case #" << i+1 << ": " << diff << endl;
    }
}
