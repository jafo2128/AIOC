#ifndef SETTINGS_H_
#define SETTINGS_H_

#include <stdint.h>
#include "usb_descriptors.h"

#define SETTINGS_REGMAP_SIZE     256
#define SETTINGS_REGMAP_READONLYADDR 0xC0

extern uint32_t settingsRegMap[SETTINGS_REGMAP_SIZE];

/* Magic number register. Mainly used to see if flash data is valid */
#define SETTINGS_REG_MAGIC                                  0x00
#define SETTINGS_REG_MAGIC_DEFAULT                          ( (((uint32_t) 'A') <<  0) | \
                                                              (((uint32_t) 'I') <<  8) | \
                                                              (((uint32_t) 'O') << 16) | \
                                                              (((uint32_t) 'C') << 24) )

/* USB ID register. The default USB VID and PID can be overwritten. Use with caution */
#define SETTINGS_REG_USBID                                  0x08
#define SETTINGS_REG_USBID_DEFAULT                          (SETTINGS_REG_USBID_VID_DFLT | SETTINGS_REG_USBID_PID_DFLT)
/* VID: USB Vendor Id */
#define SETTINGS_REG_USBID_VID_DFLT                         ((uint32_t) USB_VID << SETTINGS_REG_USBID_VID_OFFS)
#define SETTINGS_REG_USBID_VID_OFFS                         0
#define SETTINGS_REG_USBID_VID_MASK                         0x0000FFFFUL
/* PID: USB Product Id */
#define SETTINGS_REG_USBID_PID_DFLT                         ((uint32_t) USB_PID << SETTINGS_REG_USBID_PID_OFFS)
#define SETTINGS_REG_USBID_PID_OFFS                         16
#define SETTINGS_REG_USBID_PID_MASK                         0xFFFF0000UL

/* AIOC IOMUX0 register */
#define SETTINGS_REG_AIOC_IOMUX0                            0x24
#define SETTINGS_REG_AIOC_IOMUX0_DEFAULT                    (SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_DFLT)
/* PTT1SRC: Source for PTT1 signal */
#define SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_DFLT               (SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_CM108GPIO3_MASK | SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_SERIALDTRNRTS_MASK)
#define SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_OFFS               0
#define SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_MASK               0xFFFFFFFFUL
#define SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_NONE_MASK          0x00000000UL
#define SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_CM108GPIO1_MASK    0x00000001UL
#define SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_CM108GPIO2_MASK    0x00000002UL
#define SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_CM108GPIO3_MASK    0x00000004UL
#define SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_CM108GPIO4_MASK    0x00000008UL
#define SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_SERIALDTR_MASK     0x00000100UL
#define SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_SERIALRTS_MASK     0x00000200UL
#define SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_SERIALDTRNRTS_MASK 0x00000400UL
#define SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_SERIALNDTRRTS_MASK 0x00000800UL
#define SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_VPTT_MASK          0x00001000UL

/* AIOC IOMUX1 register */
#define SETTINGS_REG_AIOC_IOMUX1                            0x25
#define SETTINGS_REG_AIOC_IOMUX1_DEFAULT                    (SETTINGS_REG_AIOC_IOMUX1_PTT2SRC_DFLT)
/* PTT2SRC: Source for PTT2 signal */
#define SETTINGS_REG_AIOC_IOMUX1_PTT2SRC_DFLT               (SETTINGS_REG_AIOC_IOMUX1_PTT2SRC_CM108GPIO4_MASK)
#define SETTINGS_REG_AIOC_IOMUX1_PTT2SRC_OFFS               SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_OFFS
#define SETTINGS_REG_AIOC_IOMUX1_PTT2SRC_MASK               SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_MASK
#define SETTINGS_REG_AIOC_IOMUX1_PTT2SRC_NONE_MASK          SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_NONE_MASK
#define SETTINGS_REG_AIOC_IOMUX1_PTT2SRC_CM108GPIO1_MASK    SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_CM108GPIO1_MASK
#define SETTINGS_REG_AIOC_IOMUX1_PTT2SRC_CM108GPIO2_MASK    SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_CM108GPIO2_MASK
#define SETTINGS_REG_AIOC_IOMUX1_PTT2SRC_CM108GPIO3_MASK    SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_CM108GPIO3_MASK
#define SETTINGS_REG_AIOC_IOMUX1_PTT2SRC_CM108GPIO4_MASK    SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_CM108GPIO4_MASK
#define SETTINGS_REG_AIOC_IOMUX1_PTT2SRC_SERIALDTR_MASK     SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_SERIALDTR_MASK
#define SETTINGS_REG_AIOC_IOMUX1_PTT2SRC_SERIALRTS_MASK     SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_SERIALRTS_MASK
#define SETTINGS_REG_AIOC_IOMUX1_PTT2SRC_SERIALDTRNRTS_MASK SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_SERIALDTRNRTS_MASK
#define SETTINGS_REG_AIOC_IOMUX1_PTT2SRC_SERIALNDTRRTS_MASK SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_SERIALNDTRRTS_MASK
#define SETTINGS_REG_AIOC_IOMUX1_PTT2SRC_VPTT_MASK          SETTINGS_REG_AIOC_IOMUX0_PTT1SRC_VPTT_MASK

