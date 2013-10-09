#ifndef _03_5_H_
#define _03_5_H_

#include <fcntl.h>

/*
 * 对一个文件描述符打开一个或多个文件状态标准,先取再设置
 * set_fl(STDOUT_FILENO,O_SYNC)//每次输出到控制台都要等到写道磁盘上
 * */
void set_fl(int fd, int flags)
{
	int val = fcntl(fd, F_GETFL, 0);
	if( 0 > val)
		err_sys("fcntl F_GETFL error");

	val |= flags;

	if(0 > fcntl(fd, F_SETFL, val))
		err_sys("fcntl F_SETFL error");
}

void clr_fl(int fd, int flags)
{
	int val = fcntl(fd, F_GETFL, 0);
	if( 0 > val)
		err_sys("fcntl F_GETFL error");

	val &= ~flags;

	if(0 > fcntl(fd, F_SETFL, val))
		err_sys("fcntl F_SETFL error");
}


#endif
