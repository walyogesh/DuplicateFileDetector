#pragma once
#include <vector>
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;

enum class DeveloperOption
{
    Basic = 0,
    Extended = 1
};

class CommandLineOptions
{
public:
    CommandLineOptions() = delete;
    CommandLineOptions(char argc, char** argv);
    inline fs::path GetPath() const { return m_Path; }
    inline DeveloperOption GetDeveloperOption() const { return m_DeveloperOption; }
    ~CommandLineOptions();
private:
    std::vector< std::string> m_ProgramOptions;
    fs::path m_Path;
    DeveloperOption m_DeveloperOption;

    void SetProgrammOptions();
};
