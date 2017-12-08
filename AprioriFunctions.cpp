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

        if (currentAssociation->getSupport() > SUPPORT)
        {
            addToFrequency(frequencies, currentAssociation);
            currentAssociation = nullptr;
        }
        else
            delete currentAssociation;
    }
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

void generateFirstFrequency(CircularQueue<Frequency> *&frequencyQueue, const Itemset originalTransactions[],
                            const int &sizeOriginalTransactions)
{
    Association *currentAssociation;
    /*
     * TODO: go through original transactions and search for instances of this, for each instance increase the mSupport of the association
     * due to the nature of this we should create a search function - void searchAssociation(Association *&association, const Itemset &originalTransactions)
     * this function would search through the entire list and increase the mSupport in there
     * then in this gen1stFreq function we would check to see if the support of the association is greater than the minimum and if so append */
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