#include <algorithm>
#include <iostream>

using namespace std;


int desc[1001] = {0,};
int insc[1001] = {0,};
int arr[1001];

int main(){
	int n;
	int answer = 0;

	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int insc_max = 0;
	// check incs
	for (int i = 0; i < n; i++) {
		if (insc[i] == 0) insc[i] = 1;
		for (int j = i-1; j >= 0; j--) {
			if (arr[i] > arr[j]) 
				insc[i] = max(insc[i],insc[j]+1);
		}
		insc_max = max(insc[i], insc_max);
	}
	
	int sum_max = 0;
	int desc_max = 0;
	// check decs
	for (int i = n-1; i >= 0; i--) {
		if (desc[i] == 0) desc[i] = 1;
		for (int j = i+1; j < n; j++) {
			if (arr[i] > arr[j]) 
				desc[i] = max(desc[i],desc[j]+1);
		}
		desc_max = max(desc[i], desc_max);
		sum_max = max(desc[i]+insc[i]-1, sum_max);
	}

	answer = max(max(desc_max,insc_max),sum_max);

	cout << answer;
}