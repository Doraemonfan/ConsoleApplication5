#include "stdafx.h"
#include <graphics.h>
#include <conio.h>
#include <time.h>
#define Width 1000
#define High 600
#define CharSize 25

int main() {
	int widthNum = Width / CharSize;
	int highNum = High / CharSize;
	int CharRain[Width / CharSize][High / CharSize];
	int CNum[Width / CharSize];
	int ColorG[Width / CharSize];

	srand((unsigned)time(NULL));

	for (int i = 0; i < widthNum; i++) {
		CNum[i] = (rand() % (highNum * 9 / 10)) + highNum / 10;
		ColorG[i] = 255;
		for (int j = 0; j < CNum[i]; j++) {
			CharRain[j][i] = rand() % 26 + 'A';
		}
	}

	initgraph(Width, High);
	BeginBatchDraw();
	settextstyle(25, 10, _T("Courier"));

	while (1) {
		for (int i = 0; i < widthNum; i++) {
			if (CNum[i] < highNum - 1) {
				for (int j = CNum[i] - 1; j >= 0; j--)
					CharRain[j + 1][i] = CharRain[j][i];
				CharRain[0][i] = rand() % 26 + 'A';
				CNum[i]++;
			}
			else {
				if (ColorG[i] < 40)
					ColorG[i] -= 20;
				else {
					CNum[i] = (rand() % (highNum * 9 / 10)) + highNum / 10;
					ColorG[i] = (rand() % 75) + 180;
					for (int j = 0; j < CNum[i]; j++)
						CharRain[j][i] = rand() % 26 + 'A';
				}
			}
		}

		for (int i = 0; i < widthNum; i++) {
			int x = i * CharSize;
			for (int j = 0; j < CNum[i]; j++) {
				int y = j * CharSize;
				setcolor(RGB(0, ColorG[i], 0));
				outtextxy(x, y, CharRain[j][i]);
			}
		}

		FlushBatchDraw();
		Sleep(100);
		clearrectangle(0, 0, Width - 1, High - 1);
	}
	EndBatchDraw();
	_getch();
	closegraph();

	return 0;
}
				