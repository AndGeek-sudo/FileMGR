#include <iostream>
#include <view/cli/windows.hpp>

WindowsCliView::WindowsCliView()
{
    system("chcp 65001 > nul");
}

void WindowsCliView::DisplayPaths(const std::string &name, const std::vector<std::filesystem::path> &paths) const
{
    std::cout << name << std::endl;

    if (paths.empty())
    {
        std::cout << "└── ... Пусто ..." << std::endl;
    }

    for (const std::filesystem::path &path : paths)
    {
        if (path == paths.back())
        {
            std::cout << "└── ";
        }
        else
        {
            std::cout << "├── ";
        }
        std::cout << path.filename().string() << std::endl;
    }
}