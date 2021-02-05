#include "ft.h"

int per[SIZE] = { 0, };	//array for makable numbers
int num[10];			//calculator numbers 0~9
int res;				//want to find
int size;

int main()
{
	int case_n = 1;
	int rep;

	scanf("%d", &rep);
	while (case_n <= rep)
	{
		int i = 0;
		int ret = 0;

		initialize();
		for (int i = 0; i < 10; i++)
			scanf("%d", &num[i]);
		scanf("%d", &res);
		printf("#%d ", case_n);
		size = get_size(res);
		fill_arr(0, 0);
		if (res == 1 && per[1] == 1)
		{
			printf("2\n");
			case_n++;
			continue;
		}
		for (int i = res; i > 1; i--)
		{
			if (res == 1)
				break;
			while (per[i] > 0)
			{
				if (res % i == 0)
				{
					ret += 1 + per[i];
					res /= i;
				}
				else
					break;
			}
		}
		if (res == 1)
			printf("%d\n", ret);
		else
			printf("-1\n");
		case_n++;
	}
}

void initialize()
{
	for (int i = 0; i < SIZE; i++)
		per[i] = 0;
}

int	get_size(int n)
{
	int size = 0;

	if (n == 0)
		return 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

void fill_arr(int find, int len)
{
	if (find > res || len > size)
		return;
	//for largable 0
	if (len != 0)
		per[find] = len;
	for (int i = 0; i < 10; i++)
	{
		if (num[i] == 1)
			fill_arr(find * 10 + i, len + 1);
	}
}