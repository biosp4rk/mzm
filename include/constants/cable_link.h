#ifndef CABLE_LINK_CONSTANTS_H
#define CABLE_LINK_CONSTANTS_H

#define CABLE_LINK_ERROR_SHIFT_HARDWARE 0x10
#define CABLE_LINK_ERROR_SHIFT_CHECKSUM 0x11
#define CABLE_LINK_ERROR_SHIFT_OVERFLOW 0x12
#define CABLE_LINK_ERROR_SHIFT_SIO 0x14
#define CABLE_LINK_ERROR_SHIFT_ID_OVER 0x16

#define CABLE_LINK_ERROR_HARDWARE (1 << CABLE_LINK_ERROR_SHIFT_HARDWARE)
#define CABLE_LINK_ERROR_CHECKSUM (1 << CABLE_LINK_ERROR_SHIFT_CHECKSUM)
#define CABLE_LINK_ERROR_SEND_OVERFLOW (1 << CABLE_LINK_ERROR_SHIFT_OVERFLOW)
#define CABLE_LINK_ERROR_RECEIVE_OVERFLOW (2 << CABLE_LINK_ERROR_SHIFT_OVERFLOW)
#define CABLE_LINK_ERROR_SIO_INTERNAL (1 << CABLE_LINK_ERROR_SHIFT_SIO)
#define CABLE_LINK_ERROR_SIO_STOP (2 << CABLE_LINK_ERROR_SHIFT_SIO)
#define CABLE_LINK_ERROR_ID_OVER (1 << CABLE_LINK_ERROR_SHIFT_ID_OVER)

#endif
