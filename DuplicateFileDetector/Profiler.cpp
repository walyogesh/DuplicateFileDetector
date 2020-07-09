#include "Profiler.h"
#include <iostream>

TimeProfiler::TimeProfiler(std::string const& FunctionName /*="Function"*/)
    : m_FunctionName(FunctionName)
    , m_StartTime(std::chrono::high_resolution_clock::now())
{
}
   

TimeProfiler::~TimeProfiler()
{
    auto endtime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(endtime - m_StartTime);
    std::cout<< m_FunctionName << " took "<< duration.count() <<" seconds."<<std::endl;
}
