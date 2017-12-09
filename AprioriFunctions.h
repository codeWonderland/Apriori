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

#ifndef FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H
#define FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H


#include "Models/circularQueue.h"

const int SUPPORT = 2;

//Pre: takes in a circular queue of frequencies
//Post: returns nothing
//Purpose: adds a new empty frequency to the circular queue
void newFrequency(CircularQueue<Frequency> *&frequencyQueue);

//Pre: takes in nothing
//Post: returns numerical input from user
//Purpose: to get the number of distinct items in the dataset
int getNumItems();

//Pre: takes in the original transaction list, it's size, and the frequency circular queue
//Post: returns nothing
//Purpose: the main driver for the apriori functionality, directs flow and generates itemsets, then sends those itemsets to output
void apriori(Itemset *&originalTransactions, const int &sizeOriginalTransactions, CircularQueue<Frequency> *&frequencies);

//Pre: takes in the original transaction list, it's size, and the frequency circular queue
//Post: returns nothing
//Purpose: creates the association itemsets and determines if they meet minimum support
void aprioriGen(Itemset *&originalTransactions, const int &sizeOriginalTransactions, CircularQueue<Frequency> *&frequencies, const int &frequencyLevel, Frequency *&currentFrequency);

//Pre: takes in a frequency filled with associations
//Post: returns nothing
//Purpose: output data from frequency to file
void outputFrequency(Frequency frequency);

//Pre: takes in a pointer to the original transaction data structure as well as the input file name
//Post: returns the number of items in the original transactions
//Purpose: fills the original transactions data structure with data from file
int loadArray(Itemset *&originalTransactions, const std::string &fileName);

//Pre: takes in an association and the original transactions
//Post: returns nothing
//Purpose: determines if an association exists in original transactions and updates its support for each time it appears
void searchAssociation(Association *&association, Itemset originalTransactions[], const int &sizeOriginalTransactions);


#endif //FA17_CSI281_DECOSTA_EASTER_APRIORIFUNCTIONS_H
