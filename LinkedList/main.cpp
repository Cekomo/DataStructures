#include "LinkedList.h"

int main() {
    LinkedList list1;

    list1.InsertAtHead(15);
    list1.InsertAtPosition(21, 0);
    list1.InsertAtTail(31);
    list1.InsertAtTail(45);
    list1.InsertAtPosition(56, 11);

    list1.RemoveFromPosition(2);

    list1.PrintNodes();

    return 0;
}
