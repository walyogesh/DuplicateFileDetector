#include "FileUtils.h"
#include "CommandLineOptions.h"
#include <fstream>
#include <string.h>
#include <string>
#include <map>

#define FILE_TYPE_CPP ".cpp"
#define FILE_TYPE_C ".c"
#define FILE_TYPE_H ".h"
#define FILE_TYPE_RC ".rc"

namespace FileUtils
{
    bool IsValidFileType(std::string const& filename)
    {
        if (IsStringEndsWith(filename, FILE_TYPE_CPP)  || IsStringEndsWith(filename, FILE_TYPE_C)
            || IsStringEndsWith(filename, FILE_TYPE_H) || IsStringEndsWith(filename, FILE_TYPE_RC))
        {
            return true;
        }
        return false;
    }
    
    bool IsStringStartsWith(std::string const& filename, std::string const & starting)
    {
        if (starting.size() > filename.size()) return false;
        return std::equal(starting.begin(), starting.end(), filename.begin());
    }

    bool IsStringEndsWith(std::string const& filename, std::string const & ending)
    {
        if (ending.size() > filename.size()) return false;
        return std::equal(ending.rbegin(), ending.rend(), filename.rbegin());
    }

    std::uintmax_t GetFileSize(const fs::path& fullFileName)
    {
        return fs::file_size(fullFileName);
    }

    bool IsFileContentSame(const fs::path& file1, const fs::path& file2)
    {
        if (GetFileSize(file1) != GetFileSize(file2))
           return false;

        /*//Note : This is another way of reading whole file in one go and then comapring them 
        std::ifstream infile1{ file1 };
        std::string file_contents1{ std::istreambuf_iterator<char>(infile1), std::istreambuf_iterator<char>() };
        std::ifstream infile2{ file2 };
        std::string file_contents2{ std::istreambuf_iterator<char>(infile2), std::istreambuf_iterator<char>() };
        return file_contents1 == file_contents2;*/

        std::ifstream infile1{ file1 };
        std::ifstream infile2{ file2 };
        char f1[500], f2[256];
        while (!(infile1.eof() || infile2.eof()))
        {
            infile1.getline(f1, 256);
            infile1.getline(f2, 256);
            if (strcmp(f1, f2) != 0)
            {
                return false;
            }
        }
        return true;
    }

    void FileDirectory::CreateFileDirectory()
    {
        if (fs::is_directory(m_Path))
        {
            for (auto const& directoryEntry : fs::recursive_directory_iterator(m_Path))
            {
                if (fs::is_regular_file(directoryEntry))
                {
                    std::string const& filepath = (directoryEntry).path().parent_path().string();
                    std::string const& filename = (directoryEntry).path().filename().string();

                    if (IsValidFileType(filename))
                    {
                        std::set<fs::path>& path = m_FileDirectory[filename];
                        path.insert(filepath);
                    }
                }
            }
        }
    }

    void FileDirectory::ProcessFileDirectory()
    {
        for (auto const& dirEntry : m_FileDirectory)
        {
            auto & files = m_OutputFileDirectory[dirEntry.second];
            files.push_back(dirEntry.first);
        }
        if (m_DeveloperOption == DeveloperOption::Extended)
        {
            for (const auto& i : m_OutputFileDirectory)
            {
                for (const auto& j : i.second) //file name vector<filename>
                {
                    for (const auto& k : i.first)//parent path set<path>
                    {
                        if (i.first.size() < 2) // if file is not  present at multiple paths 
                            break;

                        auto const& fullFilePath = std::string(k.string()+"\\"+j);
                        /*
                        1. add same file name paths into vector< vector<fullfilename> >
                        2. comapre a file size with another same name files
                        3. if size is different then remove thier entry from m_OutputFileDirectory 
                            and add 2 seperate  entries into another container (unordered map) 
                        4. if file size are same then comapre thier content and seperate the entries if file content mismatches
                        Complexity: n X n 
                        */ 
                    }
                }
            }
        }
    }

    void FileDirectory::OutputFileDirectory() const
    {
        //displays the output as per required fashion. we write the output in Output.txt file.
        std::ofstream outputStream("Output.txt");

        for (auto const& i : m_OutputFileDirectory)
        {
            for (const auto& dir : i.first) // displays directories    
            {
                std::cout << dir << std::endl;
                outputStream << dir << std::endl;
            }
            std::cout << "---------------------------------------------------------\n";
            outputStream << "---------------------------------------------------------\n";
            for (const auto& file : i.second) //displays comman files for above directories 
            {
                std::cout << file <<std::endl;
                outputStream << file << std::endl;//we can also print size of the file along with name
            }
            std::cout << std::endl;
            outputStream << std::endl;
        }
        outputStream.close();
    }
}//Namespace FileUtils end