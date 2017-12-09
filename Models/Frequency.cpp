/* ***       Author:  Adam DeCosta & Alice Easter
     *  Last Update:  December 8th, 2017
     *        Class:  CSI-281
     *     Filename:  Frequency.cpp
     *
     *  Description:
     *      Definitions for Frequency Object
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     ******************************************************************/

#include "Frequency.h"

#include <utility>

Frequency::Frequency()
{
    mID = 0;
    mAssociations = new LinkedList<Association>();
}

Frequency::Frequency(int id, LinkedList<Association> &associations) : mID(id)
{
    this->mAssociations = &associations;
}

Frequency::~Frequency()
{
    mAssociations->clear();
}

int Frequency::getID() const
{
    return mID;
}

LinkedList<Association>* Frequency::getAssociations() const
{
    return mAssociations;
}

void Frequency::setID(int id)
{
    mID = id;
}

void Frequency::setAssociations(LinkedList<Association> &associations)
{
    this->mAssociations = &associations;
}

bool Frequency::searchAssociations(Association association)
{
    return mAssociations->isExist(association);
}

void Frequency::addAssociation(Association association)
{
    mAssociations->insert(association);
}