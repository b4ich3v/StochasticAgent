#include "source/data_structures/bitset/BitSet.h"


int main() {
    BitSet set(10);
    
    for (size_t i = 0; i < 4; i++) {
        set.addNumber(i);
    }
    
    set.addNumber(9);   
    
    std::cout << set << std::endl;
    std::cout << set.getAddition() << std::endl;

    return 0;
}
