//
// Created by Alice Easter on 12/6/17.
//

#ifndef FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H
#define FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H


#include "Models/circularQueue.h"


void newFrequency(CircularQueue<Frequency> *&frequencyQueue);

void outputFrequency(Frequency frequency);

int loadArray(Itemset *&originalTransactions, const std::string &fileName);

#endif //FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H
