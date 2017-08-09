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
int arr[1003];

void createData(string filename) {
	N = 1 + rand() % 1000;
	for (int i=0; i<N; i++) arr[i] = rand() % 3;

	assert(1 <= N && N <= 1000);
	for (int i=0; i<N; i++) assert(0 <= arr[i] && arr[i] <= 2);

	int ans = 0;
	int milk = 0;
	for (int i=0; i<N; i++) {
		if (arr[i] == milk) {
			ans++;
			milk = (milk + 1) % 3;
		}
	}

	printf("%d: %d\n", N, ans);

	FILE* in = fopen((filename + ".in").data(), "w");
	fprintf(in, "%d\n", N);
	for (int i=0; i<N; i++) fprintf(in, "%d ", arr[i]);
	fprintf(in, "\n");

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
