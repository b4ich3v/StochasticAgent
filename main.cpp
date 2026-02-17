#include "source/sigma_algebra/SigmaAlgebra.h"
#include "source/sigma_algebra/sigma_algebra_factory/SigmaAlgebraFactory.h"


int main() {
    ElementaryEvent e1;
    ElementaryEvent e2;
    ElementaryEvent e3("Event3");
    ElementaryEvent e4("Event4");
    ElementaryEvent e5 = e3;

    Vector<ElementaryEvent> arr;
    arr.push_back(e1);
    arr.push_back(e2);
    arr.push_back(e3);
    arr.push_back(e4);
    arr.push_back(e5);

    SetOfElementaryEvents set(arr);
    std::cout << set << std::endl;

    return 0;
}
