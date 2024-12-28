/*
 * Copyright 2013, 2017 Andrey Semashev
 * Copyright 2017 James E. King, III
 *
 * Distributed under the Boost Software License, Version 1.0.
 * See http://www.boost.org/LICENSE_1_0.txt
 */

#ifndef BOOST_WINAPI_CONFIG_HPP_INCLUDED_
#define BOOST_WINAPI_CONFIG_HPP_INCLUDED_

#include <boost/predef/version_number.h>
#include <boost/predef/platform.h>
#if defined(__CYGWIN__)
// Cygwin 64 compiler does not define _WIN64 and instead defines it in a private header. We can't define _WIN64 ourselves because
// the header defines the macro unconditionally and if the user includes both Boost.WinAPI and Cygwin WinAPI headers there will be conflict.
#include <_cygwin.h>
#endif
#if defined(__MINGW32__)
// MinGW and MinGW-w64 define __MINGW32_VERSION_MAJOR/MINOR and __MINGW64_VERSION_MAJOR/MINOR macros in a private header.
#include <_mingw.h>
#endif

// BOOST_WINAPI_IS_MINGW indicates that the target Windows SDK is provided by MinGW (http://mingw.org/).
// BOOST_WINAPI_IS_MINGW_W64 indicates that the target Windows SDK is provided by MinGW-w64 (http://mingw-w64.org).
// BOOST_WINAPI_IS_CYGWIN indicates that the target Windows SDK is provided by MinGW variant from Cygwin (https://cygwin.com/).
#if defined(__CYGWIN__)
#define BOOST_WINAPI_IS_CYGWIN
#elif BOOST_PLAT_MINGW
#if defined(__MINGW64_VERSION_MAJOR)
#define BOOST_WINAPI_IS_MINGW_W64
#else
#define BOOST_WINAPI_IS_MINGW
#endif
#endif

// These constants reflect _WIN32_WINNT_* macros from sdkddkver.h
// See also: http://msdn.microsoft.com/en-us/library/windows/desktop/aa383745%28v=vs.85%29.aspx#setting_winver_or__win32_winnt
#define BOOST_WINAPI_VERSION_NT4 0x0400
#define BOOST_WINAPI_VERSION_WIN2K 0x0500
#define BOOST_WINAPI_VERSION_WINXP 0x0501
#define BOOST_WINAPI_VERSION_WS03 0x0502
#define BOOST_WINAPI_VERSION_WIN6 0x0600
#define BOOST_WINAPI_VERSION_VISTA 0x0600
#define BOOST_WINAPI_VERSION_WS08 0x0600
#define BOOST_WINAPI_VERSION_LONGHORN 0x0600
#define BOOST_WINAPI_VERSION_WIN7 0x0601
#define BOOST_WINAPI_VERSION_WIN8 0x0602
#define BOOST_WINAPI_VERSION_WINBLUE 0x0603
#define BOOST_WINAPI_VERSION_WINTHRESHOLD 0x0A00
#define BOOST_WINAPI_VERSION_WIN10 0x0A00

// These constants reflect NTDDI_* macros from sdkddkver.h
#define BOOST_WINAPI_NTDDI_WIN2K 0x05000000
#define BOOST_WINAPI_NTDDI_WIN2KSP1 0x05000100
#define BOOST_WINAPI_NTDDI_WIN2KSP2 0x05000200
#define BOOST_WINAPI_NTDDI_WIN2KSP3 0x05000300
#define BOOST_WINAPI_NTDDI_WIN2KSP4 0x05000400

#define BOOST_WINAPI_NTDDI_WINXP 0x05010000
#define BOOST_WINAPI_NTDDI_WINXPSP1 0x05010100
#define BOOST_WINAPI_NTDDI_WINXPSP2 0x05010200
#define BOOST_WINAPI_NTDDI_WINXPSP3 0x05010300
#define BOOST_WINAPI_NTDDI_WINXPSP4 0x05010400

#define BOOST_WINAPI_NTDDI_WS03 0x05020000
#define BOOST_WINAPI_NTDDI_WS03SP1 0x05020100
#define BOOST_WINAPI_NTDDI_WS03SP2 0x05020200
#define BOOST_WINAPI_NTDDI_WS03SP3 0x05020300
#define BOOST_WINAPI_NTDDI_WS03SP4 0x05020400

