#include<bits/stdc++.h>

using namespace std;


int indexOf(int * arr, int elem, int i, int len) {
	while (i < len) {
		if (arr[i] == elem)
			return i;
		i++;
	}

  return -1;
}

string findPair(int * arr, int n, int k) {

	double lowestAbs = 1000000;
	string lowestFound = "-1";

	int j;
	int min;
	
	for (int i = 0; i < n-1; i++) {
		j = indexOf(arr, arr[i] + k, i, n);

		if (j != -1 && i <= j) {
			min = abs(i+1 - j+1);

			if (lowestAbs > min) {
				lowestFound = to_string(i+1) + " " + to_string(j+1);
				lowestAbs = min;
			}
		}
	}

	return lowestFound;
}

string find_min_days(int numOfDays, int numOfProfits, int dailyShareValue[], int profitsRequired[]) {
	string str = "";
	for (int i=0; i<numOfProfits; i++) {
		if (i != 0)
			str += ",";
		str += findPair(dailyShareValue, numOfDays, profitsRequired[i]);
	}
  return str;
}

int main() {
	int numOfDays,numOfProfits,i;
	string answer="";
	cin>>numOfDays>>numOfProfits;
	int dailyShareValue[numOfDays];
	int profitsRequired[numOfProfits];
	for (i=0;i<numOfDays;i++)
		cin>>dailyShareValue[i];
	for (i=0;i<numOfProfits;i++)
    cin>>profitsRequired[i];

  answer = find_min_days(numOfDays, numOfProfits, dailyShareValue, profitsRequired);

  // Do not remove below line
	cout<<answer<<endl;
  // Do not print anything after this line

	return 0;
}