#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>

using namespace std;

void visit(int node, vector<int> &path, int A, int B, unordered_map<int, vector<int>> &tree, double AVisits[], double BVisits[]) {
	AVisits[node] ++;
	BVisits[node] ++;
	path.push_back(node);

	for(int childnode:tree[node]) {
		visit(childnode, path, A, B, tree, AVisits, BVisits);	
	}

	int s = path.size();
	if(s > A) {
		int bnode = path[(s-1)-A];
		AVisits[bnode] += AVisits[node];	
	}

	if(s > B) {
		int bnode = path[(s-1)-B];
		BVisits[bnode] += BVisits[node];	
	}

	path.pop_back();
	return;
}

int main() {
	int T;
	cin >> T;
	for(int t = 0;t<T;t++) {
		int N, A, B;

		cin >> N >> A >> B;

		unordered_map<int, vector<int>> tree;

		double AVisits[N];
		double BVisits[N];

		for(int n = 0;n<N;n++) {
			AVisits[n] = 0;
			BVisits[n] = 0;
		}

		for(int n = 1;n<N;n++) {
			int cparent;
			cin >> cparent;
			cparent -= 1;
			if(tree.find(cparent) == tree.end()) {
				vector<int> c;
				tree[cparent] = c;
			}
			tree[cparent].push_back(n);
		}

		vector<int> path;
		visit(0, path, A, B, tree, AVisits, BVisits);

		for(int n = 0;n<N;n++) {
			AVisits[n] /= N;
			BVisits[n] /= N;
		}

		double totalpainted = 0;
		for(int i = 0;i<N;i++) {
			double aprob = AVisits[i];	
			double bprob = BVisits[i];	
			double cprob = (aprob+bprob)-(aprob*bprob);
			totalpainted += cprob;
		}

		cout << "Case #" << t+1 << ": " << std::setprecision(10) << totalpainted << endl;

	}
}
