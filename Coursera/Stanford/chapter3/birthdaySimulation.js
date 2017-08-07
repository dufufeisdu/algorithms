
// Consider a group of k people. Assume that each person's birthday is drawn uniformly at
//  random from the 365 possibilities. (And ignore leap years.) What is the smallest value
// of k such that the expected number of pairs of distinct people with the same birthday
//is at least one?
let birthdaySimulation = function () {
	//Math.random:[0,1);
	let round = 1000000;
	let expectation = 0;
	for (let i = 0; i < round; i++) {
		let pool = {};
		for (let j = 0; j < 365; j++) {
			let birthday = Math.random() * 364;
			birthday = Math.floor(birthday).toString();
			if (pool[birthday] === undefined) {
				pool[birthday] = birthday;
				expectation++;
			} else {
				break;
			}
		}
	}
	return expectation / round;
}
console.log(birthdaySimulation());
