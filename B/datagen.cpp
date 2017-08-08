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

void createData(int a, int b, string filename) {
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


	FILE *in = fopen((filename + ".in").data(), "w");
	fprintf(in, "%d %d\n", a, b);

	FILE *out = fopen((filename + ".out").data(), "w");
	fprintf(out, "%.3f\n", ans);
}


int main() {
	int i = 1;
	for (int a=1; a<=10; a++) for (int b=a; b<=10; b++) {
		char tmp[123];
		itoa(i++, tmp, 10);
		createData(a, b, tmp);
	}

	return 0;
}