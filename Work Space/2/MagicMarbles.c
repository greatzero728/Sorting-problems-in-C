#include<stdio.h>
#include<stdlib.h>

#define inf 0x3f3f3f3f
#define NN 202020

typedef struct {
    int x, y;
} Pair;

void merge(Pair* p, int left, int mid, int right) {
    int nl = mid - left,  nr = right - mid;
    
    Pair* L = (Pair*)malloc(sizeof(Pair) * nl);
    for(int i = nl; i--; ) L[i] = p[left + i];
    
    Pair* R = (Pair*)malloc(sizeof(Pair) * nr);
    for(int i = nr; i--; ) R[i] = p[mid + i];
    
	for(int i = 0, j = 0, k = left; i < nl || j < nr; k++) {
		Pair mn; mn.x = mn.y = inf;
		if(i < nl) mn = L[i];
		if(j < nr) if(R[j].x < mn.x || (R[j].x == mn.x && R[j].y < mn.y)) mn = R[j];
		
		if(i < nl && mn.x == L[i].x && mn.y == L[i].y) p[k] = L[i++];
		else p[k] = R[j++];
	}
    free(L), free(R);
}

void mergeSort(Pair* p, int L, int R) {
	if(R - L < 2) return;
	int md = L + R >> 1;
    mergeSort(p, L, md);
    mergeSort(p, md, R);
    merge(p, L, md, R);
}

int J[NN];
Pair p[NN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int t; scanf("%d", &t);
    while(t--) {
        int n; scanf("%d", &n);
		
        for(int i = n; i--; ) scanf("%d", &p[i].x);
        for(int i = n; i--; ) scanf("%d", &p[i].y);
        mergeSort(p, 0, n);
        
        for(int i = 0; i < n; i++) {
            if(!i) J[i] = p[i].y < p[i].x ? p[i].y : p[i].x;
			else {
                if(p[i].y <= p[i].x && p[i].y >= J[i - 1]) J[i] = p[i].y;
				else J[i] = p[i].x;
            }
        }
        printf("%d %d\n", p[n - 1].x, J[n - 1]);
    }
    return 0;
}