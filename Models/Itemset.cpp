//
// Created by Alice Easter on 12/4/17.
//

#include "Itemset.h"

std::string *Itemset::getItems() const
{
	return mItems;
}

std::string Itemset::getItem(int index)
{
	return mItems[index];
}

void Itemset::setItems(std::string *items)
{
	this->mItems = items;
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
	this->mSize = size;
}

Itemset::Itemset()
{
	this->mItems = nullptr;
	this->mSize = 0;
}

Itemset::Itemset(int size) : mSize(size)
{
	this->mItems = new std::string[size];
}

Itemset::Itemset(std::string *mItems, int mSize) : mItems(mItems), mSize(mSize)
{

}

bool Itemset::operator==(const Itemset &itemset) {
	int i;
	bool equal = true;
	if (this->getSize != itemset.getSize)
		equal = false;
	else
	{
		for (i = 0; i < this->getSize; i++)
		{
			if (this->mItems[i] != itemset.mItems[i])
			{
				equal = false;
				break;
			}
		}
	}

	return equal;
}

bool Itemset::operator!=(const Itemset &itemset) {
	int i;
	bool equal = true;
	if (this->getSize != itemset.getSize)
		equal = false;
	else
	{
		for (i = 0; i < this->getSize; i++)
		{
			if (this->mItems[i] != itemset.mItems[i])
			{
				equal = false;
				break;
			}
		}
	}

	return !equal;
}

bool Itemset::operator<(Itemset itemset) {
    return false;
}

bool Itemset::operator>(Itemset itemset) {
    return false;
}
