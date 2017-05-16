#pragma once
#include <vector>
using namespace std;

class Node {
protected:
	static int numRef;
	static vector<string> refs;
	static vector<string> lexs;
public:
	virtual ~Node() = default;
	virtual void dump(int = 0) = 0;
	virtual void genCode() = 0;
	static void dump(string, int);
	static void genCode(string, bool = false);
	static void indentation(int);
};

class Container : public Node {
	vector<Node*> next;
	string name;
public:
	explicit Container(vector<Node*>, string);
	void dump(int = 0) override;
	void genCode() override;
};
