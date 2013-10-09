#ifndef _01_6_H_
#define _01_6_H_


/*
 * 打印本进程信息
*/
void PrintSelfInfo()
{
	printf("process_id=%d\n",getpid());
	printf("uid=%d\n",getuid());
	printf("gid=%d\n",getgid());
}

/*
 * 从标准输入中获取shell命令并执行,不支持参数
*/
#include<sys/wait.h>
int ExcuteFromStdin()
{
	char	buf[MAXLINE];
	pid_t	pid;
	int		status;

	printf("%%  ");
	while(fgets(buf, MAXLINE, stdin) != NULL)//从标准输入中读取一行，最后字符是\n
	{
		if(buf[strlen(buf) - 1] == '\n')
		{
			buf[strlen(buf) - 1] = 0;
		}

		pid=fork();// 产生子进程，会复制父进程当前环境.在子进程返回0，在父进程中返回非负
		if(pid < 0)
		{
			err_sys("fork error");
		}
		else if(pid == 0)
		{
			// 下面的代码在子进程中运行
			execlp(buf,buf,(char*)0);
			err_ret("couldn't execute: %s",buf);
			exit(127);
		}
		else
		{
			//这里pid>0,父进程才会执行这里
		}

		// 下面代码运行在父进程
		pid = waitpid(pid,&status,0);//等待子进程结束
		if(pid<0)
			err_sys("waitpid error");
		printf("%% ");
	}

	return 1;
}


#endif
