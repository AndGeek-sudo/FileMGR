#pragma once

#include <view.hpp>

class WindowsCliView : public View
{
public:
    WindowsCliView();
    void DisplayPaths(const std::string &name, const std::vector<std::filesystem::path> &paths) const override;
};