#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include"speak.h"

class SpeechManager
{
public:
	SpeechManager();

	void ShowMenu();//显示菜单

	void ExitSystem();//退出系统

	~SpeechManager();

	//初始化属性
	void initSpeech();

	//选手容器
	vector<int>vplayer;
	//晋级选手容器
	vector<int>vpromotion;
	//前三选手容器
	vector<int>vwinner;
	// 存放编号 以及对应的 具体选手 容器
	map<int, Speak>m_speak;

	void createSpeaker();//创建选手

	void startSpeech();//开始比赛

	void speechDraw();//抽签

	void speechcontest();//开始比赛

	void showScore();//显示比赛结果
		//保存记录
	void saveRecord();

	void loadRecord(); // 读取记录
	bool fileIsEmpty;//文件为空的标志
	//往届记录
	map<int, vector<string>> m_Record;
	//比赛轮次
	int m_Index;

private:

};

