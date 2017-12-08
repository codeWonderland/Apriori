/* ***       Author:  Wei Kian Chen
     *  Last Update:  January 14, 2014
     *        Class:  CSI-281
     *     Filename:  sortingFunctions.h
     *
     *  Description:
     *      This is the template sorting functions.
     *  
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my own work.
     **********************************************************************/

#ifndef SORTING_FUNCTION_H
#define SORTING_FUNCTION_H

#include <iostream>
#include <climits>

/*      Pre:  The lhs and rhs objects are available
 *     Post:  The value for the lhs and rhs objects are swapped
 *  Purpose:  To swap two objects
 *****************************************************************************/
template <typename T>
void swapElement(T &ob1, T &ob2)
{
   T tmp;

   tmp = ob1;
   ob1 = ob2;
   ob2 = tmp;
}

/*      Pre:  the list populated, the lowerBound and upperBound are known
 *     Post:  This list is sorted in ascending order
 *  Purpose:  To sort a list using quick sort
 *****************************************************************************/
template <typename T>
void quickSort(T list[], int lowerBound, int upperBound) 
{
   int i, j;
   T   pivot;

   i = lowerBound;
   j = upperBound;

   pivot = list[(lowerBound + upperBound) / 2];

   while (i <= j)
   {
      while (list[i] < pivot)
         i++;

      while (list[j] > pivot)
         j--;

      if (i <= j)
      {
         swapElement(list[i], list[j]);

         i++;
         j--;
      }
   }

   if (lowerBound < j)
      quickSort(list, lowerBound, j);
   if (i < upperBound)
      quickSort(list, i, upperBound);
}

#endif