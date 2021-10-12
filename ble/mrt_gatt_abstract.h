/**
  *@file mrt_gatt_abstract.h
  *@brief Abstraction of ESP32 Gatt server. Made to work with MrT GATT modules
  *@author Jason Berger
  *@date 10/12/21
  */

#ifdef MRT_GATT_MODULE_ENABLED

#pragma once
#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>


/* Exported types ------------------------------------------------------------*/

typedef enum{
    ATTR_NONE,
	  ATTR_CHR,
    ATTR_CHR_VALUE,
    ATTR_CHR_DESCRIPTOR,
    ATTR_SERVICE
}attrib_type_e;

typedef uint32_t mrt_gatt_evt_status_t;
typedef uint32_t mrt_status_t;

typedef struct mrt_gatt_svc_t mrt_gatt_svc_t;                             //forward declare for self referencing callback
typedef struct mrt_gatt_char_t mrt_gatt_char_t;                             //forward declare for self referencing callback
typedef mrt_status_t (*mrt_profile_init)(void);

typedef struct{
    attrib_type_e mType;
    void* mPtr;
} attrib_table_entry_t;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define MRT_GATT_DATA_ATTR const


/* Exported functions ------------------------------------------------------- */

/**
 * @brief allocates attribute table 
 * @param attrCount number of attributes
 */
void MRT_GATT_ALLOCATE_ATTRIBUTE_TABLE(int attrCount);


/**
 * @brief registers a callback to our profile init function. This way we can inject it into their init function
 * @param cbInit callback to initialize profile
 * @return mrt_status_t 
 */
mrt_status_t MRT_GATT_REGISTER_PROFILE_INIT(mrt_profile_init cbInit);

/**
 * @brief Register our service with the server
 * @param svc ptr to service (with all characteristics already added)
 */
mrt_status_t MRT_GATT_REGISTER_SERVICE(mrt_gatt_svc_t* svc);

/**
 * @brief updates characteristic value if it has changed
 * @param chr ptr to characteristic
 * @param data ptr to data to update from
 * @param len size of data (in bytes)
 */
mrt_status_t MRT_GATT_UPDATE_CHAR(mrt_gatt_char_t* chr, uint8_t* data, int len);

/**
 * @brief Forces update even if data is the same
 * @param chr ptr to characteristic
 * @param data ptr to data to update from
 * @param len size of data (in bytes)
 */
mrt_status_t MRT_GATT_FORCE_UPDATE_CHAR(mrt_gatt_char_t* chr, uint8_t* data, int len);


#ifdef __cplusplus
}
#endif

#endif /*MRT_GATT_MODULE_ENABLED*/


