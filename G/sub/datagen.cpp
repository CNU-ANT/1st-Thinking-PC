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

void createData(string filename) {
	N = 1 + rand() % 1000;
	assert(1 <= N && N <= 1000);
	for (int i=0; i<N; i++) for (int j=0; j<N; j++) {
		int a = rand() % 3;
		assert(a == 0 || a == 1 || a == 2);
		board[i][j] = a;
	}

	memset(D, 0, sizeof(D));
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




	printf("%d %d\n", N, ans);

	FILE* in = fopen((filename + ".in").data(), "w");
	fprintf(in, "%d\n", N);
	for (int i=0; i<N; i++) {
		for (int j=0; j<N; j++) fprintf(in, "%d ", board[i][j]);
		fprintf(in, "\n");
	}

	FILE* out = fopen((filename + ".out").data(), "w");
	fprintf(out, "%d\n", ans);
}


int main() {
	srand(time(NULL));
	for (int i=1; i<=50; i++) {
		char tmp[123];
		itoa(i, tmp, 10);
		createData(tmp);
		printf("created data %d\n", i);
	}

	return 0;
}
