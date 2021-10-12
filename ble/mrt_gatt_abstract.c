/**
  *@file mrt_gatt_abstract.c
  *@brief header for 
  *@author dev
  *@date 10/12/21
  */

#ifdef MRT_GATT_MODULE_ENABLED


/* Includes ------------------------------------------------------------------*/
#include "Platforms/ESP32/ble/mrt_gatt_abstract.h"
#include "Utilities/Interfaces/GattServer/gatt_server.h"

/* Private Variables ---------------------------------------------------------*/
static bool ServerInitialized = false;                                      /* flag to make sure server is initialized before updating chars*/


/* Functions -----------------------------------------------------------------*/



void MRT_GATT_ALLOCATE_ATTRIBUTE_TABLE(int attrCount)
{
    
}



uint32_t MRT_GATT_REGISTER_SERVICE(mrt_gatt_svc_t* svc)
{


    /* Add each Characteristic in the service*/
    for(int i = 0; i < svc->mCharCount; i++)
    {
        mrt_gatt_char_t* chr = svc->mChars[i];

        

    }
   return MRT_STATUS_OK;
}

mrt_status_t MRT_GATT_UPDATE_CHAR(mrt_gatt_char_t* chr, uint8_t* data, int len)
{
    mrt_status_t status = MRT_STATUS_ERROR;

    if(!ServerInitialized) /* If server is not initialized, return error*/
    {
        return status;
    }

    if ((len <= chr->mCache.mLen) && (memcmp((void*)chr->mCache.mData, data, len) == 0)) //(memcmp((void*)chr->mCache.mData, data, len) == 0)
    {
    	status = MRT_STATUS_OK;
    }
    else
    {
		memcpy((void*)chr->mCache.mData, data, len ); //Update Cache
		chr->mCache.mLen = len;

        //TODO update through native api
		// status = aci_gatt_update_char_value(chr->mSvc->mHandle ,
		// 						 chr->mHandle,
		// 						  0, /* charValOffset */
		// 						 len, /* charValueLen */
		// 						 data);
    }
    return status;
}

mrt_status_t MRT_GATT_FORCE_UPDATE_CHAR(mrt_gatt_char_t* chr, uint8_t* data, int len)
{
    mrt_status_t status = MRT_STATUS_ERROR;

    if(!ServerInitialized) /* If server is not initialized, return error*/
    {
        return status;
    }

    memcpy((void*)chr->mCache.mData, data, len ); //Update Cache
    chr->mCache.mLen = len;


    //TODO update through native api
    // status = aci_gatt_update_char_value(chr->mSvc->mHandle ,
    // 						 chr->mHandle,
    // 						  0, /* charValOffset */
    // 						 len, /* charValueLen */
    // 						 data);
    
    return status;
}



#endif /*MRT_GATT_MODULE_ENABLED*/