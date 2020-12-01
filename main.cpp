#include <iostream>
#include "lib/math/operations.hpp"

int main()
{
    std::cout << "This statement if it is displayed, shows that Test.cpp build and executing process works. Also, compiling is a process for building. You need to link the files after compiling as well.";
    math::operations obj; // If I'm looking to use the functions I defined in the class, I need to make sure I create the object first. Can I skip the whole creating an object in the first place? Maybe, if I use static.
    // TODO
    std::cout << obj.sum(4, 6);
    return 0;
}
