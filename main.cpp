#include "rankedListGenerator.h"
#include "merge.h"
#include <bits/stdc++.h>
int main()
{
    string response = "";
    while (true)
    {

        cout << "To sort a single list, Enter sort." << endl;
        cout << "To merge two already sorted lists, Enter merge" << endl;
        cin >> response;
        transform(response.begin(), response.end(), response.begin(), ::tolower);
        if (response == "sort")
        {
            generator();
            break;
        }
        if (response == "merge")
        {
            mergeStart();
            break;
        }
        if (response == "quit")
        {
            break;
        }
        cout << "Incorrect Response" << endl;
    }

    return 0;
}