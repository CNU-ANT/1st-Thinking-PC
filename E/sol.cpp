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

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) scanf("%d", &arr[i]);

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

	printf("%d\n", ans);

	return 0;
}
