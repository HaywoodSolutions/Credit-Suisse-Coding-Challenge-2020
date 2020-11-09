#include <bits/stdc++.h>

using namespace std;

int findMaxProfit(int numOfPredictedDays, vector<int> predictedSharePrices) {
  int diff = predictedSharePrices[1] - predictedSharePrices[0]; 
  int curr_sum = diff; 
  int max_sum = curr_sum; 

  for(int i=1; i<numOfPredictedDays-1; i++) { 
    diff = predictedSharePrices[i+1] - predictedSharePrices[i]; 

    if (curr_sum > 0) 
      curr_sum += diff; 
    else
      curr_sum = diff; 

    if (curr_sum > max_sum) 
      max_sum = curr_sum; 
  } 

  return max_sum; 
}

int main() {
  int numOfPredictedDays;
	cin >> numOfPredictedDays;
	vector<int> predictedSharePrices(numOfPredictedDays);
	for (int i=0; i<numOfPredictedDays; i++)
		cin >> predictedSharePrices[i];
  
  int result = findMaxProfit(numOfPredictedDays, predictedSharePrices);

  // Do not remove this line
  cout << result << "\n";
  // Do not print anything after this line
  return 0;
}