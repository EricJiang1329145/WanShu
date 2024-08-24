//���ļ�
#include <fstream>//�ļ�����
#include <iostream>//���������
#include <string>//�ַ���
#include <map>//ӳ��
#include <stdio.h>//��׼�������
#include <Windows.h>//����̨
using namespace std;
//ȫ�ֱ���
extern string data;//�洢�ļ�����
extern int totalNodes;//�ڵ�����
extern map<int, string> datas;//�洢�ļ�����

string readIn(int hangShu);// ��ȡ����
void explainingWords(string str);// ���ʹ�
void showMenu();//��ʾ�˵�
void mapping(int num, string str);//ӳ��
void mainLoop();//��ѭ��
void initialization();//��ʼ��
void guidingWords();//������
void rewriteOut(string writeout);//��д�ļ�
int fastRead();//���ٶ�ȡ
void performExitActions();//ִ���˳�����
void reviewSlectedNode(int nodeNumber);//�鿴

//�ֲ�����
int tmp;//��ʱ���������ڴ洢reviewSlectedNode�����еĽڵ���

//��������
string readIn(int hangShu) {//��ȡָ����
    ifstream infile("trees.txt"); //���ļ�
    if (infile.is_open()) { //����ļ��򿪳ɹ�
        string line;//�洢ÿһ�е�����
        while (getline(infile, line)) {//��ȡÿһ��
            hangShu--;//������һ
            if (hangShu == 0) {//�����������0
                return line;//������һ�е�����
            }
        }
        infile.close();//�ر��ļ�
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
    std::cout << "�����ǲ˵���\n1 �鿴�˵�\n2 �鿴ָ��λ�õ�����\n3 �༭(���ǣ�ָ��λ�õ�����\n4 �鿴ӳ����С\n-1 �˳����� ";
    return;
}
void mapping(int num, string str) {
    if (str == "") {
        cout << "����Ϊ�գ�����������" << endl;
    }
    else {
        datas[num] = str;
    }
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
        case -1:
            explainingWords("�˳��ɹ���");
            return;
        default:
            explainingWords("����Ĳ������룡������һ�Ρ�\n");
        }
    }
}
void reviewSlectedNode(int nodeNumber) {
    if(nodeNumber == -2){
        explainingWords("��������Ҫ�鿴�Ľڵ��ţ���������һ������-1��\n");
        nodeNumber = fastRead();
    }
    else if (nodeNumber == -3) {
        //�����,ʹ��ӳ�����
        explainingWords("�����븲д���ݣ�");
        cin >> datas[tmp];
        explainingWords("��д�ɹ���");
        return;
    }
    if(nodeNumber == -1) {
        explainingWords("������һ��ɹ���");
        return;
    }
    tmp = nodeNumber;
    if (datas.find(nodeNumber) != datas.end()) {
        explainingWords("��Ϊ���ҵ��ڵ���Ϊ");
        cout << nodeNumber;
        explainingWords("�Ľڵ�,\n");
        explainingWords("�����鿴�Ľڵ�����Ϊ��" + datas[nodeNumber]+"\n");
        explainingWords("����������ֱ������ڵ��ţ��༭��ǰ����������-3��������һ������-1��\n�����룺\n");
        reviewSlectedNode(fastRead());
    }
    else {
        explainingWords("δ�ҵ��ڵ��Ŷ�Ӧ�����ݣ�����ڵ����Լ��Ƿ����ļ���ӳ���\n");
    }

    return;
}
void initialization() {
    //SetConsoleOutputCP(936);//���ÿ���̨�������Ϊ��������
    //explainingWords("����̨����������Ϊ��������!\n");
    //��ʼ��ӳ���
    datas[1] = "root";
    int lineNumber;
    freopen("trees.txt", "r", stdin);//����׼�����ض����ļ�
    cin >> lineNumber;
    for (int i = 1; i <= lineNumber; i++) {
        cin >> datas[i+1];
    }
    explainingWords("ӳ����ʼ���ɹ���\n");

    fclose(stdin);//�ر��ļ�

    return;
}
void guidingWords() {
    cout << "��ӭ��������������һ�����������ؽ��������Ŀ��\n����ʹ�á���������е�һ���������ʹ��������߼��ԡ�\nҪʹ������������Ҫʹ�ò������롣\n���롰1���Բ鿴�˵�����Ҳ�������롰-1���˳�����";
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
    explainingWords("����ɹ�!");
    return num*f;
}
void performExitActions() {
    explainingWords("��лʹ���������ڴ��´��ټ���");
    return;
}