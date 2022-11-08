#pragma once
#include <vector>
class DSU
{
public:
	std::vector<int>* parent;
	std::vector<int>* rank;

public:
	DSU();
	DSU(int n);
	~DSU();

	int find(int i);
	void unite(int x, int y);
};

