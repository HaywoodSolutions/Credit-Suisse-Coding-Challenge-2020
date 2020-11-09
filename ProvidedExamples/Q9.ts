import { Example } from ".";

const Q8Examples: Example[] = [
	{
		input: [
			"1",
			"2",
			"8 3",
			"3 9"
		],
		output: "Possible"
	},
	{
		input: [
			"1",
			"3",
			"2 4 0",
			"3 0 1",
			"1 0 0"
		],
		output: "Possible"
	},
	{
		input: [
			"1",
			"2",
			"1 4",
			"5 4"
		],
		output: "Impossible"
	},
	{
		input: [
			"2",
			"3",
			"2 4 0",
			"3 0 1",
			"1 0 0",
			"2",
			"1 4",
			"5 4"
		],
		output: "Possible,Impossible"
	},
	{
		input: [
			"1","9","14 3 9 6 8 14 3 6 7","9 5 7 11 14 2 8 13 4","8 5 13 2 5 14 9 10 6","10 11 7 1 10 7 2 1 1","13 10 11 3 11 4 9 8 5","13 4 2 5 8 14 9 4 5","12 4 4 1 14 6 9 7 12","6 5 7 6 2 12 8 14 2","2 1 3 14 9 1 2 2 13"
		],
		output: "Impossible"
	}
];

export default Q8Examples;