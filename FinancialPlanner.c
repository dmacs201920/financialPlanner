#include"header.h"

void main(int argc,char *argv[])
{
    if(argc!=3)
    {
	printf("Inappropriate  Arguments.\n");
	exit(-1);
    }
     main_fun(argv[1],argv[2]);
}
