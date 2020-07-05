#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct process_FCFS
{
	char arrivename[10] = " ";		//进程名称
	float arriveTime = 0xf;			//进程到达时间
	float serveTime = 0xf;			//进程服务时间
	float finishTime = 0xf;			//进程完成时间
	float roundTime = 0xf;			//进程周转时间
	float daiquanTime = 0xf;			//带权周转时间
}FCFS;
class sorttest 
{
public:
	bool operator()(FCFS v1, FCFS v2)
	{
		if (v1.arriveTime>v2.arriveTime)
		{
			return false;
		}
		return true;
	}
};
void PrintFCFS(vector<FCFS>& data, int n) //输出
{
	for (vector<FCFS>::iterator it = data.begin(); it != data.end(); it++)
	{
		cout << "进程姓名" << it->arrivename
			<< "到达时间:" << (*it).arriveTime
			<< "服务时间：" << it->serveTime
			<< "完成时间：" << it->finishTime
			<< "周转时间: " << it->roundTime
			<< "带权周转时间" << it->daiquanTime
			<< endl;
	}
}
void Fcfs(vector<FCFS>& data, int n)
{
	data[0].finishTime = data[0].arriveTime + data[0].serveTime;
	data[0].roundTime = data[0].finishTime + data[0].arriveTime;
	data[0].daiquanTime = data[0].roundTime + data[0].serveTime;
	for (int i = 1; i < data.size(); i++)
	{
		if (data[i].arriveTime < data[i - 1].finishTime)
		{
			data[i].finishTime = data[i - 1].finishTime + data[i].serveTime;
			data[i].roundTime = data[i].finishTime - data[i].arriveTime;
			data[i].daiquanTime = data[i].roundTime / data[i].serveTime;
		}
		else
		{
			data[i].finishTime = data[i].finishTime + data[i].serveTime;
			data[i].roundTime = data[i].finishTime - data[i].arriveTime;
			data[i].daiquanTime = data[i].roundTime / data[i].serveTime;
		}
	}
	cout << "先来先服务算法" << endl;
	PrintFCFS(data, n);
}
bool test(int v1, int v2) 
{
	if (v1 < v2) 
	{
		return true;
	}
	return false;
}
int main()
{
	int n;
	vector<FCFS> data;			//保存进程数据的容器
	cout << "请输入进程个数" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		FCFS newFcfs;
		cout << "进程名称";
		cin >> newFcfs.arrivename;
		cout << "进程到达时间";
		cin >> newFcfs.arriveTime;
		cout << "进程服务时间";
		cin >> newFcfs.serveTime;
		data.push_back(newFcfs);
	}
	sort(data.begin(), data.end(), sorttest());
	Fcfs(data, n);
	return 0;
}