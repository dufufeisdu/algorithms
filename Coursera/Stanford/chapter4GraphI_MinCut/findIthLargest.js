
let swap = (arr, i, j) => {
	let temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
	return arr;
}
let findIthLargest = (array, i, start, end) => {
	if (i < start || i > end) {
		return "ERROR:ELEMENT_OUT_RANGE";
	}
	start = start || 0;
	end = end || array.length;
	let pivit = Math.floor(Math.random() * (end - start) + start);
	array = swap(arr, start, pivit);
	let first = start;
	start++;
	while (end > start) {
		while (array[start] < array[first] && start !== end) {
			start++;
		}
		while (array[first] < array[end - 1] && start !== end) {
			end++;
		}
		if (start != end) {
			array = swap(array, start, end);
		}
	}
	array = swap(array, first, start);
	if (start === i) {
		return array[start];
	} else if (start > i) {
		return findIthLargest(array, i, first, start);
	} else {
		return findIthLargest(array, i, start, end);
	}
}
const arr = [11, 7, 1, 2, 9, 3, 10, 8, 4, 5, 6];
console.log(findIthLargest(arr, 3));
