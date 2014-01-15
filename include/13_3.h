#include "apue.h"
#include <pthread.h>
#include <syslog.h>

sigset_t	mask;

/*
extern int already_running(void);
*/

// 守护进程重读配置文件
void
_13_3_reread(void)
{
	/* ... */
}

// 线程函数,通过信号来加载配置
// 使用 kill -s SIGTERM 5584 测试
// 如果有其他线程修改信号处理程序，将无法正确运行
void *
_13_3_thr_fn(void *arg)
{
	int err, signo;

	syslog(LOG_NOTICE, "daemon enter thr_fn");
	for (;;) {
		err = sigwait(&mask, &signo);
		if (err != 0) {
			syslog(LOG_ERR, "sigwait failed");
			exit(1);
		}

		switch (signo) {
		case SIGHUP:
			syslog(LOG_INFO, "Re-reading configuration file");
			_13_3_reread();
			break;

		case SIGTERM:
            // 这个信号必须处理
			syslog(LOG_INFO, "got SIGTERM; exiting");
			exit(0);

		default:
			syslog(LOG_INFO, "unexpected signal %d\n", signo);
		}
	}
	return(0);
}

int
_13_3_main(int argc, char *argv[])
{
	int					err;
	pthread_t			tid;
	char				*cmd;
	struct sigaction	sa;

	if ((cmd = strrchr(argv[0], '/')) == NULL)
		cmd = argv[0];
	else
		cmd++;

    syslog(LOG_INFO, "daemonize  ...");
	/*
	 * Become a daemon.
	 */
	daemonize(cmd);
    syslog(LOG_INFO, "daemonize ok ...");

	/*
	 * Make sure only one copy of the daemon is running.
	 */
	if (already_running()) {
		syslog(LOG_INFO, "daemon already running");
		exit(1);
	}

    syslog(LOG_INFO, "restore signal ...");
	/*
	 * Restore SIGHUP default and block all signals.
     * 必须恢复信号处理，否则下面的线程不可能得到信号
     * 阻塞信号，等待线程处理
	 */
	sa.sa_handler = SIG_DFL;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGHUP, &sa, NULL) < 0)
    {
        err_quit("%s: can't restore SIGHUP default");
    }
	sigfillset(&mask);
	if ((err = pthread_sigmask(SIG_BLOCK, &mask, NULL)) != 0)
    {
        err_exit(err, "SIG_BLOCK error");
    }

    syslog(LOG_INFO, "restore signal ok");
	/*
	 * Create a thread to handle SIGHUP and SIGTERM.
	 */
	err = pthread_create(&tid, NULL, _13_3_thr_fn, 0);
	if (err != 0)
    {
        err_exit(err, "can't create thread");
    }
    
	/*
	 * Proceed with the rest of the daemon.
	 */
	/* ... */
    // 这里仅仅测试用，防止进程还没有测试就结束
    sleep(1000);
    syslog(LOG_INFO, "exiting ...");
	exit(0);
}
