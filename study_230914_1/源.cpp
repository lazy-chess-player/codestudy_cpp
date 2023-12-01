//#include<iostream>
//#include<vector>
//
//#define ti first
//#define va second
//
//using namespace std;
//
//typedef pair<int, int> pii;
//
//int T, M;
//pii f[105];
//int men[105][1005] = { -1 };
//int ans = 0;
//
//int dfs(int num, int t_rest)
//{
//	if (men[num][t_rest]!=-1)
//		return men[num][t_rest];
//	if (num == M + 1)
//	{
//		return men[num][t_rest] = 0;
//	}
//	if (t_rest >= f[num].ti)
//	{
//		return max(dfs(num + 1, t_rest), dfs(num + 1, t_rest - f[num].ti)+f[num].va);
//	}
//}
//
//void solve()
//{
//	cin >> T >> M;
//	for (int i = 1; i <= M; i++)
//	{
//		cin >> f[i].ti >> f[i].va;
//	}
//	ans = dfs(1, T);
//	cout << ans << endl;
//}
//
//int main()
//{
//	int t = 1;
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}

#include<iostream>  
#include<fstream>  
#include<string>  
#include<iomanip>  
using namespace std;

#define OK 1  
#define ERROR 0  
#define OVERFLOW -2  

typedef int Status; //�Ǻ������״̬���롣  
typedef struct Book {
    string id; //ISBN  
    string name; //����  
    double price; //����  
}ElemType;

#define MAXSIZE 5 // ˳�����󳤶�  

typedef struct {
    ElemType* elem; //�洢�ռ�Ļ���ַ  
    int length; //��ǰ����  
} SqList;

//��ʼ��������˳���  
Status InitList(SqList& L) {
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem) {
        cout << "NO";
        return ERROR; //�ڴ����ʧ��  
    }
    for (int i = 0; i < MAXSIZE; i++) { //��ʼ������λ��Ϊ��  
        L.elem[i].id = "";
        L.elem[i].name = "";
        L.elem[i].price = 0;
    }
    L.length = 0;
    return OK;
}
//��������
Status Intput(SqList& L) 
{
    for (int i = 0; i < MAXSIZE; i++) { //��ʼ������λ��Ϊ��  
        cout << "��" << i + 1 << "��:" << endl;
        cout << "����id:" << endl;
        cin>>L.elem[i].id;
        cout << "��������:" << endl;
        cin >> L.elem[i].name;
        cout << "����۸�:" << endl;
        cin >> L.elem[i].price;
    }
    cout << "�������" << endl;
    L.length++;
    return OK;
}

//ȡֵ  
Status GetElem(SqList L, int pos, ElemType& e) {
    if (pos < 1 || pos > L.length) {
        return ERROR; //λ�÷Ƿ�  
    }
    e = L.elem[pos - 1];
    return OK;
}

//����  
Status Search(SqList L, string id, int& pos) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i].id == id) {
            pos = i + 1; //�ҵ�������λ��  
            return OK;
        }
    }
    return ERROR; //δ�ҵ�  
}

//����  
Status Insert(SqList& L, int pos, string id, string name, double price) {
    if (pos < 1 || pos > L.length + 1 || L.length == MAXSIZE) { //λ�÷Ƿ�����˳�������  
        return ERROR;
    }
    ElemType e; //������Ԫ��  
    e.id = id;
    e.name = name;
    e.price = price;
    for (int i = L.length; i >= pos - 1; i--) { //�����ƶ�Ԫ��  
        L.elem[i] = L.elem[i - 1];
    }
    L.elem[pos - 1] = e; //������Ԫ��
    L.length++; //����+1  
    return OK;
}

Status Delete(SqList& L, int pos) {
    if (pos < 1 || pos > L.length) { //λ�÷Ƿ�  
        return ERROR;
    }
    for (int i = pos - 1; i < L.length - 1; i++) { //��ǰ�ƶ�Ԫ��  
        L.elem[i] = L.elem[i + 1];
    }
    L.length--; //����-1  
    return OK;
}

void Output(const SqList& L)
{
    for (int i = 0; i < L.length; i++)
    {
        cout << L.elem[i].id << " " << L.elem[i].name << " " << L.elem[i].price << endl;
    }
}


int main() {
    SqList L; // ˳������ L  
    Book e;
    int i = 0, ret,pos, choose = -1;
    string id, name;
    double price;
    cout << "0. �˳�\n" << "1. ��ʼ��\n2. ȡֵ\n3. ����\n4. ����\n5. ɾ��\n6. ���\n7. ����\n" << endl;
    while (choose != 0)
    {
        cout << "��ѡ��:";
        cin >> choose;
        switch (choose)
        {
        case 1:
            int s;
            s = InitList(L);
            if (!s) 
            {
                cout << "��ʼ���б�ʧ��" << endl;
            }
            else {
                cout << "��ʼ���б�ɹ�" << endl;
            }
            break;
        case 2: cout << "������λ�ã�";
            cin >> pos;
            s = GetElem(L, pos, e);
            if (s) {
                cout << "Ԫ��id��" << e.id << endl;
                cout << "Ԫ��name��" << e.name << endl;
                cout << "Ԫ��price��" << e.price << endl;
            }
            else {
                cout << "��ȡԪ��ʧ��" << endl;
            }
            break;
        case 3: cout << "������Ҫ���ҵ�id��";
            cin >> id;
            s = Search(L, id, pos);
            if (s) {
                cout << "�ҵ�Ԫ�أ�λ��Ϊ��" << pos << endl;
            }
            else {
                cout << "δ�ҵ�Ԫ��" << endl;
            }
            break;
        case 4: cout << "������λ�ã�";
            cin >> pos;
            cout << "������id��";
            cin >> id;
            cout << "������name��";
            cin >> name;
            cout << "������price��";
            cin >> price;
            s = Insert(L, pos, id, name, price);
            if (s) {
                cout << "����Ԫ�سɹ�" << endl;
            }
            else {
                cout << "����Ԫ��ʧ��" << endl;
            }
            break;
        case 5: cout << "������Ҫɾ����id��";
            cin >> id;
            s = Delete(L, pos);
            if (s)
            {
                cout << "ɾ��Ԫ�سɹ�" << endl;
            }
            else {
                cout << "ɾ��Ԫ��ʧ��" << endl;
            }
            break;
        case 6:
            Output(L);
            break;
        case 7:
            cout << "������" << endl;
            Intput(L);
            break;
        case 0: 
            return 0;
        default:  cout << "������������������" << endl;
        }
    }
    return 0;
}
