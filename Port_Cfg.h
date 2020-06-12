/*
 * Port_Cfg.h
 *
 *  Created on: ١٩‏/٠٣‏/٢٠٢٠
 *      Author: JOHN
 */


#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_OFF)

/* Pre-compile option for presence of Port_SetPinDirection API*/
#define PORT_SET_PIN_DIRECTION_API                (STD_ON)

/* Number of the configured Port Channels */
#define PORT_CONFIGURED_CHANNLES              (32U)     /* el mafrod el port driver by-configure kol el pins el 3andy 7ata el ana m4 hst3mlhom y3ny el 32 pins kolhm ....w lw feh pin m4 hst3mlha fa el default bta3ha howa eny a3mlha input pin ......da el default ..fa el mohm y3ny el no of channels htb2a 32 channels....*/


/* el port driver el mafrod y-configure el 32 pins kolhm bto3 el micro bta3k m4 el pins el enta htst3mlha bs(LED,BUTTON) ......la2 kolo....w kolo yero7 ll structure .....*/

/* dy e; pin bta3t el button */
#define portConf_BUTTON_ID_INDX                           0X00
#define portConf_BUTTON_PORT_NUMBER                       PORTD_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER                    PORT_PIN3
#define portConf_BUTTON_CHANNEL_DIRECTION                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE      FALSE    // mynf34 a3'yr el direction bta3 el button w led tb3an .....

/* dy el pin bta3t el LED */
#define portConf_LED_ID_INDX                              0X01
#define portConf_LED_PORT_NUMBER                          PORTC_ID
#define portConf_LED_CHANNEL_NUMBER                       PORT_PIN5
#define portConf_LED_CHANNEL_DIRECTION                    PORT_PIN_OUT
#define portConf_LED_CHANNEL_OUTPUT_PIN_MODE	          initial_Low
#define portConf_LED_CHANNEL_DIRECTION_CHANGAEBLE         FALSE    // mynf34 a3'yr el direction bta3 el button w led tb3an .....


/* rest of the pins ....................*/

// el default en ay pin lw m4 hst3mlha ha7otha b input ... da el default ................

/* howa ana kateb f el define _BUTTON_ da bs 34an kont b3ml copy w paste :D.... */

#define portConf_BUTTON_PORT_NUMBER0                       PORTA_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER0                    PORT_PIN0
#define portConf_BUTTON_CHANNEL_DIRECTION0                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE0	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE0         TRUE


#define portConf_BUTTON_PORT_NUMBER1                       PORTA_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER1                    PORT_PIN1
#define portConf_BUTTON_CHANNEL_DIRECTION1                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE1	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE1         TRUE


#define portConf_BUTTON_PORT_NUMBER2                       PORTA_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER2                    PORT_PIN2
#define portConf_BUTTON_CHANNEL_DIRECTION2                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE2	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE2         TRUE


#define portConf_BUTTON_PORT_NUMBER3                       PORTA_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER3                    PORT_PIN3
#define portConf_BUTTON_CHANNEL_DIRECTION3                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE3	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE3         TRUE


#define portConf_BUTTON_PORT_NUMBER4                       PORTA_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER4                    PORT_PIN4
#define portConf_BUTTON_CHANNEL_DIRECTION4                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE4	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE4         TRUE


#define portConf_BUTTON_PORT_NUMBER5                       PORTA_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER5                    PORT_PIN5
#define portConf_BUTTON_CHANNEL_DIRECTION5                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE5	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE5         TRUE


#define portConf_BUTTON_PORT_NUMBER6                       PORTA_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER6                    PORT_PIN6
#define portConf_BUTTON_CHANNEL_DIRECTION6                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE6	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE6         TRUE


#define portConf_BUTTON_PORT_NUMBER7                       PORTA_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER7                    PORT_PIN7
#define portConf_BUTTON_CHANNEL_DIRECTION7                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE7	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE7         TRUE


#define portConf_BUTTON_PORT_NUMBER8                       PORTB_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER8                    PORT_PIN0
#define portConf_BUTTON_CHANNEL_DIRECTION8                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE8	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE8         TRUE


#define portConf_BUTTON_PORT_NUMBER9                       PORTB_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER9                   PORT_PIN1
#define portConf_BUTTON_CHANNEL_DIRECTION9                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE9	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE9         TRUE


#define portConf_BUTTON_PORT_NUMBER10                       PORTB_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER10                    PORT_PIN2
#define portConf_BUTTON_CHANNEL_DIRECTION10                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE10	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE10         TRUE


#define portConf_BUTTON_PORT_NUMBER11                       PORTB_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER11                    PORT_PIN3
#define portConf_BUTTON_CHANNEL_DIRECTION11                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE11	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE11      TRUE


