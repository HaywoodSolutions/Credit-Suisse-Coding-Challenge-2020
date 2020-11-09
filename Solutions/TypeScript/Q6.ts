type Input = string[];

const Q6Func = (inp: Input): any => {
	const str = inp[0].replace(/ /g, '');
	const max = Math.ceil(Math.sqrt(str.length));

	const columns: string[] = new Array(max).fill("");
	
	for (var i=0; i<str.length; i++)
		columns[i % max] += str[i];

	return columns.join(' ');
};

export default Q6Func;