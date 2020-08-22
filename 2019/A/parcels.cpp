#include <iostream>
#include <vector>

using namespace std;
int main() {
	int T;
	cin >> T;
	for(int t = 0;t<T;t++) {
		int R, C;
		cin >> R >> C;

		int map[C][R];
		vector<tuple<int, int>> buildings;

		for(int r=0;r<R;r++) {
			for(int c=0;c<C;c++) {
				int inp;
				cin >> inp;
				map[c][r] = inp;
				tuple<int, int> building = (c, 
			}
		}	
	}
}
