#ifndef _03_1_H_
#define _03_1_H_

#include <fcntl.h>

/*
 * 测试能否对标准输入设置偏移量
 * */
void TestStdIoLSEEK()
{
	::printf("OPEN_MAX=%ld\n", sysconf(_SC_OPEN_MAX));

	// 当前偏移量
	if(lseek(STDIN_FILENO,0,SEEK_CUR) == -1)
		::printf("cannot seek\n");
	else
		::printf("seek OK\n");
}

#endif
