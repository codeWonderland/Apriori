/* ***       Author:  Adam DeCosta & Alice Easter
     *  Last Update:  Dec 8, 2017
     *        Class:  CSI-281
     *     Filename:  main.cpp
     *
     *  Description:
     *      Main Driver for Program, contains flow logic
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     ******************************************************************/

#include <iostream>
#include "AprioriFunctions.h"


int main()
{
    int sizeOriginalTransactions = 0;
    Itemset *originalTransactions = nullptr;
    auto *frequencies = new CircularQueue<Frequency>();
    std::string fileName = "dataset/T20.N0.1K.D1K.txt";

    sizeOriginalTransactions = loadArray(originalTransactions, fileName);

    apriori(originalTransactions, sizeOriginalTransactions, frequencies);

    delete originalTransactions;
	return 0;
}