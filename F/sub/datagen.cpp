#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int SZ = 100;
int N, K;

struct Point {
	int x, y, z;
	bool operator<(const Point rhs) const {
		return z < rhs.z;
	}
} p[SZ];


void createData(string filename) {
	N = 1 + rand() % SZ;
	K = 1 + rand() % N;
	assert(1 <= N && N <= SZ);
	assert(1 <= K && K <= N);

	for (int i=0; i<N; i++) {
		int x = rand() * rand() % 1000001;
		int y = rand() * rand() % 1000001;
		int z = rand() * rand() % 1000001;
		assert(0 <= x && x <= 1000000);
		assert(0 <= y && y <= 1000000);
		assert(0 <= z && z <= 1000000);
		p[i] ={ x, y, z };
	}

	FILE* in = fopen((filename + ".in").data(), "w");
	fprintf(in, "%d %d\n", N, K);
	for (int i=0; i<N; i++) fprintf(in, "%d %d %d\n", p[i].x, p[i].y, p[i].z);




	vector<int> xCoord, yCoord;
	for (int i=0; i<N; i++) {
		xCoord.push_back(p[i].x);
		yCoord.push_back(p[i].y);
	}

	sort(p, p + N);
	int ans = 1e9;

	for (int x : xCoord) for (int y : yCoord) {
		int z = 0;
		int cnt = 0;
		for (int i=0; i<N; i++) if (p[i].x <= x && p[i].y <= y) {
			cnt++;
			z = p[i].z;
			if (cnt == K) break;
		}

		if (cnt == K)
			ans = min(ans, x + y + z);
	}



	FILE* out = fopen((filename + ".out").data(), "w");
	fprintf(out, "%d\n", ans);

	printf("%d %d %d\n", N, K, ans);
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
