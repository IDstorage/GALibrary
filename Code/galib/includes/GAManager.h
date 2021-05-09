#include "../includes/GAWorld.h"

namespace galib {

	class GAManager {
		GAManager() {}
		static GAManager* instance;
	public:
		static GAManager* GetInstance() {
			if (instance == nullptr) instance = new GAManager();
			return instance;
		}

	private:
		GAWorldBase* targetWorld;

	public:
		void SetWorld(GAWorldBase*);

	public:
		void Run();
	};

}