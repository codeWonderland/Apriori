/* ***       Author:  Adam DeCosta & Alice Easter
     *  Last Update:  December 8th, 2017
     *        Class:  CSI-281
     *     Filename:  Association.cpp
     *
     *  Description:
     *      The definitions for the Association objects
     *
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     ******************************************************************/
#include "Association.h"

/*
 * Pre: None
 * Post: None
 * Purpose: Default Constructor for Association
 */
Association::Association() : Itemset()
{

}

/*
 * Pre: An integer array and the size of the array
 * Post: None
 * Purpose: Constructor for Associations
 */
Association::Association(int *items, int &size) : Itemset(items, size), mSupport(0)
{

}

/*
 * Pre: None
 * Post: The support of the association
 * Purpose: Gets the support of the associations
 */
int Association::getSupport()
{
	return this->mSupport;
}

/*
 * Pre: Integer to be set as the support
 * Post: None
 * Purpose: sets the support for the association
 */
void Association::setSupport(const int &support)
{
	this->mSupport = support;
}
