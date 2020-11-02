#include "communication.h"

void communication::communication()
{
    while(!ev3_bluetooth_is_connected()) {
        eslp_tsk(100);
    }

    bt = ev3_serial_open_file(EV3_SERIAL_BT);

    msg_f("通信できてます。");

}