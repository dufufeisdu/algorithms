//
//  main.cpp
//  CountInversion
//
//  Created by FUFEI DU on 5/28/17.
//  Copyright © 2017 FUFEI DU. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;
int totalComparition = 0;
template <typename T>
void medianOfThree(vector<T> &array, int first, int last, int middle)
{
	vector<T> helper;
	helper.push_back(array[first]);
	helper.push_back(array[last]);
	helper.push_back(array[middle]);
	sort(helper.begin(), helper.end());
	if (array[middle] == helper[1])
	{
		swap(array[first], array[middle]);
	}
	if (array[last] == helper[1])
	{
		swap(array[first], array[last]);
	}
}
template <typename T>
void quickSortFromHead(vector<T> &array, int start, int end)
{
	if ((end - start) < 2)
	{
		return;
	}
	else
	{
		//#1 select the first element
		//        T pivit = array[start];
		//#2 select the second element
		//        T pivit = array[end-1];
		//        swap(array[start], array[end-1]);
		//        T pivit = array[start];
		//#3 select the median of the three element(first, middle, last)
		int mid = start + (end - start - 1) / 2;
		medianOfThree(array, start, mid, end - 1);
		T pivit = array[start];
		totalComparition += (end - start - 1);
		start += 1;
		int i = start, j = start;
		while (true)
		{
			while (i < end)
			{
				if (array[i] > pivit)
				{
					break;
				}
				i++;
				j++;
			}
			while (j < end)
			{
				if (array[j] < pivit)
				{
					break;
				}
				j++;
			}
			if (i < end && j < end)
			{
				swap(array[i], array[j]);
				i++;
				j++;
			}
			else
			{
				swap(array[start - 1], array[i - 1]);
				break;
			}
		}
		quickSortFromHead(array, start - 1, i - 1);
		quickSortFromHead(array, i, end);
		return;
	}
}
int main(int argc, const char *argv[])
{
	// insert code here...
	fstream readData;
	vector<int> data;
	readData.open("./data.txt", ios::in);
	int i;
	while (readData >> i)
	{
		data.push_back(i);
	}
    readData.close();
	int size = (int)data.size();
	quickSortFromHead(data, 0, size);
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
	cout << totalComparition;
	return 0;
}
