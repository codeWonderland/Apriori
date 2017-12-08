//
// Created by Alice Easter on 12/6/17.
//

#ifndef FA17_CSI281_DECOSTA_EASTER_NODE_H
#define FA17_CSI281_DECOSTA_EASTER_NODE_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include "../sortingFunction.h"

template<typename R>
struct Node
{
	R mData;
	Node<R> *mNext;

	/*      Pre:  None
	 *     Post:  This object is initialized using default values
	 *  Purpose:  To initialize date object
	 ********************************************************************/
	Node()
	{
		mData = R();
		mNext = nullptr;
	}


	/*      Pre:  None
	 *     Post:  This object is initialized using specified data
	 *  Purpose:  To intialize date object
	 ********************************************************************/
	explicit Node(R data) : mData(data), mNext(nullptr)
	{

	}
};

#endif //FA17_CSI281_DECOSTA_EASTER_NODE_H
