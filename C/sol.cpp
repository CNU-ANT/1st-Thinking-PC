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

int main() {
	scanf("%d%d", &N, &K);
	assert(1 <= N && N <= SZ);
	assert(1 <= K && K <= N);

	for (int i=0; i<N; i++) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z);
		assert(0 <= x && x <= 1000000);
		assert(0 <= y && y <= 1000000);
		assert(0 <= z && z <= 1000000);
		p[i] ={ x, y, z };
	}

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




	printf("%d\n", ans);

	return 0;
}