/* CM108 IOMUX0 register */
#define SETTINGS_REG_CM108_IOMUX0                           0x44
#define SETTINGS_REG_CM108_IOMUX0_DEFAULT                   (SETTINGS_REG_CM108_IOMUX0_BTN1SRC_DFLT)
/* BTN1SRC: Volume-Up Button source */
#define SETTINGS_REG_CM108_IOMUX0_BTN1SRC_DFLT              (SETTINGS_REG_CM108_IOMUX0_BTN1SRC_NONE_MASK)
#define SETTINGS_REG_CM108_IOMUX0_BTN1SRC_OFFS              0
#define SETTINGS_REG_CM108_IOMUX0_BTN1SRC_MASK              0xFFFFFFFFUL
#define SETTINGS_REG_CM108_IOMUX0_BTN1SRC_NONE_MASK         0x00000000UL
#define SETTINGS_REG_CM108_IOMUX0_BTN1SRC_IO1_MASK          0x00010000UL /* AIOC's IO1 */
#define SETTINGS_REG_CM108_IOMUX0_BTN1SRC_IO2_MASK          0x00020000UL /* AIOC's IO2 */
#define SETTINGS_REG_CM108_IOMUX0_BTN1SRC_VCOS_MASK         0x01000000UL /* Virtual COS */

/* CM108 IOMUX1 register */
#define SETTINGS_REG_CM108_IOMUX1                           0x45
#define SETTINGS_REG_CM108_IOMUX1_DEFAULT                   (SETTINGS_REG_CM108_IOMUX1_BTN2SRC_DFLT)
/* BTN2SRC: Volume-Down Button source */
#define SETTINGS_REG_CM108_IOMUX1_BTN2SRC_DFLT              (SETTINGS_REG_CM108_IOMUX1_BTN2SRC_VCOS_MASK)
#define SETTINGS_REG_CM108_IOMUX1_BTN2SRC_OFFS              SETTINGS_REG_CM108_IOMUX0_BTN1SRC_OFFS
#define SETTINGS_REG_CM108_IOMUX1_BTN2SRC_MASK              SETTINGS_REG_CM108_IOMUX0_BTN1SRC_MASK
#define SETTINGS_REG_CM108_IOMUX1_BTN2SRC_NONE_MASK         SETTINGS_REG_CM108_IOMUX0_BTN1SRC_NONE_MASK
#define SETTINGS_REG_CM108_IOMUX1_BTN2SRC_IO1_MASK          SETTINGS_REG_CM108_IOMUX0_BTN1SRC_IO1_MASK
#define SETTINGS_REG_CM108_IOMUX1_BTN2SRC_IO2_MASK          SETTINGS_REG_CM108_IOMUX0_BTN1SRC_IO2_MASK
#define SETTINGS_REG_CM108_IOMUX1_BTN2SRC_VCOS_MASK         SETTINGS_REG_CM108_IOMUX0_BTN1SRC_VCOS_MASK