#define portConf_BUTTON_PORT_NUMBER12                       PORTB_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER12                    PORT_PIN4
#define portConf_BUTTON_CHANNEL_DIRECTION12                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE12	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE12         TRUE


#define portConf_BUTTON_PORT_NUMBER13                       PORTB_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER13                    PORT_PIN5
#define portConf_BUTTON_CHANNEL_DIRECTION13                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE13	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE13         TRUE


#define portConf_BUTTON_PORT_NUMBER14                       PORTB_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER14                    PORT_PIN6
#define portConf_BUTTON_CHANNEL_DIRECTION14                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE14	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE14         TRUE


#define portConf_BUTTON_PORT_NUMBER15                       PORTB_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER15                    PORT_PIN7
#define portConf_BUTTON_CHANNEL_DIRECTION15                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE15	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE15         TRUE


#define portConf_BUTTON_PORT_NUMBER16                       PORTC_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER16                    PORT_PIN0
#define portConf_BUTTON_CHANNEL_DIRECTION16                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE16	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE16         TRUE


#define portConf_BUTTON_PORT_NUMBER17                       PORTC_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER17                    PORT_PIN1
#define portConf_BUTTON_CHANNEL_DIRECTION17                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE17	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE17         TRUE


#define portConf_BUTTON_PORT_NUMBER18                       PORTC_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER18                    PORT_PIN2
#define portConf_BUTTON_CHANNEL_DIRECTION18                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE18	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE18         TRUE


#define portConf_BUTTON_PORT_NUMBER19                       PORTC_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER19                    PORT_PIN3
#define portConf_BUTTON_CHANNEL_DIRECTION19                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE19	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE19         TRUE


#define portConf_BUTTON_PORT_NUMBER20                       PORTC_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER20                    PORT_PIN4
#define portConf_BUTTON_CHANNEL_DIRECTION20                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE20	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE20         TRUE


// el PIN 21 el hya rakam 5 fe portc dy el hya el LED .......
#define portConf_BUTTON_PORT_NUMBER22                       PORTC_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER22                    PORT_PIN6   // PIN5 dy el hya el LED ................el ana m3rfha fo2 aslun.....
#define portConf_BUTTON_CHANNEL_DIRECTION22                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE22	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE22         TRUE


#define portConf_BUTTON_PORT_NUMBER23                       PORTC_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER23                    PORT_PIN7
#define portConf_BUTTON_CHANNEL_DIRECTION23                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE23	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE23         TRUE



#define portConf_BUTTON_PORT_NUMBER24                       PORTD_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER24                    PORT_PIN0
#define portConf_BUTTON_CHANNEL_DIRECTION24                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE24	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE24         TRUE


#define portConf_BUTTON_PORT_NUMBER25                       PORTD_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER25                    PORT_PIN1
#define portConf_BUTTON_CHANNEL_DIRECTION25                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE25	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE25         TRUE


// el PIN 26 el hya rakam 2 fe PORTD dy el hya el button fo2......

#define portConf_BUTTON_PORT_NUMBER27                       PORTD_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER27                    PORT_PIN3   // PIN2 dy bta3t el BUTTON ....el ana m3rfha fo2 aslun.....
#define portConf_BUTTON_CHANNEL_DIRECTION27                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE27	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE27         TRUE


#define portConf_BUTTON_PORT_NUMBER28                       PORTD_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER28                    PORT_PIN4
#define portConf_BUTTON_CHANNEL_DIRECTION28                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE28	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE28         TRUE


#define portConf_BUTTON_PORT_NUMBER29                       PORTD_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER29                    PORT_PIN5
#define portConf_BUTTON_CHANNEL_DIRECTION29                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE29	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE29         TRUE


#define portConf_BUTTON_PORT_NUMBER30                       PORTD_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER30                    PORT_PIN6
#define portConf_BUTTON_CHANNEL_DIRECTION30                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE30	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE30         TRUE


#define portConf_BUTTON_PORT_NUMBER31                       PORTD_ID    // el #defines el fe el Port.h file EL ana m3raf kol el pins w el Ports feha...........
#define portConf_BUTTON_CHANNEL_NUMBER31                    PORT_PIN7
#define portConf_BUTTON_CHANNEL_DIRECTION31                 PORT_PIN_IN
#define portConf_BUTTON_CHANNEL_INPUT_PIN_MODE31	          Disable_Pull_Up
#define portConf_BUTTON_CHANNEL_DIRECTION_CHANGAEBLE31         TRUE





#endif /* PORT_CFG_H_ */
