//
//  main.cpp
//  Assignment4
//  900222720
//  Created by Youssef Aglan on 17/04/2023.
//

#include <iostream>
#include <vector>
#include "Linkedlist.h"

using namespace std;

int main()
{
    //Declaration of the variables
    
    int n, FirstValue, SecondValue;
    
    cout << "Please Enter a Number of Integers: ";
    
    cin >> n;
    
    vector<int> V(n); // a vector used to store the integers entered by the users
    
    for( int i = 0; i < n; i++) // for loops which adds entered integers to the vector
    {
        cout << "Please Enter an Integer: " << endl;
        cin >> V[i];
    }
    
    // gets from the user the values to use them in the insertAfter Function
    
    cout << "Enter the First Value: ";
    
    cin >> FirstValue;
    
    cout << "Enter the Second Value: ";
    
    cin >> SecondValue;
    
    insertAfter(V, FirstValue, SecondValue); // calls the function
    
    cout << "Modified Vector: "; // prints the vector after modification
    
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << " ";
    }
    
    cout << endl;
    
    Linkedlist List = createLinkedlist(V); // creates a LinkedList object from the modified vector
    
    cout << "Linked List: " << endl; // prints the LinkedList
    
    List.PrintList();
    
    cout << "The Sum of All Node is: " << List.SumList() << " " << endl; //prints the sum of all nodes in the LinkedList    
}
