#include <vector>
#include <memory>

namespace galib {

    class Gene {
    private:
        char element;
    public:
        Gene(char data) : element(data) {}
        ~Gene() {}
    };

    class Chromosome {
    public:
        std::vector<std::unique_ptr<Gene>> geneList;
    };

    using Chromosome_ptr = std::unique_ptr<Chromosome>;
    using Parent = std::pair<Chromosome, Chromosome>;

}