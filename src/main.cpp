//C公共头文件
#include"../include/apue.h"

//子文件

#include "../include/ls1.h"
//listDir("/root/workspace/HelloCpp");


#include "../include/01_5.h"
//CopyStdInToStdOut1()
//[root@CentOS6 Debug]# ./HelloCpp < makefile > makefile_bak
//CopyStdInToStdOut2()
//[root@CentOS6 Debug]# ./HelloCpp < makefile > makefile_bak

#include "../include/01_6.h"
//PrintSelfInfo();
//ExcuteFromStdin();
//[root@CentOS6 Debug]# ./HelloCpp

#include "../include/01_9.h"
//::Register_Signal_Handler_Test();

#include "../include/03_1.h"
// ./HelloCpp < makefile   seek OK
// ifconfig | ./HelloCpp  cannot seek

#include "../include/03_2.h"
// CreateHoleFile(); [root@CentOS6 Debug]# od  -t x2 file.hole  ;查看磁盘快ll -s

#include "../include/03_4.h"
/*
::Test_print_fl(argc,argv);
[root@CentOS6 Debug]# ./HelloCpp 0 < /dev/tty
read only
[root@CentOS6 Debug]# ./HelloCpp 1 > temp.foo
[root@CentOS6 Debug]# cat temp.foo
write only
[root@CentOS6 Debug]# ./HelloCpp 2 2>>temp.foo
write only, append
[root@CentOS6 Debug]# ./HelloCpp 5 5<>temp.foo
read write
*/

#include "../include/03_5.h"

#include "../include/10_24.h"
/*
 * signal_sync_test();
 * */
#include "../include/11_01.h"
/*
 * test_thread_print_ids()
 * */

#include "../include/13_2.h"
/*
 * 测试单例运行进程 13-2
 * */
#include<iostream>

using namespace std;



int main(int argc,char *argv[])
{
    syslog(LOG_NOTICE, "can't open %s: %s", LOCKFILE, "lcm testing ");
    return 0;
}


