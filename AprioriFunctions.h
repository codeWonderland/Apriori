//
// Created by Alice Easter on 12/6/17.
//

#ifndef FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H
#define FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H


#include "Models/Frequency.h"
#include "Models/circularQueue.h"
#include <fstream>
#include "Models/linkedList.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "Models/Itemset.h"


void newFrequency(CircularQueue<Frequency> &frequencyQueue, Frequency &newFrequency);

void outputFrequency(Frequency frequency);

void loadArray(Itemset *originalTransactions, const std::string &fileName);

#endif //FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H
