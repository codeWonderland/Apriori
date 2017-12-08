//
// Created by adam.decosta on 12/4/2017.
//

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