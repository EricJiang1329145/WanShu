//库文件
#include <fstream>//文件操作
#include <iostream>//输入输出流
#include <string>//字符串
#include <map>//映射
#include <stdio.h>//标准输入输出
#include <Windows.h>//控制台
using namespace std;
//全局变量
extern string data;//存储文件内容
extern int totalNodes;//节点总数
extern map<int, string> datas;//存储文件内容

string readIn(int hangShu);// 读取输入
void explainingWords(string str);// 解释词
void showMenu();//显示菜单
void mapping(int num, string str);//映射
void mainLoop();//主循环
void initialization();//初始化
void guidingWords();//引导词
void rewriteOut(string writeout);//重写文件
int fastRead();//快速读取
void performExitActions();//执行退出操作
void reviewSlectedNode(int nodeNumber);//查看

//局部变量
int tmp;//临时变量，用于存储reviewSlectedNode函数中的节点编号

//函数定义
string readIn(int hangShu) {//读取指定行
    ifstream infile("trees.txt"); //打开文件
    if (infile.is_open()) { //如果文件打开成功
        string line;//存储每一行的内容
        while (getline(infile, line)) {//读取每一行
            hangShu--;//行数减一
            if (hangShu == 0) {//如果行数等于0
                return line;//返回这一行的内容
            }
        }
        infile.close();//关闭文件
    }
    else {
        cout << "Unable to open file" << std::endl;
    }
    return "0";
}
void explainingWords(string str) {
    std::cout << str << std::endl;
    return;
}
void showMenu() {
    std::cout << "以下是菜单：\n1 查看菜单\n2 查看指定位置的内容\n3 编辑(覆盖）指定位置的内容\n4 查看映射表大小\n-1 退出程序 ";
    return;
}
void mapping(int num, string str) {
    if (str == "") {
        cout << "输入为空，请重新输入" << endl;
    }
    else {
        datas[num] = str;
    }
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
        case -1:
            explainingWords("退出成功！");
            return;
        default:
            explainingWords("错误的操作代码！请再试一次。\n");
        }
    }
}
void reviewSlectedNode(int nodeNumber) {
    if(nodeNumber == -2){
        explainingWords("请输入您要查看的节点编号：（返回上一层输入-1）\n");
        nodeNumber = fastRead();
    }
    else if (nodeNumber == -3) {
        //待完成,使用映射完成
        explainingWords("请输入覆写内容：");
        cin >> datas[tmp];
        explainingWords("覆写成功！");
        return;
    }
    if(nodeNumber == -1) {
        explainingWords("返回上一层成功！");
        return;
    }
    tmp = nodeNumber;
    if (datas.find(nodeNumber) != datas.end()) {
        explainingWords("已为您找到节点编号为");
        cout << nodeNumber;
        explainingWords("的节点,\n");
        explainingWords("您所查看的节点内容为：" + datas[nodeNumber]+"\n");
        explainingWords("继续搜索请直接输入节点编号，编辑当前内容请输入-3，返回上一层输入-1。\n请输入：\n");
        reviewSlectedNode(fastRead());
    }
    else {
        explainingWords("未找到节点编号对应的内容！请检查节点编号以及是否导入文件至映射表！\n");
    }

    return;
}
void initialization() {
    //SetConsoleOutputCP(936);//设置控制台输出编码为简体中文
    //explainingWords("控制台编码已设置为简体中文!\n");
    //初始化映射表
    datas[1] = "root";
    int lineNumber;
    freopen("trees.txt", "r", stdin);//将标准输入重定向到文件
    cin >> lineNumber;
    for (int i = 1; i <= lineNumber; i++) {
        cin >> datas[i+1];
    }
    explainingWords("映射表初始化成功！\n");

    fclose(stdin);//关闭文件

    return;
}
void guidingWords() {
    cout << "欢迎来到万树！这是一个帮助人们重建记忆的项目。\n万树使用“树（编程中的一个概念）”来使事情更具逻辑性。\n要使用万树，您需要使用操作代码。\n输入“1”以查看菜单，您也可以输入“-1”退出程序。";
    return;
}
void rewriteOut(string writeout) {
    ofstream outfile("trees.txt");
    if (outfile.is_open()) {
        outfile << writeout << endl;
        outfile.close();
        cout << "File wroted successfully" << endl;
    }
    else {
        cout << "Unable to open file" << endl;
    }
    return;
}
int fastRead() {
    int num = 0,f=1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') {
            f=-1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
        c = getchar();
    }
    explainingWords("快读成功!");
    return num*f;
}
void performExitActions() {
    explainingWords("感谢使用万树！期待下次再见。");
    return;
}