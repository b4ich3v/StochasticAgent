#include "source/sigma_algebra/SigmaAlgebra.h"
#include "source/sigma_algebra/sigma_algebra_factory/SigmaAlgebraFactory.h"


int main() {
    ElementaryEvent e1("Event 1");
    ElementaryEvent e2("Event 2");
    ElementaryEvent e3("Event 3");

    Vector<ElementaryEvent> arr;
    arr.push_back(e1);
    arr.push_back(e2);
    arr.push_back(e3);

    Omega omega(arr);

    SigmaAlgebraAbstractFactory* factory = new SigmaAlgebraFactory();
    SigmaAlgebra* sigma = factory->create(SigmaAlgebraPattern::TRIVIAL, &omega);
    std::cout << *sigma << std::endl;





    delete factory;
    delete sigma;
    return 0;
}
