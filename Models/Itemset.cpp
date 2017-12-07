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

bool Itemset::operator==(Itemset itemset) {
    return false;
}

bool Itemset::operator!=(Itemset itemset) {
    return false;
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
