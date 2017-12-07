//
// Created by Alice Easter on 12/4/17.
//

#include "Itemset.h"

int *Itemset::getItems() const
{
	return mItems;
}

int Itemset::getItem(int index)
{
	return mItems[index];
}

void Itemset::setItems(int *items)
{
	this->mItems = items;
}

bool Itemset::searchItem(const int &item)
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
	this->mItems = new int[size];
}

Itemset::Itemset(int *mItems, int mSize) : mItems(mItems), mSize(mSize)
{

}

bool Itemset::operator==(const Itemset &itemset) {
	int i, thisSize = this->getSize();
	bool equal = true;
	if (this->getSize() != thisSize)
		equal = false;
	else
	{
		for (i = 0; i < thisSize; i++)
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
	int i, thisSize = this->getSize();
	bool equal = true;
	if (thisSize != itemset.getSize())
		equal = false;
	else
	{
		for (i = 0; i < thisSize; i++)
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

bool Itemset::operator<(const Itemset &itemset) {
    bool less = true;
    if (this->mSize==itemset.mSize);
    else
    {
        int size = this->getSize();
        int i;
        for (i = 0; i < size; i++)
        {
            if (this->mItems[i] > itemset.mItems[i])
            {
                less = false;
            }
        }
    }

    return less;
}

bool Itemset::operator>(const Itemset &itemset) {
    bool greater = true;
    if (this->mSize==itemset.mSize);
    else
    {
        int size = this->getSize();
        int i;
        for (i = 0; i < size; i++)
        {
            if (this->mItems[i] < itemset.mItems[i])
            {
                greater = false;
            }
        }
    }

    return greater;
}

bool Itemset::operator>=(const Itemset &itemset) {
	bool less = true;
	if (this->mSize == itemset.mSize);
	else
	{
		int size = this->getSize();
		int i;
		for (i = 0; i < size; i++)
		{
			if (this->mItems[i] > itemset.mItems[i])
			{
				less = false;
			}
		}
	}

	return !less;
}

bool Itemset::operator<=(const Itemset &itemset) {
	bool greater = true;
	if (this->mSize == itemset.mSize);
	else
	{
		int size = this->getSize();
		int i;
		for (i = 0; i < size; i++)
		{
			if (this->mItems[i] < itemset.mItems[i])
			{
				greater = false;
			}
		}
	}

	return !greater;
}
