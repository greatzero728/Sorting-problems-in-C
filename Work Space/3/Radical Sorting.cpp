#include<bits/stdc++.h>
#define y second
#define x first

using namespace std;
using INT = long long;
using pii = pair<int, int>;

const int NN = 656565;

char tmp[NN];
string s[NN];
int len[NN], id[NN];

void solve() {
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %s", len + i, tmp);
		
		s[i].resize(len[i] + 1);
		for(int j = 0; j < len[i]; j++) s[i][j + 1] = tmp[j];
		id[i] = i;
	}
	sort(id + 1, id + n + 1, [&](int u, int v) {
		int k = 1, min_len = min(len[u], len[v]);
		while(s[u][k] == s[v][k]) k++;
		if(k <= min_len) {
			if(k & 1) return s[u][k] < s[v][k];
			return s[u][k] > s[v][k];
		}
		if(min_len & 1) return len[u] < len[v];
		return len[u] > len[v];
	});
	for(int i = 1; i <= n; i++) {
		int k = id[i];
		for(int j = 1; j <= len[k]; j++) putchar(s[k][j]);
		puts("");
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) solve();
	return 0;
}