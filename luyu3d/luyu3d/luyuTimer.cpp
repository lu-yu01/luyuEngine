#include "luyuTimer.h"

using namespace std::chrono;

luyuTimer::luyuTimer()
{
    last = steady_clock::now();
}

float luyuTimer::Mark()
{
    const auto old = last;
    last = steady_clock::now();
    const duration<float> frameTime = last - old;
    return frameTime.count();
}

float luyuTimer::Peek() const
{
    return duration<float>(steady_clock::now() - last).count();
}