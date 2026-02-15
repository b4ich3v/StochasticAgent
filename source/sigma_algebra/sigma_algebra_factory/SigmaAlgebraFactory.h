#include "SigmaAlgebraAbstractFactory.h"


class SigmaAlgebraFactory: public SigmaAlgebraAbstractFactory {
public:
    void create(SigmaAlgebraPattern pattern) override;
}