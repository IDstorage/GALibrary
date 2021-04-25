namespace galib {

	using Chromosome_ptr = std::unique_ptr<Chromosome>;
	using Parent = std::pair<Chromosome, Chromosome>;
	class Population_ptr;

	template <class _Typ>
	class OperationBase {
	public:
		virtual void Execute();

	protected:
		_Typ* nextOperation = nullptr;
	public:

		_Typ* Next() const;
	};

	class SelectionBase : public OperationBase {
	public:
		virtual Parent& Execute(Population_ptr) = 0;
	};

	class CrossoverBase : public OperationBase {
	public:
		virtual Chromosome_ptr Execute(Chromosome_ptr, Chromosome_ptr) = 0;
		Chromosome_ptr Execute(Parent& prnt) {
			Execute(prnt.first, prnt.second);
		}
	};

	class MutationBase : public OperationBase {
	public:
		virtual Chromosome_ptr Execute(Chromosome_ptr) = 0;
	};

	class ReplacementBase : public OperationBase {
	public:
		virtual Chromosome_ptr Execute(Chromosome_ptr) = 0;
	};

}