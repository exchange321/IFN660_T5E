#include <cstdio>
#include <string>
#include <iostream>
#include <AST/Node/AstNode.h>
using namespace std;

void Node::dump(string message, int indent) {
	indentation(indent);
	cout << message << endl;
}

void Node::indentation(int indent) {
	for (auto i = 0; i < indent; i++) {
		printf("  ");
	}
}

Container::Container(vector<Node *> _next, string _name) : next(_next),
                                                           name(_name) { }

void Container::dump(int indent) {
	auto message = name + ": ";
	Node::dump(message, indent);
	for (auto &i : next) {
		i->dump(indent + 1);
	}
}

int Container::eval(int line, FILE* output) {
	for (auto &i : next) {
		line = i->eval(line, output);
	}
	return line;
}