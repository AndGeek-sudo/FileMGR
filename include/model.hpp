#pragma once

#include <filesystem>
#include <string>
#include <vector>

class FileSystemModel
{
public:
    void MakeFile(const std::filesystem::path &path, const std::string &name);
    void MakeDirectory(const std::filesystem::path &path, const std::string &name);
    void RemoveByPath(const std::filesystem::path &path);
    void RenamePath(const std::filesystem::path &path, const std::string &name);
    void Copy(const std::filesystem::path &path, const std::filesystem::path &newPath);
    void Move(const std::filesystem::path &path, const std::filesystem::path &newPath);
    std::vector<std::filesystem::path> GetPaths(const std::filesystem::path &path) const;
    bool IsExists(const std::filesystem::path &path) const;
};