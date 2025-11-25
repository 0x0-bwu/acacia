#pragma once
#ifndef ACACIA_CURRENT_CXX_VERSION
    #define ACACIA_CURRENT_CXX_VERSION 23
#endif

#ifndef ACACIA_CURRENT_BOOST_LIBRARY_VER
    #define ACACIA_CURRENT_BOOST_LIBRARY_VER 183
#endif

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    #define ACACIA_OS_WINDOWS
        #ifdef __WIN64
            #define ACACIA_OS_WINDOWS_64
        #else
            #define ACACIA_OS_WINDOWS_32
        #endif
#elif defined(__APPLE__)
    #include <TargetConditionals.h>
    #if TARGET_OS_MAC
        #define ACACIA_OS_MAC
    #endif
#else
    #define ACACIA_OS_LINUX
#endif

#ifdef ACACIA_OS_WINDOWS
    #define ACACIA_LIKELY(EXP)   (EXP)
    #define ACACIA_UNLIKELY(EXP) (EXP)
#else
    #define ACACIA_LIKELY(EXP)   __builtin_expect(!!(EXP), 1)
    #define ACACIA_UNLIKELY(EXP) __builtin_expect(!!(EXP), 0)
#endif
