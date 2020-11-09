type NumberOfPredictedDays = number;
type DailySharePrices = number[];

const Q1Func = (input: string[]): string => {
	let predictedSharePrices = input[0].split(' ').map(v => parseInt(v));
	const numOfPredictedDays: NumberOfPredictedDays = predictedSharePrices[0];
	const dailySharePrices: DailySharePrices = predictedSharePrices.slice(1);

	return maxDiff(dailySharePrices, numOfPredictedDays).toString();
}

const maxDiff = (predictedSharePrices: number[], numOfPredictedDays: number): number => {  
	let diff: number = predictedSharePrices[1]-predictedSharePrices[0]; 
	let curr_sum: number = diff; 
	let max_sum: number = curr_sum; 

	for(let i: number=1; i<numOfPredictedDays-1; i++) { 
		diff = predictedSharePrices[i+1] - predictedSharePrices[i]; 

		if (curr_sum > 0) 
			curr_sum += diff; 
		else
			curr_sum = diff;
			
		if (curr_sum > max_sum) 
			max_sum = curr_sum; 
	} 

	return max_sum; 
};

export default Q1Func;