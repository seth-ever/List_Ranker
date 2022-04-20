#ifndef RANKEDLISTGENERATOR_H // To make sure you don't declare the function more than once by including the header multiple times.
#define RANKEDLISTGENERATOR_H

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void populateRandom();
void populateVector(vector<string> &array, string fileName);
bool compare(string left, string right);
void printList(vector<string> list);
int partition(vector<string> &items, int left, int right);
void quicksort(vector<string> &items, int left, int right);
vector<string> quicksort2(vector<string> items);
void archiveSortedList(vector<string> sortedItems, string fileName);
void generator();

#endif