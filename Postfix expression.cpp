//											POST FIX EXPRESSION
#include <iostream>
#include <string>

using namespace std;

struct Node
{
	char not_num;
	int precedence;
	Node* next;
};
class Stack
{

public:
	int top();
	char topp();
	char pop();
	void push(char);
	bool Empty();
//	bool BracketCheck();
	string expression;
	int size;
	Stack()
	{
	
	}
private:
	Node* top1 = NULL;
};
int main()
{
	Stack* s = new Stack();
	string result;
	int check;
	char brackets;
	bool invalid, done = false;
	cout << "Write an infix expression to convert it into a postfix expression:-\n";
	cout << "NOTE: Close the expression within brackets ()\n";
	cout << "\n>>\t";
	
	getline(cin, s->expression);
	s->size = s->expression.length();
		for (int i = 0; i < s->size; i++)
		{
			invalid = true;
			switch (s->expression.at(i))
			{
			case '(':
				s->push('(');
				break;

			case '{':
				s->push('{');
				break;

			case '[':
				s->push('[');
				break;

			case '+':
				while (invalid)
				{
					check = s->top();
					if (check >= 2)
					{
						result += s->pop();
					}
					else
						invalid = false;
				}
				s->push('+');
				break;

			case '-':
				while (invalid)
				{
					check = s->top();
					if (check >= 1)
					{
						result += s->pop();
					}
					else
						invalid = false;
				}
				s->push('-');
				break;

			case '*':
				while (invalid)
				{
					check = s->top();
					if (check >= 3)
					{
						result += s->pop();
					}
					else
						invalid = false;
				}
				s->push('*');
				break;

			case '/':
				while (invalid)
				{
					check = s->top();
					if (check >= 4)
					{
						result += s->pop();
					}
					else
						invalid = false;
				}
				s->push('/');
				break;
			case '^':
				while (invalid)
				{
					check = s->top();
					if (check == 5)
					{
						result += s->pop();
					}
					else
						invalid = false;
				}
				s->push('/');
				break;
			case ')':
			/*	if (!s->BracketCheck())
				{
					cout << "Brackets Imbalanced\n";
					exit(1);
				}*/
				while (invalid)
				{
					brackets = s->topp();
					if (brackets == '(')
					{
						s->pop();
						invalid = false;
					}
					else
						result += s->pop();
				}
				break;

			case '}':
			/*	if (!s->BracketCheck())
				{
					cout << "Brackets Imbalanced\n";
					exit(1);
				}*/
				while (invalid)
				{
					brackets = s->topp();
					if (brackets == '{')
					{
						s->pop();
						invalid = false;
					}
					else
						result += s->pop();
				}
				break;

			case ']':
				/*if (!s->BracketCheck())
				{
					cout << "Brackets Imbalanced\n";
					exit(1);
				}*/
				while (invalid)
				{
					brackets = s->topp();
					if (brackets == '[')
					{
						s->pop();
						invalid = false;
					}
					else
						result += s->pop();
				}
				break;

			default:
				if (int(s->expression.at(i)) > 47 && int(s->expression.at(i)) < 58)
				{
					result += s->expression.at(i);
				}
				break;
			}
			
		}
		if (!s->Empty())
			cout << "Expression not right\n";
		else
		cout << result;
}
int Stack::top()
{
	if (!Empty()) {
		int value = top1->precedence;
		return value;
	}
}
char Stack::topp()
{
	if (!Empty()) {
		char value = top1->not_num;
		return value;
	}
}
char Stack::pop()
{
	if (!Empty()) {
		char result = top1->not_num;
		Node* oldtop = top1;
		top1 = oldtop->next;
		delete oldtop;
		return result;
	}
}
void Stack::push(char not_num)
{

	Node* temp = new Node;
	temp->not_num = not_num;
	switch (not_num)
	{
	case '-':
		temp->precedence = 1;
		break;
	case '+':
		temp->precedence = 2;
		break;
	case '*':
		temp->precedence = 3;
		break;
	case '/':
		temp->precedence = 4;
		break;
	case '^':
		temp->precedence = 4;
		break;
	/*case '(':
		temp->precedence = -12;
		break;
	case '{':
		temp->precedence = -11;
		break;
	case '[':
		temp->precedence = -10;
		break;
		*/
	}

	temp->next = top1;
	top1 = temp;

}
bool Stack::Empty() // To check wheteher top node is empty
{
	return top1 == NULL;

}

/*bool Stack::BracketCheck()
{
	bool invalid = true;
	int p1 = 0, p2 = 0;
	Node* temp = top1;
	for(int i = 0;i<size;i++)
	while (invalid)
	{
		if (expression.at(i) == '(' || expression.at(i) == '{' || expression.at(i) == '[')
		{
			if (p1 == 0)
				p1 = temp->precedence;
			else
				p2 = temp->precedence;
		}
		if (p2 != 0)
			if (p1 < p2)
				return false;
		temp = temp->next;
	}
	return true;
}*/