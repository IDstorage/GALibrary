#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <random>
#include <functional>
#include <algorithm>

namespace galib {

    template <class _Typ>
    class Chromosome {
    protected:
        std::vector<_Typ> geneList;

    public:
        Chromosome() {}
        virtual ~Chromosome() {}

    public:
        virtual std::string ToString() const { return "No Init"; }

        virtual float GetFitness() { return 0.0f; }

    public:
        void Init(const std::initializer_list<_Typ>& list) {
            geneList = std::vector<_Typ>(list);
        }

    public:
        _Typ& operator [](int index) {
            return geneList[index];
        }
    };

    template <class _Typ>
    using Parent = std::pair<Chromosome<_Typ>*, Chromosome<_Typ>*>;
    template <class _Typ>
    using Population = std::vector<Chromosome<_Typ>*>;

}