#define BOOST_WINAPI_NTDDI_WIN6 0x06000000
#define BOOST_WINAPI_NTDDI_WIN6SP1 0x06000100
#define BOOST_WINAPI_NTDDI_WIN6SP2 0x06000200
#define BOOST_WINAPI_NTDDI_WIN6SP3 0x06000300
#define BOOST_WINAPI_NTDDI_WIN6SP4 0x06000400

#define BOOST_WINAPI_NTDDI_VISTA BOOST_WINAPI_NTDDI_WIN6
#define BOOST_WINAPI_NTDDI_VISTASP1 BOOST_WINAPI_NTDDI_WIN6SP1
#define BOOST_WINAPI_NTDDI_VISTASP2 BOOST_WINAPI_NTDDI_WIN6SP2
#define BOOST_WINAPI_NTDDI_VISTASP3 BOOST_WINAPI_NTDDI_WIN6SP3
#define BOOST_WINAPI_NTDDI_VISTASP4 BOOST_WINAPI_NTDDI_WIN6SP4

#define BOOST_WINAPI_NTDDI_LONGHORN  BOOST_WINAPI_NTDDI_VISTA

#define BOOST_WINAPI_NTDDI_WS08 BOOST_WINAPI_NTDDI_WIN6SP1
#define BOOST_WINAPI_NTDDI_WS08SP2 BOOST_WINAPI_NTDDI_WIN6SP2
#define BOOST_WINAPI_NTDDI_WS08SP3 BOOST_WINAPI_NTDDI_WIN6SP3
#define BOOST_WINAPI_NTDDI_WS08SP4 BOOST_WINAPI_NTDDI_WIN6SP4

#define BOOST_WINAPI_NTDDI_WIN7 0x06010000
#define BOOST_WINAPI_NTDDI_WIN7SP1 0x06010100 // Not defined in Windows SDK
#define BOOST_WINAPI_NTDDI_WIN8 0x06020000
#define BOOST_WINAPI_NTDDI_WINBLUE 0x06030000
#define BOOST_WINAPI_NTDDI_WINTHRESHOLD 0x0A000000
#define BOOST_WINAPI_NTDDI_WIN10 0x0A000000
#define BOOST_WINAPI_NTDDI_WIN10_TH2 0x0A000001
#define BOOST_WINAPI_NTDDI_WIN10_RS1 0x0A000002
#define BOOST_WINAPI_NTDDI_WIN10_RS2 0x0A000003
#define BOOST_WINAPI_NTDDI_WIN10_RS3 0x0A000004

#define BOOST_WINAPI_DETAIL_MAKE_NTDDI_VERSION2(x) x##0000
#define BOOST_WINAPI_DETAIL_MAKE_NTDDI_VERSION(x) BOOST_WINAPI_DETAIL_MAKE_NTDDI_VERSION2(x)

#if !defined(BOOST_USE_WINAPI_VERSION)
#if defined(_WIN32_WINNT)
#define BOOST_USE_WINAPI_VERSION _WIN32_WINNT
#elif defined(WINVER)
#define BOOST_USE_WINAPI_VERSION WINVER
#else
// By default use Windows 10 API on compilers that support it and latest versions on the others
#if (defined(_MSC_VER) && _MSC_VER < 1500) || defined(BOOST_WINAPI_IS_MINGW)
#define BOOST_USE_WINAPI_VERSION BOOST_WINAPI_VERSION_WINXP
#elif (defined(_MSC_VER) && _MSC_VER < 1600)
#define BOOST_USE_WINAPI_VERSION BOOST_WINAPI_VERSION_WIN6
#elif (defined(_MSC_VER) && _MSC_VER < 1700)
#define BOOST_USE_WINAPI_VERSION BOOST_WINAPI_VERSION_WIN7
#elif (defined(_MSC_VER) && _MSC_VER < 1800)
#define BOOST_USE_WINAPI_VERSION BOOST_WINAPI_VERSION_WIN8
#elif (defined(_MSC_VER) && _MSC_VER < 1900)
#define BOOST_USE_WINAPI_VERSION BOOST_WINAPI_VERSION_WINBLUE
#else
#define BOOST_USE_WINAPI_VERSION BOOST_WINAPI_VERSION_WIN10
#endif
#endif
#endif

