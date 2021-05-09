#include "../includes/GAWorld.h"

using namespace galib;


GAWorldBase::GAWorldBase() {}
GAWorldBase::~GAWorldBase() {}


template <class _Typ>
void GAWorldBase::Initialize(const Chromosome<_Typ>& chrm) {

}

void GAWorldBase::SetWorldSetting(const GAWorldBase::Setting& setting) {
	this->setting = setting;
}


void GAWorldBase::AddGeneration(int n) {
	if (n <= 0) return;
	for (int i = 0; i < n; ++i) {
		Run();
		currentGeneration++;
	}
}

void GAWorldBase::MoveNext() {
	AddGeneration(1);
}

void GAWorldBase::Run() {
	static int _lastExecutedGen = -1;
	if (_lastExecutedGen == currentGeneration) throw new RunSameGenException();
	_lastExecutedGen = currentGeneration;
}

