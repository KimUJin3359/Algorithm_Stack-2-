#include <stdio.h>
#pragma warning (disable:4996)
#define SIZE 1000

bool check[SIZE] = { false, };
int map[SIZE][SIZE] = { 0, };
void initialize();

int main()
{
	int size;
	int case_n = 1;
	int dot;
	int edge;

	while (case_n <= 10)
	{
		int from, to;

		initialize();
		printf("#%d ", case_n);
		scanf("%d", &dot);
		scanf("%d", &edge);
		for (int i = 0; i < edge; i++)
		{
			scanf("%d %d", &from, &to);
			from--;
			to--;
			map[from][to] = 1;
		}

		for (int i = 0; i < dot; i++)
		{
			if (check[i] == false)
			{
				int j;
				for (j = 0; j < dot; j++)
				{
					if (map[j][i] == 1 && check[j] == false)
						break;
				}
				if (j == dot)
				{
					printf("%d ", i + 1);
					check[i] = true;
					i = -1;
				}
			}
		}
		printf("\n");
		case_n++;
	}
}

void initialize()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
			map[i][j] = 0;
		check[i] = false;
	}
}