#if !defined(BOOST_USE_NTDDI_VERSION)
#if defined(NTDDI_VERSION)
#define BOOST_USE_NTDDI_VERSION NTDDI_VERSION
// Default to respective Windows version with the latest Service Pack
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WIN2K
#define BOOST_USE_NTDDI_VERSION BOOST_WINAPI_NTDDI_WIN2KSP4
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WINXP
#define BOOST_USE_NTDDI_VERSION BOOST_WINAPI_NTDDI_WINXPSP3
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WS03
#define BOOST_USE_NTDDI_VERSION BOOST_WINAPI_NTDDI_WS03SP2
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WIN6
#define BOOST_USE_NTDDI_VERSION BOOST_WINAPI_NTDDI_WIN6SP2
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WIN7
#define BOOST_USE_NTDDI_VERSION BOOST_WINAPI_NTDDI_WIN7SP1
#elif BOOST_USE_WINAPI_VERSION == BOOST_WINAPI_VERSION_WIN10
#define BOOST_USE_NTDDI_VERSION BOOST_WINAPI_NTDDI_WIN10_RS3
#else
#define BOOST_USE_NTDDI_VERSION BOOST_WINAPI_DETAIL_MAKE_NTDDI_VERSION(BOOST_USE_WINAPI_VERSION)
#endif
#endif

// Known Windows SDK versions, taken from VER_PRODUCTBUILD macro value defined in ntverp.h.
// These values can be used to compare with BOOST_PLAT_WINDOWS_SDK_VERSION from Boost.Predef.
#define BOOST_WINAPI_WINDOWS_SDK_MSVC71 BOOST_VERSION_NUMBER(0, 0, 3668) // Windows SDK bundled with MSVC 7.1
#define BOOST_WINAPI_WINDOWS_SDK_MSVC8 BOOST_VERSION_NUMBER(0, 0, 3790) // Windows SDK bundled with MSVC 8
#define BOOST_WINAPI_WINDOWS_SDK_6_0 BOOST_VERSION_NUMBER(0, 0, 6000) // Windows SDK 6.0
#define BOOST_WINAPI_WINDOWS_SDK_7_0 BOOST_VERSION_NUMBER(0, 0, 7600) // Windows SDK 7.0, 7.1
#define BOOST_WINAPI_WINDOWS_SDK_8_0 BOOST_VERSION_NUMBER(0, 0, 9200) // Windows SDK 8.0
#define BOOST_WINAPI_WINDOWS_SDK_8_1 BOOST_VERSION_NUMBER(0, 0, 9600) // Windows SDK 8.1
#define BOOST_WINAPI_WINDOWS_SDK_10_0 BOOST_VERSION_NUMBER(0, 0, 10011) // Windows SDK 10.0
// MinGW does not have the ntverp.h header but it defines VER_PRODUCTBUILD in ddk/ntifs.h.
// Cygwin MinGW also defines this version.
#define BOOST_WINAPI_WINDOWS_SDK_MINGW BOOST_VERSION_NUMBER(0, 0, 10000)
// MinGW-w64 defines the same version as the Windows SDK bundled with MSVC 8
#define BOOST_WINAPI_WINDOWS_SDK_MINGW_W64 BOOST_VERSION_NUMBER(0, 0, 3790)

#if !defined(BOOST_USE_WINAPI_FAMILY)
#if defined(WINAPI_FAMILY)
#define BOOST_USE_WINAPI_FAMILY WINAPI_FAMILY
#elif defined(WINAPI_FAMILY_DESKTOP_APP)
// If none is specified, default to a desktop application which is the most
// backwards compatible to previous ways of doing things, if families are even
// defined.
#define BOOST_USE_WINAPI_FAMILY WINAPI_FAMILY_DESKTOP_APP
#endif
#endif

