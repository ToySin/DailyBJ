#include <iostream>
#include <string>

typedef struct Node
{
	int			data;
	struct Node	*link;
}Node;

class Stack
{
	private:
		Node	*top;
		int		count;

	public:
		Stack()
		{
			top = NULL;
			count = 0;
		}
		void	push(int v);
		int		pop();
		int		peek();

		int		size();
		int		empty();
};

void	Stack::push(int v)
{
	Node *node = new Node;
	node->data = v;
	node->link = top;
	top = node;
	count += 1;
}

int	Stack::pop()
{
	if (empty())
		return -1;
	
	Node *temp = top;
	int v = temp->data;

	top = top->link;
	count -= 1;
	delete temp;
	return v;
}

int	Stack::peek()
{
	if (empty())
		return -1;
	else
		return top->data;
}

int Stack::size()
{
	return count;
}

int	Stack::empty()
{
	return !top;
}

int main()
{
	std::cout.tie(NULL);
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	Stack s;

	int N;
	std::cin >> N;

	std::string oper;
	int v;
	for (int i = 0; i < N; i++)
	{
		std::cin >> oper;
		if (oper == "push")
		{
			std::cin >> v;
			s.push(v);
		}
		else if (oper == "pop")
			std::cout << s.pop() << '\n';
		else if (oper == "top")
			std::cout << s.peek() << '\n';
		else if (oper == "empty")
			std::cout << s.empty() << '\n';
		else if (oper == "size")
			std::cout << s.size() << '\n';
	}
}