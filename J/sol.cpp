#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include <map>



char bar[43][43];

struct Node {
	map<string, Node*> children;
	~Node() {
		for (auto p : children) delete p.second;
	}
	void printDescendents(int d) {
		for (auto p : children) {
			printf("%s%s\n", bar[d], p.first.data());
			p.second->printDescendents(d+2);
		}
	}
};

int main() {
	memset(bar, '-', sizeof(bar));
	for (int i=0; i<43; i++) bar[i][i] = NULL;

	Node root;

	int N; scanf("%d", &N);
	while (N--) {
		Node *node = &root;

		int D; scanf("%d", &D);
		while (D--) {
			char tmp[123]; scanf("%s", tmp);
			string s(tmp);

			if (node->children[s] == NULL) node->children[s] = new Node;
			node = node->children[s];
		}
	}

	root.printDescendents(0);

	return 0;
}

