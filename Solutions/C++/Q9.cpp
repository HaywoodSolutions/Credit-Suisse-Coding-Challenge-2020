#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
string organizingContainers(int size, vector<vector<int>> matrix) {
	string str = "";
	if (size == 2)
		if (matrix[0][0] == matrix[1][1] || matrix[0][1] == matrix[1][0])
			return "Possible";

	vector<int> columns(size + 1);
	
	for (int x=0; x<size; x++)
		for (int y=0; y<size; y++)
			if (x != y)
				columns[x] += matrix[y][x];

	sort(columns.begin(), columns.end());
	columns.erase( unique( columns.begin(), columns.end() ), columns.end() );

	for (int i=0; i<columns.size()-1; i++) {
		int head = columns[i];
		if (head > 0)
			for (int j=i+1; j<columns.size(); j++)
				columns[i] -= head;
	}

	return columns[columns.size()-1] == 0 ? "Possible" : "Impossible";
}

int main(){
	int q;
	cin >> q;
	string answer = "";
	for(int a0 = 0; a0 < q; a0++) {
		int n;
		cin >> n;
		vector<vector<int>> M(n,vector<int>(n));
		for(int M_i = 0;M_i < n;M_i++)
			for(int M_j = 0;M_j < n;M_j++)
				cin >> M[M_i][M_j];

		string result=organizingContainers(n, M);
		if (answer == "")
			answer = result;
		else
			answer = answer + "," + result;
	}
	// Do not remove below line
	cout << answer << endl;
	// Do not print anything after this line

	return 0;
}