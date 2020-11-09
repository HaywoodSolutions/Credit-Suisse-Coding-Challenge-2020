#include<bits/stdc++.h>
using namespace std;


double maximumExpectedMoney(int tradeCount, int maxTrades, double profitProbability[], double potenitalProfit[], double potenitalLoss[]) {
	double * list = new double[tradeCount];
  
  double total;
	for (int i=0; i<tradeCount; i++) {
		total = (profitProbability[i] * potenitalProfit[i]) - ((1.0 - profitProbability[i]) * potenitalLoss[i]);
		if (total > 0)
			list[i] = total;
	}

	struct greater {
		bool operator()(double const &a, double const &b) const { return a > b; }
	};


  sort(list, list + tradeCount, greater());
	
	double res = 0.0;
	for (int i=0; i<min(tradeCount, maxTrades); i++)
		res += list[i];

	float value = (int)(res * 100 + .5); 
	return (float)value / 100;
}


int main(){
	int n, m;
	cin >> n >> m;
	double p[n], x[n], y[n];
	for(int i = 0; i < n; i++)
		cin >> p[i];
	for(int i = 0; i < n; i++)
		cin >> x[i];
	for(int i = 0; i < n; i++)
		cin >> y[i];
	double result = maximumExpectedMoney(n,m,p,x,y);

	// Do not remove below line
	cout << result << endl;
	// Do not print anything after this line
	return 0;
}