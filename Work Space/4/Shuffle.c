#include <stdio.h>
#include <stdlib.h>

#define NN 202020
#define inf 0x3f3f3f3f

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int c[1010101];
int a[NN], b[NN];

void solve() {
	int k, m; scanf("%d %d", &k, &m);
	for(int i = k * m; i--; ) scanf("%d", c + i);
	int J; scanf("%d", &J);
	
	for(int i = 0; i < m; i++) a[i] = 0;
	for(int i = 0, id = k * m; i < m; i++) {
		for(int j = 1, x; j <= k; j++) {
			x = c[--id];
			if(j ^ J) {
				if(x > a[i]) a[i] = x;
			}
			else b[i] = x;
		}
	}
    
    qsort(a, m, sizeof(int), compare);
    qsort(b, m, sizeof(int), compare);
	
	int ans = 0;
	for(int i = 0, j = 0; i < m && j < m; j++) {
		if(a[i] < b[j]) ans++, i++;
	}
	printf("%d\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
	while(t--) solve();

    return 0;
}
