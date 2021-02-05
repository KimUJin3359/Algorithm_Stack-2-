#include "list.h"
#include "list.cpp"

int main()
{
	List<char> stack;
	List<int> num;
	char *str;
	int size = 0;
	int case_n = 1;

	while (case_n <= 10)
	{
		int i = 0;

		printf("#%d ", case_n);
		scanf("%d\n", &size);
		str = new char[size + 1];
		scanf("%s", str);
		while (str[i])
		{
			int res = 0;
			int flag = 1;

			if (str[i] >= '0' && str[i] <= '9')
			{
				while (str[i] >= '0' && str[i] <= '9')
				{
					res *= 10;
					res += str[i] - '0';
					i++;
				}
				flag = 0;
			}
			else if (str[i] == '(')
				stack.push('(');
			else if (str[i] == ')')
			{
				while (stack.top() != '(')
				{
					char c = stack.pop();
					int a = num.pop();
					int b = num.pop();

					if (c == '+')
						num.push(a + b);
					else if (c == '*')
						num.push(a * b);
				}
				stack.pop();
			}
			else if (str[i] == '*')
				stack.push('*');
			else if (str[i] == '+')
			{
				while (stack.get_size())
				{
					if (stack.top() == '(')
						break;

					char c = stack.pop();
					int a = num.pop();
					int b = num.pop();

					if (c == '+')
						num.push(a + b);
					else if (c == '*')
						num.push(a * b);
				}
				stack.push('+');
			}
			if (flag)
				i++;
			else
				num.push(res);
		}
		while (stack.get_size())
		{
			char c = stack.pop();
			int a = num.pop();
			int b = num.pop();

			if (c == '+')
				num.push(a + b);
			else if (c == '*')
				num.push(a * b);
		}
		printf("%d", num.pop());
		printf("\n");
		delete str;
		case_n++;
	}
}