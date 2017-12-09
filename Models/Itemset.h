/* ***       Author:  Adam DeCosta & Alice Easter
     *  Last Update:  Dec 8, 2017
     *        Class:  CSI-281
     *     Filename:  main.cpp
     *
     *  Description:
     *      Main Driver for Program, contains flow logic
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     ******************************************************************/

#ifndef FA17_CSI281_DECOSTA_EASTER_ITEMSET_H
#define FA17_CSI281_DECOSTA_EASTER_ITEMSET_H


#include "Node.h"

class Itemset
{
	public:

		Itemset();

		Itemset(int size);

		Itemset(int *items, int size);

		virtual ~Itemset() = default;

		int *getItems() const;

		int getItem(int index);

		int getSize() const;

		void setSize(int size);

		void setItems(int *items);

		bool searchItem(const int &item) const;

		bool canContain(const Itemset &itemset);

		bool operator<(const Itemset &itemset);

		bool operator>(const Itemset &itemset);
		
		bool operator<=(const Itemset &itemset);

		bool operator>=(const Itemset &itemset);

        bool operator==(const Itemset &itemset);

        bool operator!=(const Itemset &itemset);

	protected:
		int *mItems;
		int mSize;
};


#endif //FA17_CSI281_DECOSTA_EASTER_ITEMSET_H
