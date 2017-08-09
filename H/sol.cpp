#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
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
/*
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
*/


int H, W;
int h[503];

int main() {
	scanf("%d%d", &H, &W);
	assert(1 <= H && H <= 500);
	assert(1 <= W && W <= 500);
	for (int i=1; i<=W; i++) {
		scanf("%d", &h[i]);
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
	printf("%d\n", ans);

	return 0;
}

