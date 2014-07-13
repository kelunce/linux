#ifndef _01_5_H_
#define _01_5_H_
/*
 * 将标准输入复制到标准输出
 * 1. 使用不带缓冲的IO
 * 比如:open,read,write,lseek,close
*/
#include <unistd.h>

#define BUFFSIZE 4096

int CopyStdInToStdOut1()
{
	int n;
	char buf[BUFFSIZE];

	while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
	{
		// 从标准输入中得到多少就写入多少
		if(write(STDOUT_FILENO,buf,n) != n)
		{
			return -1;
		}
	}

	if (n < 0)
		return -1;

	return 1;
}

/*
 * 2. 使用标准IO(带缓冲)
*/

int CopyStdInToStdOut2()
{
	int c;

	while ((c = getc(stdin)) != EOF)
	{
		if(putc(c,stdout) == EOF)
		{
			return -1;
		}
	}

	if (ferror(stdin))
		return -1;

	return 1;
}

#undef BUFFSIZE

#endif
