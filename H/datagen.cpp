#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int solveLinear(const vector<int> &h) {
	if (h.empty()) return 0;
	int ans = 0;

	vector<pair<int, int>> st;
	st.push_back(make_pair(1e9, -123));

	for (int a : h) {
		int width = 1;
		while (st.back().first <= a) {
			ans += st.back().second * (a - st.back().first);
			width += st.back().second;
			st.pop_back();
		}

		st.push_back(make_pair(a, width));
	}

	return ans;
}
int solveQuadratic(vector<int> h) {
	reverse(h.begin(), h.end());
	int ans = 0;
	while (!h.empty()) {
		// Find the highest place
		// In case of a tie, choose the leftmost one
		int p = 0;
		for (int i=1; i<h.size(); i++)
			if (h[p] < h[i])
				p = i;

		for (int i=p+1; i<h.size(); i++) {
			ans += h[p] - h[i];
			assert(0 <= h[p] - h[i]);
		}

		h.resize(p);
	}
	return ans;
}
int solve(vector<int> h) {
	reverse(h.begin(), h.end());

	int ans = 0;
	int maxval = -123;
	for (int a : h) {
		if (maxval < a)
			maxval = a;
		else
			ans += maxval - a;
	}

	return ans;
}

void createData(string filename) {
	static int H, W;
	static int h[503];

	H = rand() % 500 + 1;
	W = rand() % 500 + 1;
	assert(1 <= H && H <= 500);
	assert(1 <= W && W <= 500);
	for (int i=1; i<=W; i++) {
		h[i] = rand() % (H + 1);
		assert(0 <= h[i] && h[i] <= H);
	}

	vector<int> pos;
	int maxval = -123;
	for (int i=1; i<=W; i++) {
		if (maxval < h[i]) {
			maxval = h[i];
			pos.clear();
			pos.push_back(i);
		}
		else if (maxval == h[i]) {
			pos.push_back(i);
		}
	}
	int L = pos.front();
	int R = pos.back();

	int ans = 0;
	for (int i=L; i<=R; i++) {
		assert(0 <= maxval - h[i]);
		ans += maxval - h[i];
	}

	vector<int> left;
	for (int i=L-1; i>=1; i--) left.push_back(h[i]);
	vector<int> right;
	for (int i=R+1; i<=W; i++) right.push_back(h[i]);
	ans += solveLinear(left) + solveLinear(right);

	assert(solveLinear(left) == solveQuadratic(left));
	assert(solveLinear(left) == solve(left));
	assert(solveLinear(right) == solveQuadratic(right));
	assert(solveLinear(right) == solve(right));


/*
	FILE* in = fopen((filename + ".in").data(), "w");
	fprintf(in, "%d %d\n", H, W);
	for (int i=1; i<=W; i++) fprintf(in, "%d ", h[i]);
	fprintf(in, "\n");

	FILE* out = fopen((filename + ".out").data(), "w");
	fprintf(out, "%d\n", ans);
	*/
}



int main() {
	srand(time(NULL));
	for (int i=1; i<=50; i++) {
		char tmp[123];
		itoa(i, tmp, 10);
		createData(tmp);
		printf("data %d created!\n", i);
	}


	return 0;
}

