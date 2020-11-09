type Input = string[];

const Q9Func = (input: Input, logging: boolean = false): string => {
	const numberOfUnsortedProblems = parseInt(input[0]);
	const unsortedProblems = input[1];

	let results: ("Possible"|"Impossible")[] = [];

	let line = 1;

	for (let i=0; i<numberOfUnsortedProblems; i++) {
		const matrixSize = parseInt(input[line]);
		line++;

		let matrix: number[][] = [];
		for (let mln=0; mln<matrixSize; mln++) {
			matrix[mln] = input[line].split(" ").map((v) => parseInt(v));
			line++;
		}

		results.push(solveMatrix(matrixSize, matrix, logging));
	}

	return results.join(",");
};

export default Q9Func;

const solveMatrix = (size: number, matrix: number[][], logging: boolean = false): "Possible"|"Impossible" => {
	if (size == 2)
		if (matrix[0][0] == matrix[1][1] || matrix[0][1] == matrix[1][0])
			return "Possible";

	let columns: number[] = new Array(size).fill(0);

	logging && console.log(matrix);

	for (let x=0; x<size; x++)
		for (let y=0; y<size; y++)
			if (x != y)
				columns[x] += matrix[y][x];

	columns = [...new Set(columns)].sort((a,b) => a-b);
	logging && console.log(columns);

	while (columns.length > 1) {
		let head = columns.shift();
		if (head && head > 0)
			for (let i=0; i<columns.length; i++)
				columns[i] -= head;
		logging && console.log(columns);
	}

	let complete = columns[0] == 0;
	return complete ? "Possible" : "Impossible";
}