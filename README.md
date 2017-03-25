# Bison Template

## Message
This contains all the scanner and parser rules needed for `x = 42;` exercise. Pull this branch for resetting or Create branch based on this to modify the code if needed.
The parser rules are ordered in a hierarchical structure while the leaves are placed in the "END" category and operator groups are placed in the "Utility" group.
The code is already tested without any compile error.

**Scanner** rules require manual edit:
- [ ] TemplateLiteral - Jason
- [x] BinaryIntegerLiteral - John
- [x] OctalIntegerLiteral - John
- [x] HexIntegerLiteral - John


**Parser Grammars added by John**
- [x] **VariableStatement**
	- [x] **VariableDeclarationList**
		- [x] **VariableDeclaration**
			- [x] **BindingIdentifier**
				- [x] **Initializer_opt**
				- [x] **Initializer**
			- [x] **BindingPattern**
				- [x] **ObjectBindingPattern**
					- [ ] BindingPropertyList
				- [ ] ArrayBindingPattern

- [x] **Declaration**
		- [ ] HoistableDeclaration
		- [ ] ClassDeclaration
		- [ ] LexicalDeclaration
- [x] **IfStatement**
- [x] **Block**
	- [x] **StatementList_opt**

Rules removed from scanner.l are stored in `dump.txt` file. Refer if needed.