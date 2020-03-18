#include"header.h"

void main(int argc,char *argv[])
{
    int i=0;
    if(argc!=4)
    {
	printf("Inappropriate  Arguments.\n");
	exit(-1);
    }
    initscr();
    start_color();
    init_pair(0,COLOR_WHITE,COLOR_BLACK);
    init_pair(1,COLOR_GREEN,COLOR_BLACK);
    init_pair(2,COLOR_CYAN,COLOR_BLACK);
    init_pair(3,COLOR_MAGENTA,COLOR_BLACK);
    init_pair(4,COLOR_RED,COLOR_BLACK);
    i=MainWin(argv[3]);
    refresh();
    if(i==1)
	i=MainFun(argv[1],argv[2]);
    if(i==0)
    {
	refresh();
	endwin();
    }
}
