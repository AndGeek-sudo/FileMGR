#include <algorithm>
#include <fstream>
#include <model.hpp>

void FileSystemModel::MakeFile(const std::filesystem::path &path, const std::string &name)
{
    std::ofstream file(path / name);

    if (!file.is_open())
    {
        throw std::runtime_error("Failed to create file");
    }
    file.close();
}

void FileSystemModel::MakeDirectory(const std::filesystem::path &path, const std::string &name)
{
    if (!std::filesystem::create_directory(path / name))
    {
        throw std::runtime_error("Failed to create directory");
    }
}

void FileSystemModel::RemoveByPath(const std::filesystem::path &path)
{
    std::filesystem::remove_all(path);
}

void FileSystemModel::RenamePath(const std::filesystem::path &path, const std::string &name)
{
    std::filesystem::rename(path, path.parent_path() / name);
}

void FileSystemModel::Copy(const std::filesystem::path &path, const std::filesystem::path &newPath)
{
    std::filesystem::copy(path, newPath, std::filesystem::copy_options::recursive);
}

void FileSystemModel::Move(const std::filesystem::path &path, const std::filesystem::path &newPath)
{
    std::filesystem::rename(path, newPath);
}

std::vector<std::filesystem::path> FileSystemModel::GetPaths(const std::filesystem::path &path) const
{
    if (!std::filesystem::is_directory(path))
    {
        throw std::runtime_error("Path is not a directory");
    }

    std::vector<std::filesystem::path> files;

    for (const auto &entry : std::filesystem::directory_iterator(path))
    {
        files.push_back(entry.path());
    }

    std::sort(files.begin(), files.end(), [](const auto &first, const auto &second) {
        return std::filesystem::is_directory(first) && !std::filesystem::is_directory(second);
    });

    return files;
}

bool FileSystemModel::IsExists(const std::filesystem::path &path) const
{
    return std::filesystem::exists(path);
}