#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int score(int a, int b) {
	return a==b ? 100 + a : (a + b) % 10;
}

int main() {
	int a, b; scanf("%d%d", &a, &b);
	assert(1 <= a && a <= 10);
	assert(1 <= b && b <= 10);

	int cnt[11];
	for (int x=1; x<=10; x++) cnt[x] = 2;
	cnt[a]--;
	cnt[b]--;

	vector<int> cards;
	for (int x=1; x<=10; x++)
		while (cnt[x]--)
			cards.push_back(x);
	assert(cards.size() == 18);

	int winCount = 0;
	for (int i=0; i<cards.size(); i++) for (int j=i+1; j<cards.size(); j++) {
		int aa = cards[i];
		int bb = cards[j];

		if (score(a, b) > score(aa, bb))
			winCount++;
	}


	double ans = (double)winCount / 153;
	printf("%.3f", ans);

	return 0;
}

