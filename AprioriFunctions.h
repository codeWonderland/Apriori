//
// Created by Alice Easter on 12/6/17.
//

#ifndef FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H
#define FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H


#include "Models/circularQueue.h"

const SUPPORT = 2;
const LARGEST_ITEM = 99;

void newFrequency(CircularQueue<Frequency> *&frequencyQueue);

void outputFrequency(Frequency frequency);

int loadArray(Itemset *&originalTransactions, const std::string &fileName);

void generateFirstFrequency(CircularQueue<Frequency> *&frequencyQueue, const Itemset &originalTransactions);

#endif //FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H
