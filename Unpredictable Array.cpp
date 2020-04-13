#include<stdio.h>
void input(int* num) {
	register int c = getchar_unlocked();
	*num = 0;
	
	while(c > 47 && c < 58) {
		*num = (*num<<1) + (*num<<3) + c - 48;
		c = getchar_unlocked();
	}
}

int main() {
	int t,n,q;
	input(&t);
	int tCopy = t;
	while(t) {
		printf("\nCase %d:",tCopy-t+1);
		input(&n); input(&q);
		int i,j,arr[n];
		for(i=0;i<n;i++) {
			input(&arr[i]);
		}
		while(q) {
			int a,b;
			long int res = 0;
			input(&a); input(&b);
			if(arr[0] == a) {
				arr[0] = b;
			}
			if(n == 1) {
				res = arr[0];
			}
			for(i=1;i<n;i++) {
				if(arr[i] == a) {
					arr[i] = b;
				}
				res += abs(arr[i] - arr[i-1]);
			}
			printf("\n%ld",res);
			--q;
		}
		--t;
	}
}
