//
// Created by Alice Easter on 12/4/17.
//

#include "Association.h"

Association::Association() : Itemset()
{

}

Association::Association(int *mItems, int &mSize) : Itemset(mItems, mSize), mSupport(0)
{

}

int Association::getSupport()
{
	return this->mSupport;
}

void Association::setSupport(const int &support)
{
	this->mSupport = support;
}
