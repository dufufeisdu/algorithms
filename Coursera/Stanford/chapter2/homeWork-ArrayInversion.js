// This file contains all of the 100,000 integers between 1 and 100,000 (inclusive) in some order, with no integer repeated.
// Your task is to compute the number of inversions in the file given, where the ith row of the file indicates the ith
//entry of an array.
// Because of the large size of this array, you should implement the fast divide-and-conquer algorithm covered in the
// video lectures.
// The numeric answer for the given input file should be typed in the space below.
// So if your answer is 1198233847, then just type 1198233847 in the space provided
// without any space / commas / any other punctuation marks.
//  You can make up to 5 attempts, and we'll use the best one for grading.
// (We do not require you to submit your code, so feel free to use any programming
//language you want --- just type the final numeric answer in the following space.)
// [TIP: before submitting, first test the correctness of your program on some small test files or your own devising.
//Then post your best test cases to the discussion forums to help your fellow students!]
//let data = readFile('dir');
let fs = require('fs');
let readData = (callback) => {
	fs.readFile(__dirname + '/data.txt', 'utf8', (err, data) => {
		data = data.split('\n');
		data = data.map((ele) => (Number(ele)));
		//console.log(data.length);
		callback(data);
	});
}
//let data = [6, 5, 4, 3, 2, 1];
let inversion = 0;
let arrayInversion = (arr) => {
	if (!Array.isArray(arr)) {
		console.log('Input formate is', typeof arr);
		console.log('Need an Array');
		return;
	}
	if (arr.length < 2) {
		return arr;
	}
	let subArr0 = arr.slice(0, arr.length / 2);
	let subArr1 = arr.slice(arr.length / 2);
	subArr0 = arrayInversion(subArr0);
	subArr1 = arrayInversion(subArr1);
	let arrLen = arr.length;
	let returnArr = [];
	let index0 = 0;
	let index1 = 0;
	while (subArr0[index0] !== undefined && subArr1[index1] !== undefined) {
		if (subArr0[index0] > subArr1[index1]) {
			returnArr.push(subArr1[index1]);
			inversion += (subArr0.length - index0);
			index1++;
		} else {
			returnArr.push(subArr0[index0]);
			index0++;
		}
	}
	while (subArr0[index0] !== undefined) {
		returnArr.push(subArr0[index0]);
		index0++;
	}
	while (subArr1[index1] !== undefined) {
		returnArr.push(subArr1[index1]);
		index1++;
	}
	return returnArr;
}
readData(function (data) {
	arrayInversion(data);
	console.log(inversion);
});


