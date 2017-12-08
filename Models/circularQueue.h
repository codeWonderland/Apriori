/* ***       Author:  Wei Kian Chen
     *  Last Update:  October 2, 2017
     *        Class:  CSI-281
     *     Filename:  circularQueue.h
     *
     *  Description:
     *      This is the template circular queue definition.
     *  
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my work.
     ******************************************************************/

#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "Frequency.h"

using namespace std;

const int C_CAPACITY = 2;

template<typename T>
class CircularQueue
{
	private:
		T mList[C_CAPACITY];

		int mHead, mTail, mCount;

	public:
		CircularQueue();

		T dequeue();

		void display();

		void enqueue(T data);

		bool isEmpty();

		bool isExist(T searchKey);

		bool isFull();

		friend void addToFrequency(CircularQueue<Frequency> *frequencyQueue, Association *association);

		void setTailFrequency(int id);
};


template<typename T>
CircularQueue<T>::CircularQueue()
{
	mHead = 0;
	mTail = 0;
	mCount = 0;
}




template<typename T>
T CircularQueue<T>::dequeue()
{
	T data = T();

	if (!isEmpty())
	{
		data = mList[mHead];
		mHead = (mHead + 1) % C_CAPACITY;
		mCount--;
	} else
		cout << "The list is empty; cannot remove any item\n";

	return data;
}


template<typename T>
void CircularQueue<T>::display()
{
	int i;

	if (mCount == 0)
		cout << "Empty list\n";
	else
	{
		for (i = 0; i < mCount; i++)
			cout << mList[(mHead + i) % C_CAPACITY] << " ";
		cout << endl;
	}
}


template<typename T>
void CircularQueue<T>::enqueue(T data)
{
	if (!isFull())
	{
		if (mCount == 0)
			mList[mHead] = data;
		else
		{
			mTail = (mTail + 1) % C_CAPACITY;
			mList[mTail] = data;
		}

		mCount++;
	} else
		cout << "Cannot add to the list; it is full\n";
}


template<typename T>
bool CircularQueue<T>::isEmpty()
{
	return (mCount == 0);
}


template<typename T>
bool CircularQueue<T>::isExist(T searchKey)
{
	int i;
	bool found = false;

	for (i = 0; i < mCount; i++)
		if (mList[(mHead + i) % C_CAPACITY] == searchKey)
		{
			found = true;
			break;
		}

	return found;
}


template<typename T>
bool CircularQueue<T>::isFull()
{
	return (mCount == C_CAPACITY);
}

template<typename T>
void CircularQueue<T>::setTailFrequency(int id)
{
	mList[mTail].setID(id);
}

#endif