/*
 * Port.c
 *
 *  Created on: ١٩‏/٠٣‏/٢٠٢٠
 *      Author: JOHN
 */



#include "Port.h"
#include "Dio_Regs.h"

#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"
/* AUTOSAR Version checking between Det and Dio Modules */
#if ((DET_AR_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 || (DET_AR_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 || (DET_AR_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Det.h does not match the expected version"
#endif

#endif

STATIC uint8 Port_Status = PORT_NOT_INITIALIZED ;
STATIC Port_ConfigChannel *port_PortChannels = NULL_PTR;   /* da pointer mn no3 el structure el howa ConfigChannel  ... el howa feh kol 7aga ...el howa ana 3mlto mn nafsy kda mkn4 mwgod f el types ely ana el mafrod a3mlha ...w ana 3mlto 34an ast5dmo f el struct el esmo Port_ConfigType...........lama 3amalt array mn el Configchannel da b 3adad el ports bta3ty......               ..*/


STATIC Port_PortType get_portID(Port_PinType pin){   // ana el 3amelha m4 f el SWS..
	Port_PortType port_id ;
	if ((pin >= PORT_A_START) && (pin <= PORT_A_FINISH))
	{
		port_id = PORTA_ID;
	}
	else if ((pin >= PORT_B_START) && (pin <= PORT_B_FINISH))
	{
		port_id = PORTB_ID;
	}
	else if ((pin >= PORT_C_START) && (pin <= PORT_C_FINISH))
	{
		port_id = PORTC_ID;
	}
	else if ((pin >= PORT_D_START) && (pin <= PORT_D_FINISH))
	{
		port_id = PORTD_ID;

	}
	else
	{

	}

	return port_id;
}


STATIC Port_PinType get_pinID(Port_PinType pin){
	Port_PinType pin_id ;
	pin_id = (Port_PortType) pin% PINS_PER_PORT ;
	return pin_id;
}

/********************************Functions*********************************/


void Port_Init(const Port_ConfigType* ConfigPtr)  // hygelha struct el feh el init conditions...el howa mwgod f el " Port_PBcfg.c " el hya el link time configs.....*/
{
	Port_PortType *DDR_ptr;
	Port_PortType *port_ptr;
	boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* check if the input configuration pointer is not a NULL_PTR */
	if (NULL_PTR == ConfigPtr)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
		     PORT_E_PARAM_CONFIG);
		error = TRUE;
	}
	else
#endif
    if(FALSE == error)
	{
		port_PortChannels = ConfigPtr->port_channels;  // el port channels el by4awr 3leha el ConfigPtr da h7otha f el pointer el esmo PortChannels da....
		for (int itr = 0; itr < PORT_CONFIGURED_CHANNLES; itr++) {
			/*get port */
			switch (port_PortChannels[itr].port) {  // awl 7aga h4of rakam el port...
			case PORTA_ID: DDR_ptr  = &DDRA_REG;
						   port_ptr = &PORTA_REG;
			break;
			case PORTB_ID: DDR_ptr  = &DDRB_REG;
						   port_ptr = &PORTB_REG;
			break;
			case PORTC_ID: DDR_ptr  = &DDRC_REG;
						   port_ptr = &PORTC_REG;
			break;
			case PORTD_ID: DDR_ptr  = &DDRD_REG;
						   port_ptr = &PORTD_REG;
			break;
			}
			if(PORT_PIN_IN==port_PortChannels[itr].direction)  // h4of el direction input wla output .... fa awl 7aga lw input zay el push button lazm a7ded howa pull up wla la2.........
			{
				CLEAR_BIT(*DDR_ptr,port_PortChannels[itr].pin_num);
				if (Disable_Pull_Up == port_PortChannels[itr].pin_in_mode)
				{
					CLEAR_BIT(*port_ptr, port_PortChannels[itr].pin_num);

				}
				else if(Enable_Pull_Up== port_PortChannels[itr].pin_in_mode)
				{
					SET_BIT(*port_ptr, port_PortChannels[itr].pin_num);
				}
				else
				{

				}

			}
			else if(PORT_PIN_OUT==port_PortChannels[itr].direction)   // tab lw output ... lazm a7ded el initial value b kam..
			{
				SET_BIT(*DDR_ptr,port_PortChannels[itr].pin_num);
				if (initial_Low==port_PortChannels[itr].pin_out_mode)
				{
					CLEAR_BIT(*port_ptr,port_PortChannels[itr].pin_num);

				}
				else if (initial_High==port_PortChannels[itr].pin_out_mode)
				{
					SET_BIT(*port_ptr,port_PortChannels[itr].pin_num);
				}
				else
				{

				}

			}
			else
			{

			}

		}//end For Loop
		Port_Status = PORT_INITIALIZED;   // kda yb2a initialized .... 34an m4 y-report error b3d kda....34an m4 h3raf a3ml ay operation tany ela lw howa initialized.....
	}
}


#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction) {  /* 5aly balak el function dy runtime function 34an lw 3ayz a3'yr pin mo3yna f el runtime....*/
	Port_PortType *DDR_ptr;
	Port_PortType local_port;
	Port_PinType local_pin;
	boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if (Port_Status == PORT_NOT_INITIALIZED)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,PORT_E_UNINIT);  /* hena el function id hya el init function la2n kda aslun el pins not initialized fa hya el mo4kla feha hya ..........*/
	    error = TRUE;
	}
	if (PORT_CONFIGURED_CHANNLES <= Pin)   /* dy ana zwdtha aho .... lw invalid Port Pin ID requested .....(DET error).....*/
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
			error = TRUE;
		}
	if (port_PortChannels[Pin].pin_change == FALSE)  /* dy ana zwdtha bardo aho ... lw el pin direction aslun unchangable(mynf34 a3'yr el pin direction) .....5aly balak el parameter da m3mol l pins mo3yna m4 ll pins kolha ...la2n feh pins 3ady changable lakn fe pins la2 ..fa hya lazm t4of el pin el gaya dy bl t7ded el enta 3ayz t3'yr el direction bta3ha....*/
	{
		Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,PORT_E_DIRECTION_UNCHANGEABLE);
	    error = TRUE;
	}
	else
