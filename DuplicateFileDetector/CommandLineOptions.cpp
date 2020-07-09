#include "CommandLineOptions.h"
#include "FileUtils.h"

#define DEVLOPER_OPTION_EXTENDED "extended"

CommandLineOptions::CommandLineOptions(char argc, char ** argv)
{
    m_Path = "."; //default directory is current directory
    m_DeveloperOption = DeveloperOption::Basic; //checks duplication only with file name and not content
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            if (argv[i][0] == '/')
            {
                m_ProgramOptions.push_back(argv[i]);
            }
        }
        SetProgrammOptions();
    }
}

void CommandLineOptions::SetProgrammOptions()
{
    for (auto const & option : m_ProgramOptions)
    {
        if (FileUtils::IsStringStartsWith(option, "/path:"))
        {
            m_Path = std::move(option.substr(6,option.length()-1));
            if (!exists(m_Path))
            {
                throw ("Given Path is Invalid..!\n");
            }
        }
        else if (FileUtils::IsStringStartsWith(option, "/developerMode:"))//can use #define macro
        {
           std::string const& developerOption = option.substr(14, option.length() - 1);

           m_DeveloperOption = developerOption == DEVLOPER_OPTION_EXTENDED ? DeveloperOption::Extended : DeveloperOption::Basic;
           std::cout<<"Developer Option Mode : "<< (int)m_DeveloperOption;
        }
    }
}

CommandLineOptions::~CommandLineOptions()
{
    m_ProgramOptions.clear();
}
