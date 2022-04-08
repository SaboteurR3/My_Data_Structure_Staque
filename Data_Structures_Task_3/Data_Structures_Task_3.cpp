#include <iostream>
#include "Staque.h"
using namespace std;

int main()
{
    // შევქმნათ ცარიელი სია
    Staque* node = NULL;
    cout << "\Before adding nodes in a linked list, ";
    // არის თუ არა სია ცარიელი?
    (node->isEmpty(node)) ? cout << "Linked list is empty!" : cout << "Linked list is not empty!";
    // ელემენტები დაემატება LIFO პირნციპით იმისდამიხედვით ლუწია თუ კენტი
    node->add(&node, 5);
    node->add(&node, 1);
    node->add(&node, 2);
    node->add(&node, 4);
    cout << "\nAfter adding nodes in a linked list, ";
    // ისევ ვამოწმებთ არის თუ არა სია ცარიელი?
    (node->isEmpty(node)) ? cout << "Linked list is empty!" : cout << "Linked list is not empty!";
    cout << "\nLinked list before 'remove' method: ";
    node->printList(node);
    // უნდა ამოშალოს პირველი ელემენტი ამ შემთხვეევაში მარცხნიდან რადგან თავში პირველი ლუწი რიცხვია(4)
    node->remove(&node, node); 
    cout << endl;
    cout << "Linked list after 'remove' method: ";
    node->printList(node);
    // უნდა ამოშალოს პირველი ელემენტი ამ შემთხვეევაში მარჯვნიდან რადგან node->getNext() არის '1' და არის კენტი
    node->remove(&node, node->getNext());
    cout << "\nLinked list after calling 'remove' method again: ";
    node->printList(node);
    // არის თუ არა სია ცარიელი?
    (node->isEmpty(node)) ? cout << "Linked list is empty!" : cout << "Linked list is not empty!";
    // არის თუ არა 15 და 5 სიაში?
    (node->search(node, 15)) ? cout << "\n15 is in a linked list " : cout << "\n15 isn't in a linked list ";
    (node->search(node, 5)) ? cout << "\n5 is in a linked list " : cout << "\n5 isn't in a linked list ";
    // ვიძახებთ copy constuctor - ს
    Staque* node2 = node;
    cout << "\nCalling copy constuctor... after creating second doubly linked list it has elements: ";
    node2->printList(node2);
    cout << endl;
    return 0;
}
