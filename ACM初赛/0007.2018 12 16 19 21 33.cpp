#include<stdio.h>
#include<math.h>
using namespace std;

int sim(int a[], int b[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += (a[i] - b[i])*(a[i] - b[i]);
	}

	return sum;

}

int main() {
	int T, a[50000], b[50000], n, min;
	scanf("%d",&T);
	for (int i = 0; i < T; ++i) {
		scanf("%d",&n);
		for (int j = 0; j < n; ++j) {
			scanf("%d",&a[j]);
		}
		for (int j = 0; j < n; ++j) {
			scanf("%d",&b[j]);
		}

		min = sim(a, b, n);

		for (int j = 1; j < n; ++j) {
			int m[50000];
			for (int j = 1; j < n; ++j) {
				for (int k = 0; k < n; ++k) {
					m[k] = a[k + j < n ? k + j : abs(k + j - n)];
				}
			

				int t = sim(m, b, n);
				min = t < min ? t : min;
			}
		}

		printf("%d\n",min);

	}

	return 0;
}
