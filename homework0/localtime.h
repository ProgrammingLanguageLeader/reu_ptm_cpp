#pragma once

#include <ctime>


namespace crossPlatformTime {
	tm localtime(const std::time_t & time);
};