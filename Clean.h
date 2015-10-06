#pragma once
#include<iostream>
#include<chrono>
#include<string>
#include<experimental\filesystem>
#include<ctime>
#include<fstream>
#include<iomanip>

using namespace std;
namespace fs = experimental::filesystem;
/*
本类的功能是便利其所在位置的文件夹和其子文件夹，并在每个
文件夹下面登记所拥有的文件名称
并将其记录在“登记簿.txt”文件中
文件要求：
	1.每一次运行将会覆盖之前内容，登记最新的内容，并将运行时间写入第一行
	2.每一个文件及文件夹用一行来表示（过长可以换行），每一个文件之间用许多横线分割
*/
class Clean
{
private:

public:
	Clean();//构造函数，负责输出第一行的时间
	int coreWork(fs::path currentPath);//核心功能，返回当前目录文件及文件夹个数
	~Clean();
};

