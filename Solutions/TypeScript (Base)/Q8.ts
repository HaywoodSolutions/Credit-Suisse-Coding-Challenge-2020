type Input = string[];

const Q8Func = (input: Input, logging: boolean = false): string => {
	const desiredAmount = parseInt(input[0].split(" ")[0]);
	// const coinTypes = input[0][1];
	const coins = input[1].split(" ").map(v => parseInt(v));
	
	return countV2(coins, coins.length /* coinTypes */, desiredAmount, logging).toString();
};

const countV2 = (S: number[], m: number, n: number, logging: boolean = false): number => {
	logging && console.log(m, n)
	const table: number[] = new Array(n+1).fill(0);
	table[0] = 1;

	logging && console.log(table.length);

	for(let i=0; i<m; i++) 
		for(let j=S[i]; j<=n; j++) 
			table[j] += table[j-S[i]];

	logging && console.log(table.slice(150, n));

	return table[n];
}
  

export default Q8Func;