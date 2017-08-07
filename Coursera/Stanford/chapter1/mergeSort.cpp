#include <iostream>
#include <vector>
using namespace std;
template <class T>
vector<T> merge(vector<T> arr)
{
	unsigned long len = arr.size();
	if (arr.size() < 2)
	{
		return arr;
	}
	vector<T> subArr1(arr.begin(), arr.begin() + len / 2);
	vector<T> subArr2(arr.begin() + len / 2, arr.end());
	vector<T> array;
	subArr1 = merge(subArr1);
	subArr2 = merge(subArr2);
	typename vector<T>::iterator it1 = subArr1.begin();
	typename vector<T>::iterator it2 = subArr2.begin();
	while (it1 != subArr1.end() && it2 != subArr2.end())
	{
		if (*it1 > *it2)
		{
			array.push_back(*it2);
			it2++;
		}
		else
		{
			array.push_back(*it1);
			it1++;
		}
	}
	while (it1 != subArr1.end())
	{
		array.push_back(*it1);
		it1++;
	}
	while (it2 != subArr2.end())
	{
		array.push_back(*it2);
		it2++;
	}
	return array;
}
int main(int argc, const char *argv[])
{
	int myints[] = {16, 2, 77, 29, 1, 3, 5, 8, 14};
	vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
	vector<int> result = merge<int>(fifth);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << ' ';
	}
	return 0;
}
