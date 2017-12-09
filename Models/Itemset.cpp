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

bool Itemset::searchItem(const int &item) const
{
	int i = 0;
	for (i; i < this->mSize; i++)
	{
		if (this->mItems[i] == item)
			return true;
		else if (this->mItems[i] > item)
			return false;
	}
	return false;
}

bool Itemset::canContain(const Itemset &itemset) {
    bool possible = true;
    if (*this != itemset)
    {
        int smallestSize = this->getSize() < itemset.getSize() ? this->getSize() : itemset.getSize();
        int i;
        for (i = 0; i < smallestSize; i++)
        {
            if (this->mItems[i] > itemset.mItems[i])
            {
                possible = false;
                break;
            }
        }
    }
    return possible;
}

int Itemset::getSize() const
{
	return this->mSize;
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

Itemset::Itemset(int *items, int size)
{
    mItems = new int[size];
    mSize = size;
    int i;
    for (i = 0; i < mSize; i++)
        mItems[i] = items[i];

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
    bool less = false;
	if (*this != itemset)
	{
		int leftSize = this->getSize();
		int rightSize = itemset.getSize();
		int smallestSize = leftSize < rightSize ? leftSize : rightSize;
		int i;
		for (i = 0; i < smallestSize; i++)
		{
			if (this->mItems[i] < itemset.mItems[i])
			{
				less = true;
				break;
			}
            else if (this->mItems[i] > itemset.mItems[i])
            {
                less = false;
                break;
            }
            else if (i == smallestSize - 1 && rightSize > leftSize)
            {
                less = true;
            }
		}
	}
    return less;
}

bool Itemset::operator>(const Itemset &itemset) {
	bool more = false;
	if (*this != itemset)
	{
		int leftSize = this->getSize();
		int rightSize = itemset.getSize();
		int smallestSize = leftSize < rightSize ? leftSize : rightSize;
		int i;
        for (i = 0; i < smallestSize; i++)
        {
            if (this->mItems[i] > itemset.mItems[i])
            {
                more = true;
                break;
            }
            else if (this->mItems[i] < itemset.mItems[i])
            {
                more = false;
                break;
            }
            else if (i == smallestSize - 1 && rightSize < leftSize)
            {
                more = true;
            }
        }
	}
	return more;
}

bool Itemset::operator>=(const Itemset &itemset) {
    bool less = false;
    if (*this != itemset)
    {
        int leftSize = this->getSize();
        int rightSize = itemset.getSize();
        int smallestSize = leftSize < rightSize ? leftSize : rightSize;
        int i;
        for (i = 0; i < smallestSize; i++)
        {
            if (this->mItems[i] < itemset.mItems[i])
            {
                less = true;
                break;
            }
            else if (this->mItems[i] > itemset.mItems[i])
            {
                less = false;
                break;
            }
            else if (i == smallestSize - 1 && rightSize > leftSize)
            {
                less = true;
            }
        }
    }
    return !less;
}

bool Itemset::operator<=(const Itemset &itemset) {
    bool more = false;
    if (*this != itemset)
    {
        int leftSize = this->getSize();
        int rightSize = itemset.getSize();
        int smallestSize = leftSize < rightSize ? leftSize : rightSize;
        int i;
        for (i = 0; i < smallestSize; i++)
        {
            if (this->mItems[i] > itemset.mItems[i])
            {
                more = true;
                break;
            }
            else if (this->mItems[i] < itemset.mItems[i])
            {
                more = false;
                break;
            }
            else if (i == smallestSize - 1 && rightSize < leftSize)
            {
                more = true;
            }
        }
    }
    return !more;
}
