//
// Created by Alice Easter on 12/6/17.
//

#include "AprioriFunctions.h"

void newFrequency(CircularQueue<Frequency> *frequencyQueue, Frequency &newFrequency)
{
	if (frequencyQueue->isFull())
	{
		outputFrequency(frequencyQueue->dequeue());
	}

	frequencyQueue->enqueue(newFrequency);
}

void outputFrequency(Frequency frequency)
{
	std::ofstream outFile;
	outFile.open("output.txt", ios::out | ios::app);

	outFile << "Frequency " + frequency.getID() + ":\n";

	LinkedList<Association> *associationList = frequency.getAssociations();

	outputList(associationList);

	outFile << "\n";

	std::cout << "Frequency Output Successful" << std::endl;

	outFile.close();

	delete outFile;
}

void outputList(LinkedList<Association> *linkedList)
{
	int i = 0;
	std::ofstream outFile;
	outFile.open("output.txt", ios::out | ios::app);

	LinkedList::Node *tmp = linkedList->mHead;

	while (tmp->mData != NULL)
	{
		for (i; i < tmp->mData->getSize(); i++)
		{
			outFile << tmp->mData->getItem(i) + "; Support: " + tmp->mData->getSupport() + "\n";
		}
		tmp = tmp->mNext;
	}

	outFile.close();

	delete outFile;
}

void addToFrequency(CircularQueue *frequncyQueue, Association *association)
{
	frequncyQueue->mList[frequncyQueue->mTail]->addAssociation(association);
}