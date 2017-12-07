//
// Created by adam.decosta on 12/4/2017.
//

#include "Frequency.h"

#include <utility>

Frequency::Frequency()
{
    mID = "";
    mAssociations = nullptr;
}

Frequency::Frequency(std::string id, LinkedList<Association> &associations)
{
    mID = std::move(id);
    this->mAssociations = &associations;
}

Frequency::~Frequency()
{
    mAssociations->clear();
}

std::string Frequency::getID()
{
    return mID;
}

LinkedList<Association>* Frequency::getAssociations()
{
    return mAssociations;
}

void Frequency::setID(std::string id)
{
    mID = std::move(id);
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