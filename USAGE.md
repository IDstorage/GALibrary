### EXAMPLE


class MyWorld : public galib::GAWorld<char> { /* ... */ }

...

galib::UqPtr<MyWorld> world1 = galib::UqPtr<MyWorld>::Create();

world1->SetFitnessFunction(func);
world1->SetWorldType(type);
world1->SetCrossoverOper(oper);
world1->SetMutationOper(oper);
...
...

// true면 100까지, false면 앞으로 100 더
world1->Run(delay: 10.0f, resetGene: true, targetGen: 100);

world1->SetSavePoint("~/Result/day1.txt");

world1->BeginCrossoverCallback = []() => {}
world2->EndMutationCallback = []() => {}

...


class CustomCrossover : public galib::CrossoverBase<int> {
public:
    virtual galib::Chromosome<int> Execute(galib::Chromosome<int>, )
}