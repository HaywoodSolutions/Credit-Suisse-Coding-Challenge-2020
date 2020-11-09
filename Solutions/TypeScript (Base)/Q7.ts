type Input = string[]

const Q7Func = (input: Input, logging: boolean = false): any => {
	let peopleCount = parseInt(input[0]);

	const questions: Record<number, number[]> = input[1].split(",")
		.map((v) => v.split(" ").map(v => parseInt(v)))
		.reduce((m: Record<number, number[]>, v) => {
			let s = v.slice(1)
			if (s.length > 0)
				m[v[0]] = s;
			return m;
		}, {});

	const flags: Set<number> = new Set();

	Object.entries(questions).forEach(([author, answerers]) => {
		let authorId = parseInt(author);
		answerers.forEach(answerer => {
			if (questions[answerer] && questions[answerer].indexOf(authorId) != -1) {
				logging && console.log("DUP", authorId, answerer)

				flags.add(authorId)
				flags.add(answerer);
			}
		})
	});

	flags.forEach(f => delete questions[f]);

	let foundOne = true;

	logging && console.log({...questions});
	logging && console.log(flags);

	while (foundOne) {
		foundOne = false;
		Object.entries(questions).forEach(([author, answerers]) => {
			if (!flags.has(parseInt(author))) {
				const suspiciousAns = answerers.filter((v) => flags.has(v));
				console.log(author, suspiciousAns.length)
				if (suspiciousAns.length >= 2) {
					flags.add(parseInt(author));
					delete questions[parseInt(author)];
					foundOne = true;
				}
			}
		});
		
	};
	logging && console.log({...questions});
	return [...flags].sort((a,b) => a-b).join(',');
}

export default Q7Func;