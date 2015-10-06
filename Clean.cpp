#include "Clean.h"
#include<cmath>


Clean::Clean()
{
	
}


int Clean::coreWork(fs::path currentPath)
{
	int fileCounter = 0;
	string name = currentPath.string() + "\\登记簿.txt";
	fstream f(name, ios::out);
	auto time_c = chrono::system_clock::now();
	auto time = chrono::system_clock::to_time_t(time_c);
	f << "本次登记的时间为: " << put_time(localtime(&time), "%F %T") << endl << endl <<
		"==============================================" <<
		endl;

	for (auto &file_i : fs::directory_iterator(currentPath)) {
		auto file = fs::path(file_i);
		if (fs::is_directory(file)) {
			fileCounter += Clean::coreWork(file);
		}
		fileCounter++;
		if (name!=(file.string())) {
			f << "文件（夹）为: " << file << endl;
			if (!fs::is_directory(file)) {
				double fileSizeTemp = fs::file_size(file);
				double fileSize = fileSizeTemp;
				if (fileSizeTemp >= pow(2, 10 * 3)) {
					fileSize = fileSizeTemp / pow(2, 10 * 3);
					f << "大小为： " << fileSize<< "GB" << endl;
				}
				else if (fileSizeTemp >= pow(2, 10 * 2)) {
					fileSize = fileSizeTemp / pow(2, 10 * 2);
					f << "大小为： " << fileSize << "MB" << endl;
				}
				else if (fileSizeTemp >= pow(2, 10 * 1)) {
					fileSize = fileSizeTemp / pow(2, 10 * 1);
					f << "大小为： " << fileSize << "KB" << endl;
				}
				else f << "大小为： " << fileSize<< "B" << endl;
			}
			else f << "文件夹木有大小。。。" << endl;

			f << "============================================" << endl;
		}
	}
	f << endl;
	f << "该文件夹及其子文件夹中共有文件（不包含登记簿）" << fileCounter-1 << "个" << endl;
	f.close();

	return fileCounter -1 ;
}




Clean::~Clean()
{
}
