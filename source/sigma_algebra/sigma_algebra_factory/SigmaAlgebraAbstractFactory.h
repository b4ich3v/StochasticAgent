#include "../SigmaAlgebraPattern.h"


class SigmaAlgebraAbstractFactory {
public:
    virtual void create(SigmaAlgebraPattern pattern) = 0;
    virtual ~SigmaAlgebraAbstractFactory() = default;
}