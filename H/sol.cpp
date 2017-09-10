#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


pair<int, int> solve1(int N) {
	N--;
	int g = (-1 + sqrt(1+8*N)) / 2;
	int M = g * (g + 1) / 2;
	int dif = N - M;
	int a = g + 1 - dif;
	int b = 1 + dif;

	//printf("1: %d %d\n", a, b);
	return make_pair(a, b);
}
pair<int, int> solveN(int N) {
	int a = 1;
	int b = 1;
	for (int z=0; z<N-1; z++) {
		if (a == 1) {
			a = b + 1;
			b = 1;
		}
		else {
			a--;
			b++;
		}
	}
	//printf("N: %d %d\n", a, b);
	return make_pair(a, b);
}


int main() {
	int N;
	scanf("%d", &N);
	assert(1 <= N && N <= 1000);

	assert(solve1(N) == solveN(N));
	int a = solve1(N).first;
	int b = solve1(N).second;
	printf("%d %d\n", a, b);

	return 0;
}
