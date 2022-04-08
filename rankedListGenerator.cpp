#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void populatRandom(vector<string>& array){
    for (size_t i = 0; i < 30; i++){
        array.push_back(to_string(rand() % 200));
    }
}

void populateVector(vector<string>& array,string fileName){
    if (fileName == "Random"){ //Purely For test Implementaion, 
        populatRandom(array);
        fileName += ".txt";
        return;
    }
    ifstream inpuStream;
    inpuStream.open(fileName);
    if (!inpuStream.is_open()){
        throw std::invalid_argument("File does not exist.\n");
    }
    string line;
    while (getline(inpuStream, line)){
        if (line != "") array.push_back(line);
    }
    inpuStream.close();
}

bool compare(string left, string right){// Returns false if left is greater than right, true otherwise. >
    static int compCount = 0;
    int answer;
    if (left == right) return false;
    compCount++;
    while (true){
        cout << endl << endl << endl; 
        cout << "CompCount " << compCount << endl;
        cout << "Which item is better:" << endl << "1. " << left << endl <<"2. " << right << endl;
        
        cin >> answer;
        if (answer == 1) return false;
        else if (answer == 2) return true;
        else cout << "Invalid Response" << endl;
    }
    
}

void printList(vector<string> list){
    for (size_t i = 0; i < list.size(); i++){
        cout << list.at(i) << endl;
    }
}

int partition(vector<string> &items, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    string pivotValue = items[pivotIndex];
    int i = left, j = right;
    string temp;
    while(i <= j) {
        while(compare(pivotValue, items[i] )) { // pivotValue < items[i]
            i++;
        }
        while(compare(items[j], pivotValue)) { //items[j] > pivotValue
            j--;
        }
        if(i <= j) {
            temp = items[i];
            items[i] = items[j];
            items[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(vector<string> &items, int left, int right) {
    if(left < right) {
        int pivotIndex = partition(items, left, right);
        quicksort(items, left, pivotIndex - 1);
        quicksort(items, pivotIndex, right);
    }
}

void archiveSortedList(vector<string> sortedItems, string fileName){
    string newFileName = "Ranked_" + fileName;
    ofstream outputStream(newFileName);
    for (size_t i = 0; i < sortedItems.size(); i++){
        outputStream << i + 1 << ". " << sortedItems.at(i) << endl;
    }
    outputStream.close();
}

int main(){
    string fileName;
    cout << "Enter the file name of the unsorted list." << endl;
    cin >> fileName;
    vector<string> items;

    populateVector(items, fileName); //printList(items);
            
    
    quicksort(items, 0, items.size() - 1);
    archiveSortedList(items, fileName);
    
    return 0;
}

