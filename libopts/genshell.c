/*   -*- buffer-read-only: t -*- vi: set ro:
 *  
 *  DO NOT EDIT THIS FILE   (genshell.c)
 *  
 *  It has been AutoGen-ed  Sunday April 17, 2005 at 11:55:00 AM PDT
 *  From the definitions    genshell.def
 *  and the template file   options
 */

#define OPTION_CODE_COMPILE 1
#include "genshell.h"

#ifdef  __cplusplus
extern "C" {
#endif
tSCC zCopyright[] =
       "genshellopt copyright (c) 1999-2005 Bruce Korb, all rights reserved";
tSCC zCopyrightNotice[] =
       "genshellopt is free software; you can redistribute it and/or\n\
modify it under the terms of the GNU Lesser General Public\n\
License as published by the Free Software Foundation; either\n\
version 2.1 of the License, or (at your option) any later version.\n\n\
genshellopt is distributed in the hope that it will be useful,\n\
but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU\n\
Lesser General Public License for more details.\n\n\
You should have received a copy of the GNU Lesser General Public\n\
License along with genshellopt; if not, write to:\n\
           The Free Software Foundation, Inc.,\n\
           59 Temple Place - Suite 330,\n\
           Boston,  MA  02111-1307, USA.";
extern tUsageProc genshelloptUsage;

#ifndef NULL
#  define NULL 0
#endif
#ifndef EXIT_SUCCESS
#  define  EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
#  define  EXIT_FAILURE 1
#endif
/*
 *  Script option description:
 */
tSCC    zScriptText[] =
        "Output Script File";
tSCC    zScript_NAME[]             = "SCRIPT";
tSCC    zScript_Name[]             = "script";
#define SCRIPT_FLAGS       (OPTST_DISABLED \
	| OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/*
 *  Shell option description:
 */
tSCC    zShellText[] =
        "Shell name (follows \"#!\" magic)";
tSCC    zShell_NAME[]              = "SHELL";
tSCC    zNotShell_Name[]           = "no-shell";
tSCC    zNotShell_Pfx[]            = "no";
#define zShell_Name                  (zNotShell_Name + 3)
#define SHELL_FLAGS       (OPTST_INITENABLED \
	| OPTST_SET_ARGTYPE(OPARG_TYPE_STRING))

/*
 *  Help/More_Help/Version option descriptions:
 */
tSCC zHelpText[]       = "Display usage information and exit";
tSCC zHelp_Name[]      = "help";

tSCC zMore_HelpText[]  = "Extended usage information passed thru pager";
tSCC zMore_Help_Name[] = "more-help";

tSCC zVersionText[]    = "Output version information and exit";
tSCC zVersion_Name[]   = "version";
/*
 *  Declare option callback procedures
 */
extern tOptProc
    optionPagedUsage, optionPrintVersion;
static tOptProc
    doUsageOpt;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  Define the Genshellopt Option Descriptions.
 */
