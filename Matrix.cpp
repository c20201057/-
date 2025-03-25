#include <bits/stdc++.h>



using namespace std;
int n = 2, times;

int res, temp;
int main() {
	n = 512;
	int a[300000005]; 
	for (int i = 9; i <= 28; i++) {
		res = 0;
		for (int t = 1; t <= n; t++) {
			a[t] = 1;
		}
		times = 1e8 / n;
		times = max(times, 1);
		temp = n;
		auto start = std::chrono::high_resolution_clock::now();
		for (register int tim = 1; tim <= times; tim++) {
			for (; temp != 1; temp >>= 1) {
				for (register int l = 1; l <= temp ; l += 2) {
					a[(l + 1) >> 1] = a[l] + a[l + 1];
				}
			} 
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		cout << duration.count() / times << '\n';
		n <<= 1;
	}
	return 0;
} 
