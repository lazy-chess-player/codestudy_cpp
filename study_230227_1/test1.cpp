#include"game.h"
void move(double& x, double& y, double speed, double time)
{
	const double g = 9.8; // 重力加速度
	const double k = 0.1; // 空气阻力系数
	double vx = speed; // 水平速度
	double vy = 0.0; // 垂直速度

	while (time > 0.0)
	{
		double dt = std::min(0.01, time); // 时间步长
		double ax = -k * vx * vx; // 水平加速度（空气阻力）
		double ay = -g - k * vy * vy; // 垂直加速度（重力和空气阻力）

		vx += ax * dt; // 计算新的水平速度
		vy += ay * dt; // 计算新的垂直速度
		x += vx * dt; // 计算新的水平位置
		y += vy * dt; // 计算新的垂直位置
		time -= dt; // 更新剩余时间
	}
}
int main()
{
	Entity e(1, "zhang", 0, 0);
	return 0;
}