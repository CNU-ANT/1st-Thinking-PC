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
ll error1(int a, int b) {
	return a * a * Sxx
		+ b * b * N
		+ Syy
		- 2 * a * Sxy
		- 2 * b * Sy
		+ 2 * a * b * Sx;
}
/*
ll sqr(ll x) { return x * x; }
ll error2(int a, int b) {
ll S = 0;
for (int i=0; i<N; i++)
S += sqr(a*x[i] + b - y[i]);
return S;
}
*/



int main() {
	scanf("%d", &N); assert(2 <= N && N <= 100);
	for (int i=0; i<N; i++) {
		scanf("%d%d", &x[i], &y[i]);
		assert(1 <= x[i] && x[i] <= 1000);
		assert(1 <= y[i] && y[i] <= 1000);
	}

	prepare();
	int ma = 1, mb = 1;
	ll minError = error1(1, 1);
	for (int a=1; a<=100; a++) for (int b=1; b<=100; b++) {
		if (minError > error1(a, b)) {
			minError = error1(a, b);
			ma = a;
			mb = b;
		}
	}

	for (int a=1; a<=100; a++) for (int b=1; b<=100; b++)
		if (!(a==ma && b==mb))
			assert(minError != error1(a, b));

	printf("%d %d\n", ma, mb);

	return 0;
}
