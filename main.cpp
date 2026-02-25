#include "source/sigma_algebra/SigmaAlgebra.h"
#include "source/sigma_algebra/sigma_algebra_factory/SigmaAlgebraFactory.h"
#include "source/distributions/discrete_distributions/binomial/Binomial.h"
#include "source/distributions/BernoulliSchemeRandomVariable.hpp"
#include "source/Constants.h"
#include <iostream>


void test1() {
    size_t countOfExperimenents = 10;
    BernoulliSchemeRandomVariable<bool>* ber1 = new Bernoulli(0.9);
    BernoulliSchemeRandomVariable<bool>* ber2 = new Bernoulli(0.5);

    HeterogeneousContainer<BernoulliSchemeRandomVariable<bool>> bersFair;
    HeterogeneousContainer<BernoulliSchemeRandomVariable<bool>> bersUnFair;
    for (size_t i = 0; i < countOfExperimenents; i++) bersFair.addElement(ber2);
    for (size_t i = 0; i < countOfExperimenents; i++) bersUnFair.addElement(ber1);
    
    BernoulliSchemeRandomVariable<uint32_t>* binFair = new Binomial(bersFair);
    BernoulliSchemeRandomVariable<uint32_t>* binUnFair = new Binomial(bersUnFair);
    std::cout << binFair->calculateProbability(5) << std::endl;
    std::cout << binUnFair->calculateProbability(5) << std::endl;

    delete ber1;
    delete ber2;
    delete binFair;
    delete binUnFair;
}

void test2() {
    ElementaryEvent elementartyEvent1("I studided hard for statistics exam");
    ElementaryEvent elementartyEvent2("I passed statistics exam");
    ElementaryEvent elementartyEvent3("I did not passed statistics exam");

    ElementaryEvent result1 = elementartyEvent1 | elementartyEvent2;
    ElementaryEvent result2 = elementartyEvent1 & elementartyEvent2;
    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;
}

int main() {


    return 0;
}

