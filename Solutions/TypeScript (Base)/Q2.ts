type NumberOfPredictedDays = number;
type DailySharePrices = number[];

const Q2Func = (input: string[]): string => {
	let arr = input[0].split(' ').map(v => parseInt(v));
	const numOfPredictedDays: NumberOfPredictedDays = arr[0];
	const dailySharePrices: DailySharePrices = arr.slice(1);
	
	return stockBuySell(dailySharePrices, numOfPredictedDays).toString();
}

const stockBuySell = (price: number[], n: number): number => {
	if (n == 1) 
		return 0;

	let buy: number, sell: number, i: number = 0, total: number = 0;

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

export default Q2Func;

