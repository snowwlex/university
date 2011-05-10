
#ifndef EXCEPTION_HANDLING_H
#define EXCEPTION_HANDLING_H

// Here we define a set of macros, used to catch different types
// îf exceptions and aquire additional information.
// All these macros ought to be used inside methods of Test class.
//
// This header depends on the following "defines":
//   CATCH_STD_EXCEPTIONS     - enables catching and decoding descendants 
//                              of std::exception
//   CATCH_BORLAND_EXCEPTIONS - enables catching and decoding descendants
//                              of Borland's Exception
//   CATCH_SYSTEM_EXCEPTIONS  - enables catching and decoding structured
//                              C windows exceptions
//
// All the exception decoders assume that a variable "result" of type 
// TestResult is reachable.
// Catchers are used solely inside Test::run() function.
//                 

#ifdef CATCH_STD_EXCEPTIONS
#include <exception>
#endif // CATCH_STD_EXCEPTIONS

#ifdef CATCH_BORLAND_EXCEPTIONS
#include <SysUtils.hpp>
#endif // CATCH_BORLAND_EXCEPTIONS

#ifdef CATCH_SYSTEM_EXCEPTIONS
// For structured C exception handling
#include <Windows.h>
#include <excpt.h>
// For throwing std::runtime_error()
#include <stdexcept>
#endif // CATCH_SYSTEM_EXCEPTIONS

// CATCH_STD_EXCEPTIONS symbol enables catching and decoding
//    of std::exception
#ifdef CATCH_STD_EXCEPTIONS

#define STD_CATCHER \
        } catch (std::exception& e) { \
                result.addFailure (Failure (e.what(), name, __FILE__, __LINE__)); \
         \

#else
#define STD_CATCHER
#endif // CATCH_STD_EXCEPTIONS


// CATCH_BORLAND_EXCEPTIONS symbol disables catching and decoding
//    Borland C++Builder Exception

#ifdef CATCH_BORLAND_EXCEPTIONS

#define BORLAND_CATCHER \
        } catch (Exception& e) { \
                result.addFailure (Failure (e.Message.c_str(), name, __FILE__, __LINE__)); \
         \

#else
#define BORLAND_CATCHER
#endif // CATCH_BORLAND_EXCEPTIONS


// All the additional cathers. If you defined some - add it here.
// Sequence DOES matter.

#define SPECIAL_CATCHERS \
        STD_CATCHER \
        BORLAND_CATCHER \


//////////////////////////////////////////////////////////////////////////
//
// Win32 (and Borland C++ Builder) specific code to catch system exceptions.
//
//////////////////////////////////////////////////////////////////////////

#ifdef CATCH_SYSTEM_EXCEPTIONS

// All the system exceptions are rethrown as standard ones, so you
// SHOULDN'T use system exception processing without standard exception
// processing.

#ifndef CATCH_STD_EXCEPTIONS
#error "Can't catch system exceptions without standard. Enable CATCH_STD_EXCEPTIONS"
#endif // CATCH_STD_EXCEPTIONS

extern int xfilter(EXCEPTION_POINTERS *xp);

#define S_TRY_BEGIN \
        EXCEPTION_POINTERS *xp; \
	try { \

#define S_TRY_END \
        } __except (xfilter(xp = GetExceptionInformation())) { \
        } \

#else  // if CATCH_SYSTEM_EXCEPTIONS isn't defined

#define S_TRY_BEGIN
#define S_TRY_END

#endif // CATCH_SYSTEM_EXCEPTIONS

#endif  // guard