#endif
	if(FALSE == error)
	{
		local_port = get_portID(Pin);   // ana aslun 3ayz el ID 34an a-set el direction 34an kda 3mlt el function el fo2 dy ....
		local_pin = get_pinID(Pin);
		switch (local_port) {
		case PORTA_ID:DDR_ptr = &DDRA_REG;
		break;
		case PORTB_ID:DDR_ptr = &DDRB_REG;
		break;
		case PORTC_ID:DDR_ptr = &DDRC_REG;
		break;
		case PORTD_ID:DDR_ptr = &DDRD_REG;
		break;
		}

		if (PORT_PIN_OUT == Direction)
		{
			SET_BIT(*DDR_ptr, local_pin);

		}
		else if (PORT_PIN_IN == Direction)
		{
			CLEAR_BIT(*DDR_ptr, local_pin);

		}
		else
		{

		}
	}

}
#endif

#if (PORT_VERSION_INFO_API == STD_ON)
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	/* Check if input pointer is not Null pointer */
	if(NULL_PTR == versioninfo)
	{
		/* Report to DET  */
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
	}
	else
#endif /* (PORT_DEV_ERROR_DETECT == STD_ON) */
	{
		/* Copy the vendor Id */
		versioninfo->vendorID = (uint16)PORT_VENDOR_ID;
		/* Copy the module Id */
		versioninfo->moduleID = (uint16)PORT_MODULE_ID;
		/* Copy Software Major Version */
		versioninfo->sw_major_version = (uint8)PORT_SW_MAJOR_VERSION;
		/* Copy Software Minor Version */
		versioninfo->sw_minor_version = (uint8)PORT_SW_MINOR_VERSION;
		/* Copy Software Patch Version */
		versioninfo->sw_patch_version = (uint8)PORT_SW_PATCH_VERSION;
	}
}
#endif





void Port_RefreshPortDirection(void)  /* a3tkd hya hya htb2a zay el init function la2ny h3ml refresh ll direction bta3 el ports bardo mfy4 gded .......*/
{
	    Port_PortType *DDR_ptr;
        Port_PortType *port_ptr;
        boolean error = FALSE;

        /* Det errors */
#if (PORT_DEV_ERROR_DETECT == STD_ON)
	if (Port_Status == PORT_NOT_INITIALIZED)
	{
		Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,PORT_E_UNINIT);
		error = TRUE;
	}
#endif
	if(FALSE == error)
	{
		for (int itr = 0; itr < PORT_CONFIGURED_CHANNLES; itr++) {
			/*get port */
			switch (port_PortChannels[itr].port) {  // awl 7aga h4of rakam el port...
			case PORTA_ID: DDR_ptr  = &DDRA_REG;
						   port_ptr = &PORTA_REG;
			break;
			case PORTB_ID: DDR_ptr  = &DDRB_REG;
						   port_ptr = &PORTB_REG;
			break;
			case PORTC_ID: DDR_ptr  = &DDRC_REG;
						   port_ptr = &PORTC_REG;
			break;
			case PORTD_ID: DDR_ptr  = &DDRD_REG;
						   port_ptr = &PORTD_REG;
			break;
			}
			if(PORT_PIN_IN==port_PortChannels[itr].direction)
			{
				CLEAR_BIT(*DDR_ptr,port_PortChannels[itr].pin_num);
			}
			else if(PORT_PIN_OUT==port_PortChannels[itr].direction)
			{
				SET_BIT(*DDR_ptr,port_PortChannels[itr].pin_num);
			}





		}//end For Loop
	}
}

void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode)
{
	/* el function dy mlha4 lazma fe 7alet enna bnst3ml atmega16 la2n kda kda ay pin t2dar t4t3'l f el mode el hya 3ayzah mn 3'er ma a3'yro 3aks el tm4c123 msln ...bs tb3an lazm tb2a mwgoda f el driver .....w hasebha fadya ....h3ml el DET error bs kda w asebha fadya ......*/
    /* eih b2a el DET errors bta3tha....lw ft7t el SWS htla2y en el pin dy el mode bta3ha aslun unchangable aslun ....aw en el mode da aslun 3'lt...y3ny wrong mode ....aw en el pin aslun m4 initialized.....*/

	boolean error = FALSE;

#if (PORT_DEV_ERROR_DETECT == STD_ON)    /* Report Errors */

	if (Port_Status == PORT_NOT_INITIALIZED)  // 1- non initialized pin ......
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,PORT_E_UNINIT);
			error = TRUE;
		}

	/* hena f el atmega16 el mode m4 hyt3'yr aslun */
	if (PORT_E_MODE_UNCHANGEABLE == STD_ON)  // 2- unchangable pin mode ( el mode mynf34 yt3'yr aslun) ......
		{
			Det_ReportError(PORT_MODULE_ID,PORT_INSTANCE_ID,PORT_SET_PIN_DIRECTION_SID,PORT_E_MODE_UNCHANGEABLE);
		    error = TRUE;
		}

	if (PORT_E_PARAM_INVALID_MODE <= Mode)   // 3- invalid mode ... el mode aslun 3'lt .....
		{
			Det_ReportError(PORT_MODULE_ID, PORT_INSTANCE_ID,
				PORT_SET_PIN_MODE_SID, PORT_E_PARAM_INVALID_MODE);
			error = TRUE;
		}

#endif
}



