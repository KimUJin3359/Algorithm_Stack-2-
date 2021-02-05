#include <stdio.h>
#pragma warning (disable:4996)

int main()
{
	char *str;
	int size;
	int case_n = 1;

	while (case_n <= 10)
	{
		int flag = 1;
		int i = 0;

		scanf("%d", &size);
		str = new char[size + 1];
		scanf("%s", str);
		while (flag)
		{
			flag = 0;
			i = 0;
			while (i < size - 1)
			{
				if (str[i] == str[i + 1])
				{
					while (i < size - 1)
					{
						str[i] = str[i + 2];
						i++;
						flag = 1;
					}
					size--;
					break;
				}
				i++;
			}
		}
		printf("#%d %s", case_n, str);
		delete str;
		case_n++;
	}
}