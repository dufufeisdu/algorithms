let remove_duplicate = (arr) => {
	let len = arr.length;
	let index = 1;
	for (let i = 1; i < len; i++) {
		if (arr[i] !== arr[index - 1]) {
			arr[index++] = arr[i];
		}
	}
	return arr.slice(0, index);
}
module.exports = remove_duplicate;
console.log(remove_duplicate([1, 1, 2, 2, 3, 3, 5, 5]))
