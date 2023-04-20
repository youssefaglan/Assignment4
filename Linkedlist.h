//
//  Linkedlist.h
//  Assignment4
//  900222720
//  Created by Youssef Aglan on 17/04/2023.
//

#ifndef Linkedlist_h
#define Linkedlist_h
#include <iostream>
#include <vector>

using namespace std;


struct Node {
    
    public :
    
    int Value;
    int Counter; // number of times the value appears in the list
    Node* Next; // a pointer to the next node in the list
    
    Node(int V, int C) : Value(V), Counter(C), Next(nullptr) {}
};

class Linkedlist {
    
private:
    Node* head; //  a pointer to the first node in the list

public:
    
    Linkedlist() : head(nullptr) {}
    
    // adds a new node to the end of the list with the given value and counter
    void AddNode(int Value, int Counter) {
        
        Node* NNode = new Node(Value, Counter);
     
        if (head == nullptr)
        {
            head = NNode;
        }
        else {
            Node* Cur = head;
            
            while(Cur -> Next != nullptr)
            {
                Cur = Cur -> Next;
            }
            Cur -> Next = NNode;
        }
    }
    
    // Removes the first node from with the given value from the list
    void RemoveNode(int Value)
    {
        Node* Cur = head;
        Node* Prev = nullptr;
    
        while (Cur != nullptr && Cur -> Value != Value)
        {
            Prev = Cur;
            Cur = Cur -> Next;
        }
        
        if(Cur == nullptr)
        {
            cout << "Value doesn't Exist in List" << endl;
        }
        
        else if(Prev == nullptr)
        {
            head = Cur -> Next;
            delete Cur;
        }
        
        else
        {
            Prev -> Next = Cur -> Next;
            delete Cur;
        }
    }
    
    // A function which prints out the values and counters of each node in the list
    void PrintList()
    {
        Node* Cur = head;
        
        while (Cur != nullptr)
        {
            cout << Cur -> Value << "(" << Cur -> Counter << ")" << " ";
        
        Cur = Cur -> Next;
        }
        cout << endl;
    }
    
    //Calculates the sum of the product of each node's value and counter and returns it
    int SumList()
    {
        int S = 0;
        Node* Cur = head;
        
        while(Cur != nullptr)
        {
            S += Cur -> Value * Cur -> Counter;
            Cur = Cur -> Next;
        }
        return S;
    }
};

// This function takes a vector of integers V and two integers which are the FirstValue and SecondValue and inserts the SecondValue after the first calling of FirstValue in the vector V.
void insertAfter(vector<int>& V, int FirstValue, int SecondValue)
{
    int n = V.size();
    
    for(int i = 0; i < n; i++)
    {
        if(V[i] == FirstValue)
        {
            V.insert(V.begin() + i + 1, SecondValue);
            i++;
            n++;
        }
    }
}

// This function takes a vector of integers V and creates a new Linkedlist object where each integer value in V is represented by a single node in the list, with the counter member indicating the number of times the value appears in V.
Linkedlist createLinkedlist(vector<int>& V)
{
    int n = V.size();
    
    Linkedlist List;
    
    for(int i = 0; i < n; i++)
    {
        int Counter = 1;
        int Value = V[i];
        
        for(int j = i + 1; j < n; j++)
        {
            if(V[j] == Value)
            {
                Counter++;
                V.erase(V.begin() + j);
                n--;
                j--;
            }
        }
        
        List.AddNode(Value, Counter);
    }
    return List;
}
#endif //LINKEDLIST_H
