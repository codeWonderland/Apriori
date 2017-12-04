//
// Created by Alice Easter on 12/4/17.
//

#ifndef FA17_CSI281_DECOSTA_EASTER_ITEMSET_H
#define FA17_CSI281_DECOSTA_EASTER_ITEMSET_H


#include <string>

class Itemset
{
	public:

		Itemset();

		Itemset(std::string *mItems, int mSize);

		virtual ~Itemset();

		std::string *getItems() const;

		int getSize() const;

		void setSize(int size);

		void setItems(std::string *items);

		bool searchItem(const std::string &item);

	private:
		std::string *mItems;
		int mSize;
};


#endif //FA17_CSI281_DECOSTA_EASTER_ITEMSET_H
