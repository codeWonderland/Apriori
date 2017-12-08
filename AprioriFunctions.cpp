//
// Created by Alice Easter on 12/6/17.
//

#include "AprioriFunctions.h"

void newFrequency(CircularQueue<Frequency> *&frequencyQueue)
{
    if (frequencyQueue->isFull())
    {
        outputFrequency(frequencyQueue->dequeue());
    }

    frequencyQueue->enqueue(Frequency());
}

void apriori(Itemset *&originalTransactions, const int &sizeOriginalTransactions,
             CircularQueue<Frequency> *&frequencies)
{
    int numDistinctItems = getNumItems();
    int i, frequencyNum = 1, associationSize = 1;
    Association *currentAssociation = nullptr;
    // Generating frequency - 1
    for (i = 0; i < numDistinctItems; i++)
    {
        currentAssociation = new Association(new int[associationSize]{i}, associationSize);
        searchAssociation(currentAssociation, originalTransactions, sizeOriginalTransactions);

        if (currentAssociation->getSupport() >= SUPPORT)
        {
            addToFrequency(frequencies, currentAssociation);
            currentAssociation = nullptr;
        }
        else
            delete currentAssociation;
    }

    //TODO: Add next level frequencies
    Frequency *currentFrequency = nullptr;

    do
    {
        if (frequencyNum > 2)
        {
            outputFrequency(frequencies->dequeue());
        }
        if (frequencyNum > 3)
            frequencies->enqueue(*currentFrequency);

        frequencies->setTailFrequency(frequencyNum);

        frequencyNum++;
        currentFrequency = aprioriGen(originalTransactions, sizeOriginalTransactions, frequencies, frequencyNum);
    }
    while(!currentFrequency->getAssociations()->isEmpty());
}

Frequency* aprioriGen(Itemset *&originalTransactions, const int &sizeOriginalTransactions, CircularQueue<Frequency> *&frequencies, const int &frequencyLevel)
{
    auto *candidateSet = new Itemset();
    auto *currentFrequency = new Frequency();
    currentFrequency->setID(frequencyLevel);

    Node<Association> *tmp = nullptr;
    Association *tmpAssoc = nullptr;
    int i;
    for (i = 0; i < frequencyLevel-2; i++)
    {
        tmp = frequencies->mList[frequencies->mHead].getAssociations()->getHead();
        while (tmp != nullptr) {
            tmpAssoc = &tmp->mData;
            searchAssociation(tmpAssoc, originalTransactions, sizeOriginalTransactions);

            if (tmpAssoc->getSupport() >= SUPPORT)
            {
                currentFrequency->addAssociation(*tmpAssoc);
            }
            else
                tmpAssoc = nullptr;

            tmp = tmp->mNext;
        }

    }

    return currentFrequency;
}



int getNumItems()
{
    std::string input;
    std::cout << "How many distinct items are in your dataset: ";
    std::cin >> input;
    return std::stoi(input);
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

int loadArray(Itemset *&originalTransactions, const std::string &fileName)
{
    std::ifstream fin;
    std::string line;
    std::stringstream ss;
    int *tmpArr = nullptr;
    int numItemsets = 0;
    int numNums, item;

    fin.open(fileName);

    if (fin.fail())
    {
        std::cout << "Couldn't Open Data File\n";
        system("pause");
        exit(12);
    }

    while (getline(fin, line))                       //FINDS NUMBER OF ITEMSETS IN THE FILE
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

        tmpArr = new int[numNums];                // ALLOCATES THE TMP ARRAY WITH THE NUMBER OF ITEMS

        for (j = 0; j < numNums; j++)               // LOADS EACH ITEM INTO TMP ARRAY
            ss >> tmpArr[j];

        originalTransactions[i].setItems(tmpArr);
        originalTransactions[i].setSize(numNums);    // CREATES EACH ITEMSET
    }

    fin.close();
    tmpArr = nullptr;

    quickSort(originalTransactions, 0, numItemsets - 1);


    return numItemsets;
}

void searchAssociation(Association *&association, Itemset originalTransactions[], const int &sizeOriginalTransactions)
{
    int i, j;
    bool associationExists;
    int associationSize = association->getSize();

    //Loops through all of the original transactions
    for (i = 0; i < sizeOriginalTransactions; i++)
    {

        associationExists = true; // assume true unless proven wrong

        if (originalTransactions[i].canContain(*association))
        {
            //If the size of the associations is greater than the transaction then the association cannot exist
            if (associationSize > originalTransactions[i].getSize())
                associationExists = false;
            else
            {
                //Loops through every item in associations
                for (j = 0; j < associationSize; j++)
                {
                    // If an item in the association doesn't exist in the transaction then association doesn't exist
                    if (!originalTransactions[i].searchItem(association->getItem(j)))
                    {
                        associationExists = false;
                        break;    //Stops looping through this association since it cannot exist
                    }
                }
            }
        }
        else
            break;
        // Increases the support of the association if the association exists
        if (associationExists)
        {
            association->setSupport(association->getSupport() + 1);
        }
    }
}