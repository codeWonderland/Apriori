//
// Created by Alice Easter on 12/6/17.
//

#ifndef FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H
#define FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H


#include "Models/circularQueue.h"

const int SUPPORT = 2;
const int LARGEST_ITEM = 99;

void newFrequency(CircularQueue<Frequency> *&frequencyQueue);

void outputFrequency(Frequency frequency);

int loadArray(Itemset *&originalTransactions, const std::string &fileName);

void generateFirstFrequency(CircularQueue<Frequency> *&frequencyQueue, const Itemset originalTransactions[], const int &sizeOriginalTransactions);

void searchAssociation(Association *&association, Itemset originalTransactions[], const int &sizeOriginalTransactions);


#endif //FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H
