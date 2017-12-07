//
// Created by Alice Easter on 12/6/17.
//

#ifndef FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H
#define FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H

#include "Models/Frequency.h"
#include "Models/circularQueue.h"
#include <fstream>
#include "Models/linkedList.h"

void newFrequency(CircularQueue<Frequency> *frequencyQueue, Frequency &newFrequency);

void outputFrequency(Frequency frequency);

#endif //FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H