/* CM108 IOMUX2 register */
#define SETTINGS_REG_CM108_IOMUX2                           0x46
#define SETTINGS_REG_CM108_IOMUX2_DEFAULT                   (SETTINGS_REG_CM108_IOMUX2_BTN3SRC_DFLT)
/* BTN3SRC: Playback-Mute Button source */
#define SETTINGS_REG_CM108_IOMUX2_BTN3SRC_DFLT              (SETTINGS_REG_CM108_IOMUX2_BTN3SRC_NONE_MASK)
#define SETTINGS_REG_CM108_IOMUX2_BTN3SRC_OFFS              SETTINGS_REG_CM108_IOMUX0_BTN1SRC_OFFS
#define SETTINGS_REG_CM108_IOMUX2_BTN3SRC_MASK              SETTINGS_REG_CM108_IOMUX0_BTN1SRC_MASK
#define SETTINGS_REG_CM108_IOMUX2_BTN3SRC_NONE_MASK         SETTINGS_REG_CM108_IOMUX0_BTN1SRC_NONE_MASK
#define SETTINGS_REG_CM108_IOMUX2_BTN3SRC_IO1_MASK          SETTINGS_REG_CM108_IOMUX0_BTN1SRC_IO1_MASK
#define SETTINGS_REG_CM108_IOMUX2_BTN3SRC_IO2_MASK          SETTINGS_REG_CM108_IOMUX0_BTN1SRC_IO2_MASK
#define SETTINGS_REG_CM108_IOMUX2_BTN3SRC_VCOS_MASK         SETTINGS_REG_CM108_IOMUX0_BTN1SRC_VCOS_MASK

/* CM108 IOMUX3 register */
#define SETTINGS_REG_CM108_IOMUX3                           0x47
#define SETTINGS_REG_CM108_IOMUX3_DEFAULT                   (SETTINGS_REG_CM108_IOMUX3_BTN4SRC_DFLT)
/* BTN4SRC: Record-Mute Button source */
#define SETTINGS_REG_CM108_IOMUX3_BTN4SRC_DFLT              (SETTINGS_REG_CM108_IOMUX3_BTN4SRC_NONE_MASK)
#define SETTINGS_REG_CM108_IOMUX3_BTN4SRC_OFFS              SETTINGS_REG_CM108_IOMUX0_BTN1SRC_OFFS
#define SETTINGS_REG_CM108_IOMUX3_BTN4SRC_MASK              SETTINGS_REG_CM108_IOMUX0_BTN1SRC_MASK
#define SETTINGS_REG_CM108_IOMUX3_BTN4SRC_NONE_MASK         SETTINGS_REG_CM108_IOMUX0_BTN1SRC_NONE_MASK
#define SETTINGS_REG_CM108_IOMUX3_BTN4SRC_IO1_MASK          SETTINGS_REG_CM108_IOMUX0_BTN1SRC_IO1_MASK
#define SETTINGS_REG_CM108_IOMUX3_BTN4SRC_IO2_MASK          SETTINGS_REG_CM108_IOMUX0_BTN1SRC_IO2_MASK
#define SETTINGS_REG_CM108_IOMUX3_BTN4SRC_VCOS_MASK         SETTINGS_REG_CM108_IOMUX0_BTN1SRC_VCOS_MASK

/* Serial (CDC) Control register */
#define SETTINGS_REG_SERIAL_CTRL                            0x60
#define SETTINGS_REG_SERIAL_CTRL_DEFAULT                    (SETTINGS_REG_SERIAL_CTRL_TXFRCPTT_DFLT | SETTINGS_REG_SERIAL_CTRL_RXIGNPTT_DFLT)
/* TXFRCPTT: Forces PTT signal(s) to zero when transmitting serial data to radio if enabled */
#define SETTINGS_REG_SERIAL_CTRL_TXFRCPTT_DFLT              (SETTINGS_REG_SERIAL_CTRL_TXFRCPTT_PTT1_MASK)
#define SETTINGS_REG_SERIAL_CTRL_TXFRCPTT_OFFS              8
#define SETTINGS_REG_SERIAL_CTRL_TXFRCPTT_MASK              0x00000F00UL
#define SETTINGS_REG_SERIAL_CTRL_TXFRCPTT_NONE_MASK         0x00000000UL
#define SETTINGS_REG_SERIAL_CTRL_TXFRCPTT_PTT1_MASK         0x00000100UL
#define SETTINGS_REG_SERIAL_CTRL_TXFRCPTT_PTT2_MASK         0x00000200UL
/* RXIGNPTT: Ignores reception of data from radio when PTT signal(s) asserted if enabled */
#define SETTINGS_REG_SERIAL_CTRL_RXIGNPTT_DFLT              (SETTINGS_REG_SERIAL_CTRL_RXIGNPTT_PTT1_MASK)
#define SETTINGS_REG_SERIAL_CTRL_RXIGNPTT_OFFS              16
#define SETTINGS_REG_SERIAL_CTRL_RXIGNPTT_MASK              0x000F0000UL
#define SETTINGS_REG_SERIAL_CTRL_RXIGNPTT_NONE_MASK         0x00000000UL
#define SETTINGS_REG_SERIAL_CTRL_RXIGNPTT_PTT1_MASK         0x00010000UL
#define SETTINGS_REG_SERIAL_CTRL_RXIGNPTT_PTT2_MASK         0x00020000UL

