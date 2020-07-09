#include "FileUtils.h"
#include "CommandLineOptions.h"
#include "Profiler.h"

int main(int argc, char *argv[])
{
    try
    {
        CommandLineOptions options(argc, argv);
        TimeProfiler profiler;
        FileUtils::FileDirectory fileHash(options.GetPath(), options.GetDeveloperOption() );
        fileHash.CreateFileDirectory();
        fileHash.ProcessFileDirectory();
        fileHash.OutputFileDirectory();
    }
    catch (const char* error)
    {
        std::cout <<"Error: "<< error;
        getchar(); //debug purpose only
        return -1; // we should return error codes
    }
    getchar(); //debug purpose only
    return 0;
}
