//
// Created by Alice Easter on 12/6/17.
//

#ifndef FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H
#define FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H


#include "Models/circularQueue.h"

const SUPPORT = 2;


void newFrequency(CircularQueue<Frequency> *&frequencyQueue);

void outputFrequency(Frequency frequency);

int loadArray(Itemset *&originalTransactions, CircularQueue<Frequency> *&frequencies, const std::string &fileName);

#endif //FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H
