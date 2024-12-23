#include <iostream>
#include <view/cli/linux.hpp>

void LinuxCliView::DisplayPaths(const std::string &name, const std::vector<std::filesystem::path> &paths) const
{
    std::cout << "\033[32m" << name << "\033[0m" << std::endl;

    if (paths.empty())
    {
        std::cout << "\033[32m└── ... Пусто ...\033[0m" << std::endl;
    }

    for (const std::filesystem::path &path : paths)
    {
        if (std::filesystem::is_directory(path))
        {
            std::cout << "\033[32m";
        }
        else
        {
            std::cout << "\033[34m";
        }

        if (path == paths.back())
        {
            std::cout << "└── ";
        }
        else
        {
            std::cout << "├── ";
        }

        std::cout << path.filename().string() << "\033[0m" << std::endl;
    }
}