/* Serial (CDC) IOMUX0 register */
#define SETTINGS_REG_SERIAL_IOMUX0                          0x64
#define SETTINGS_REG_SERIAL_IOMUX0_DEFAULT                  (SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_DFLT)
/* DCDSRC: DCD (Data Carrier Detect) signal source */
#define SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_DFLT              (SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_VCOS_MASK)
#define SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_OFFS              SETTINGS_REG_CM108_IOMUX0_BTN1SRC_OFFS
#define SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_MASK              SETTINGS_REG_CM108_IOMUX0_BTN1SRC_MASK
#define SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_NONE_MASK         SETTINGS_REG_CM108_IOMUX0_BTN1SRC_NONE_MASK
#define SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_IO1_MASK          SETTINGS_REG_CM108_IOMUX0_BTN1SRC_IO1_MASK
#define SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_IO2_MASK          SETTINGS_REG_CM108_IOMUX0_BTN1SRC_IO2_MASK
#define SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_VCOS_MASK         SETTINGS_REG_CM108_IOMUX0_BTN1SRC_VCOS_MASK

/* Serial (CDC) IOMUX1 register */
#define SETTINGS_REG_SERIAL_IOMUX1                          0x65
#define SETTINGS_REG_SERIAL_IOMUX1_DEFAULT                  (SETTINGS_REG_SERIAL_IOMUX1_DSRSRC_DFLT)
/* DSRSRC: DSR (Data Set Ready) signal source */
#define SETTINGS_REG_SERIAL_IOMUX1_DSRSRC_DFLT              (SETTINGS_REG_SERIAL_IOMUX1_DSRSRC_NONE_MASK)
#define SETTINGS_REG_SERIAL_IOMUX1_DSRSRC_OFFS              SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_OFFS
#define SETTINGS_REG_SERIAL_IOMUX1_DSRSRC_MASK              SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_MASK
#define SETTINGS_REG_SERIAL_IOMUX1_DSRSRC_NONE_MASK         SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_NONE_MASK
#define SETTINGS_REG_SERIAL_IOMUX1_DSRSRC_IO1_MASK          SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_IO1_MASK
#define SETTINGS_REG_SERIAL_IOMUX1_DSRSRC_IO2_MASK          SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_IO2_MASK
#define SETTINGS_REG_SERIAL_IOMUX1_DSRSRC_VCOS_MASK         SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_VCOS_MASK

/* Serial (CDC) IOMUX2 register */
#define SETTINGS_REG_SERIAL_IOMUX2                          0x66
#define SETTINGS_REG_SERIAL_IOMUX2_DEFAULT                  (SETTINGS_REG_SERIAL_IOMUX2_RISRC_DFLT)
/* RISRC: RI (Ring Indicator) signal source */
#define SETTINGS_REG_SERIAL_IOMUX2_RISRC_DFLT               (SETTINGS_REG_SERIAL_IOMUX2_RISRC_NONE_MASK)
#define SETTINGS_REG_SERIAL_IOMUX2_RISRC_OFFS               SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_OFFS
#define SETTINGS_REG_SERIAL_IOMUX2_RISRC_MASK               SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_MASK
#define SETTINGS_REG_SERIAL_IOMUX2_RISRC_NONE_MASK          SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_NONE_MASK
#define SETTINGS_REG_SERIAL_IOMUX2_RISRC_IO1_MASK           SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_IO1_MASK
#define SETTINGS_REG_SERIAL_IOMUX2_RISRC_IO2_MASK           SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_IO2_MASK
#define SETTINGS_REG_SERIAL_IOMUX2_RISRC_VCOS_MASK          SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_VCOS_MASK

