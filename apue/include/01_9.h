#ifndef _01_9_H_
#define _01_9_H_

/*
 * 自定义处理系统发给进程的中断信号
*/

static void sig_int(int)
{
	printf("\n interrupt \n");
	exit(127);
}

int Register_Signal_Handler_Test()
{
	if(SIG_ERR == signal(SIGINT, sig_int))
	{
		err_sys("signal error");
		return -1;
	}

	char c;
	while(EOF != (c=getc(stdin)))
		continue;

	return 1;
}

#endif
