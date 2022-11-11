#include <iostream>
#include "LinkedList_char.h"


using namespace std;


LinkedList::LinkedList()
{
    //default linked list has no first or last
    first = nullptr;
    last  = nullptr;
}


LinkedList::~LinkedList()
{
    //NOTE: probably a way to auto free the memory instead of manually doing it
    //if size is 0 or 1 manually free memory
    if ((first == nullptr) || ((*first).next == nullptr))
    {
        delete last;
        first = nullptr;
        last  = nullptr;
    }
    //if size is larger than 1 loop through the linked list and free memory node by node
    while (last != nullptr)
    {
        Node *current = first;
        Node *next    = (*current).next;
        delete current;
        if (next != last)
        {
            first = next;
        }
        else
        {
            // resets the linked list
            delete next;
            first = nullptr;
            last  = nullptr;
        }
    }
}


void LinkedList::insertAtBack(char element)
{
    //make a new node to insert at the back of the linked list
    Node *newNode = new Node;

    //default values for a node
    (*newNode).val  = element;
    (*newNode).next = nullptr;
    //if first is set to nothing set it to the first node
    if (first == nullptr)
    {
        first = newNode;
    }
    //if this is the second or greater element update the previous node to pochar to the new node
    if (last != nullptr)
    {
        (*last).next = newNode;
    }
    //no matter what, last needs to get set to the new node
    last = newNode;
}


bool LinkedList::removeFromBack()
{
    Node *current = first;

    //if one item in linked list manually remove it
    if (size() == 1)
    {
        delete last;
        last  = nullptr;
        first = nullptr;
        return true;
    }
    //loop through array until you get to the last one, remove it
    while (size() != 0)
    {
        if ((*current).next == last)
        {
            delete last;
            last = current;
            return true;
        }
        else
        {
            current = (*current).next;
        }
    }
    //if size is 0 return false
    return false;
}


void LinkedList::print()
{
    //loop through the linked list and cout node as you get to it
    Node *current   = first;
    char sizeLinked = size();

    for (char i = 0; i < sizeLinked; i++)
    {
        if (i + 1 != sizeLinked)
        {
            cout << (*current).val << ", ";
        }
        else
        {
            cout << (*current).val;
        }
        current = current->next;
    }
}


bool LinkedList::isEmpty()
{
    return size() == 0;
}


int LinkedList::size()
{
    //manual check if size is 0
    if (first == nullptr)
    {
        return 0;
    }
    //else loop through linked list and count how many nodes you have visited till you get to the last node
    Node *current = first;
    int  size     = 1;

    while (true)
    {
        if (current == last)
        {
            return size;
        }
        else
        {
            current = current->next;
            size++;
        }
    }
    cout << endl;
}


void LinkedList::clear()
{
    //if size is 0 or 1 manually free memory
    if ((first == nullptr) || ((*first).next == nullptr))
    {
        delete last;
        first = nullptr;
        last  = nullptr;
    }
    //if size is larger than 1 loop through the linked list and free memory node by node
    while (last != nullptr)
    {
        Node *current = first;
        Node *next    = (*current).next;
        delete current;
        if (next != last)
        {
            first = next;
        }
        else
        {
            // resets the linked list
            delete next;
            first = nullptr;
            last  = nullptr;
        }
    }
}


void LinkedList::insertAtFront(char element)
{
    Node *newNode = new Node;

    (*newNode).val = element;
    //if linked list is empty next is null, if linked list is not empty then set the next node to the first node
    size() != 0? (*newNode).next = first : (*newNode).next = nullptr;

    //if last is set to nothing set it to the new node
    if (last == nullptr)
    {
        last = newNode;
    }
    first = newNode;
}


bool LinkedList::removeFromFront()
{
    //if linked list is empty return false as there is nothing to delete
    if (size() == 0)
    {
        return false;
    }
    else if (size() > 1)
    {
        //make a copy of the next node, delete the first node and set the first node to the next node
        Node *nextNode = (*first).next;
        delete first;
        first = nextNode;
        return true;
    }
    //covers the case where the size is 1 and after it gets removed the linked list has nothing left
    else
    {
        delete first;
        first = nullptr;
        last  = nullptr;
    }
}
