type Input = string[];

const Q4Func = (input: Input, logging: boolean = false): string => {
	const [tradeCount, maxTrades] = input[0].split(' ').map(v => parseInt(v));
	const profitProbability = input[1].split(' ').map(v => parseFloat(v));
	const potenitalProfit = input[2].split(' ').map(v => parseFloat(v));
	const potenitalLoss = input[3].split(' ').map(v => parseFloat(v));

	return Q4FuncMini(tradeCount, maxTrades, profitProbability, potenitalProfit, potenitalLoss, logging);
};


const Q4FuncMini = (tradeCount: number, maxTrades: number, profitProbability: number[], potenitalProfit: number[], potenitalLoss: number[], logging: boolean = false): string => {

	let list = [];
	for (let i=0; i<tradeCount; i++) {
		let total = (profitProbability[i] * potenitalProfit[i]) - ((1 - profitProbability[i]) * potenitalLoss[i]);

		if (total >= 0)
			list.push(total);
	}

	list = list.sort((a,b) => b-a);

	logging && console.log(list);

	let res = 0;
	if (list.length <= maxTrades)
		res = list.reduce((a,b) => a+b, 0)
	 else
		res = list.slice(0, maxTrades).reduce((a,b) => a+b, 0);

	const str = res.toFixed(2);

	return str[str.length - 1] == "0" ? str.substring(0, str.length -1) : str;
};


export default Q4Func;