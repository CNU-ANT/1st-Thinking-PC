#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int N;
int board[1003][1003];
int D[1003][1003][3];

int main() {
	scanf("%d", &N);
	assert(1 <= N && N <= 1000);
	for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
		int a; scanf("%d", &a);
		assert(a == 0 || a == 1 || a == 2);
		board[i][j] = a;
	}

	for (int i = N-1; i>=0; i--) for (int j=N-1; j>=0; j--) {
		for (int t : {0, 1, 2}) {
			if (board[i][j] == t) {
				int tt = (t + 1) % 3;
				D[i][j][t] = 1 + max(D[i+1][j][tt], D[i][j+1][tt]);
			}
			else
				D[i][j][t] = max(D[i+1][j][t], D[i][j+1][t]);
		}
	}

	int ans = D[0][0][0];
	printf("%d\n", ans);


	return 0;
}