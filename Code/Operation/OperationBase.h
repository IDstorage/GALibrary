#include <functional>
#include <list>

namespace galib {

	using Chromosome_ptr = std::unique_ptr<Chromosome>;
	using Parent = std::pair<Chromosome, Chromosome>;
	class Population_ptr;


	class SelectionOperator {
		static std::list<std::function<void(Population_ptr&, Parent&)>> operations;
	public:
		static void AddOperation(std::function<void(Population_ptr, Parent&)> oper, int specificOrder = -1) {
			if (specificOrder != -1) operations.insert(operations.begin() + specificOrder, oper);
			else operations.push_back(oper);
		}
		static void RemoveOperation(int order) {
			if (order < 0) order = 0;
			else if (order >= operations.size()) order = operations.size() - 1;
			operations.remove(operations.begin() + order);
		}

		static void Execute() {
			for (auto iter = operations.begin(); iter != operations.end(); ++iter) {
				(*iter)();
			}
		}
	};

	class CrossoverOperator {
		static std::list<std::function<void(const Parent&&, Chromosome_ptr&)>> operations;
	public:
		static void AddOperation(std::function<void(const Parent&&, Chromosome_ptr&)> oper, int specificOrder = -1) {
			if (specificOrder != -1) operations.insert(operations.begin() + specificOrder, oper);
			else operations.push_back(oper);
		}
		static void RemoveOperation(int order) {
			if (order < 0) order = 0;
			else if (order >= operations.size()) order = operations.size() - 1;
			operations.remove(operations.begin() + order);
		}

		static void Execute() {
			for (auto iter = operations.begin(); iter != operations.end(); ++iter) {
				(*iter)();
			}
		}
	};

	class MutationOperator {
		static std::list<std::function<void(Chromosome_ptr&)>> operations;
	public:
		static void AddOperation(std::function<void(Chromosome_ptr&)> oper, int specificOrder = -1) {
			if (specificOrder != -1) operations.insert(operations.begin() + specificOrder, oper);
			else operations.push_back(oper);
		}
		static void RemoveOperation(int order) {
			if (order < 0) order = 0;
			else if (order >= operations.size()) order = operations.size() - 1;
			operations.remove(operations.begin() + order);
		}

		static void Execute() {
			for (auto iter = operations.begin(); iter != operations.end(); ++iter) {
				(*iter)();
			}
		}
	};

	class ReplacementOperator {
		static std::list<std::function<void(Chromosome_ptr&)>> operations;
	public:
		static void AddOperation(std::function<void(Chromosome_ptr&)> oper, int specificOrder = -1) {
			if (specificOrder != -1) operations.insert(operations.begin() + specificOrder, oper);
			else operations.push_back(oper);
		}
		static void RemoveOperation(int order) {
			if (order < 0) order = 0;
			else if (order >= operations.size()) order = operations.size() - 1;
			operations.remove(operations.begin() + order);
		}

		static void Execute() {
			for (auto iter = operations.begin(); iter != operations.end(); ++iter) {
				(*iter)();
			}
		}
	};

}