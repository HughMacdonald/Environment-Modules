/*****
 ** ** Module Header ******************************************************* **
 ** 									     **
 **   Modules Revision 3.0						     **
 **   Providing a flexible user environment				     **
 ** 									     **
 **   File:		cmdSet.c					     **
 **   First Edition:	2012/03/11					     **
 ** 									     **
 **   Authors:	Hugh Macdonald, hugh.macdonald@nvizible.com				     **
 ** 									     **
 **   Description:	The Tcl module-set routine which sets informa-  **
 **			tion about the state of Modules as the modulefile    **
 **			is being parsed. 				     **
 ** 									     **
 **   Exports:		cmdModuleSet					     **
 ** 									     **
 **   Notes:								     **
 ** 									     **
 ** ************************************************************************ **
 ****/

/** ** Copyright *********************************************************** **
 ** 									     **
 ** Copyright 1991-1994 by John L. Furlan.                      	     **
 ** see LICENSE.GPL, which must be provided, for details		     **
 ** 									     ** 
 ** ************************************************************************ **/

static char Id[] = "@(#)$Id: cmdSet.c,v 1.8.22.1 2012/03/11 18:23:18 hughmacdonald Exp $";
static void *UseId[] = { &UseId, Id };

/** ************************************************************************ **/
/** 				      HEADERS				     **/
/** ************************************************************************ **/

#include "modules_def.h"

/** ************************************************************************ **/
/** 				  LOCAL DATATYPES			     **/
/** ************************************************************************ **/

/** not applicable **/

/** ************************************************************************ **/
/** 				     CONSTANTS				     **/
/** ************************************************************************ **/

/** not applicable **/

/** ************************************************************************ **/
/**				      MACROS				     **/
/** ************************************************************************ **/

/** not applicable **/

/** ************************************************************************ **/
/** 				    LOCAL DATA				     **/
/** ************************************************************************ **/

static	char	module_name[] = "cmdSet.c";	/** File name of this module **/
#if WITH_DEBUGGING_CALLBACK
static	char	_proc_cmdModuleSet[] = "cmdModuleSet";
#endif

/** ************************************************************************ **/
/**				    PROTOTYPES				     **/
/** ************************************************************************ **/

/** not applicable **/


/*++++
 ** ** Function-Header ***************************************************** **
 ** 									     **
 **   Function:		cmdModuleSet					     **
 ** 									     **
 **   Description:	Callback function for 'module-set'		     **
 ** 									     **
 **   First Edition:	2012/03/11					     **
 ** 									     **
 **   Parameters:	ClientData	 client_data			     **
 **			Tcl_Interp	*interp		According Tcl interp.**
 **			int		 argc		Number of arguments  **
 **			char		*argv[]		Argument array	     **
 ** 									     **
 **   Result:		int	TCL_OK		Successful completion	     **
 **				TCL_ERROR	Any error		     **
 ** 									     **
 **   Attached Globals:	g_flags			These are set up accordingly **
 **						before this function is	     **
 **						called in order to control   **
 **						everything.		     **
 **			g_specified_module	The module name from the     **
 **						command line.		     **
 **			g_current_module	The module which is handled  **
 **						by the current command	     **
 ** 									     **
 ** ************************************************************************ **
 ++++*/

int	cmdModuleSet(	ClientData	 client_data,
	      		Tcl_Interp	*interp,
	      		int		 argc,
	      		CONST84 char	*argv[])
{
    char *s, *t, buf[ BUFSIZ];

#if WITH_DEBUGGING_CALLBACK
    ErrorLogger( NO_ERR_START, LOC, _proc_cmdModuleSet, NULL);
#endif

    /**
     **  Parameter check
     **/

    if( argc < 2) {
	if( OK != ErrorLogger( ERR_USAGE, LOC, argv[0], "info-descriptor ",
	    "descriptor-args", NULL))
	    return( TCL_ERROR);		/** -------- EXIT (FAILURE) -------> **/
    }
  
    /**
     **  'module-set resolve-symlinks' ?
     **/

    if( !strcmp( argv[1], "resolve-symlinks")) {
        g_resolve_symlinks = 1;
        Tcl_SetResult( interp, "1", TCL_STATIC);

    /**
     **  unknown command ....
     **/

    } else {
	if( OK != ErrorLogger( ERR_INFO_DESCR, LOC, argv[1], NULL))
	    return( TCL_ERROR);		/** -------- EXIT (FAILURE) -------> **/
    }

#if WITH_DEBUGGING_CALLBACK
    ErrorLogger( NO_ERR_END, LOC, _proc_cmdModuleSet, NULL);
#endif

    return( TCL_OK);

} /** End of 'cmdModuleSet' **/
