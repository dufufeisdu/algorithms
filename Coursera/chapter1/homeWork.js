
// Divide and Conquer, Sorting and Searching, and Randomized Algorithms from Stanford University
//ChapterOne assignment
// In this programming assignment you will implement one or more of the integer multiplication algorithms
// described in lecture.
// To get the most out of this assignment, your program should restrict itself to multiplying only
//pairs of single-digit numbers. You can implement the grade-school algorithm if you want, but to get
// the most out of the assignment you'll want to implement recursive integer multiplication and/or
//Karatsuba's algorithm.

// So: what's the product of the following two 64-digit numbers?
// 3141592653589793238462643383279502884197169399375105820974944592
// *
// 2718281828459045235360287471352662497757247093699959574966967627

// [TIP: before submitting, first test the correctness of your program on some small
//test cases of your own devising. Then post your best test cases to the discussion forums to
// help your fellow students!]
// [Food for thought: the number of digits in each input number is a power of
// 2. Does this make your life easier? Does it depend on which algorithm you're implementing?]
// The numeric answer should be typed in the space below. So if your answer is 1198233847,
//then just type 1198233847 in the space provided without any space / commas / any other punctuation marks.
// (We do not require you to submit your code, so feel free to use any programming language you want
//--- just type the final numeric answer in the following space.)
let num1 = '3141592653589793238462643383279502884197169399375105820974944592';
let num2 = '2718281828459045235360287471352662497757247093699959574966967627';
//bigAdd for whatever two positive number sum
let bigAdd = function (number1, number2) {
	let biggerNumber, smallNumber, sum;
	if (number1.length >= number2.length) {
		biggerNumber = number1;
		smallNumber = number2;
	} else {
		biggerNumber = number2;
		smallNumber = number1;
	}
	biggerNumber = biggerNumber.split("").reverse();
	smallNumber = smallNumber.split("").reverse();
	let carryFlag = 0;
	let len = biggerNumber.length;
	sum = biggerNumber.map((digit, index) => {
		let bigDigit = Number(digit);
		let smalDigit = Number(smallNumber[index]);
		if (smalDigit) {
			bigDigit += smalDigit;
		}
		bigDigit += carryFlag;
		carryFlag = bigDigit.toString().length === 1 ? 0 : 1;
		let str = bigDigit.toString();
		return str.length === 1 ? str[0] : str[1];
	});
	if (carryFlag === 1) {
		sum.push('1');
	}
	return sum.reverse().join("");
};
//removeHeadZero will remove the head zero of a string
//'000012311414' => '12311414';
//'0000' => '0'
let removeHeadZero = function (num) {
	num = num.split("");
	while (num[0] === '0') {
		num.shift();
	}
	num = num.join("")
	return num ? num : 0;
}


//Javascript accurate:
//console.log(9999999999 * 9999999999)  =>99999999890000000000 not accurate;
//console.log(9999999 * 99999999) =>999999890000001 accruate when digits sum below (15);
//karatsuba algorithm:
//karatsuba explain:
//(10a+b)(10c+d) = 100ac + 10(ad+bc)+bd;
let karatsubaMutiply = function (number1, number2) {

	number1 = number1.toString();
	number2 = number2.toString();
	if (number1.length + number2.length < 14) {
		return (number1 * number2).toString();
	}
	let num1Len = number1.length;
	let num2Len = number2.length;
	let a = number1.slice(0, parseInt(num1Len / 2));
	let b = number1.slice(parseInt(num1Len / 2));
	//if b = '000' or '000011111', B will be 0 / 11111
	let B = removeHeadZero(b);
	let c = number2.slice(0, parseInt(num2Len / 2));
	let d = number2.slice(parseInt(num2Len / 2));
	let D = removeHeadZero(d);
	let headMul = karatsubaMutiply(a, c) + Array(b.length + d.length).fill(0).join("");
	let middleMul1 = karatsubaMutiply(a, D) + Array(b.length).fill(0).join("");
	let middleMul2 = karatsubaMutiply(B, c) + Array(d.length).fill(0).join("");
	let tailMul = karatsubaMutiply(B, D);
	let sum = bigAdd(headMul, middleMul1);
	sum = bigAdd(sum, middleMul2);
	sum = bigAdd(sum, tailMul);
	return sum;
}
//console.log(bigAdd(num1, num2));
//var a = '00000';
//console.log(removeHeadZero(a));
console.log(karatsubaMutiply(num1, num2));
//8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184
