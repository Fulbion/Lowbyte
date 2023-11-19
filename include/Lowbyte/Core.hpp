#pragma once

#ifdef LB_PLATFORM_WINDOWS
#ifdef LB_BUILD_DLL
#define LOWBYTE_API __declspec(dllexport)
#else
#define LOWBYTE_API __declspec(dllimport)
#endif // LB_BUILD_DLL
#else
#error Lowbyte exclusively supports Windows...
#endif // LB_PLATFORM_WINDOWS

#define BIT(k) (1 << k)
