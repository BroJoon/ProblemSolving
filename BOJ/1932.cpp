#include <iostream>
#include <algorithm>

using namespace std;

int n, result;

int arr[501][501];

int main() {
	cin >> n;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			if(j == 1) arr[i][j] += arr[i - 1][j];
			else if(j == i) arr[i][j] += arr[i - 1][j - 1];
			else arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
		}
	}
	for(int i = 1; i <= n; i++) result = max(result, arr[n][i]);
	
	cout << result;
	
	return 0;
}