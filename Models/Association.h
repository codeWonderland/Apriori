/* ***       Author:  Adam DeCosta & Alice Easter
     *  Last Update:  December 8th, 2017
     *        Class:  CSI-281
     *     Filename:  Association.h
     *
     *  Description:
     *      Header for Association.cpp
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     ******************************************************************/

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
