#include<iostream>

class Log
{
public:
	void SetLevel(int level)
	{
		m_LogLevel = level;
	};
	void Error(const char* message)
	{
		if (m_LogLevel >= LogLevelError)
			std::cout << "[ERROR]" << message << std::endl;
	};
	void Warn(const char* message)
	{
		if (m_LogLevel >= LogLevelWarning)
			std::cout << "[WARNING]" << message << std::endl;
	};
	void Infor(const char* message)
	{
		if (m_LogLevel >= LogLevelInfor)
			std::cout << "[INFOR]" << message << std::endl;
	};
public:
	const int LogLevelError = 0;
	const int LogLevelWarning = 1;
	const int LogLevelInfor = 2;
private:
	int m_LogLevel=LogLevelInfor;
};
int main()
{
	Log log;
	log.SetLevel(log.LogLevelWarning);
	log.Error("System Error!");
	log.Warn("System Warning!");
	log.Infor("System Information");
	std::cin.get();
	return 0;
}