//
// Created by Alice Easter on 12/4/17.
//

#ifndef FA17_CSI281_DECOSTA_EASTER_ASSOCIATION_H
#define FA17_CSI281_DECOSTA_EASTER_ASSOCIATION_H

#include "Itemset.h"

class Association : public Itemset
{
	public:
		Association();

		Association(int *items, int &size);

		virtual ~Association() = default;

		int getSupport();

		void setSupport(const int &support);

	private:
		int mSupport;
};


#endif //FA17_CSI281_DECOSTA_EASTER_ASSOCIATION_H
