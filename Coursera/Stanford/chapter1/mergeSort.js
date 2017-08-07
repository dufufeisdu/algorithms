//
let raw1 = [1, 9, 8, 0, 3, 7, 4, 5, 6, 11, 19, 22, 39, 48, 12, 2];
let raw2 = [3, 1];
let raw3 = [1];
let raw4 = [4, 1, 5];
let mergeSort = (arr) => {
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
	subArr0 = mergeSort(subArr0);
	subArr1 = mergeSort(subArr1);
	let arrLen = arr.length;
	let returnArr = [];
	for (let i = 0, j = 0, k = 0; i < arrLen; i++) {
		if (subArr0[j] === undefined && subArr1[k] != undefined) {
			returnArr.push(subArr1[k]);
			k++;
			continue;
		}
		if (subArr1[k] === undefined && subArr0[j] != undefined) {
			returnArr.push(subArr0[j]);
			j++;
			continue;
		}
		if (subArr0[j] < subArr1[k]) {
			returnArr.push(subArr0[j]);
			j++;
		} else {
			returnArr.push(subArr1[k]);
			k++;
		}
	}
	return returnArr;
}
console.log(mergeSort(raw1));
//[ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 19, 22, 39, 48 ]
