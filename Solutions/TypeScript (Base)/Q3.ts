type Input = string[];

const Q3Func = (input: Input): string => {
	const [numOfDays, numOfProfits] = input[0].split(' ').map(v => parseInt(v));
	const dailyShareValue: number[] = input[1].split(' ').map(v => parseInt(v));
	const profitsRequired: number[] = input.slice(2).map(v => parseInt(v));

  return profitsRequired.map(v => {
		return findPair(dailyShareValue, numOfDays, v);
	}).join(',');
};

export default Q3Func;

function indexOf(arr: number[], elem: number, i: number): number {
	let len = arr.length;

	while (i < len) {
		if (arr[i] == elem)
			return i;
		i++;
	}

  return -1;
}

export function findPair(arr: number[], n: number, k: number): string {
	let lowestAbs: number = 1000000;
	let lowestFound: string = "-1";

	let j: number;
	let min: number;

	for (let i = 0; i < n-1; i++) {
		j = indexOf(arr, arr[i] + k, i);

		if (j != -1 && i <= j) {
			min = Math.abs(i+1 - j+1);

			if (lowestAbs > min) {
				lowestFound = `${i+1} ${j+1}`;
				lowestAbs = min;
			}
		}
	}

	return lowestFound;
}