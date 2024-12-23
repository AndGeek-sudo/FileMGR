#pragma once

#include <view.hpp>

class LinuxCliView : public View
{
public:
    void DisplayPaths(const std::string &name, const std::vector<std::filesystem::path> &paths) const override;
};