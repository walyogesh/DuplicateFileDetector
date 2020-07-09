#pragma once
#include <string>
#include <chrono>

class TimeProfiler
{
public:
    TimeProfiler(std::string const& FunctionName = "Operation");
    ~TimeProfiler();
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
    std::string m_FunctionName;
};

