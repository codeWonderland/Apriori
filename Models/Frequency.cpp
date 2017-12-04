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

}

std::string Frequency::getID()
{

}

LinkedList<Association> Frequency::getAssociations()
{

}

void Frequency::setID(std::string id)
{

}

void Frequency::setAssociations(LinkedList<Association> associations)
{

}

bool Frequency::searchAssociations(Association association)
{

}

void Frequency::addAssociation(Association association)
{

}