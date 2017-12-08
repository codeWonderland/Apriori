#include <iostream>
#include "AprioriFunctions.h"


int main()
{
    int sizeOriginalTransactions = 0;
    Itemset *originalTransactions = nullptr;
    CircularQueue<Frequency> *frequencies = new CircularQueue<Frequency>;
    std::string fileName = "dataset/T5.N0.1K.D1K.txt";

    sizeOriginalTransactions = loadArray(originalTransactions, frequencies, fileName);

    quickSort(originalTransactions, 0, sizeOriginalTransactions - 1);
    
    delete originalTransactions;
	return 0;
}