/* Serial (CDC) IOMUX3 register */
#define SETTINGS_REG_SERIAL_IOMUX3                          0x67
#define SETTINGS_REG_SERIAL_IOMUX3_DEFAULT                  (SETTINGS_REG_SERIAL_IOMUX3_BRKSRC_DFLT)
/* BRKSRC: BREAK (Break) signal source */
#define SETTINGS_REG_SERIAL_IOMUX3_BRKSRC_DFLT              (SETTINGS_REG_SERIAL_IOMUX3_BRKSRC_NONE_MASK)
#define SETTINGS_REG_SERIAL_IOMUX3_BRKSRC_OFFS              SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_OFFS
#define SETTINGS_REG_SERIAL_IOMUX3_BRKSRC_MASK              SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_MASK
#define SETTINGS_REG_SERIAL_IOMUX3_BRKSRC_NONE_MASK         SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_NONE_MASK
#define SETTINGS_REG_SERIAL_IOMUX3_BRKSRC_IO1_MASK          SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_IO1_MASK
#define SETTINGS_REG_SERIAL_IOMUX3_BRKSRC_IO2_MASK          SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_IO2_MASK
#define SETTINGS_REG_SERIAL_IOMUX3_BRKSRC_VCOS_MASK         SETTINGS_REG_SERIAL_IOMUX0_DCDSRC_VCOS_MASK

/* Virtual PTT level control register */
#define SETTINGS_REG_VPTT_LVLCTRL                           0x82
#define SETTINGS_REG_VPTT_LVLCTRL_DEFAULT                   (SETTINGS_REG_VPTT_LVLCTRL_THRSHLD_DFLT)
/* THRSHLD: Virtual PTT threshold level */
#define SETTINGS_REG_VPTT_LVLCTRL_THRSHLD_DFLT              ((uint32_t) 16 << SETTINGS_REG_VPTT_LVLCTRL_THRSHLD_OFFS)
#define SETTINGS_REG_VPTT_LVLCTRL_THRSHLD_OFFS              0
#define SETTINGS_REG_VPTT_LVLCTRL_THRSHLD_MASK              0x0000FFFFUL

/* Virtual PTT timing control register */
#define SETTINGS_REG_VPTT_TIMCTRL                           0x84
#define SETTINGS_REG_VPTT_TIMCTRL_DEFAULT                   (SETTINGS_REG_VPTT_TIMCTRL_TIMEOUT_DFLT)
/* TIMEOUT: Timeout (trailing) time in milliseconds in 12.4 format */
#define SETTINGS_REG_VPTT_TIMCTRL_TIMEOUT_DFLT              ((uint32_t) (20 << 4) << SETTINGS_REG_VPTT_TIMCTRL_TIMEOUT_OFFS)
#define SETTINGS_REG_VPTT_TIMCTRL_TIMEOUT_OFFS              0
#define SETTINGS_REG_VPTT_TIMCTRL_TIMEOUT_MASK              0xFFFFFFFFUL

/* Virtual COS level control register */
#define SETTINGS_REG_VCOS_LVLCTRL                           0x92
#define SETTINGS_REG_VCOS_LVLCTRL_DEFAULT                   (SETTINGS_REG_VCOS_LVLCTRL_THRSHLD_DFLT)
/* THRSHLD: Virtual COS threshold level */
#define SETTINGS_REG_VCOS_LVLCTRL_THRSHLD_DFLT              ((uint32_t) 256 << SETTINGS_REG_VCOS_LVLCTRL_THRSHLD_OFFS)
#define SETTINGS_REG_VCOS_LVLCTRL_THRSHLD_OFFS              0
#define SETTINGS_REG_VCOS_LVLCTRL_THRSHLD_MASK              0x0000FFFFUL

/* Virtual COS timing control register */
#define SETTINGS_REG_VCOS_TIMCTRL                           0x94
#define SETTINGS_REG_VCOS_TIMCTRL_DEFAULT                   (SETTINGS_REG_VCOS_TIMCTRL_TIMEOUT_DFLT)
/* TIMEOUT: Timeout (trailing) time in milliseconds in 12.4 format  */
#define SETTINGS_REG_VCOS_TIMCTRL_TIMEOUT_DFLT              ((uint32_t) (200 << 4) << SETTINGS_REG_VCOS_TIMCTRL_TIMEOUT_OFFS)
#define SETTINGS_REG_VCOS_TIMCTRL_TIMEOUT_OFFS              0
#define SETTINGS_REG_VCOS_TIMCTRL_TIMEOUT_MASK              0x0000FFFFUL

