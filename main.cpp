#include <iostream>
#include "AprioriFunctions.h"


int main()
{
    int sizeOriginalTransactions = 0;
    Itemset *originalTransactions = nullptr;
    auto *frequencies = new CircularQueue<Frequency>();
    std::string fileName = "dataset/T5.N0.1K.D1K.txt";

    sizeOriginalTransactions = loadArray(originalTransactions, fileName);

    apriori(originalTransactions, sizeOriginalTransactions, frequencies);

    delete originalTransactions;
	return 0;
}