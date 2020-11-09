type Input = string[]

const Q5Func = (input: Input, logging: boolean = false): string => {
	const [numberOfBankers, bankersPrefrences] = input[0].split(' ');
	const [numberOfVisitors, visitorsPrefrences] = input[1].split(' ');
	
	let bankerLogger: Set<number>[] = new Array(parseInt(numberOfBankers));
	let visitorsLogger: Set<number>[] = new Array(parseInt(numberOfVisitors));

	for (let i=0; i<parseInt(numberOfBankers); i++) {
		bankerLogger[i] = new Set();
	}
	for (let i=0; i<parseInt(numberOfVisitors); i++) {
		visitorsLogger[i] = new Set();
	}

	const addConnection = (visitor: number, banker: number): void => {
		visitorsLogger[visitor].add(banker);
		bankerLogger[banker].add(visitor);
	}

	bankersPrefrences.split(",").forEach(function(pref, banker) {
		if (pref.indexOf("&") == -1) {
			addConnection(parseInt(pref) - 1, banker);
		} else {
			pref.split("&").forEach(function(p){
				addConnection(parseInt(p) - 1, banker);
			})
		}
	});

	visitorsPrefrences.split(",").forEach(function(pref, visitor) {
		if (pref.indexOf("&") == -1) {
			addConnection(visitor, parseInt(pref) - 1);
		} else {
			pref.split("&").forEach(function(p){
				addConnection(visitor, parseInt(p) - 1);
			})
		}
	});

	logging && console.log(bankerLogger);
	logging && console.log(visitorsLogger);

	let bankerLogs: number[] = bankerLogger.map(v => v.size).filter(v => v != 0);
	let	visitorsLogs: number[] = visitorsLogger.map(v => v.size).filter(v => v != 0);
	return Math.max(...bankerLogs, ...visitorsLogs).toString();
};

export default Q5Func;