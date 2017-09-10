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

void createData(string filename) {
	int N = 1 + rand()%1000;
	assert(1 <= N && N <= 1000);

	assert(solve1(N) == solveN(N));
	int a = solve1(N).first;
	int b = solve1(N).second;


	FILE* in = fopen((filename + ".in").data(), "w");
	fprintf(in, "%d\n", N);

	FILE* out = fopen((filename + ".out").data(), "w");
	fprintf(out, "%d %d\n", a, b);

	printf("%d: %d %d\n", N, a, b);
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
