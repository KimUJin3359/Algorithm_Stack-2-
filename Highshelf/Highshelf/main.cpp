#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	int num[20];
	int test_c = 1;
	int rep;	//maximum test_case
	int res;	//want to find
	int size;	//number of clerk

	scanf("%d", &rep);
	while (test_c <= rep)
	{
		int min = 987654321;

		scanf("%d %d", &size, &res);
		for (int i = 0; i < size; i++)
			scanf("%d", &num[i]);
		for (int i = 0; i < (1 << size); i++)
		{
			int tot = 0;
			for (int j = 0; j < size; j++)
				if (i & (1 << j))
					tot += num[j];
			if (tot >= res)
			{
				if (min > tot)
					min = tot;
			}
		}
		printf("#%d %d\n", test_c, (min - res));
		test_c++;
	}
}