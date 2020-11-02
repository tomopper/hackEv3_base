#include "ev3api.h"
#include "app.h"
#include <stdio.h>          /* ファイル関数を使うため*/ 

#if defined(BUILD_MODULE)
#include "module_cfg.h"
#else
#include "kernel_cfg.h"
#endif

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

static FILE *bt = NULL;     /* Bluetoothファイルポインタの宣言*/

void main_task(intptr_t unused)
{
    bt = ev3_serial_open_file(EV3_SERIAL_BT);
    assert(bt != NULL);
}