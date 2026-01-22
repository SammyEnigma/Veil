/*
 * PROJECT:   Veil
 * FILE:      Veil.System.Nls.h
 * PURPOSE:   This file is part of Veil.
 *
 * LICENSE:   MIT License
 *
 * DEVELOPER: MeeSong (meesong@outlook.com)
 */

#pragma once

   // Warnings which disabled for compiling
#if _MSC_VER >= 1200
#pragma warning(push)
// nonstandard extension used : nameless struct/union
#pragma warning(disable:4201)
// nonstandard extension used : bit field types other than int
#pragma warning(disable:4214)
// 'struct_name' : structure was padded due to __declspec(align())
#pragma warning(disable:4324)
// 'enumeration': a forward declaration of an unscoped enumeration must have an
// underlying type (int assumed)
#pragma warning(disable:4471)
#endif

VEIL_BEGIN()

NTSYSAPI USHORT NlsAnsiCodePage;

#ifndef _KERNEL_MODE

#ifdef _NTSYSTEM_

// Try to avoid these, the preferred system ACP/OEMCP is UTF-8 and these are then irrelevent
#define NLS_MB_CODE_PAGE_TAG NlsMbCodePageTag
#define NLS_MB_OEM_CODE_PAGE_TAG NlsMbOemCodePageTag

#else

// Try to avoid these, the preferred system ACP/OEMCP is UTF-8 and these are then irrelevent
#define NLS_MB_CODE_PAGE_TAG (*NlsMbCodePageTag)
#define NLS_MB_OEM_CODE_PAGE_TAG (*NlsMbOemCodePageTag)

#endif // _NTSYSTEM_

extern BOOLEAN NLS_MB_CODE_PAGE_TAG;     // TRUE -> Multibyte CP, FALSE -> Singlebyte
extern BOOLEAN NLS_MB_OEM_CODE_PAGE_TAG; // TRUE -> Multibyte CP, FALSE -> Singlebyte

#define MAXIMUM_LEADBYTES 12

/**
 * Stores the NLS file formats.
 *
 * \sa https://learn.microsoft.com/en-us/previous-versions/mt791523(v=vs.85)
 */
typedef struct _CPTABLEINFO
{
    USHORT CodePage;                        // Specifies the code page number.
    USHORT MaximumCharacterSize;            // Specifies the maximum length in bytes of a character.
    USHORT DefaultChar;                     // Specifies the default character (MB).
    USHORT UniDefaultChar;                  // Specifies the default character (Unicode).
    USHORT TransDefaultChar;                // Specifies the translation of the default character (Unicode).
    USHORT TransUniDefaultChar;             // Specifies the translation of the Unicode default character (MB).
    USHORT DBCSCodePage;                    // Specifies non-zero for DBCS code pages.
    UCHAR LeadByte[MAXIMUM_LEADBYTES];      // Specifies the lead byte ranges.
    PUSHORT MultiByteTable;                 // Specifies a pointer to a MB translation table.
    PVOID WideCharTable;                    // Specifies a pointer to a WC translation table.
    PUSHORT DBCSRanges;                     // Specifies a pointer to DBCS ranges.
    PUSHORT DBCSOffsets;                    // Specifies a pointer to DBCS offsets.
} CPTABLEINFO, * PCPTABLEINFO;

/**
 * Stores the NLS file formats.
 *
 * \sa https://learn.microsoft.com/en-us/previous-versions/mt791531(v=vs.85)
 */
typedef struct _NLSTABLEINFO
{
    CPTABLEINFO OemTableInfo;               // Specifies OEM table.
    CPTABLEINFO AnsiTableInfo;              // Specifies an ANSI table.
    PUSHORT UpperCaseTable;                 // Specifies an 844 format uppercase table.
    PUSHORT LowerCaseTable;                 // Specifies an 844 format lowercase table.
} NLSTABLEINFO, * PNLSTABLEINFO;

#else // !_KERNEL_MODE

NTSYSAPI USHORT NlsOemCodePage;

//
//  Code Page Default Values.
//  Please Use Unicode, either UTF-16 (as in WCHAR) or UTF-8 (code page CP_ACP)
//
#define CP_ACP                    0           // default to ANSI code page
#define CP_OEMCP                  1           // default to OEM  code page
#define CP_MACCP                  2           // default to MAC  code page
#define CP_THREAD_ACP             3           // current thread's ANSI code page
#define CP_SYMBOL                 42          // SYMBOL translations

#define CP_UTF7                   65000       // UTF-7 translation
#define CP_UTF8                   65001       // UTF-8 translation

#include <ntnls.h>

#endif // _KERNEL_MODE

VEIL_END()

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif
