#ifndef _10_24_H_
#define _10_24_H__
#include "apue.h"
/*
 * 父子进程通过信号来同步
 * */
/* 该变量定义为volatile，达到原子访问的目的,
 * 这里并不是因为fork有两个进程访问，毕竟这个变量会在父子进程中都有一份独立内存
 * 而是要防止异步信号处理线程和主线程的访问不一致
 */
static volatile sig_atomic_t sigflag; /* set nonzero by sig handler */
// 信号屏蔽字，子进程会从父进程中继承过来
static sigset_t newmask, oldmask, zeromask;
// 信号处理函数
static void sig_usr(int signo) /* one signal handler for SIGUSR1 and SIGUSR2 */
{
	// 进入这个函数的是异步线程，但是用户线程都暂停执行。而且会设置这个信号的屏蔽字
	sigflag = 1;
	//  离开会把阻塞屏蔽字还原
}

// 设置阻塞SIGUSR1，SIGUSR2
void TELL_WAIT(void)
{
	// 设置信号处理函数
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		err_sys("signal(SIGUSR1) error");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		err_sys("signal(SIGUSR2) error");
	// 清空信号集
	sigemptyset(&zeromask);
	sigemptyset(&newmask);
	// 把SIGUSR1，SIGUSR2加入到信号集
	sigaddset(&newmask, SIGUSR1);
	sigaddset(&newmask, SIGUSR2);

	/*
	 * Block SIGUSR1 and SIGUSR2, and save current signal mask.
	 * 设置当前线程的信号屏蔽字
	 */
	if (sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
		err_sys("SIG_BLOCK error");
}

// // 该函数由子进程调用，向父进程发送信号SIGUSR2信号
void TELL_PARENT(pid_t pid)
{
	kill(pid, SIGUSR2); /* tell parent we're done */
}

void WAIT_PARENT(void)
{
	// sigflag不是父子进程共享的，是各自独立的
	while (sigflag == 0)
	{
		/*
		 *  这个函数会临时设置屏蔽字为zeromask，即接受所有信号，如果收到任意信号则处理并返回。还原调用前的信号。
		 *  上面说的这些操作会是一个原子操作
		 * */
		sigsuspend(&zeromask); /* and wait for parent */
	}
	sigflag = 0;

	/*
	 * Reset signal mask to original value.
	 */
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
}

// 该函数由父进程调用，向子进程发送信号SIGUSR1
void TELL_CHILD(pid_t pid)
{
	kill(pid, SIGUSR1); /* tell child we're done */
}

void WAIT_CHILD(void)
{
	while (sigflag == 0)
		sigsuspend(&zeromask); /* and wait for child */
	sigflag = 0;

	/*
	 * Reset signal mask to original value.
	 */
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
		err_sys("SIG_SETMASK error");
}

// 这其实是8.9节说的，通过信号机制，父子进程在通知彼此都初始化完成后才能继续执行
void signal_sync_test()
{
	__pid_t pid;
	// 阻塞SIGUSR1，SIGUSR2
	TELL_WAIT(); /* set things up for TELL_xxx & WAIT_xxx */

	if ((pid = fork()) < 0)
	{
		err_sys("fork error");
	}
	else if (pid == 0)
	{ /* child */

		/* child does whatever is necessary ...
		 * 子进程在这里处理自己的初始化逻辑
		 * */
		err_msg("子进程初始化逻辑结束");

		// 向父进程发送信号SIGUSR2信号
		TELL_PARENT(getppid()); /* tell parent we're done */
		err_msg("子进程发送SIGUSR2信号完成");
		// 等待信号
		WAIT_PARENT(); /* and wait for parent */
		err_msg("子进程接受到信号，准备退出");

		/* and the child continues on its way ... */

		exit(0);
	}

	/* parent does whatever is necessary ... */
	err_msg("父进程初始化逻辑结束");
	TELL_CHILD( pid); /* tell child we're done */
	err_msg("父进程发送SIGUSR1信号完成");
	WAIT_CHILD(); /* and wait for child */
	err_msg("父进程接受到信号，准备退出");
	/* and the parent continues on its way ... */

	exit(0);
}
/*测试结果
父进程初始化逻辑结束
父进程发送SIGUSR1信号完成
子进程初始化逻辑结束
子进程发送SIGUSR2信号完成
子进程接受到信号，准备退出
父进程接受到信号，准备退出
 * */
#endif
