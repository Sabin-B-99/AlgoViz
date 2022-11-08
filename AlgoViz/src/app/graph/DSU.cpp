#include "DSU.h"

DSU::DSU()
{
}

DSU::DSU(int n)
{
	parent = new std::vector<int>(n, -1);
	rank = new std::vector<int>(n, -1);
}

DSU::~DSU()
{
}

int DSU::find(int i)
{
	if (parent->at(i) == -1) {
		return i;
	}
	return parent->at(i) = find(parent->at(i));
}

void DSU::unite(int x, int y)
{
	int nodeI = find(x);
	int nodeII = find(y);

	if (nodeI != nodeII) {
		if (rank->at(nodeI) < rank->at(nodeII))
		{
			parent->at(nodeI) = nodeII;
			rank->at(nodeII) += rank->at(nodeI);
		}
		else {
			parent->at(nodeII) = nodeI;
			rank->at(nodeI) += rank->at(nodeII);
		}
	}
}
