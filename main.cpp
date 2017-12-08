#include <iostream>
#include "AprioriFunctions.h"


int main()
{
    int sizeOriginalTransactions = 0;
    Itemset *originalTransactions = nullptr;
    std::string fileName = "dataset/T5.N0.1K.D1K.txt";

    sizeOriginalTransactions = loadArray(originalTransactions, fileName);

    quickSort(originalTransactions, 0, sizeOriginalTransactions - 1);

    int i, j;
    for (i = 0; i < 1000; i++)
    {
        for (j = 0; j < originalTransactions[i].getSize(); j++)
            std::cout << originalTransactions[i].getItem(j) << " ";
       std::cout << std::endl;
    }
    delete originalTransactions;
	return 0;
}