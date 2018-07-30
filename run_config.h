#ifndef RUN_CONFIG_H
#define RUN_CONFIG_H

#ifdef RUN_SYSTEM == "UBUNTU_PC"
    #define COM_PORT_NAME   "ttyUSB0"
#elif RUN_SYSTEM == "WINDOWS_PC"
    #define COM_PORT_NAME   "COM3"
#else
    #error "System not defined!"
#endif

#endif // RUN_CONFIG_H
