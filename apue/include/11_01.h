#ifndef _11_01_H_
#define _11_01_H__
#include "apue.h"
//  线程头文件
#include <pthread.h>
// 如果是makefile需要 -lpthread
// 如果是eclipse，需要在项目的GNU C++ 编译器中添加支持库pthread
// Properties->C/C++ Build->Settings->GNU C++ 连接器->Libraries
// 打印线程ID

pthread_t ntid;

void printids(const char *s)
{
	pid_t 			pid;
	// 线程ID
	pthread_t 	tid;

	pid = getpid();
	tid = pthread_self();
	printf("%s pid %u tid %u (0x%x)\n", s, (unsigned int)pid, (unsigned int)tid, (unsigned int)tid);

}

// 线程函数
void * thr_fn(void *args)
{
	printids("new thread:  ");
	return ((void*) 0);
}

void test_thread_print_ids()
{
	int err;
	err = pthread_create(&ntid, NULL, thr_fn, NULL);
	if (err != 0)
		err_quit("can't create thread: %s\n", strerror(err));
	printids("main thread: ");
	sleep(1);
	exit(0);
}


#endif
