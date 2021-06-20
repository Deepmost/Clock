#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include<math.h>
int main()
{
    initgraph(640, 480);
    int x, y;
    x = 320; y = 240;
    int secondlen=128;
    int minutelen = 107;
    int hourlen = 90;
    int secondendx, secondendy;
    int minuteendx, minuteendy;
    int hourendx, hourendy;
    float secondangle,minuteangle,hourangle ;
    SYSTEMTIME ti;
    setbkcolor(WHITE);
    cleardevice();
    setlinestyle(PS_SOLID, 3);
    setcolor(BLACK);
    circle(x, y, 160);
    int m, n, i;
    setlinestyle(PS_SOLID, 4);
    line(320, 80, 320, 100);
    line(320, 400, 320, 380);
    line(160, 240, 180, 240);
    line(480, 240, 460, 240);

    line(320 + 160 * 0.5, 240 - 160 * sin(3.14 / 3), 390, 119);
    line(320 + 160 * 0.86, 240 - 80, 440, 240 - 70);
    line(320 + 160 * 0.5, 240 + 160 * sin(3.14 / 3), 390, 240+140-17 );
    line(320 + 160 * 0.86, 240 + 80, 440, 240 + 70);
    line(320 - 80, 240 - 160 * sin(3.14 / 3), 250, 119);
    line(320 - 160 * 0.86, 240 - 80, 200, 240 - 70);
    line(320 - 80, 240 + 160 * sin(3.14 / 3), 250,360);
    line(320 - 160 * 0.86, 320, 200, 310);
    TCHAR s_12[] = _T("12");
    TCHAR s_9[] = _T("9");
    TCHAR s_6[] = _T("6");
    TCHAR s_3[] = _T("3");
    outtextxy(310, 105, s_12);
    outtextxy(185, 235, s_9);
    outtextxy(315, 365, s_6);
    outtextxy(455, 230, s_3);
    while (1)
    {
        setcolor(BLACK);
        GetLocalTime(&ti);
        secondangle = ti.wSecond * 2 * 3.14 / 60;
        minuteangle = ti.wMinute * 2 * 3.14 / 60+secondangle/60;
        hourangle = ti.wHour * 2 * 3.14 / 12+minuteangle/12;
        secondendx = x + secondlen * sin(secondangle);
        secondendy = y - secondlen * cos(secondangle);
        minuteendx = x + minutelen * sin(minuteangle);
        minuteendy = y - minutelen * cos(minuteangle);
        hourendx = x + hourlen * sin(hourangle);
        hourendy = y - hourlen * cos(hourangle);
        setlinestyle(PS_SOLID, 2);
        setcolor(BLACK);
        line(x, y, secondendx, secondendy);
        setlinestyle(PS_SOLID, 4);
        setcolor(BLUE);
        line(x, y, minuteendx, minuteendy);
        setlinestyle(PS_SOLID, 6);
        setcolor(RED);
        line(x, y, hourendx, hourendy);
        Sleep(10);
        setcolor(WHITE);
        setlinestyle(PS_SOLID, 2);
        line(x, y, secondendx, secondendy);
        setlinestyle(PS_SOLID, 5);
        line(x, y, minuteendx, minuteendy);
        setlinestyle(PS_SOLID, 10);
        line(x, y, hourendx, hourendy);
    }
    _getch();
    closegraph();
    return 0;
}