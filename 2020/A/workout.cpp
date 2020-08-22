#include <iostream>
#include <math.h>

using namespace std;

int kNeeded(int N, int diffs[], int optimal) {
    int k = 0;
    double diff;
    for(int i = 0; i < N-1; i++) {
       diff = diffs[i+1]-diffs[i];
       k += ceil(diff/optimal)-1;
    }
    return k;
}

int lowestDiff(int N, int diffs[], int k) {
    int minDiff = 1;
    int maxDiff = 1;
    int currentDiff;
    for(int i = 0;i<N-1;i++) {
        maxDiff = max(maxDiff, diffs[i+1]-diffs[i]);
    }
    while(minDiff < maxDiff) {
        currentDiff = floor((minDiff+maxDiff)/2);
        int kneeded = kNeeded(N, diffs, currentDiff);
        // We need more than we have, k has to be smaller. K goes down when currentDiff goes up, So currentDiff cannot get any smaller.
        if(kneeded > k) {
            minDiff = currentDiff+1;
        }
        // We have more than we need, k could get larger. K goes up when currentDiff goes down, So currentDiff cannot get any larger.
        else if(kneeded < k) {
            maxDiff = currentDiff;
        }
        else if(kneeded == k) { 
            maxDiff = currentDiff;
        }
    }
    return minDiff;
}

int main() {
    int t, N, K;
    cin >> t;
    for(int i = 0;i<t;i++) {
       cin >> N >> K; 
       int differences[N];
       for(int n = 0;n < N;n++) {
           cin >> differences[n];
       }
       int output = lowestDiff(N, differences, K);
       cout << "Case #" << i+1 << ": " << output << endl;
    }
}