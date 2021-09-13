#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	int n;
	long long arr[1000001] = {0,1,2,3,4,5,6,7,8,9,0};
	cin >> n;

	int tmp = 10;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < arr[i]%10; j++) {
			arr[tmp] = arr[i]*10 + j;
			tmp++;
		}
	}

	if (n != 0 && arr[n] == 0) cout << -1;
	else cout << arr[n];
}