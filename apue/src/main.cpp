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
#include "../include/13_1.h"
#include "../include/13_2.h"
/*
 * 测试单例运行进程 13-2
 * */
#include "../include/13_3.h"
#include "../include/13_4.h"
/*
 *_13_3_main : 测试守护进程通过线程处理挂起信号重新加载配置
 *_13_4_main : 测试守护进程通过非线程处理挂起信号重新加载配置
 * */

/*
 * 非阻塞write 14-1
 * */
#include "../include/14_1.h"


#include<iostream>

using namespace std;



int main(int argc,char *argv[])
{
    _14_1_main(argc, argv);
    return 0;
}


