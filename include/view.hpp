#pragma once

#include <vector>
#include <filesystem>

class View 
{
public:
    virtual void DisplayPaths(const std::string& name, const std::vector<std::filesystem::path>& paths) const = 0;
};