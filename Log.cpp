//库文件
#include <fstream>//文件操作
#include <iostream>//输入输出流
#include <string>//字符串
#include <map>//映射
#include <stdio.h>//标准输入输出
#include <Windows.h>//控制台

using namespace std;
//全局变量
extern int totalNodes;//节点总数
extern map<int, string> datas;//存储文件内容

string UTF8ToGB(const char* str);//UTF8转GB，用于显示中文，因为Windows控制台默认不支持UTF8，所以需要转换，否则会乱码，直接抄的csdn代码，原文：https://blog.csdn.net/qq_36251561/article/details/107752098
string readIn(int hangShu);// 读取输入
void ModifyLineData(int lineNum, string lineData);//修改指定行
void explainingWords(string str);// 解释词
void showMenu();//显示菜单
void mainLoop();//主循环
void initialization();//初始化
void guidingWords();//引导词
int fastRead();//快速读取
void performExitActions();//执行退出操作
void reviewSlectedNode(int nodeNumber);//查看
void createNewNode();//新建节点

//局部变量
int tmp;//临时变量，用于存储reviewSlectedNode函数中的节点编号
const char *filePath = "D:\\Dev\\WanShu\\trees.txt";
//函数定义
string readIn(int hangShu) {//读取指定行
	ifstream infile(filePath); //打开文件
	if (infile.is_open()) { //如果文件打开成功
		explainingWords("文件打开成功！");
		string line;//存储每一行的内容
		while (getline(infile, line)) {//读取每一行
			hangShu--;//行数减一
			if (hangShu == 0) {//如果行数等于0
				string str = UTF8ToGB(line.c_str()).c_str();
				return str;//返回这一行的内容
			}
		}
		infile.close();//关闭文件
	}
	else {
		explainingWords("文件打开失败！");
	}
	return "0";
}

//从博客园粘贴并修改的代码，原文：https://www.cnblogs.com/xiaohai123/p/13663026.html
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
	//写入文件
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
	explainingWords("以下是菜单：\n1 查看菜单\n2 查看/编辑（覆盖）指定位置的内容\n3 查看映射表大小\n4 新建节点\n-1 退出程序 ");
	return;
}

void mainLoop() {
	int operationCode;//操作代码
	while (true) {
		explainingWords("\n请输入您的操作代码: ");
		operationCode = fastRead();
		switch (operationCode) {
		case 1:
			showMenu();
			break;
		case 2:
			reviewSlectedNode(-2);
			break;
		case 3:
			explainingWords("映射表大小为：" + to_string(datas.size()));
			break;
		case  4:
			createNewNode();
			break;
		case -1:
			explainingWords("退出成功！");
			return;
		default:
			explainingWords("错误的操作代码！请再试一次。\n");
		}
	}
}
void reviewSlectedNode(int nodeNumber) {
	if (nodeNumber == -2) {
		explainingWords("请输入您要查看/编辑的节点编号：（返回上一层输入-1）\n");
		nodeNumber = fastRead();
	}
	else if (nodeNumber == -3) {
		//待完成,使用映射完成
		explainingWords("请输入覆写内容：");
		cin >> datas[tmp];
		explainingWords("覆写成功！");
		ModifyLineData(tmp, datas[tmp]);
		explainingWords("修改文件成功！");
		return;
	}
	if (nodeNumber == -1) {
		explainingWords("返回上一层成功！");
		return;
	}
	tmp = nodeNumber;
	if (datas.find(nodeNumber) != datas.end()) {
		explainingWords("已为您找到节点编号为");
		cout << nodeNumber;
		explainingWords("的节点,\n");
		explainingWords("您所查看的节点内容为：\n" + datas[nodeNumber] + "\n");
		explainingWords("继续搜索请直接输入节点编号，编辑当前内容请输入-3，返回上一层输入-1。\n请输入：\n");
		reviewSlectedNode(fastRead());
	}
	else {
		explainingWords("未找到节点编号对应的内容！请检查节点编号以及是否导入文件至映射表！\n");
	}

	return;
}
void initialization() {
	//初始化映射表
	datas[1] = "root";
	totalNodes = stoi(readIn(1));
	int i = 2;
	while (i <= totalNodes + 1) {
		datas[i] = readIn(i);
		i++;
	}

	explainingWords("映射表初始化成功！\n");
	return;
}
void guidingWords() {
	explainingWords("欢迎来到万树！这是一个帮助人们重建记忆的项目。\n万树使用“树（编程中的一个概念）”来使事情更具逻辑性。\n要使用万树，您需要使用操作代码。\n输入“1”以查看菜单，您也可以输入“-1”退出程序。");
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
	explainingWords("快读成功!");
	return num * f;
}
void performExitActions() {
	explainingWords("感谢使用万树！期待下次再见。");
	return;
}
void createNewNode() {
	explainingWords("当前有：" + to_string(totalNodes) + "个节点");
	explainingWords("新节点的编号将是："+to_string(totalNodes+1));
	explainingWords("请输入新节点的数据：");
	cin >> datas[totalNodes + 1];
    totalNodes++;
	ModifyLineData(totalNodes, datas[totalNodes]);
	explainingWords("创建成功！数据为：\n"+datas[totalNodes]);
	ModifyLineData(1, to_string(totalNodes));
	return;
}
string UTF8ToGB(const char* str) {
	string result;
	WCHAR* strSrc;
	LPSTR szRes;

	//获得临时变量的大小
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//获得临时变量的大小
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}