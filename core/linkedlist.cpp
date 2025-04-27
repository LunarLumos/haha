#include<iostream>
#include<list> 
using namespace std;

int main() {
    list<int> myList;
    int valueToDelete;

    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    cout << "Original List: ";
    for (int x : myList)
        cout << x << " ";
    cout << endl;

    cout << "Enter value to delete: ";
    cin >> valueToDelete;

    myList.remove(valueToDelete);

    cout << "After Delete:";
    for (int x : myList)
        cout << x << " ";
    cout << endl;

    return 0;
}
