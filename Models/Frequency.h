//
// Created by adam.decosta on 12/4/2017.
//

#ifndef FA17_CSI281_DECOSTA_EASTER_FREQUENCY_H
#define FA17_CSI281_DECOSTA_EASTER_FREQUENCY_H

#include "linkedList.h"

class Frequency {
private:

    int mID;
    LinkedList<Association> *mAssociations;

public:

    Frequency();

    Frequency(int id, LinkedList<Association> &associations);
    ~Frequency();

    int getID() const;

    LinkedList<Association>* getAssociations() const;

    void setID(int id);
    void setAssociations(LinkedList<Association> &associations);

    bool searchAssociations(Association association);
    void addAssociation(Association association);

};


#endif //FA17_CSI281_DECOSTA_EASTER_FREQUENCY_H
