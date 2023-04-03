#include"game.h"
void move(double& x, double& y, double speed, double time)
{
	const double g = 9.8; // �������ٶ�
	const double k = 0.1; // ��������ϵ��
	double vx = speed; // ˮƽ�ٶ�
	double vy = 0.0; // ��ֱ�ٶ�

	while (time > 0.0)
	{
		double dt = std::min(0.01, time); // ʱ�䲽��
		double ax = -k * vx * vx; // ˮƽ���ٶȣ�����������
		double ay = -g - k * vy * vy; // ��ֱ���ٶȣ������Ϳ���������

		vx += ax * dt; // �����µ�ˮƽ�ٶ�
		vy += ay * dt; // �����µĴ�ֱ�ٶ�
		x += vx * dt; // �����µ�ˮƽλ��
		y += vy * dt; // �����µĴ�ֱλ��
		time -= dt; // ����ʣ��ʱ��
	}
}
int main()
{
	Entity e(1, "zhang", 0, 0);
	return 0;
}