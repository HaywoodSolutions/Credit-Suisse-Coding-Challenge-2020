#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
	string words;
	getline(cin, words);
  
	words.erase(remove(words.begin(), words.end(), ' '), words.end()); 
	int size = words.size();
	int max = ceil(sqrt(size));
	string map[max];
	for (int i=0; i<size; i++)
		map[i % max] += words[i];
	string str;
	for (int i=0; i<max; i++) {
		if (i != 0)
			str += " ";
		str += map[i];
	}
	string result = str;

	// Do not remove below line
	cout << result << "\n";
	// Do not print anything after this line
	return 0;
}
