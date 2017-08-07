let fs = require('fs');
let _ = require('./underscore.js');
let data = fs.readFileSync(__dirname + '/homeWorkData.txt', 'utf8');
data = data.split('\n').map((ele) => (ele.split('\t')));
data.pop();
let len = data.length;
let finalCut = len - 1;
let findMinCut = () => {
	let minCut = Infinity;
	data = _.shuffle(data);
	let unioned = [];
	let merged = [];
	for (let i = 0; i < data.length / 2; i++) {
		unioned.push(data[i][0]);
		let toMerge = data[i].slice();
		toMerge.shift();
		merged = merged.concat(toMerge);
		merged = merged.filter((element) => {
			let flag = true;
			unioned.forEach((ele) => {
				if (ele === element) {
					flag = false;
				}
			});
			return flag;
		});
		if (merged.length === 1) {
			console.log(data);
		}
		minCut = minCut > merged.length ? merged.length : minCut;
	}
	return minCut;
}
for (let j = 0; j < 1000; j++) {
	let cut = findMinCut();
	finalCut = finalCut > cut ? cut : finalCut;
}
console.log(finalCut);
