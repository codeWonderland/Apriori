//
// Created by adam.decosta on 12/4/2017.
//

#include "Frequency.h"

Frequency::Frequency()
{
    mID = "";
    mAssociations = NULL;
}

Frequency::Frequency(std::string id, LinkedList<Association> &associations)
{
    mID = id;
    this->mAssociations = associations;
}

Frequency::~Frequency()
{
    mAssociations.clear();
}

std::string Frequency::getID()
{
    return mID;
}

LinkedList<Association> Frequency::getAssociations()
{
    return mAssociations;
}

void Frequency::setID(std::string id)
{
    mID = id;
}

void Frequency::setAssociations(LinkedList<Association> &associations)
{
    this->mAssociations = associations;
}

bool Frequency::searchAssociations(Association association)
{
    mAssociations.isExist(association);
}

void Frequency::addAssociation(Association association)
{
    mAssociations.insert(association);
}