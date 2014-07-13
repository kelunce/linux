#ifndef _03_2_H_
#define _03_2_H_

#include <fcntl.h>

/*
 * 创建一个具有空洞的文件
 * */
void CreateHoleFile()
{
	char buf1[] = "abcdefghijk";
	char buf2[] = "ABCDEFGHIJK";

	int fd;
	if( 0 > (fd = ::creat("file.hole",FILE_MODE)))
		err_sys("create error");
	if( strlen(buf1) != (unsigned int)write(fd,buf1,strlen(buf1)) )
		err_sys("buf1 write error");
	/* offset now = 10 */
	if(-1 == lseek(fd,1024*10,SEEK_SET))
		err_sys("lseek error");
	/* offset now = 10240*/
	if(strlen(buf2) != (unsigned int)write(fd,buf2,strlen(buf2)))
		err_sys("buf2 write error");
	/* offset now = 10250*/
}

#endif
