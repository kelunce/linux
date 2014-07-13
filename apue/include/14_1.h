#include "apue.h"
#include <errno.h>
#include <fcntl.h>


char buf[500000];

int test(void )
{
	int		ntowrite, nwrite;
	char	*ptr;

    /* Standard file descriptors.  */
    //#define	STDIN_FILENO	0	/* Standard input.  */
    //#define	STDOUT_FILENO	1	/* Standard output.  */
    //#define	STDERR_FILENO	2	/* Standard error output.  */
	ntowrite = read(STDIN_FILENO, buf, sizeof(buf));

    // stderr stdout stdin类型是_IO_FILE(也就是FILE)
	fprintf(stderr, "read %d bytes\n", ntowrite);

    // 标准输出为非阻塞
	set_fl(STDOUT_FILENO, O_NONBLOCK);	/* set nonblocking */

    // 为什么需要循环write?
	ptr = buf;
	while (ntowrite > 0) {
		errno = 0;
		nwrite = write(STDOUT_FILENO, ptr, ntowrite);
		fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);
        // 可能会出现errno == EAGAIN
		if (nwrite > 0) {
			ptr += nwrite;
			ntowrite -= nwrite;
		}
	}
    
	clr_fl(STDOUT_FILENO, O_NONBLOCK);	/* clear nonblocking */

	exit(0);
}

void _14_1_main(int argc, char *argv[])
{
    test();
}
