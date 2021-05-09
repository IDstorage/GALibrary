#include "main.h"
#include <set>

std::tr1::mt19937 engine((unsigned int)time(NULL));
std::tr1::uniform_real_distribution<double> distribution_real(0.0, 1.0);
std::tr1::uniform_int_distribution<int> distribution_int(0, 4);
auto generator_real = std::bind(distribution_real, engine);
auto generator_int = std::bind(distribution_int, engine);


struct Point {
	int x;
	int y;

	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

	bool operator==(const Point& other) {
		return this->x == other.x && this->y == other.y;
	}
};

class IsaacWorld : public galib::GAWorld<Point> {
public:
	~IsaacWorld() {}
};

class Chromosome : public galib::Chromosome<Point> {

public:
	Chromosome(int length) {
		SetRandomGene(length);
	}

private:
	Point GetNextPt(Point pt, int index) {
		if (index == 0) return Point(pt.x, pt.y + 1);
		else if (index == 1) return Point(pt.x - 1, pt.y);
		else if (index == 2) return Point(pt.x + 1, pt.y);
		else return Point(pt.x, pt.y - 1);
	}

	void SetRandomGene(int length) {
		geneList.clear();
		geneList.push_back(Point(0, 0));

		Point center = geneList[0];
		std::vector<Point> ablePt;

		int retryCount = 0;
		for (int i = 0; i < length - 1; ++i) {
			ablePt.clear();

			if (retryCount == 5) {
				std::cout << "Wrong random!!!" << std::endl;
				break;
			}

			for (int j = 0; j < 4; ++j) {
				if (std::find(geneList.begin(), geneList.end(), GetNextPt(center, j)) != geneList.end()) continue;
				ablePt.push_back(GetNextPt(center, j));
			}

			if (ablePt.size() == 0) {
				center = geneList[rand() % geneList.size()];
				i--;
				retryCount++;
				continue;
			}

			retryCount = 0;

			int count = rand() % ablePt.size() + 1;
			//std::cout << i + 1 << " :  " << count << " / " << ablePt.size() << std::endl;

			for (int j = 0; j < count && ablePt.size() > 0; ++j) {
				int idx = rand() % ablePt.size();
				//std::cout << "     " << j << " :  " << idx << " / " << ablePt.size() << std::endl;
				geneList.push_back(ablePt[idx]);
				ablePt.erase(ablePt.begin() + idx);
			}
		}
	}

public:
	std::string ToString() const {
		std::string str = "";
		for (int i = 0; i < geneList.size(); ++i) {
			str += "(" + std::to_string(geneList[i].x) + "," + std::to_string(geneList[i].y) + ")";
			if (i < geneList.size() - 1) str += " / ";
		}
		return str;
	}

	float GetFitness() {
		SortClockwise(geneList);
		return CalculateArea(geneList);
	}

private:
	float avgX, avgY;
	bool Compare(const Point& pt1, const Point& pt2) {
		float angle1 = atan2(pt1.y - avgY, pt1.x - avgX);
		float angle2 = atan2(pt2.y - avgY, pt2.x - avgX);
		return angle1 > angle2;
	}
	void SortClockwise(std::vector<Point>& list) {
		avgX = 0, avgY = 0;
		for (Point pt : list) {
			avgX += pt.x;
			avgY += pt.y;
		}
		avgX /= list.size();
		avgY /= list.size();

		for (int i = 0; i < list.size() - 1; ++i) {
			for (int j = i + 1; j < list.size(); ++j) {
				if (Compare(list[i], list[j])) continue;
				Point temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
	float CalculateArea(const std::vector<Point>& list) {
		float area = 0;
		for (int i = 1; i < list.size() - 1; ++i) {
			float r = (list[i].x - list[0].x) * (list[i + 1].y - list[0].y)
				- (list[i].y - list[0].y) * (list[i + 1].x - list[0].x);
			area += r / 2;
		}
		return abs(area);
	}
};


galib::Parent<Point> Selection(galib::Population<Point> popl) {
	galib::Parent<Point> prnt;
	float max = popl[0]->GetFitness();
	int maxIndex = 0;
	int excludeIndex = 0;
	for (int i = 0; i < popl.size(); ++i) {
		float fitness = popl[i]->GetFitness();
		if (fitness > max) {
			max = fitness;
			maxIndex = excludeIndex = i;
		}
	}
	prnt.first = popl[maxIndex];
	for (int i = 0; i < popl.size(); ++i) {
		if (i == excludeIndex) continue;
		float fitness = popl[i]->GetFitness();
		if (fitness > max) {
			max = fitness;
			maxIndex = i;
		}
	}
	prnt.second = popl[maxIndex];
	return prnt;
}

void Crossover(Chromosome* p1, Chromosome* p2, Chromosome* self) {

}

void Mutation(Chromosome* chrm) {

}

void Replacement(Chromosome* chrm) {

}




int main() {

#pragma region Preparing
	srand((unsigned int)time(NULL));

	/*auto setting = galib::GAWorldBase::Setting();
	setting.worldName = "Isaac Map";
	setting.chrmCount = 20;
	setting.chrmLength = 15;

	auto world = new IsaacWorld();
	world->SetWorldSetting(setting);
	world->Initialize(new Chromosome());*/
#pragma endregion

	int roomCount = (int)(generator_real() * 7) + 15;

	/*Chromosome* ch = new Chromosome(roomCount);
	ch->Init({ Point(4, 6), Point(-4, -8), Point(-4, 6), Point(8, -8), Point(4, -4), Point(8, -4) });
	std::cout << ch->GetFitness() << std::endl;
	std::cout << ch->ToString() << std::endl;

	Chromosome* ch2 = new Chromosome(roomCount);
	ch2->Init({ Point(0, 0), Point(10, 0), Point(8, 10) });
	std::cout << ch2->GetFitness() << std::endl;
	std::cout << ch2->ToString() << std::endl;
	delete ch, ch2;*/

	Chromosome* ch = new Chromosome(roomCount);
	std::cout << ch->GetFitness() << std::endl;
	std::cout << ch->ToString() << std::endl;

	system("pause");
	return 0;
}
