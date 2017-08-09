#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int SZ = 103;
const int A = 100;
const int B = 100;

int N;
int x[SZ], y[SZ];
ll Sx, Sxx, Sy, Syy, Sxy;

void prepare() {
	Sx = Sxx = Sy = Syy = Sxy = 0;
	for (int i=0; i<N; i++) {
		Sx += x[i];
		Sxx += x[i] * x[i];
		Sy += y[i];
		Syy += y[i] * y[i];
		Sxy += x[i] * y[i];
	}
}
ll error1(ll a, ll b) {
	return a * a * Sxx
		+ b * b * N
		+ Syy
		- 2 * a * Sxy
		- 2 * b * Sy
		+ 2 * a * b * Sx;
}
ll sqr(ll x) { return x * x; }
ll error2(ll a, ll b) {
	ll S = 0;
	for (int i=0; i<N; i++)
		S += sqr(a*x[i] + b - y[i]);
	return S;
}



bool createData(string filename) {
	if (rand()&1)
		N = 2 + rand() % 10;
	else
		N = 2 + rand() % 90;

	if (rand()&1) {
		for (int i=0; i<N; i++) {
			x[i] = 1 + rand() % 30;
			y[i] = 1 + x[i] * (rand() % 20) + rand() % 10;
		}
	}
	else {
		for (int i=0; i<N; i++) {
			x[i] = 1 + rand() % 10;
			y[i] = 1 + x[i] * (rand() % 80) + rand() % 100;
		}
	}


	assert(2 <= N && N <= 100);
	for (int i=0; i<N; i++) {
		assert(1 <= x[i] && x[i] <= 1000);
		assert(1 <= y[i] && y[i] <= 1000);
	}

	prepare();
	int ma = 1, mb = 1;
	ll minError = error1(1, 1);
	for (int a=1; a<=A; a++) for (int b=1; b<=B; b++) {
		assert(error1(a, b) == error2(a, b));
		if (minError > error1(a, b)) {
			minError = error1(a, b);
			ma = a;
			mb = b;
		}
	}

	for (int a=1; a<=A; a++) for (int b=1; b<=B; b++) if (!(a==ma && b==mb)) {
		//assert(minError != error1(a, b));
		if (minError == error1(a, b)) {
			puts("error!");
			return false;
		}
	}



	FILE* in = fopen((filename + ".in").data(), "w");
	fprintf(in, "%d\n", N);
	for (int i=0; i<N; i++)
		fprintf(in, "%d %d\n", x[i], y[i]);

	FILE* out = fopen((filename + ".out").data(), "w");
	fprintf(out, "%d %d\n", ma, mb);

	printf("created data %d %d %d\n", N, ma, mb);

	return true;
}



int main() {
	srand(time(NULL));
	for (int i=1; i<=50; i++) {
		char tmp[123];
		itoa(i, tmp, 10);
		while (!createData(tmp));
	}


	return 0;
}
