/*
 * Port.h
 *
 *  Created on: ١٩‏/٠٣‏/٢٠٢٠
 *      Author: JOHN
 */


// allez el zamalek ya 3omryyyyyyyyyyyyyyyyyyyyyyyyyy ...................


#ifndef PORT_H
#define PORT_H

/*
/* Id for the company in the AUTOSAR
 * for example John's ID = 2000 :p   */
#define PORT_VENDOR_ID    (1U)

/* Port Module Id */
#define PORT_MODULE_ID    (124U)  // gebto mn el document el BSW ...............................

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Port_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Port_Cfg.h does not match the expected version"
#endif

/* Non AUTOSAR files */
#include "Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* el function ID btb2a mwgoda m3 el function f el SWS doc.  */
/* Service ID for PORT Initialization  */
#define PORT_INIT_SID           				     (uint8)0x00

/* Service ID for PORT set pin direction */
#define PORT_SET_PIN_DIRECTION_SID          		 (uint8)0x01

/* Service ID for PORT refresh direction */
#define PORT_REFRESH_PORT_DIRECTION_SID              (uint8)0x02

/* Service ID for Port GetVersionInfo */
#define PORT_GET_VERSION_INFO_SID                    (uint8)0x12

/* Service ID for PORT set pin mode */
#define PORT_SET_PIN_MODE_SID						 (uint8)0x04

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* slide 26 f el SWS ....error classification .............ch.7......
 *
 */
/* Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN 			   (uint8)0x0A

/* Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE  (uint8)0x0B

/* API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_CONFIG 		   (uint8)0x0C

/* API Port_SetPinMode service called with invalid mode */
#define PORT_E_PARAM_INVALID_MODE 	   (uint8)0x0D

/* API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE 	   (uint8)0x0E   // lw el pin el ana 3ayz a3'yrha f el runtime dy unchangable mynf34 a3'yrha ....

/* API service called without module initialization */
#define PORT_E_UNINIT 				   (uint8)0x0F

/* APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER 		   (uint8)0x10

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
/* ch.8 ...type definitions.....*/

typedef uint8 Port_PinType;
typedef uint8 Port_PinModeType;     /* m4 applicable f el atmega16 hena la2n mfy4 7war el modes da..........*/
typedef uint8 Port_PortType;


/* da el variable el hy4of el changeability bta3 el direction bta3 el pin(ynfa3 a3'yr el direction wla la2 ?? ....*/
// afta7 el SWS w shof el parameter da fe anhy container (slide 42)....

typedef boolean Port_Pin_Direction_Changaeble;




typedef enum            // mwgoda f el SWS dy .......................
{
	PORT_PIN_IN,PORT_PIN_OUT  /* el input b zero w el output b 1 ...................... mfy4 " ; " fe a5er el satr a7a mtnsa4 ..............*/
}Port_PinDirectionType;


typedef enum {      // ana el 3amelha h7tagha f el config channel struct ...... shof el comments bta3t el DIO driver w htfham .....
	Disable_Pull_Up,
	Enable_Pull_Up
} Port_Input_Mode;

typedef enum {        // ana el 3amelha h7tagha f el config channel struct ...... shof el comments bta3t el DIO driver w htfham .....
	initial_Low,
	initial_High
} Port_output_Mode;

typedef struct {      // dy ana el 3amelha ...........hst3mlha f el ConfigType struct..... fa dy feha el port w rakam el pin w el direction w el mode bta3 el pin dy .............

	Port_PortType port;
	Port_PinType pin_num;
	Port_PinDirectionType direction;
	Port_Input_Mode pin_in_mode;
	Port_output_Mode pin_out_mode;
	Port_Pin_Direction_Changaeble pin_change;

} Port_ConfigChannel;

typedef struct
{
	 Port_ConfigChannel port_channels[PORT_CONFIGURED_CHANNLES];
}Port_ConfigType;


/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/
/* bardo ch.8 ...........  8.3  Function definitions .................
 *
 */
/* Initializes the Port Driver module */
void Port_Init(const Port_ConfigType *ConfigPtr);  //1

/* Sets the port pin direction */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);  //1
#endif

/* Refreshes port direction */
void Port_RefreshPortDirection(void);

/* Returns the version information of this module */
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo);   //1

/*Sets the port pin mode*/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);  //1


/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
/* Extern PB structures to be used by Port and other modules */  /* kan mmkn a7otha f el Port_PBCfg.h bs m4 lazm mmkn a7otha f el Port.h 3ltol............*/
extern const Port_ConfigType Port_Configuration;


/*********************************************************************************
 * 						PIN Definitions 														 *
 * *******************************************************************************/

#define PORTA_ID					(0U)
#define PORTB_ID					(1U)
#define PORTC_ID					(2U)
#define PORTD_ID					(3U)

#define PORT_PIN0 					        (Port_PinType)0
#define PORT_PIN1 							(Port_PinType)1
#define PORT_PIN2 							(Port_PinType)2
#define PORT_PIN3 							(Port_PinType)3
#define PORT_PIN4 							(Port_PinType)4
#define PORT_PIN5 							(Port_PinType)5
#define PORT_PIN6 							(Port_PinType)6
#define PORT_PIN7 							(Port_PinType)7

#define PINS_NUM						(32U)
#define PINS_PER_PORT					(8U)
#define NUMBER_OF_PORTS					(4U)

#define PORT_A                          (0U)
#define PORT_A_START					(0U)
#define PORT_A_FINISH					(7U)

#define PORT_B							(1U)
#define PORT_B_START					(8U)
#define PORT_B_FINISH					(15U)

#define PORT_C							(2U)
#define PORT_C_START					(16U)
#define PORT_C_FINISH					(23U)

#define PORT_D							(3U)
#define PORT_D_START					(24U)
#define PORT_D_FINISH					(31U)

#define PIN_0							(0U)
#define PIN_1							(1U)
#define PIN_2							(2U)
#define PIN_3							(3U)
#define PIN_4							(4U)
#define PIN_5							(5U)
#define PIN_6							(6U)
#define PIN_7							(7U)
#define PIN_8							(8U)
#define PIN_9							(9U)
#define PIN_10							(10U)
#define PIN_11							(11U)
#define PIN_12							(12U)
#define PIN_13							(13U)
#define PIN_14							(14U)
#define PIN_15							(15U)
#define PIN_16							(16U)
#define PIN_17							(17U)
#define PIN_18							(18U)
#define PIN_19							(19U)
#define PIN_20							(20U)
#define PIN_21							(21U)
#define PIN_22							(22U)
#define PIN_23							(23U)
#define PIN_24							(24U)
#define PIN_25							(25U)
#define PIN_26							(26U)
#define PIN_27							(27U)
#define PIN_28							(28U)
#define PIN_29							(29U)
#define PIN_30							(30U)
#define PIN_31							(31U)

#endif /* PORT_H */






