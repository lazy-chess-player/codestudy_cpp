#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

int sum[4 * N]{ 0 };//������߶���
int tag[4 * N]{ 0 };//�ӳٽڵ�
int minNum[4 * N]{ 0 };//��Сֵ�߶���
int nums[N];

void build(int l, int r, int p)//lΪ��ǰ��߽磬rΪ��ǰ�ұ߽�,pΪ�߶�����ǰ�ڵ������
{
	//���l��r��ȣ���ʾ�Ѿ�����Ҷ�ڵ㣬ֱ�ӷ��ء�
	if (l == r)
	{
		sum[p] = nums[l];
		return;
	}
	//���ֵݹ齨��
	int mid = (l + r) / 2;
	build(l, mid, p * 2);
	build(mid + 1, r, p * 2 + 1);
	sum[p] = sum[p * 2] + sum[p * 2 + 1];
}

void buildMinNum(int l, int r, int p)//lΪ��ǰ��߽磬rΪ��ǰ�ұ߽�,pΪ�߶�����ǰ�ڵ������
{
	//���l��r��ȣ���ʾ�Ѿ�����Ҷ�ڵ㣬ֱ�ӷ��ء�
	if (l == r)
	{
		sum[p] = nums[l];
		return;
	}
	//���ֵݹ齨��
	int mid = (l + r) / 2;
	buildMinNum(l, mid, p * 2);
	buildMinNum(mid + 1, r, p * 2 + 1);
	sum[p] = min(sum[p * 2], sum[p * 2 + 1]);
}


void checkDelay(int l, int r, int p, char opt = '=')//��⺯������鵱ǰ�ڵ��Ƿ����ӳٱ�ǣ����򴫵ݸ�����
{
	if (!tag[p])
		return;
	int mid = (l + r) / 2;
	if (opt == '=')
	{
		tag[p * 2] = tag[p * 2 + 1] = tag[p];
		sum[p * 2] = (mid - l + 1) * tag[p];
		sum[p * 2 + 1] = (r - mid) * tag[p];
	}
	else if (opt == '+')
	{
		tag[p * 2] += tag[p];
		tag[p * 2 + 1] += tag[p];
		sum[p * 2] += (mid - l + 1) * tag[p];
		sum[p * 2 + 1] += (r - mid) * tag[p];
	}
	tag[p] = 0;
}

ll getSum(int x, int y, int l, int r, int p)//x,yΪ����ѯ����[x,y]�����ұ߽�
{
	if (x <= l && r <= y)//�����ǰ�ڵ㱻������ֱ�ӷ��ص�ǰ�ڵ��ֵ
		return sum[p];
	checkDelay(l, r, p);
	int mid = (l + r) / 2;
	ll sum = 0;
	if (x <= mid)//�м�ֵ���ڵ�����߽磬��ʾ������Ҫ��ѯ
		sum += getSum(x, y, l, mid, p * 2);
	if (mid < y)//�м�ֵС���ұ߽磬��ʾ�ұ߽���Ҫ��ѯ���������ʾû���Ұ����
		sum += getSum(x, y, mid + 1, r, p * 2 + 1);
	return sum;
}

int getMin(int x, int y, int l, int r, int p)//x,yΪ����ѯ����[x,y]�����ұ߽�
{
	if (x <= l && r <= y)//�����ǰ�ڵ㱻������ֱ�ӷ��ص�ǰ�ڵ��ֵ
		return minNum[p];
	checkDelay(l, r, p);
	int mid = (l + r) / 2;
	int mn = 0;
	if (x <= mid)//�м�ֵ���ڵ�����߽磬��ʾ������Ҫ��ѯ
		mn = min(mn, getMin(x, y, l, mid, p * 2));
	if (mid < y)//�м�ֵС���ұ߽磬��ʾ�ұ߽���Ҫ��ѯ���������ʾû���Ұ����
		mn = min(mn,getMin(x, y, mid + 1, r, p * 2 + 1));
	return mn;
}

void changeNode(int pos, int v, int l, int r, int p)//posΪĿ��λ�ã�vΪĿ��ֵ
{
	if (l == r)
	{
		sum[p] = v;
		return;
	}
	int mid = (l + r) / 2;
	if (pos <= mid)//pos��������
		changeNode(pos, v, l, mid, p * 2);
	else//pos��������
		changeNode(pos, v, mid + 1, r, p * 2 + 1);
	sum[p] = sum[p * 2] + sum[p * 2 + 1];//�ݹ���ݸ���
}

void changeInterval(int x, int y, int v, int l, int r, int p)
{
	if (x <= l && r <= y)
	{
		tag[p] = v;
		sum[p] = v * (r - l + 1);
		return;
	}
	checkDelay(l, r, p);
	int mid = (l + r) / 2;
	if (x <= mid)
		changeInterval(x, y, v, l, mid, p * 2);
	if (mid <= y)
		changeInterval(x, y, v, mid + 1, r, p * 2 + 1);
	sum[p] = sum[p * 2] + sum[p * 2 + 1];
}

void addInterval(int x, int y, int v, int l, int r, int p)
{
	if (x <= l && r <= y)
	{
		tag[p] += v;
		sum[p] += v * (r - l + 1);
		return;
	}
	checkDelay(l, r, p, '+');
	int mid = (l + r) / 2;
	if (x <= mid)
		addInterval(x, y, v, l, mid, p * 2);
	if (mid <= y)
		addInterval(x, y, v, mid + 1, r, p * 2 + 1);
	sum[p] = sum[p * 2] + sum[p * 2 + 1];
}

int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> nums[i];
	}
	build(1, n, 1);
	return 0;
}