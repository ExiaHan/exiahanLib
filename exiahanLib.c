/*
 * =====================================================================================
 *
 *       Filename:  exiahanLib.c
 *
 *    Description:  exiahanLib source file, some useful sources
 *
 *        Version:  1.0
 *        Created:  2015年10月06日 16时36分18秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ExiaHan
 *   Organization:  exiahan.com
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exiahanLib.h"

u_int32_t getTracerPid(int32_t iPID)
{
    char strPath[MAXLENGTH];
    char strBuff[MAXLENGTH];
    char *strTarget = "TracerPid";
    char *strParse = ":";
    char *strPoint = NULL;
    char *strTracerPid = NULL;
    char *strSavePtr = NULL;
    FILE *fp = NULL;
    u_int32_t uTracerPid = -1;
	
    //Wrong Argument, return Error
    if (iPID < 0)
      goto RETURN;

    //Generate the path string
    sprintf(strPath, "/proc/%d/status", iPID);

    if (!(fp = fopen(strPath, "r")))
      goto RETURN;

    while(fgets(strBuff, MAXLENGTH - 10, fp)) {
      if ((strPoint = strstr(strBuff, strTarget)) != NULL)
    	break;
    }

    //error if not found TracerPid String
    if (!strPoint)
      goto RETURN;
    //error if Parse failed
    if (!(strTracerPid = strtok_r(strPoint, strParse, &strSavePtr)))
      goto RETURN;
    if (!(strTracerPid = strtok_r(NULL, strParse, &strSavePtr)))
      goto RETURN;
    uTracerPid = atoi(strTracerPid);
    
 RETURN:
    return uTracerPid; 
}
