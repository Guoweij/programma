#include "SpeechManager.h"
#include<algorithm>
#include<deque>
#include<numeric>
#include<map>
#include<fstream>
SpeechManager::SpeechManager()
{
	this->initSpeech();

	this->createSpeaker();

	this->initSpeech();

}
//�˵�
void SpeechManager::ShowMenu() {
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void SpeechManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::createSpeaker() {
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		Speak sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		//12��ѡ�ֱ��
		this->vplayer.push_back(i);
		//ѡ�ֱ�� �Լ���Ӧ��ѡ�� ��ŵ�map������
		this->m_speak.insert(pair<int, Speak>(i, sp));
	}
}

void SpeechManager::startSpeech()
{
	// ��һ�ֱ���
		//1����ǩ
	this->speechDraw();
		//2������
	this->speechcontest();
		//3����ʾ�������
	this->showScore();
		//�ڶ��ֱ���
	this->m_Index++;
	//1����ǩ
	this->speechDraw();
	//2������
	this->speechcontest();
	//3����ʾ�������
	this->showScore();

		//4���������
	this->saveRecord();
	cout << "����������" << endl;
}

void SpeechManager::speechDraw()
{
	cout << "��" << this->m_Index << "�ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "---------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	if (this->m_Index == 1)//��һ��
	{
		random_shuffle(vplayer.begin(), vplayer.end());//ѡ������ϴ��
		for (vector<int>::iterator it = vplayer.begin(); it != vplayer.end(); it++)
		{
			cout << " " << *it << " ";
			// ����ǩ�����ӵ�����ѡ��������
			this->vpromotion.push_back(*it);
		}
		cout << endl;
	}
	else
	{
		random_shuffle(vpromotion.begin(), vpromotion.end());//����ѡ������ϴ��
		for (vector<int>::iterator it = vpromotion.begin(); it != vpromotion.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::speechcontest()
{
	cout << "------------- ��" << this->m_Index << "����ʽ������ʼ��------------- " << endl;

	multimap<double, int, greater<int>> groupScore; //��ʱ����������key���� value ѡ�ֱ��

	int num = 0; //��¼��Ա����6��Ϊ1��

	vector <int>v_Src;   //��������Ա����
	if (this->m_Index == 1)
	{
		v_Src = vplayer;
	}
	else
	{
		v_Src = vpromotion;
	}

	//�������в���ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;  // 600 ~ 1000
			//cout << score << " ";
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());				//����
		d.pop_front();												//ȥ����߷�
		d.pop_back();												//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);				//��ȡ�ܷ�
		double avg = sum / (double)d.size();									//��ȡƽ����

		//ÿ����ƽ����
		//cout << "��ţ� " << *it  << " ѡ�֣� " << this->m_Speaker[*it].m_Name << " ��ȡƽ����Ϊ�� " << avg << endl;  //��ӡ����
		this->m_speak[*it].m_Score[this->m_Index - 1] = avg;

		//6����һ�飬����ʱ��������
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{

			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "���: " << it->second << " ������ " << this->m_speak[it->second].m_Name << " �ɼ��� " << this->m_speak[it->second].m_Score[this->m_Index - 1] << endl;
			}

			int count = 0;
			//ȡǰ����
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					vpromotion.push_back((*it).second);
				}
				else
				{
					vwinner.push_back((*it).second);
				}
			}

			groupScore.clear();

			cout << endl;

		}
	}
	cout << "------------- ��" << this->m_Index << "�ֱ������  ------------- " << endl;
	system("pause");
}

void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // ������ķ�ʽ���ļ�  -- д�ļ�

	//��ÿ��������д�뵽�ļ���
	for (vector<int>::iterator it = vwinner.begin(); it != vwinner.end(); it++)
	{
		ofs << *it << ","
			<< m_speak[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();

	cout << "��¼�Ѿ�����" << endl;
}

void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in); //���������� ��ȡ�ļ�

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��!" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;

	ifs.putback(ch); //��ȡ�ĵ����ַ��Ż�ȥ

	string data;
	int index = 0;
	while (ifs >> data)
	{
		//cout << data << endl;
		vector<string>v;

		int pos = -1;
		int start = 0;

		while (true)
		{
			pos = data.find(",", start); //��0��ʼ���� ','
			if (pos == -1)
			{
				break; //�Ҳ���break����
			}
			string tmp = data.substr(start, pos - start); //�ҵ���,���зָ� ����1 ��ʼλ�ã�����2 ��ȡ����
			v.push_back(tmp);
			start = pos + 1;
		}

		this->m_Record.insert(make_pair(index, v));
		index++;
	}

	ifs.close();
}

void SpeechManager::showScore() {
	cout << "---------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�-----------" << endl;
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = vpromotion;
	}
	else
	{
		v = vwinner;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << " ������ " << m_speak[*it].m_Name << " �÷֣� " << m_speak[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->ShowMenu();
}

SpeechManager::~SpeechManager()
{
}

void SpeechManager::initSpeech()
{
	//������֤Ϊ��
	this->vplayer.clear();
	this->vpromotion.clear();
	this->vwinner.clear();
	this->m_speak.clear();
	this->m_Index = 1;
}
