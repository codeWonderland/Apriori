/* ***       Author:  Adam DeCosta & Alice Easter
     *  Last Update:  December 8th, 2017
     *        Class:  CSI-281
     *     Filename:  Association.h
     *
     *  Description:
     *      Header for Frequency.cpp
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     ******************************************************************/

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
