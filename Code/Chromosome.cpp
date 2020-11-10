#include "UqPtr.h"
#include <vector>

namespace galib {

    template <class _Typ>
    class Chromosome {
        std::vector<UqPtr<_Typ>> geneList;
    };

}