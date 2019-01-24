
#ifndef _FREERTOS_POSIX_ASSERT_H_
#define _FREERTOS_POSIX_ASSERT_H_

#ifdef _DEBUG

    void assert(int expression);

#else

    #define assert(ex)

#endif

#endif
