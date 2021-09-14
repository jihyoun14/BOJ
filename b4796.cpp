#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	int num = 1;
	while (true) {
		long long l,p,v;
		cin >> l >> p >> v;

		if (l == 0) break;

		int answer = (v/p)*l;
		answer += v%p <= l ? v%p : l;

		cout << "Case " << num << ": " << answer << "\n";
		num++;
	}
}