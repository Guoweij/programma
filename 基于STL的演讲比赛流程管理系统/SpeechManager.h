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

	void ShowMenu();//��ʾ�˵�

	void ExitSystem();//�˳�ϵͳ

	~SpeechManager();

	//��ʼ������
	void initSpeech();

	//ѡ������
	vector<int>vplayer;
	//����ѡ������
	vector<int>vpromotion;
	//ǰ��ѡ������
	vector<int>vwinner;
	// ��ű�� �Լ���Ӧ�� ����ѡ�� ����
	map<int, Speak>m_speak;

	void createSpeaker();//����ѡ��

	void startSpeech();//��ʼ����

	void speechDraw();//��ǩ

	void speechcontest();//��ʼ����

	void showScore();//��ʾ�������
		//�����¼
	void saveRecord();

	void loadRecord(); // ��ȡ��¼
	bool fileIsEmpty;//�ļ�Ϊ�յı�־
	//�����¼
	map<int, vector<string>> m_Record;
	//�����ִ�
	int m_Index;

private:

};

