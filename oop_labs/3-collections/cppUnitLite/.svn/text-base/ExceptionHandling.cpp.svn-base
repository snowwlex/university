

#include "ExceptionHandling.h"

#ifdef CATCH_SYSTEM_EXCEPTIONS

// This is an exception filter for processing "structured
// C exceptions.
// This code goes from C++ Builder help system. Exception
// filters article.
// It was my idea to throw standard exceptions here (in filter
// function) and it may be wrong.

int xfilter(EXCEPTION_POINTERS *xp)

    {
        int rc;
        EXCEPTION_RECORD *xr = xp->ExceptionRecord;
        CONTEXT *xc = xp->ContextRecord;
        switch (xr->ExceptionCode) {
            case EXCEPTION_BREAKPOINT:
                // whoops, someone left an embedded breakpoint.
                // just step over it (1 byte on x86)
                ++xc->Eip;
                rc = EXCEPTION_CONTINUE_EXECUTION;
                break;
            case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
                throw std::runtime_error("Array out of bounds");
            case EXCEPTION_FLT_DENORMAL_OPERAND:
            case EXCEPTION_FLT_DIVIDE_BY_ZERO:
            case EXCEPTION_FLT_INEXACT_RESULT:
            case EXCEPTION_FLT_INVALID_OPERATION:
            case EXCEPTION_FLT_OVERFLOW:
            case EXCEPTION_FLT_STACK_CHECK:
            case EXCEPTION_FLT_UNDERFLOW:
                throw std::runtime_error("Nasty problems with floating point");
            case EXCEPTION_INT_DIVIDE_BY_ZERO:
            case EXCEPTION_INT_OVERFLOW:
                throw std::runtime_error("Nasty problems with integral arithmetics");
            case EXCEPTION_STACK_OVERFLOW:
                throw std::runtime_error("Stack overflow");
            case EXCEPTION_ACCESS_VIOLATION:
                throw std::runtime_error("Access violation");

/*
EXCEPTION_PRIV_INSTRUCTION          STATUS_PRIVILEGED_INSTRUCTION
EXCEPTION_IN_PAGE_ERROR             STATUS_IN_PAGE_ERROR
EXCEPTION_ILLEGAL_INSTRUCTION       STATUS_ILLEGAL_INSTRUCTION
EXCEPTION_NONCONTINUABLE_EXCEPTION  STATUS_NONCONTINUABLE_EXCEPTION
EXCEPTION_INVALID_DISPOSITION       STATUS_INVALID_DISPOSITION
EXCEPTION_GUARD_PAGE                STATUS_GUARD_PAGE_VIOLATION
EXCEPTION_INVALID_HANDLE            STATUS_INVALID_HANDLE
CONTROL_C_EXIT                      STATUS_CONTROL_C_EXIT
*/

            default:
                // give up
                rc = EXCEPTION_CONTINUE_SEARCH;
                break;
        };
        return rc;
    }

#endif // CATCH_SYSTEM_EXCEPTIONS    
