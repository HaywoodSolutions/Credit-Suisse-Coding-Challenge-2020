#include <bits/stdc++.h>
#include <istream>
using namespace std;

int main() {
  int n;
	cin >> n;
	int m;
	cin >> m;
	vector<int> S(m);
	for (int i=0; i<m; i++)
		cin >> S[i];
  
	vector<long> table(n+1);
	table[0] = 1;
	for(int i=0; i<m; i++) 
		for(int j=S[i]; j<=n; j++)
			table[j] += table[j-S[i]];

	long result = table[n];
	cout << result << "\n";
	return 0;
}
