#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#include <map>


FILE *out;

char bar[43][43];

struct Node {
	map<string, Node*> children;
	~Node() {
		for (auto p : children) delete p.second;
	}
	void printDescendents(int d) {
		for (auto p : children) {
			char sol[123]; fscanf(out, "%s", sol);
			char myans[123]; sprintf(myans, "%s%s", bar[d], p.first.data());

			assert(strcmp(sol, myans) == 0);
			puts(sol);
			puts(myans);

			p.second->printDescendents(d+2);
		}
	}
};



int main() {
	memset(bar, '-', sizeof(bar));
	for (int i=0; i<43; i++) bar[i][i] = NULL;

	for (int tc=1; tc<=10; tc++) {
		printf("Testing case %d...\n", tc);

		char fi[123]; sprintf(fi, "data/%d.in", tc); 
		FILE *in = fopen(fi, "r");

		Node root;
		int N; fscanf(in, "%d", &N);
		while (N--) {
			Node *node = &root;

			int D; fscanf(in, "%d", &D);
			while (D--) {
				char tmp[123]; fscanf(in, "%s", tmp);
				string s(tmp);

				if (node->children[s] == NULL) node->children[s] = new Node;
				node = node->children[s];
			}
		}


		char fo[123]; sprintf(fo, "data/%d.out", tc); 
		out = fopen(fo, "r");
		root.printDescendents(0);

		fclose(in);
		fclose(out);
	}


	return 0;
}

