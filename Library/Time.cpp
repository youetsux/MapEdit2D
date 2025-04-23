#include "time.h"
#include <Windows.h>

namespace {
	LARGE_INTEGER freq;
	LARGE_INTEGER current;
	float deltaTime;
};
void Time::Init()
{
	QueryPerformanceFrequency(&freq);
	QueryPerformanceCounter(&current);
}

void Time::Refresh()
{
	LARGE_INTEGER last = current;
	QueryPerformanceCounter(&current);
	deltaTime = static_cast<float >(current.QuadPart - last.QuadPart) / freq.QuadPart;
}

float Time::DeltaTime()
{
	return deltaTime;
}
