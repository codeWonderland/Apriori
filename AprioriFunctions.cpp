//
// Created by Alice Easter on 12/6/17.
//

#include "AprioriFunctions.h"

void loadArray(Itemset *originalTransactions, std::string fileName)
{
    std::ifstream fin;
    std::string line;
    std::stringstream ss;
    std::string *tmpArr;
    int numItemsets = 0;
    int numNums;
    std::string item;

    fin.open(fileName);

    while(getline(fin, line))                       //FINDS NUMBER OF ITEMSETS IN THE FILE
        numItemsets++;

    fin.clear();
    fin.seekg(0, fin.beg);                          //RETURNS TO THE BEGINNING OF THE FILE

    originalTransactions = new Itemset[numItemsets];

    int i, j;
    for (i = 0; i < numItemsets; i++)               //LOADS EACH ITEMSET
    {
        getline(fin, line);
        ss = std::stringstream(line);

        for (numNums = 0; ss >> item; numNums++);   // GETS THE NUMBER OF ITEMS ON EACH LINE

        ss.clear();                                 // RETURNS TO THE BEGINNING OF THE LINE
        ss.seekg(0, fin.beg);

        tmpArr = new std::string[numNums];          // ALLOCATES THE TMP ARRAY WITH THE NUMBER OF ITEMS

        for (j = 0; j < numNums; j++)               // LOADS EACH ITEM INTO TMP ARRAY
            ss >> tmpArr[j];

        originalTransactions[i] = Itemset(tmpArr, numNums);     // CREATES EACH ITEMSET
    }

    fin.close();
}