#include <iostream>
#include "AprioriFunctions.h"


int main()
{
    int sizeOriginalTransactions = 0;
    Itemset *originalTransactions = nullptr;
    auto *frequencies = new CircularQueue<Frequency>();
    std::string fileName = "dataset/T5.N0.1K.D1K.txt";

    sizeOriginalTransactions = loadArray(originalTransactions, fileName);

    int i = 0;
    for (i ; i < originalTransactions[0].getSize(); i++)
        std::cout << originalTransactions[0].getItem(i) << " ";
    std::cout << std::endl;
    int size = 2;
    auto itemarray = new int[size]{0, 3};
    auto *myAssociation = new Association(itemarray, size);

    searchAssociation(myAssociation, originalTransactions, sizeOriginalTransactions);

    std::cout << myAssociation->getSupport();

    delete originalTransactions;
	return 0;
}