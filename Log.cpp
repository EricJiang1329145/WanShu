//���ļ�
#include <fstream>//�ļ�����
#include <iostream>//���������
#include <string>//�ַ���
#include <map>//ӳ��
#include <stdio.h>//��׼�������
#include <Windows.h>//����̨

using namespace std;
//ȫ�ֱ���
extern int totalNodes;//�ڵ�����
extern map<int, string> datas;//�洢�ļ�����

string UTF8ToGB(const char* str);//UTF8תGB��������ʾ���ģ���ΪWindows����̨Ĭ�ϲ�֧��UTF8��������Ҫת������������룬ֱ�ӳ���csdn���룬ԭ�ģ�https://blog.csdn.net/qq_36251561/article/details/107752098
string readIn(int hangShu);// ��ȡ����
void ModifyLineData(int lineNum, string lineData);//�޸�ָ����
void explainingWords(string str);// ���ʹ�
void showMenu();//��ʾ�˵�
void mainLoop();//��ѭ��
void initialization();//��ʼ��
void guidingWords();//������
int fastRead();//���ٶ�ȡ
void performExitActions();//ִ���˳�����
void reviewSlectedNode(int nodeNumber);//�鿴
void createNewNode();//�½��ڵ�

//�ֲ�����
int tmp;//��ʱ���������ڴ洢reviewSlectedNode�����еĽڵ���
const char *filePath = "D:\\Dev\\WanShu\\trees.txt";
//��������
string readIn(int hangShu) {//��ȡָ����
	ifstream infile(filePath); //���ļ�
	if (infile.is_open()) { //����ļ��򿪳ɹ�
		explainingWords("�ļ��򿪳ɹ���");
		string line;//�洢ÿһ�е�����
		while (getline(infile, line)) {//��ȡÿһ��
			hangShu--;//������һ
			if (hangShu == 0) {//�����������0
				string str = UTF8ToGB(line.c_str()).c_str();
				return str;//������һ�е�����
			}
		}
		infile.close();//�ر��ļ�
	}
	else {
		explainingWords("�ļ���ʧ�ܣ�");
	}
	return "0";
}

//�Ӳ���԰ճ�����޸ĵĴ��룬ԭ�ģ�https://www.cnblogs.com/xiaohai123/p/13663026.html
void ModifyLineData(int lineNum, string lineData) {
	ifstream in;
	in.open(filePath);
	string strFileData = "";
	int line = 1;
	string tmpLineData = "";
	while (getline(in, tmpLineData)) {
		if (line == lineNum) {
			strFileData += lineData;
			strFileData += "\n";
		}
		else {
			strFileData += tmpLineData;
			strFileData += "\n";
		}
		line++;
	}
	in.close();
	//д���ļ�
	ofstream out;
	out.open(filePath);
	out.flush();
	out << strFileData;
	out.close();
	return;
}

void explainingWords(string str) {
	cout << str << endl;
	return;
}


void showMenu() {
	explainingWords("�����ǲ˵���\n1 �鿴�˵�\n2 �鿴/�༭�����ǣ�ָ��λ�õ�����\n3 �鿴ӳ����С\n4 �½��ڵ�\n-1 �˳����� ");
	return;
}

void mainLoop() {
	int operationCode;//��������
	while (true) {
		explainingWords("\n���������Ĳ�������: ");
		operationCode = fastRead();
		switch (operationCode) {
		case 1:
			showMenu();
			break;
		case 2:
			reviewSlectedNode(-2);
			break;
		case 3:
			explainingWords("ӳ����СΪ��" + to_string(datas.size()));
			break;
		case  4:
			createNewNode();
			break;
		case -1:
			explainingWords("�˳��ɹ���");
			return;
		default:
			explainingWords("����Ĳ������룡������һ�Ρ�\n");
		}
	}
}
void reviewSlectedNode(int nodeNumber) {
	if (nodeNumber == -2) {
		explainingWords("��������Ҫ�鿴/�༭�Ľڵ��ţ���������һ������-1��\n");
		nodeNumber = fastRead();
	}
	else if (nodeNumber == -3) {
		//�����,ʹ��ӳ�����
		explainingWords("�����븲д���ݣ�");
		cin >> datas[tmp];
		explainingWords("��д�ɹ���");
		ModifyLineData(tmp, datas[tmp]);
		explainingWords("�޸��ļ��ɹ���");
		return;
	}
	if (nodeNumber == -1) {
		explainingWords("������һ��ɹ���");
		return;
	}
	tmp = nodeNumber;
	if (datas.find(nodeNumber) != datas.end()) {
		explainingWords("��Ϊ���ҵ��ڵ���Ϊ");
		cout << nodeNumber;
		explainingWords("�Ľڵ�,\n");
		explainingWords("�����鿴�Ľڵ�����Ϊ��\n" + datas[nodeNumber] + "\n");
		explainingWords("����������ֱ������ڵ��ţ��༭��ǰ����������-3��������һ������-1��\n�����룺\n");
		reviewSlectedNode(fastRead());
	}
	else {
		explainingWords("δ�ҵ��ڵ��Ŷ�Ӧ�����ݣ�����ڵ����Լ��Ƿ����ļ���ӳ���\n");
	}

	return;
}
void initialization() {
	//��ʼ��ӳ���
	datas[1] = "root";
	totalNodes = stoi(readIn(1));
	int i = 2;
	while (i <= totalNodes + 1) {
		datas[i] = readIn(i);
		i++;
	}

	explainingWords("ӳ����ʼ���ɹ���\n");
	return;
}
void guidingWords() {
	explainingWords("��ӭ��������������һ�����������ؽ��������Ŀ��\n����ʹ�á���������е�һ���������ʹ��������߼��ԡ�\nҪʹ������������Ҫʹ�ò������롣\n���롰1���Բ鿴�˵�����Ҳ�������롰-1���˳�����");
	return;
}

int fastRead() {
	int num = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = -1;
		}
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		num = num * 10 + (c - '0');
		c = getchar();
	}
	explainingWords("����ɹ�!");
	return num * f;
}
void performExitActions() {
	explainingWords("��лʹ���������ڴ��´��ټ���");
	return;
}
void createNewNode() {
	explainingWords("��ǰ�У�" + to_string(totalNodes) + "���ڵ�");
	explainingWords("�½ڵ�ı�Ž��ǣ�"+to_string(totalNodes+1));
	explainingWords("�������½ڵ�����ݣ�");
	cin >> datas[totalNodes + 1];
    totalNodes++;
	ModifyLineData(totalNodes, datas[totalNodes]);
	explainingWords("�����ɹ�������Ϊ��\n"+datas[totalNodes]);
	ModifyLineData(1, to_string(totalNodes));
	return;
}
string UTF8ToGB(const char* str) {
	string result;
	WCHAR* strSrc;
	LPSTR szRes;

	//�����ʱ�����Ĵ�С
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//�����ʱ�����Ĵ�С
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}