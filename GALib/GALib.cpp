// GALib.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include "GALib.h"

using namespace std;

class IsaacMapGen : public galib::GAWorld {

};

class CustomChromosome : public galib::Chromosome<int> {

};

class Oper : public galib::MutationBase<int> {
public:
	galib::Chromosome_ptr<int> Execute(galib::Chromosome_ptr<int> obj) {
		galib::MutationBase<int>::Execute(obj);
		cout << "Mutation by Oper" << endl;
	}
};


int main() {

	Oper* oper = new Oper();
	oper->Execute(nullptr);

	cout << "Hello CMake." << endl;
	return 0;
}
