let rotateBinarySearch = (arr, ele) => {
	let first = 0;
	let last = arr.length - 1;
	while (first <= last) {
		const mid = Math.floor((first + last) / 2);
		if (arr[mid] === ele) {
			return mid;
		}
		if (arr[first] <= arr[mid]) {
			if (arr[first] <= ele && arr[mid] > ele) {
				last = mid;
			} else {
				first = mid + 1;
			}
		} else {
			if (ele >= arr[mid] && ele <= arr[last]) {
				first = mid;
			} else {
				last = mid - 1;
			}

		}
	}
	return -1;
}
console.log(rotateBinarySearch([10, 12, 14, 15, 16, 2, 6, 9], 14) === 2);
console.log(rotateBinarySearch([10, 12, 14, 15, 16, 2, 6, 9], 0) === -1);
console.log(rotateBinarySearch([16, 2, 6, 9, 10, 12, 14], 10) === 4);
console.log(rotateBinarySearch([16, 2], 2) === 1);

