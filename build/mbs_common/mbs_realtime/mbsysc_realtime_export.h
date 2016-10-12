
#ifndef MBSYSC_REALTIME_EXPORT_H
#define MBSYSC_REALTIME_EXPORT_H

#ifdef MBSYSC_REALTIME_STATIC_DEFINE
#  define MBSYSC_REALTIME_EXPORT
#  define MBSYSC_REALTIME_NO_EXPORT
#else
#  ifndef MBSYSC_REALTIME_EXPORT
#    ifdef MBsysC_realtime_EXPORTS
        /* We are building this library */
#      define MBSYSC_REALTIME_EXPORT 
#    else
        /* We are using this library */
#      define MBSYSC_REALTIME_EXPORT 
#    endif
#  endif

#  ifndef MBSYSC_REALTIME_NO_EXPORT
#    define MBSYSC_REALTIME_NO_EXPORT 
#  endif
#endif

#ifndef MBSYSC_REALTIME_DEPRECATED
#  define MBSYSC_REALTIME_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef MBSYSC_REALTIME_DEPRECATED_EXPORT
#  define MBSYSC_REALTIME_DEPRECATED_EXPORT MBSYSC_REALTIME_EXPORT MBSYSC_REALTIME_DEPRECATED
#endif

#ifndef MBSYSC_REALTIME_DEPRECATED_NO_EXPORT
#  define MBSYSC_REALTIME_DEPRECATED_NO_EXPORT MBSYSC_REALTIME_NO_EXPORT MBSYSC_REALTIME_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef MBSYSC_REALTIME_NO_DEPRECATED
#    define MBSYSC_REALTIME_NO_DEPRECATED
#  endif
#endif

#endif