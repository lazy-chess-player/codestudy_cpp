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

typedef int Status; //是函数结果状态代码。  
typedef struct Book {
    string id; //ISBN  
    string name; //书名  
    double price; //定价  
}ElemType;

#define MAXSIZE 5 // 顺序表最大长度  

typedef struct {
    ElemType* elem; //存储空间的基地址  
    int length; //当前长度  
} SqList;

//初始化，创建顺序表  
Status InitList(SqList& L) {
    L.elem = new ElemType[MAXSIZE];
    if (!L.elem) {
        cout << "NO";
        return ERROR; //内存分配失败  
    }
    for (int i = 0; i < MAXSIZE; i++) { //初始化所有位置为空  
        L.elem[i].id = "";
        L.elem[i].name = "";
        L.elem[i].price = 0;
    }
    L.length = 0;
    return OK;
}
//输入数据
Status Intput(SqList& L) 
{
    for (int i = 0; i < MAXSIZE; i++) { //初始化所有位置为空  
        cout << "第" << i + 1 << "本:" << endl;
        cout << "输入id:" << endl;
        cin>>L.elem[i].id;
        cout << "输入名字:" << endl;
        cin >> L.elem[i].name;
        cout << "输入价格:" << endl;
        cin >> L.elem[i].price;
    }
    cout << "输入完成" << endl;
    L.length++;
    return OK;
}

//取值  
Status GetElem(SqList L, int pos, ElemType& e) {
    if (pos < 1 || pos > L.length) {
        return ERROR; //位置非法  
    }
    e = L.elem[pos - 1];
    return OK;
}

//查找  
Status Search(SqList L, string id, int& pos) {
    for (int i = 0; i < L.length; i++) {
        if (L.elem[i].id == id) {
            pos = i + 1; //找到，返回位置  
            return OK;
        }
    }
    return ERROR; //未找到  
}

//插入  
Status Insert(SqList& L, int pos, string id, string name, double price) {
    if (pos < 1 || pos > L.length + 1 || L.length == MAXSIZE) { //位置非法或者顺序表已满  
        return ERROR;
    }
    ElemType e; //定义新元素  
    e.id = id;
    e.name = name;
    e.price = price;
    for (int i = L.length; i >= pos - 1; i--) { //往后移动元素  
        L.elem[i] = L.elem[i - 1];
    }
    L.elem[pos - 1] = e; //插入新元素
    L.length++; //长度+1  
    return OK;
}

Status Delete(SqList& L, int pos) {
    if (pos < 1 || pos > L.length) { //位置非法  
        return ERROR;
    }
    for (int i = pos - 1; i < L.length - 1; i++) { //往前移动元素  
        L.elem[i] = L.elem[i + 1];
    }
    L.length--; //长度-1  
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
    SqList L; // 顺序表变量 L  
    Book e;
    int i = 0, ret,pos, choose = -1;
    string id, name;
    double price;
    cout << "0. 退出\n" << "1. 初始化\n2. 取值\n3. 查找\n4. 插入\n5. 删除\n6. 输出\n7. 输入\n" << endl;
    while (choose != 0)
    {
        cout << "请选择:";
        cin >> choose;
        switch (choose)
        {
        case 1:
            int s;
            s = InitList(L);
            if (!s) 
            {
                cout << "初始化列表失败" << endl;
            }
            else {
                cout << "初始化列表成功" << endl;
            }
            break;
        case 2: cout << "请输入位置：";
            cin >> pos;
            s = GetElem(L, pos, e);
            if (s) {
                cout << "元素id：" << e.id << endl;
                cout << "元素name：" << e.name << endl;
                cout << "元素price：" << e.price << endl;
            }
            else {
                cout << "获取元素失败" << endl;
            }
            break;
        case 3: cout << "请输入要查找的id：";
            cin >> id;
            s = Search(L, id, pos);
            if (s) {
                cout << "找到元素，位置为：" << pos << endl;
            }
            else {
                cout << "未找到元素" << endl;
            }
            break;
        case 4: cout << "请输入位置：";
            cin >> pos;
            cout << "请输入id：";
            cin >> id;
            cout << "请输入name：";
            cin >> name;
            cout << "请输入price：";
            cin >> price;
            s = Insert(L, pos, id, name, price);
            if (s) {
                cout << "插入元素成功" << endl;
            }
            else {
                cout << "插入元素失败" << endl;
            }
            break;
        case 5: cout << "请输入要删除的id：";
            cin >> id;
            s = Delete(L, pos);
            if (s)
            {
                cout << "删除元素成功" << endl;
            }
            else {
                cout << "删除元素失败" << endl;
            }
            break;
        case 6:
            Output(L);
            break;
        case 7:
            cout << "请输入" << endl;
            Intput(L);
            break;
        case 0: 
            return 0;
        default:  cout << "输入有误，请重新输入" << endl;
        }
    }
    return 0;
}
