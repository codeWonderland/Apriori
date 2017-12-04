//
// Created by adam.decosta on 12/4/2017.
//

#ifndef FA17_CSI281_DECOSTA_EASTER_FREQUENCY_H
#define FA17_CSI281_DECOSTA_EASTER_FREQUENCY_H

#include <iostream>
#include <string>

#include "linkedList.h"
#include "Association.h"

class Frequency {
private:

    std::string mID;
    LinkedList<Association> mAssociations;

public:

    Frequency();

    Frequency(std::string id, LinkedList<Association> &associations);
    ~Frequency();

    std::string getID();

    LinkedList<Association> getAssociations();

    void setID(std::string id);
    void setAssociations(LinkedList<Association> associations);

    bool searchAssociations(Association association);
    void addAssociation(Association association);

};


#endif //FA17_CSI281_DECOSTA_EASTER_FREQUENCY_H
