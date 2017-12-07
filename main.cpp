#include <iostream>
#include "AprioriFunctions.h"


int main()
{
    Itemset *originalTransactions = nullptr;
    std::string fileName = "dataset/T5.N0.1K.D1K.txt";

    loadArray(originalTransactions, fileName);

    delete originalTransactions;
	return 0;
}