//
// Created by Alice Easter on 12/4/17.
//

#include "Itemset.h"

std::string *Itemset::getItems() const
{
	return mItems;
}

void Itemset::setItems(std::string *items)
{
	Itemset::mItems = items;
}

bool Itemset::searchItem(const std::string &item)
{
	int i = 0;
	for (i; i < this->mSize; i++)
	{
		if (this->mItems[i] == item)
		{
			return true;
		}
	}
	return false;
}

int Itemset::getSize() const
{
	return mSize;
}

void Itemset::setSize(int size)
{
	Itemset::mSize = size;
}

Itemset::Itemset()
{
	this->mItems = NULL;
	this->mSize = 0;
}

Itemset::Itemset(std::string *mItems, int mSize) : mItems(mItems), mSize(mSize)
{

}

Itemset::~Itemset()
{

}
