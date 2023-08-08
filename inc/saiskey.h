/**
 * Copyright (c) 2014 Microsoft Open Technologies, Inc.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License"); you may
 *    not use this file except in compliance with the License. You may obtain
 *    a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
 *
 *    THIS CODE IS PROVIDED ON AN *AS IS* BASIS, WITHOUT WARRANTIES OR
 *    CONDITIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT
 *    LIMITATION ANY IMPLIED WARRANTIES OR CONDITIONS OF TITLE, FITNESS
 *    FOR A PARTICULAR PURPOSE, MERCHANTABILITY OR NON-INFRINGEMENT.
 *
 *    See the Apache Version 2.0 License for specific language governing
 *    permissions and limitations under the License.
 *
 *    Microsoft would like to thank the following companies for their review and
 *    assistance with these files: Intel Corporation, Mellanox Technologies Ltd,
 *    Dell Products, L.P., Facebook, Inc., Marvell International Ltd.
 *
 * @file    saiskey.h
 *
 * @brief   This module defines SAI skey interface
 */

#if !defined (__SAISKEY_H_)
#define __SAISKEY_H_

#include <saitypes.h>

/**
 * @defgroup SAISKEY SAI - skey specific API definitions
 *
 * @{
 */

/**
 * @brief Defines maximum length of key.
 */
#define SAI_SKEY_KEY_SIZE 25

/**
 * @brief Attribute Id for skey
 */
typedef enum _sai_skey_attr_t
{
    /**
     * @brief Start of attributes
     */
    SAI_SKEY_ATTR_START,

    /**
     * @brief Key [char[SAI_SKEY_KEY_SIZE]]
     *
     * @type char
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_SKEY_ATTR_KEY = SAI_SKEY_ATTR_START,

    /**
     * @brief Serial number
     *
     * @type sai_uint64_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_SKEY_ATTR_SN,

    /**
     * @brief MAC address of the switch
     *
     * @type sai_mac_t
     * @flags MANDATORY_ON_CREATE | CREATE_ONLY
     */
    SAI_SKEY_ATTR_MAC,

    /**
     * @brief End of attributes
     */
    SAI_SKEY_ATTR_END,

} sai_skey_attr_t;

/**
 * @brief Create a service key
 *
 * @param[out] skey_id Service Key
 * @param[in] switch_id Switch Object id
 * @param[in] attr_count Number of attributes
 * @param[in] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_create_skey_fn)(
        _Out_ sai_object_id_t *skey_id,
        _In_ sai_object_id_t switch_id,
        _In_ uint32_t attr_count,
        _In_ const sai_attribute_t *attr_list);

/**
 * @brief Delete a service key
 *
 * @param[in] skey_id Service Key
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_remove_skey_fn)(
        _In_ sai_object_id_t skey_id);

/**
 * @brief Set service key attribute
 *
 * @param[in] skey_id Service Key
 * @param[in] attr Attribute
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_set_skey_attribute_fn)(
        _In_ sai_object_id_t skey_id,
        _In_ const sai_attribute_t *attr);

/**
 * @brief Get service key attribute
 *
 * @param[in] skey_id Service Key
 * @param[in] attr_count Number of attributes
 * @param[inout] attr_list Array of attributes
 *
 * @return #SAI_STATUS_SUCCESS on success, failure status code on error
 */
typedef sai_status_t (*sai_get_skey_attribute_fn)(
        _In_ sai_object_id_t skey_id,
        _In_ uint32_t attr_count,
        _Inout_ sai_attribute_t *attr_list);

/**
 * @brief Service key methods table retrieved with sai_api_query()
 */
typedef struct _sai_skey_api_t
{
    sai_create_skey_fn          create_skey;
    sai_remove_skey_fn          remove_skey;
    sai_set_skey_attribute_fn   set_skey_attribute;
    sai_get_skey_attribute_fn   get_skey_attribute;
} sai_skey_api_t;

/**
 * @}
 */
#endif /** __SAISKEY_H_ */
