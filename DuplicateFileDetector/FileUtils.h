#pragma once
#include "CommandLineOptions.h"
#include <experimental/filesystem>
#include <iostream>
#include <unordered_map>
#include <set>
#include <map>
namespace fs = std::experimental::filesystem;
namespace FileUtils 
{
bool IsStringStartsWith(std::string const& filename, std::string const & starting) ;
bool IsStringEndsWith(std::string const& filename, std::string const & ending) ;
std::uintmax_t GetFileSize(const fs::path& fullfileName);
bool IsFileContentSame(const fs::path& file1, const fs::path& file2);
class FileDirectory
{
public:
    FileDirectory(fs::path path, DeveloperOption devloperOption)
        : m_Path(path)
        , m_DeveloperOption(devloperOption)
    {
    }

    ~FileDirectory()
    {
        m_FileDirectory.clear();
        m_OutputFileDirectory.clear();
    }

    void CreateFileDirectory();
    void ProcessFileDirectory();
    void OutputFileDirectory() const;
private:
    const fs::path  m_Path;
    DeveloperOption m_DeveloperOption;
    std::unordered_map<std::string, std::set<fs::path> > m_FileDirectory; // map of fileName as a key , its available path as a value
    std::map<std::set<fs::path>, std::vector<std::string>> m_OutputFileDirectory;//path as a key with associated files are values 
};
}//namespace end

