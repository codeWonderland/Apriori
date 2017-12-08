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


#endif //PA3_SORTING_H