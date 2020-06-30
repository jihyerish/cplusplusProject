// BOARDCOVER.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include "BOARDCOVER.h"

using namespace std;

int calH[][2] = { {-1, -1}, {-1, -1}, {0, -1}, {0, -1}, {0, 1}, {0, 1}, {1, 1}, {1, 1} };
int calW[][2] = { {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, -1}, {1, 1}, {0, -1}, {0, 1} };

int counter(char board[][22], int w, int h, int currentW, int currentH)
{
	int success = 0;

	char localboard[22][22];

	for (size_t i = 0; i < 22; i++)
	{
		for(size_t j = 0; j < 22; j++)
		{
			localboard[i][j] = board[i][j];
		}
	}

	if ((localboard[currentH][currentW] == '#')
		|| localboard[currentH][currentW] == 'o')
	{
		if (currentW == w)
		{
			currentW = 0;
			if (currentH == h)
				return success;

			currentH++;
		}
		else
		{
			currentW++;
		}

		return success + counter(board, w, h, currentW, currentH);
	}
	else
	{
		for (size_t i = 0; i < 8; i++)
		{
			if (('#' == localboard[currentH + calH[i][0]][currentW + calW[i][0]])
				|| ('o' == localboard[currentH + calH[i][0]][currentW + calW[i][0]]))
			{
				continue;
			}
			else
			{
				localboard[currentH + calH[i][0]][currentW + calW[i][0]] = 'o';
			}
				

			if (('#' == localboard[currentH + calH[i][1]][currentW + calW[i][1]])
				|| ('o' == localboard[currentH + calH[i][1]][currentW + calW[i][1]]))
			{
				continue;
			}
			else
			{
				localboard[currentH + calH[i][1]][currentW + calW[i][1]] = 'o';
			}

			bool done = true;
			for (size_t x = 0; x < h; x++)
			{
				for (size_t y = 0; y < w; y++)
				{
					if ('.' == localboard[x][y])
					{
						done = false;
					}
				}
			}

			if (true == done)
			{
				success++;
				return success;
			}
			else
			{
				if (currentW == w)
				{
					currentW = 0;
					if (currentH == h)
						return success;

					currentH++;
				}
				else
				{
					currentW++;
				}

				success = success + counter(localboard, w, h, currentW, currentH);
			}
		}
	}

	return success;
}

int main()
{
	size_t max = 0, w = 0, h = 0;
	
	cin >> max;
	cin >> h >> w;

	h++;
	w++;
	char board[22][22] = { 0 };
	for (size_t count = 0; count < max; count++)
	{
		for (size_t i = 0; i < 22; i++)
		{
			for (size_t j = 0; j < 22; j++)
			{
				board[i][j] = '#';
			}
		}

		for (size_t i = 1; i < h; i++)
		{
			for (size_t j = 1; j < w; j++)
			{

				cin >> board[i][j];
			}
		}

		size_t success = counter(board, w, h, 1, 1);
		cout << success << endl;
	}

	return 0;
}
