#ifndef _03_4_H_
#define _03_4_H_

#include <fcntl.h>

void print_fl(int fd);
int Test_print_fl(int argc,char *argv[])
{
	if(argc!=2)
		err_quit("usage: a.out <descriptor#>");
	int val = atoi(argv[1]);
	print_fl(val);
	return 0;
}

/*
 * 打印文件状态标志
 * */
void print_fl(int fd)
{
	// 获取文件状态标志
	int val = fcntl(fd, F_GETFL, 0);
	if(0 > val)
		err_sys("fcntl error for fd %d",fd);

	switch(val & O_ACCMODE)
	{
	case O_RDONLY:
		printf("read only");
		break;
	case O_WRONLY:
		printf("write only");
		break;
	case O_RDWR:
		printf("read write");
		break;
	default:
		err_dump("unknown access mode");
	}

	if(val & O_APPEND)
		printf(", append");
	if(val & O_NONBLOCK)
		printf(", nonblocking");

#if defined (O_SYNC)

	if(val & O_SYNC)
		printf(", synchronous writes");

#endif

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC)

	if(val & O_FSYNC)
			printf(", synchronous writes");

#endif

	putchar('\n');
}

#endif
