//
// Created by Alice Easter on 12/6/17.
//

#include "AprioriFunctions.h"

void newFrequency(CircularQueue<Frequency> &frequencyQueue, Frequency &newFrequency)
{
	if (frequencyQueue.isFull())
	{
		outputFrequency(frequencyQueue.dequeue());
	}

	frequencyQueue.enqueue(newFrequency);
}

void outputFrequency(Frequency frequency)
{
	std::ofstream outFile;
	outFile.open("output.txt", ios::out | ios::app);

	outFile << "Frequency " << frequency.getID() << ":\n";

	LinkedList<Association> *associationList = frequency.getAssociations();

	outputList(associationList);

	outFile << "\n";

	std::cout << "Frequency Output Successful" << std::endl;

	outFile.close();
}

void outputList(LinkedList<Association> *linkedList)
{
	int i = 0;
	std::ofstream outFile;
	outFile.open("output.txt", ios::out | ios::app);

	Node<Association> *tmp = linkedList->mHead;

	while (tmp != nullptr)
	{
		for (i = 0; i < tmp->mData.getSize(); i++)
		{
			outFile << tmp->mData.getItem(i) << "; Support: " << tmp->mData.getSupport() << "\n";
		}
		tmp = tmp->mNext;
	}

	outFile.close();
}

void addToFrequency(CircularQueue<Frequency> *frequencyQueue, Association *association)
{
	frequencyQueue->mList[frequencyQueue->mTail].addAssociation(*association);
}

void loadArray(Itemset *originalTransactions, const std::string &fileName)
{
    std::ifstream fin;
    std::string line;
    std::stringstream ss;
    int *tmpArr = nullptr;
    int numItemsets = 0;
    int numNums;
    int item;

    fin.open(fileName);

	if (fin.fail())
	{
		std::cout << "Couldn't Open Data File\n";
		system("pause");
		exit(12);
	}

    while(getline(fin, line))                       //FINDS NUMBER OF ITEMSETS IN THE FILE
        numItemsets++;

    fin.clear();
    fin.seekg(0, fin.beg);                          //RETURNS TO THE BEGINNING OF THE FILE

    originalTransactions = new Itemset[numItemsets];

    int i, j;
    for (i = 0; i < numItemsets; i++)               //LOADS EACH ITEMSET
    {
        getline(fin, line);
        ss = std::stringstream(line);

        for (numNums = 0; ss >> item; numNums++);   // GETS THE NUMBER OF ITEMS ON EACH LINE

        ss.clear();                                 // RETURNS TO THE BEGINNING OF THE LINE
        ss.seekg(0, fin.beg);

        tmpArr = new int[numNums];          // ALLOCATES THE TMP ARRAY WITH THE NUMBER OF ITEMS

        for (j = 0; j < numNums; j++)               // LOADS EACH ITEM INTO TMP ARRAY
            ss >> tmpArr[j];

		originalTransactions[i].setItems(tmpArr);
		originalTransactions[i].setSize(numNums); 	// CREATES EACH ITEMSET
    }

    fin.close();
	tmpArr = nullptr;
	delete tmpArr;
}