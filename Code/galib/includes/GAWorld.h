#include <iostream>
#include "Chromosome.h"

namespace galib {

	class GAWorldBase {
	public:
		struct Setting {
			std::string worldName = "Genetic Algorithm";
			int chrmCount = 50;
			int chrmLength = 0;
		};

	public:
		GAWorldBase();
		virtual ~GAWorldBase();

	protected:
		int currentGeneration = 0;
		Setting setting;

	public:
		void SetWorldSetting(const Setting&);

	public:
		template <class _Typ>
		void Initialize(const Chromosome<_Typ>&);

	public:
		void AddGeneration(int);
		void MoveNext();

	public:
		virtual void Run();

	public:
		class RunSameGenException : public ::std::exception {
		public:
			RunSameGenException() noexcept
				: ::std::exception("Do not run same generation! Duplicated result!", 1) {}
		};
	};

	template <class _Typ>
	class GAWorld : public GAWorldBase {
	private:
		std::vector<Chromosome<_Typ>*> population;

	public:
		GAWorld() {}
		virtual ~GAWorld() {}

	public:
		void Initialize(Chromosome<_Typ>* base) {
		}
	};

}
