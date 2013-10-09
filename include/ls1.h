#ifndef _LS1_H_
#define _LS1_H_
#include<dirent.h>
#include<string>


int listDir(const std::string strPath)
{
	// 打开一个目录流
	DIR *dp = opendir(strPath.c_str());
	if (dp == NULL)
		printf("can't open %s", strPath.c_str());

	// 直到读到空为止
	struct dirent *dirp = readdir(dp);
	while (dirp != NULL)
	{
		printf("%s\n", dirp->d_name);
		dirp = readdir(dp);
	}

	// 关闭流
	closedir(dp);
	return 0;
}

#endif