/* AIOC debug register 0 */
#define SETTINGS_REG_DBGAIOC0                               0xC0
#define SETTINGS_REG_DBGAIOC0_DEFAULT                       0
/* Various digital signal states */
#define SETTINGS_REG_DBGAIOC0_PTT1STATE_MASK                0x00010000UL
#define SETTINGS_REG_DBGAIOC0_PTT2STATE_MASK                0x00020000UL

/* UAC audio debug register 0 */
#define SETTINGS_REG_DBGAUDIO0                              0xD0
#define SETTINGS_REG_DBGAUDIO0_DEFAULT                      0
/* Playback or recording muted (master and first channel) */
#define SETTINGS_REG_DBGAUDIO0_RECMUTE0_MASK                0x00010000UL
#define SETTINGS_REG_DBGAUDIO0_RECMUTE1_MASK                0x00020000UL
#define SETTINGS_REG_DBGAUDIO0_PLAYMUTE0_MASK               0x00100000UL
#define SETTINGS_REG_DBGAUDIO0_PLAYMUTE1_MASK               0x00200000UL
/* Virtual PTT and COS states */
#define SETTINGS_REG_DBGAIOC0_VPTTSTATE_MASK                0x01000000UL
#define SETTINGS_REG_DBGAIOC0_VCOSSTATE_MASK                0x10000000UL

/* Playback and recording state */
#define SETTINGS_REG_DBGAUDIO0_RECSTATE_OFFS                24
#define SETTINGS_REG_DBGAUDIO0_RECSTATE_MASK                0x0F000000UL
#define SETTINGS_REG_DBGAUDIO0_RECSTATE_OFF_ENUM            0
#define SETTINGS_REG_DBGAUDIO0_RECSTATE_START_ENUM          1
#define SETTINGS_REG_DBGAUDIO0_RECSTATE_RUN_ENUM            2
#define SETTINGS_REG_DBGAUDIO0_PLAYSTATE_OFFS               28
#define SETTINGS_REG_DBGAUDIO0_PLAYSTATE_MASK               0xF0000000UL
#define SETTINGS_REG_DBGAUDIO0_PLAYSTATE_OFF_ENUM           0
#define SETTINGS_REG_DBGAUDIO0_PLAYSTATE_START_ENUM         1
#define SETTINGS_REG_DBGAUDIO0_PLAYSTATE_RUN_ENUM           2

/* Audio debug register 1 */
#define SETTINGS_REG_DBGAUDIO1                              0xD1
#define SETTINGS_REG_DBGAUDIO1_DEFAULT                      0

/* Audio debug register 2 */
#define SETTINGS_REG_DBGAUDIO2                              0xD2
#define SETTINGS_REG_DBGAUDIO2_DEFAULT                      0
/* Recording samplerate */
#define SETTINGS_REG_DBGAUDIO2_RECRATE_OFFS                 0
#define SETTINGS_REG_DBGAUDIO2_RECRATE_MASK                 0xFFFFFFFFUL

/* Audio debug register 3 */
#define SETTINGS_REG_DBGAUDIO3                              0xD3
#define SETTINGS_REG_DBGAUDIO3_DEFAULT                      0
/* Recording volume (master and first channel) */
#define SETTINGS_REG_DBGAUDIO3_RECVOL0_OFFS                 0
#define SETTINGS_REG_DBGAUDIO3_RECVOL0_MASK                 0x0000FFFFUL
#define SETTINGS_REG_DBGAUDIO3_RECVOL1_OFFS                 16
#define SETTINGS_REG_DBGAUDIO3_RECVOL1_MASK                 0xFFFF0000UL

/* TODO: D4, D5, D6 -> Recording buffer levels (avg/min/max) */

/* Audio debug register 4 */
#define SETTINGS_REG_DBGAUDIO4                              0xD4
#define SETTINGS_REG_DBGAUDIO4_DEFAULT                      0

/* Audio debug register 5 */
#define SETTINGS_REG_DBGAUDIO5                              0xD5
#define SETTINGS_REG_DBGAUDIO5_DEFAULT                      0

/* Audio debug register 6 */
#define SETTINGS_REG_DBGAUDIO6                              0xD6
#define SETTINGS_REG_DBGAUDIO6_DEFAULT                      0

