//
// Created by Alice Easter on 12/4/17.
//

#ifndef FA17_CSI281_DECOSTA_EASTER_ITEMSET_H
#define FA17_CSI281_DECOSTA_EASTER_ITEMSET_H


#include "Node.h"

class Itemset
{
	public:

		Itemset();

		Itemset(int size);

		Itemset(std::string *mItems, int mSize);

		virtual ~Itemset() = default;

		std::string *getItems() const;

		std::string getItem(int index);

		int getSize() const;

		void setSize(int size);

		void setItems(std::string *items);

		bool searchItem(const std::string &item);

	protected:
		std::string *mItems;
		int mSize;
};


#endif //FA17_CSI281_DECOSTA_EASTER_ITEMSET_H
