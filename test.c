/*
 * =====================================================================================
 *
 *       Filename:  test.c
 *
 *    Description:  For test
 *
 *        Version:  1.0
 *        Created:  2015年10月06日 17时25分27秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ExiaHan 
 *   Organization:  exiahan.com
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "exiahanLib.h"

int main(int argc, char **argv)
{
    if (argc != 2){
        printf("[I]: Usage %s PID\n", argv[0]);
        return -1;
    }
    
    printf("%d\n", getTracerPid(atoi(argv[1])));
    return 0;
}

