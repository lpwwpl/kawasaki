#ifndef TYPES_H
#define TYPES_H


enum ELuaWorkerState
{
    lsEXECUTING,
    lsDEBUGGING,
    lsWAITING
};

/** \brief Enumerator for indicating relative or absolute paths.
*/
enum EPathBase
{
    pbABSOLUTE,     ///< Absolute path
    pbRELATIVE      ///< Path relative to the application directory
};

/** \brief verschiedene Textmarker zum hervorheben von Quelltextzeilen. */
enum ETextMarker
{
    tmNONE       = 0,
    tmERROR      = 1<<1,
    tmHIGHLIGHT  = 1<<2,
    tmBREAKPOINT = 1<<3,
    tmALL        = tmERROR | tmHIGHLIGHT | tmBREAKPOINT
};

#endif // TYPES_H
