#include <iostream>
#include "AprioriFunctions.h"


int main()
{
    int sizeOriginalTransactions = 0;
    Itemset *originalTransactions = nullptr;
    std::string fileName = "dataset/T5.N0.1K.D1K.txt";

    sizeOriginalTransactions = loadArray(originalTransactions, fileName);

    quickSort(originalTransactions, 0, sizeOriginalTransactions);

    std::cout << originalTransactions[98].getItem(3);
    delete originalTransactions;
	return 0;
}