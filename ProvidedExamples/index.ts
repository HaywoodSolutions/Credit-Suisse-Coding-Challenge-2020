import Q1 from './Q1';
import Q2 from './Q2';
import Q3 from './Q3';
import Q4 from './Q4';
import Q5 from './Q5';
import Q6 from './Q6';
import Q7 from './Q7';
import Q8 from './Q8';
import Q9 from './Q9';

export type Example = {
	input: string[],
	output: string
};

type Examples = Record<number, Example[]>;

const allExamples: Examples = {
	1: Q1,
	2: Q2,
	3: Q3,
	4: Q4,
	5: Q5,
	6: Q6,
	7: Q7,
	8: Q8,
	9: Q9,
}

export default allExamples;