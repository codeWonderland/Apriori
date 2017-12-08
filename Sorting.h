//Author: Alice Easter
//		Class: CSI 281-01
//		Assignment: PA 3
//Date Assigned: Aug 28, 2017
//		Due Date: Sept 4, 2017
//Description:
//		Sorting Algorithm Templates
//Certification of Authenticity:
//		I certify that this is entirely my own work, except where I have given fullydocumented
//references to the work of others. I understand the definition and
//consequences of plagiarism and acknowledge that the assessor of this assignment
//		may, for the purpose of assessing this assignment:
//- Reproduce this assignment and provide a copy to another member of
//academic staff; and/or
//- Communicate a copy of this assignment to a plagiarism checking service
//		(which may then retain a copy of this assignment on its database for
//the purpose of future plagiarism checking)

#ifndef PA3_SORTING_H
#define PA3_SORTING_H

// Pre: list, lower bound of list, mid index of list, and upper bound of list
// Post: returns a sorted list
// Purpose: to act as a sub function of the merge sort that sorts the lists when they are reduced to smaller sizes
template <typename T>
void merge (T list[], int lowerBound, int mid, int upperBound);


// Pre: a list and the size of said list
// Post: the list in incrementing order
// Post: sorts an array
template <typename T>
void bubbleSort (T list[], int size)
{
	int i;
	T temp;
	bool swapped = true;

	while (swapped)
	{
		swapped = false;
		for (i = 0; i < size; i++)
		{
			if (list[i + 1] < list[i])
			{
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;

				swapped = true;
			}
		}
	}
}


// Pre: a list and the size of said list
// Post: the list in incrementing order
// Post: sorts an array
template <typename T>
void insertionSort (T list[], int size)
{
	int i, j;
	T value;

	for (i = 1; i < size; i++)
	{
		value = list[i];
		j = i - 1;

		while(j >= 0 && list[j] > value)
		{
			list[j + 1] = list[j];
			j--;
		}

		list[j + 1] = value;
	}
}

// Pre: a list and the size of said list
// Post: the list in incrementing order
// Post: sorts an array
template <typename T>
void selectionSort (T list[], int size)
{
	int i, j, minIndex;
	T temp;

	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;

		for (j = i; j < size; j++)
		{
			if (list[j] < list[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			temp = list[i];
			list[i] = list[minIndex];
			list[minIndex] = temp;
		}
	}
}

// Pre: a list and the size of said list
// Post: the list in incrementing order
// Post: sorts an array
template <typename T>
void shellSort (T list[], int size)
{
	int gap, i;
	T temp;

	gap = size / 2;

	while (gap > 0)
	{
		for (i = 0; i < size - gap; i++)
		{
			if (list[i] > list[i + gap])
			{
				temp = list[i];
				list[i] = list[i + gap];
				list[i + gap] = temp;
			}
		}

		gap = gap / 2;
	}

	bubbleSort(list, size);
}

// Pre: a list and the upper and lower bounds for said list
// Post: the list in incrementing order
// Post: sorts an array
template <typename T>
void mergeSort (T list[], int lowerBound, int upperBound)
{
	int mid;

	if (lowerBound < upperBound)
	{
		mid = (lowerBound + upperBound) / 2;
		mergeSort(list, lowerBound, mid);
		mergeSort(list, mid + 1, upperBound);
		merge(list, lowerBound, mid, upperBound);
	}
}

template <typename T>
void merge (T list[], int lowerBound, int mid, int upperBound)
{
	int size1, size2, i, j, k;

	size1 = mid - lowerBound + 1;
	size2 = upperBound - mid;

	T *tmp1, *tmp2;

	tmp1 = new T[size1 + 1];
	tmp2 = new T[size2 + 1];

	for (i = 0; i < size1; i++)
	{
		tmp1[i] = list[lowerBound + i];
	}

	for (j = 0; j < size2; j++)
	{
		tmp2[j] = list[mid + j + 1];
	}

	tmp1[size1] = 10000001;
	tmp2[size2] = 10000001;

	i = 0;
	j = 0;

	for (k = lowerBound; k <= upperBound; k++)
	{
		if (tmp1[i] <= tmp2[j])
		{
			list[k] = tmp1[i];
			i++;
		}
		else
		{
			list[k] = tmp2[j];
			j++;
		}
	}

	delete [] tmp1;
	delete [] tmp2;
}

// Pre: a list and the upper and lower bounds for said list
// Post: the list in incrementing order
// Post: sorts an array
template <typename T>
void quickSort (T list[], int lowerBound, int upperBound)
{
	int i, j;
	T pivot, temp;

	i = lowerBound;
	j = upperBound;

	pivot = list[(lowerBound + upperBound) / 2];

	while (i <= j)
	{
		while (list[i] < pivot)
		{
			i++;
		}

		while (list[j] > pivot)
		{
			j--;
		}

		if (i <= j)
		{
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;
			i++;
			j--;
		}
	}

	if (lowerBound < j)
	{
		quickSort(list, lowerBound, j);
	}

	if (i < upperBound)
	{
		quickSort(list, i, upperBound);
	}
}

// Pre: a list and the size of said list
// Post: the list in incrementing order
// Post: sorts an array
// Note: Concept and design for algorithm is from http://www.geeksforgeeks.org/cocktail-sort/
template <typename T>
void cocktailSort (T list[], int size)
{
	bool swapped = true;
	int start = 0, end = size - 1, i;
	T temp;

	while (swapped)
	{
		swapped = false;

		for (i = start; i < end; i++)
		{
			if (list[i] > list[i + 1])
			{
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				swapped = true;
			}
		}

		if (!swapped)
			break;

		swapped = false;

		end--;

		for (i = end - 1; i >= start; i--)
		{
			if (list[i] > list[i + 1])
			{
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				swapped = true;
			}
		}

		start++;
	}
}

#endif //PA3_SORTING_H