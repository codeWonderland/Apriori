//
// Created by Alice Easter on 12/4/17.
//

#include "Association.h"

Association::Association() : Itemset()
{

}

Association::Association(std::string *mItems, int &mSize, int &mSupport) : Itemset(mItems, mSize), mSupport(mSupport)
{

}

Association::~Association()
= default;

int Association::getSupport()
{
	return this->mSupport;
}

void Association::setSupport(const int &support)
{
	this->mSupport = support;
}
