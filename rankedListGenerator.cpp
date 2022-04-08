#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void populatRandom(vector<string>& array){//Values 0-199
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

bool compare(string left, string right){// Returns false if left is better than right, true otherwise. Better quality < Worse quality.
    static int compCount = 0;
    int answer;
    if (left == right) return false;
    compCount++;
    while (true){ 
        cout << "CompCount " << compCount << endl;
        cout << "Which item is better:" << endl << "1. " << left << endl <<"2. " << right << endl;
        cin >> answer;
        cout << endl << endl << endl;
        if (answer == 1) return false;
        else if (answer == 2) return true;
        else cout << "Invalid Response" << endl;
    }
    
}

void printList(vector<string> list){//For testing Purposes.
    for (size_t i = 0; i < list.size(); i++){
        cout << list.at(i) << endl;
    }
}

int partition(vector<string> &items, int left, int right) {//iterates through vector, (sub-vector) seperates as greater than/less than pivot.
    int pivotIndex = left + (right - left) / 2;
    string pivotValue = items[pivotIndex];
    int i = left, j = right;
    string temp;
    while(i <= j) {
        while(compare(pivotValue, items[i] )) { // pivotValue > items[i]
            i++;
        }
        while(compare(items[j], pivotValue)) { //items[j] < pivotValue
            j--;
        }
        if(i <= j) {
            swap(items[i],items[j]);
            i++;
            j--;
        }
    }
    return i;
}

void quicksort(vector<string> &items, int left, int right) { //Invokes the partion, recurcive
    if(left < right) {
        int pivotIndex = partition(items, left, right);
        quicksort(items, left, pivotIndex - 1);
        quicksort(items, pivotIndex, right);
    }
}

vector<string> quicksort2(vector<string> items){//more spacially complex but perhaps faster.
    vector<string> result;
    if (items.size() == 1){
        result.push_back(items[0]);
        return result;
    }
    if (items.size() == 0){ return result;}
    vector<string> left;
    vector<string> right;
    string pivotValue = items[0];
    for (size_t i = 1;i <items.size(); i++){
        if (compare(items[i], pivotValue)) {left.push_back(items[i]);} //items[i] < pivotValue
        else {right.push_back(items[i]);}// items[i] > pivotValue
    }
    vector<string> sortedLeft = quicksort2(left);
    vector<string> sortedRight = quicksort2(right);

    result.insert(result.end(),sortedLeft.begin(),sortedLeft.end());
    result.push_back(pivotValue);
    result.insert(result.end(),sortedRight.begin(),sortedRight.end());
    return result;

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
    //quicksort2(items);

    archiveSortedList(items, fileName);
    
    return 0;
}

