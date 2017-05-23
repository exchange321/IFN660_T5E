#pragma once
#include <vector>
#include <AST/AstNode.h>
#include <AST/AstExpression.h>
#include <AST/AstScript.h>

using namespace std;

class Statement : public Node {
public:
	virtual ~Statement() = default;
	void dump(int = 0) override = 0;
	void Gecode() override= 0;
};

class BlockStatement : public Statement {
	vector<Node*> next;
	Statement *statement;
public:
	explicit BlockStatement(Statement *);
	void dump(int = 0) override;
	void Gecode() override;
};

class Block : public Statement {
	vector<Node*> next;
	StatementList *statementlist;
public:
	explicit Block(StatementList *);
	void dump(int = 0) override;
	void Gecode() override;
};

class ExpressionStatement : public Statement {
	vector<Node*> next;
	Expression *expression;
public:
	explicit ExpressionStatement(Expression *);
	void dump(int = 0) override;
	void Gecode() override;
};

class IfStatement : public Statement {
	vector<Node*> next;
	Expression *expression;
	Statement *ifStatement;
	Statement *elseStatement;
public:
	explicit IfStatement(Expression *, Statement *, Statement *);
	explicit IfStatement(Expression *, Statement *);
	void dump(int = 0) override;
	void Gecode() override;
};