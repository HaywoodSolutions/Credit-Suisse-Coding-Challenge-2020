#include <bits/stdc++.h>
using namespace std;

int findMaxProfit(int n, vector<int> price) {
  if (n == 1) 
    return 0; 

  double total = 0; 
  int i = 0;
  int buy;
  int sell;
  while (i < n - 1) {
    while ((i < n - 1) && (price[i + 1] <= price[i]))
      i++;
    if (i == n - 1)
      break;
    buy = i++;
    while ((i < n) && (price[i] >= price[i - 1])) 
      i++; 
    sell = i - 1; 
		total += price[sell] - price[buy];
  }
  return total;
}


int main() {
  int numOfPredictedTimes;
	cin >> numOfPredictedTimes;
	vector<int> predictedSharePrices(numOfPredictedTimes);
	for (int i=0; i<numOfPredictedTimes; i++)
		cin >> predictedSharePrices[i];
  int result = findMaxProfit(numOfPredictedTimes, predictedSharePrices);
  // Do not remove below line
  cout << result << "\n";
  // Do not print anything after this line
  return 0;
}