static tOptDesc optDesc[ OPTION_CT ] = {
  {  /* entry idx, value */ 0, VALUE_OPT_SCRIPT,
     /* equiv idx, value */ 0, VALUE_OPT_SCRIPT,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ SCRIPT_FLAGS, 0,
     /* last opt argumnt */ NULL,
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ zScriptText, zScript_NAME, zScript_Name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ 1, VALUE_OPT_SHELL,
     /* equiv idx, value */ 1, VALUE_OPT_SHELL,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ SHELL_FLAGS, 0,
     /* last opt argumnt */ NULL,
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ NULL,
     /* desc, NAME, name */ zShellText, zShell_NAME, zShell_Name,
     /* disablement strs */ zNotShell_Name, zNotShell_Pfx },

  {  /* entry idx, value */ INDEX_OPT_VERSION, VALUE_OPT_VERSION,
     /* equiv idx value  */ NO_EQUIVALENT, 0,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ OPTST_SET_ARGTYPE(OPARG_TYPE_STRING)
                          | OPTST_ARG_OPTIONAL, 0,
     /* last opt argumnt */ NULL,
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ optionPrintVersion,
     /* desc, NAME, name */ zVersionText, NULL, zVersion_Name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_HELP, VALUE_OPT_HELP,
     /* equiv idx value  */ NO_EQUIVALENT, 0,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ OPTST_IMM, 0,
     /* last opt argumnt */ NULL,
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL, NULL,
     /* option proc      */ doUsageOpt,
     /* desc, NAME, name */ zHelpText, NULL, zHelp_Name,
     /* disablement strs */ NULL, NULL },

  {  /* entry idx, value */ INDEX_OPT_MORE_HELP, VALUE_OPT_MORE_HELP,
     /* equiv idx value  */ NO_EQUIVALENT, 0,
     /* equivalenced to  */ NO_EQUIVALENT,
     /* min, max, act ct */ 0, 1, 0,
     /* opt state flags  */ OPTST_IMM, 0,
     /* last opt argumnt */ NULL,
     /* arg list/cookie  */ NULL,
     /* must/cannot opts */ NULL,  NULL,
     /* option proc      */ optionPagedUsage,
     /* desc, NAME, name */ zMore_HelpText, NULL, zMore_Help_Name,
     /* disablement strs */ NULL, NULL }
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 *  Define the Genshellopt Option Environment
 */
tSCC   zPROGNAME[]   = "GENSHELLOPT";
tSCC   zUsageTitle[] =
"genshellopt - Generate Shell Option Processing Script - Ver. 1\n\
USAGE:  %s [ -<flag> [<val>] | --<name>[{=| }<val>] ]...\n";
#define zRcName     NULL
#define apzHomeList NULL

tSCC   zBugsAddr[]    = "autogen-users@lists.sf.net";
tSCC   zExplain[]     = "\n\
Note that `shell' is only useful if the output file does not already\n\
exist.  If it does, then the shell name and optional first argument\n\
will be extracted from the script file.\n";
tSCC    zDetail[]     = "\n\
If the script file already exists and contains Automated Option Processing\n\
text, the second line of the file through the ending tag will be replaced\n\
by the newly generated text.  The first `#!' line will be regenerated.\n";
tSCC    zFullVersion[] = GENSHELLOPT_FULL_VERSION;
/* extracted from optcode.tpl near line 309 */

#if defined(ENABLE_NLS)
# define OPTPROC_BASE OPTPROC_TRANSLATE
  static tOptionXlateProc translate_option_strings;
#else
# define OPTPROC_BASE OPTPROC_NONE
# define translate_option_strings NULL
#endif /* ENABLE_NLS */

tOptions genshelloptOptions = {
    OPTIONS_STRUCT_VERSION,
    0, NULL,                    /* original argc + argv    */
    ( OPTPROC_BASE
    + OPTPROC_ERRSTOP
    + OPTPROC_SHORTOPT
    + OPTPROC_LONGOPT
    + OPTPROC_NO_REQ_OPT
    + OPTPROC_NEGATIONS
    + OPTPROC_NO_ARGS ),
    0, NULL,                    /* current option index, current option */
    NULL,         NULL,         zPROGNAME,
    zRcName,      zCopyright,   zCopyrightNotice,
    zFullVersion, apzHomeList,  zUsageTitle,
    zExplain,     zDetail,      optDesc,
    zBugsAddr,                  /* address to send bugs to */
    NULL, NULL,                 /* extensions/saved state  */
    genshelloptUsage,       /* usage procedure */
    translate_option_strings,   /* translation procedure */
    /*
     *  Indexes to special options
     */
    { INDEX_OPT_MORE_HELP,
       0 /* no option state saving */,
      NO_EQUIVALENT /* index of '-#' option */,
      NO_EQUIVALENT /* index of default opt */
    },
    OPTION_CT, 2 /* user option count */
};

/*
 *  Create the static procedure(s) declared above.
 */
static void
doUsageOpt(
    tOptions*   pOptions,
    tOptDesc*   pOptDesc )
{
    USAGE( EXIT_SUCCESS );
}
/* extracted from optcode.tpl near line 396 */

#if ENABLE_NLS
#include <string.h>
#include <stdio.h>
#include <autoopts/usage-txt.h>

static char*
AO_gettext( const char* pz )
{
    char* pzRes;
    if (pz == NULL)
        return NULL;
    pzRes = _(pz);
    if (pzRes == pz)
        return pzRes;
    pzRes = strdup( pzRes );
    if (pzRes == NULL) {
        fputs( _("No memory for duping translated strings\n"), stderr );
        exit( EXIT_FAILURE );
    }
    return pzRes;
}

/*
 *  This invokes the translation code (e.g. gettext(3)).
 */
static void
translate_option_strings( void )
{
    /*
     *  Guard against re-translation.  It won't work.  The strings will have
     *  been changed by the first pass through this code.  One shot only.
     */
    if (option_usage_text.field_ct == 0)
        return;
    /*
     *  Do the translations.  The first pointer follows the field count field.
     *  The field count field is the size of a pointer.
     */
    {
        char** ppz = (char**)(void*)&(option_usage_text);
        int    ix  = option_usage_text.field_ct;

        do {
            ppz++;
            *ppz = AO_gettext(*ppz);
        } while (--ix > 0);
    }
    option_usage_text.field_ct = 0;

    {
        tOptDesc* pOD = genshelloptOptions.pOptDesc;
        int       ix  = genshelloptOptions.optCt;

        for (;;) {
            pOD->pzText           = AO_gettext(pOD->pzText);
            pOD->pz_NAME          = AO_gettext(pOD->pz_NAME);
            pOD->pz_Name          = AO_gettext(pOD->pz_Name);
            pOD->pz_DisableName   = AO_gettext(pOD->pz_DisableName);
            pOD->pz_DisablePfx    = AO_gettext(pOD->pz_DisablePfx);
            if (--ix <= 0)
                break;
            pOD++;
        }
    }
    genshelloptOptions.pzCopyright   = AO_gettext(genshelloptOptions.pzCopyright);
    genshelloptOptions.pzCopyNotice  = AO_gettext(genshelloptOptions.pzCopyNotice);
    genshelloptOptions.pzFullVersion = AO_gettext(genshelloptOptions.pzFullVersion);
    genshelloptOptions.pzUsageTitle  = AO_gettext(genshelloptOptions.pzUsageTitle);
    genshelloptOptions.pzExplain     = AO_gettext(genshelloptOptions.pzExplain);
    genshelloptOptions.pzDetail      = AO_gettext(genshelloptOptions.pzDetail);
}

#endif /* ENABLE_NLS */

#ifdef  __cplusplus
}
#endif