//
// UWP Support
//
// On platforms without windows family partition support it is assumed one
// has all APIs and access is controlled by _WIN32_WINNT or similar mechanisms.
//
// Leveraging Boost.Predef here
//
#if BOOST_PLAT_WINDOWS_UWP
#define BOOST_WINAPI_PARTITION_APP           (BOOST_PLAT_WINDOWS_DESKTOP || BOOST_PLAT_WINDOWS_STORE || BOOST_WINAPI_PARTITION_PHONE)
#define BOOST_WINAPI_PARTITION_PC            (BOOST_PLAT_WINDOWS_STORE)
#define BOOST_WINAPI_PARTITION_PHONE         (BOOST_PLAT_WINDOWS_PHONE)
#define BOOST_WINAPI_PARTITION_SYSTEM        (BOOST_PLAT_WINDOWS_SYSTEM)
#define BOOST_WINAPI_PARTITION_SERVER        (BOOST_PLAT_WINDOWS_SERVER)
#define BOOST_WINAPI_PARTITION_DESKTOP       (BOOST_PLAT_WINDOWS_DESKTOP)
#else // BOOST_PLAT_WINDOWS_UWP
#define BOOST_WINAPI_PARTITION_APP           (1)
#define BOOST_WINAPI_PARTITION_PC            (1)
#define BOOST_WINAPI_PARTITION_PHONE         (1)
#define BOOST_WINAPI_PARTITION_SYSTEM        (1)
#define BOOST_WINAPI_PARTITION_SERVER        (1)
#define BOOST_WINAPI_PARTITION_DESKTOP       (1)
#endif // BOOST_PLAT_WINDOWS_UWP

//
// Windows 8.x SDK defines some items in the DESKTOP partition and then Windows SDK 10.0 defines
// the same items to be in APP or SYSTEM partitions, and APP expands to DESKTOP or PC or PHONE.
// The definition of BOOST_WINAPI_PARTITION_APP_SYSTEM provides a universal way to get this
// right as it is seen in a number of places in the SDK.
//
#define BOOST_WINAPI_PARTITION_APP_SYSTEM \
    ( \
        ((BOOST_PLAT_WINDOWS_SDK_VERSION >= BOOST_WINAPI_WINDOWS_SDK_10_0) && (BOOST_WINAPI_PARTITION_APP || BOOST_WINAPI_PARTITION_SYSTEM)) || \
        ((BOOST_PLAT_WINDOWS_SDK_VERSION < BOOST_WINAPI_WINDOWS_SDK_10_0) && BOOST_WINAPI_PARTITION_DESKTOP) \
    )

// Simiarly, some other symbols were re-classified as DESKTOP or SYSTEM
#define BOOST_WINAPI_PARTITION_DESKTOP_SYSTEM \
    ( \
        ((BOOST_PLAT_WINDOWS_SDK_VERSION >= BOOST_WINAPI_WINDOWS_SDK_10_0) && (BOOST_WINAPI_PARTITION_DESKTOP || BOOST_WINAPI_PARTITION_SYSTEM)) || \
        ((BOOST_PLAT_WINDOWS_SDK_VERSION < BOOST_WINAPI_WINDOWS_SDK_10_0) && BOOST_WINAPI_PARTITION_DESKTOP) \
    )

#if defined(BOOST_USE_WINDOWS_H) || defined(BOOST_WINAPI_DEFINE_VERSION_MACROS)
// We have to define the version macros so that windows.h provides the necessary symbols
#if !defined(_WIN32_WINNT)
#define _WIN32_WINNT BOOST_USE_WINAPI_VERSION
#endif
#if !defined(WINVER)
#define WINVER BOOST_USE_WINAPI_VERSION
#endif
#if !defined(NTDDI_VERSION)
#define NTDDI_VERSION BOOST_USE_NTDDI_VERSION
#endif
#if !defined(WINAPI_FAMILY) && defined(BOOST_USE_WINAPI_FAMILY)
#define WINAPI_FAMILY BOOST_USE_WINAPI_FAMILY
#endif
#endif

#if defined (WIN32_PLATFORM_PSPC)
#define BOOST_WINAPI_IMPORT BOOST_SYMBOL_IMPORT
#define BOOST_WINAPI_IMPORT_EXCEPT_WM
#elif defined (_WIN32_WCE)
#define BOOST_WINAPI_IMPORT
#define BOOST_WINAPI_IMPORT_EXCEPT_WM
#else
#define BOOST_WINAPI_IMPORT BOOST_SYMBOL_IMPORT
#define BOOST_WINAPI_IMPORT_EXCEPT_WM BOOST_SYMBOL_IMPORT
#endif

#include <boost/config.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#endif // BOOST_WINAPI_CONFIG_HPP_INCLUDED_
