#include <algorithm>
#include <iostream>

using namespace std;

int main(){
	int arr[1001];
	int dp[1001] = {0,};
	int n;
	int answer = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (dp[i] == 0) dp[i] = 1;
		for (int j = i-1; j >= 0; j--) {
			if (arr[i] > arr[j]) 
				dp[i] = max(dp[i], dp[j]+1);
		}
		answer = max(answer, dp[i]);
	}

	cout << answer;
}