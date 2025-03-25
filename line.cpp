#include <bits/stdc++.h>



using namespace std;
int n = 10, m = 10, times = 100000;
int a[10005][10005]; 
int b[10005], res[10005];
int main() {
	for (int i = 1; i <= 3; i++) {
		m = n;
		for (int j = 1; j <= 9; j++) {
			for (int t = 1; t <= n; t++) {
				for (int h = 1;  h <= m; h++) a[t][h] = 1;
				b[t] = 1, res[t] = 0;
			}
			auto start = std::chrono::high_resolution_clock::now();
			for (register int tim = 1; tim <= times; tim++) {
				for (register int t = 1; t <= m; t++) {
					for (register int h = 1; h <= m; h += 10) {
						res[h] += a[t][h] * b[h];
						res[h + 1] += a[t][h + 1] * b[h + 1];
						res[h + 2] += a[t][h + 2] * b[h + 2];
						res[h + 3] += a[t][h + 3] * b[h + 3];
						res[h + 4] += a[t][h + 4] * b[h + 4];
						res[h + 6] += a[t][h + 6] * b[h + 6];
						res[h + 7] += a[t][h + 7] * b[h + 7];
						res[h + 8] += a[t][h + 8] * b[h + 8];
						res[h + 9] += a[t][h + 9] * b[h + 9];
					}
					
				} 
			}
    		auto end = std::chrono::high_resolution_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
			cout << duration.count() / times << '\n';
			m += n; 
		}
		times /= 100;
		n = n * 10;
	}
	return 0;
} 
