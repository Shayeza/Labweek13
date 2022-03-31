
#include "ais1002/SinglyLinkedList.hpp"

#include <iostream>
#include <string>

using namespace ais1002;

int main() {

    SinglyLinkedList<std::string> list;
    list.addFirst("Per");

    std::cout << "Hello " << list.removeLast() << "!" << std::endl;
}