/* Audio debug register 7 */
#define SETTINGS_REG_DBGAUDIO7                              0xD7
#define SETTINGS_REG_DBGAUDIO7_DEFAULT                      0

/* Audio debug register 8 */
#define SETTINGS_REG_DBGAUDIO8                              0xD8
#define SETTINGS_REG_DBGAUDIO8_DEFAULT                      0
/* Playback samplerate */
#define SETTINGS_REG_DBGAUDIO8_PLAYRATE_OFFS                0
#define SETTINGS_REG_DBGAUDIO8_PLAYRATE_MASK                0xFFFFFFFFUL

/* Audio debug register 9 */
#define SETTINGS_REG_DBGAUDIO9                              0xD9
#define SETTINGS_REG_DBGAUDIO9_DEFAULT                      0
/* Playback volume (master and first channel) */
#define SETTINGS_REG_DBGAUDIO9_PLAYVOL0_OFFS                 0
#define SETTINGS_REG_DBGAUDIO9_PLAYVOL0_MASK                 0x0000FFFFUL
#define SETTINGS_REG_DBGAUDIO9_PLAYVOL1_OFFS                 16
#define SETTINGS_REG_DBGAUDIO9_PLAYVOL1_MASK                 0xFFFF0000UL

/* Audio debug register 10 */
#define SETTINGS_REG_DBGAUDIO10                             0xDA
#define SETTINGS_REG_DBGAUDIO10_DEFAULT                     0
/* Average playback buffer level */
#define SETTINGS_REG_DBGAUDIO10_PLAYBUFAVG_OFFS             0
#define SETTINGS_REG_DBGAUDIO10_PLAYBUFAVG_MASK             0x0000FFFFUL

/* Audio debug register 11 */
#define SETTINGS_REG_DBGAUDIO11                             0xDB
#define SETTINGS_REG_DBGAUDIO11_DEFAULT                     0
/* Minimum playback buffer level */
#define SETTINGS_REG_DBGAUDIO11_PLAYBUFMIN_OFFS             0
#define SETTINGS_REG_DBGAUDIO11_PLAYBUFMIN_MASK             0x0000FFFFUL

/* Audio debug register 12 */
#define SETTINGS_REG_DBGAUDIO12                             0xDC
#define SETTINGS_REG_DBGAUDIO12_DEFAULT                     0
/* Maximum playback buffer level */
#define SETTINGS_REG_DBGAUDIO12_PLAYBUFMAX_OFFS             0
#define SETTINGS_REG_DBGAUDIO12_PLAYBUFMAX_MASK             0x0000FFFFUL

/* Audio debug register 13 */
#define SETTINGS_REG_DBGAUDIO13                             0xDD
#define SETTINGS_REG_DBGAUDIO13_DEFAULT                     0
/* Average UAC2.0 Feedback Value since last playback */
#define SETTINGS_REG_DBGAUDIO13_PLAYFBAVG_OFFS              0
#define SETTINGS_REG_DBGAUDIO13_PLAYFBAVG_MASK              0xFFFFFFFFUL

/* Audio debug register 14 */
#define SETTINGS_REG_DBGAUDIO14                             0xDE
#define SETTINGS_REG_DBGAUDIO14_DEFAULT                     0
/* Minimum UAC2.0 Feedback Value since last playback */
#define SETTINGS_REG_DBGAUDIO14_PLAYFBMIN_OFFS              0
#define SETTINGS_REG_DBGAUDIO14_PLAYFBMIN_MASK              0xFFFFFFFFUL

/* Audio debug register 15 */
#define SETTINGS_REG_DBGAUDIO15                             0xDF
#define SETTINGS_REG_DBGAUDIO15_DEFAULT                     0
/* Maximum UAC2.0 Feedback Value since last playback */
#define SETTINGS_REG_DBGAUDIO15_PLAYFBMAX_OFFS              0
#define SETTINGS_REG_DBGAUDIO15_PLAYFBMAX_MASK              0xFFFFFFFFUL



void Settings_Init();
uint8_t Settings_RegWrite(uint8_t address, const uint8_t * buffer, uint8_t bufsize);
uint8_t Settings_RegRead(uint8_t address, uint8_t * buffer, uint8_t bufsize);
void Settings_Store(void);
void Settings_Recall(void);
void Settings_Default(void);

#endif /* SETTINGS_H_ */
