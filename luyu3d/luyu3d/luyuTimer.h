#pragma once
#include <chrono>

class luyuTimer
{
public:
	luyuTimer();
	float Mark();
	float Peek() const;

private:
	std::chrono::steady_clock::time_point last;
};


