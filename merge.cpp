#include "merge.h"

vector<string> merger(vector<string> l1, vector<string> l2)
{
    vector<string> combinedList;
    combinedList.reserve(l1.size() + l2.size());
    size_t l1Index = 0;
    size_t l2Index = 0;
    while (true)
    {
        if (l1Index == l1.size()) // List one runs out first
        {
            for (l1Index; l2Index < l2.size(); l2Index++) // Appends the rest of list two
            {
                combinedList.push_back(l2[l2Index]);
            }
            break;
        }

        if (l2Index == l2.size()) // List two runs out first
        {
            for (l1Index; l1Index < l1.size(); l1Index++) // Appends the rest of list one
            {
                combinedList.push_back(l1[l1Index]);
            }
            break;
        }
        if (compare(l1[l1Index], l2[l2Index]))
        {
            combinedList.push_back(l2[l2Index]);
            l2Index++;
        }
        else
        {
            combinedList.push_back(l1[l1Index]);
            l1Index++;
        }
    }
    return combinedList;
}

void mergeStart()
{
    string fileName1;
    cout << "Enter the file name of the FIRST sorted list." << endl;
    cin >> fileName1;
    vector<string> items1;

    string fileName2;
    cout << "Enter the file name of the SECOND sorted list." << endl;
    cin >> fileName2;
    vector<string> items2;

    populateVector(items1, fileName1); // printList(items);
    populateVector(items2, fileName2); // printList(items);
    vector<string> combinedList = merger(items1, items2);
    for (size_t i = 0; i < 4; i++)
    {
        fileName1.pop_back();
        fileName2.pop_back();
    }
    string newFileName = "Combined_" + fileName1 + "_" + fileName2 + ".txt";
    archiveSortedList(combinedList, newFileName);
}