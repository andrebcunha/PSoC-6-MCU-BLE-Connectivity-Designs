/*******************************************************************************
* File Name: hps.h
* Version 1.0
*
* Description:
*  Contains the function prototypes and constants used by HTTP Proxy Service.
*
********************************************************************************
* Copyright 2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include <project.h>


/***************************************
*       Data Struct Definition
***************************************/

/** HPS Characteristic value parameter structure */
typedef struct
{
    uint16_t statusCode;                                  /**< Status Code */
    uint8_t  dataStatus;                                  /**< Data Status */
} hps_ntf_data_t;

/** HPS send request states */
typedef enum
{
    STATE_FILL_URI = 0x00u,
    STATE_FILL_HTTP_HEADERS,
    STATE_FILL_ENTITY_BODY,
    STATE_SEND_REQUEST
}http_send_request_state_t;

/** HPS read response states */
typedef enum
{
    STATE_READ_HTTP_HEADERS = 0x00u,
    STATE_READ_ENTITY_BODY
}http_read_response_state_t;


/***************************************
*          Constants
***************************************/

/* HPS Characteristic Size */
#define HPS_HTTP_HEADER_SIZE                (512u)
#define HPS_HTTP_BODY_SIZE                  (HPS_HTTP_HEADER_SIZE)
#define HPS_HTTP_URI_SIZE                   (HPS_HTTP_HEADER_SIZE)

#define HPS_HTTP_REQ_URI_SIZE               (27u)
#define HPS_HTTP_GET_HEADER_SIZE            (100u)
#define HPS_HTTP_LED_ON_SIZE                (12u)
#define HPS_HTTP_LED_OFF_SIZE               (13u)

#define HPS_CCCD_CONFIG_SIZE                (2u)

#define HPS_HTTP_NOTIFICATION_SIZE          (3u)

/* HTTP Status codes */
/* 1xx Informational */
#define HPS_HTTP_CONTINUE                   (100u)
#define HPS_HTTP_SWITCHING_PROTOCOLS        (101u)
#define HPS_HTTP_PROCESSING                 (102u)
#define HPS_HTTP_NAME_NOT_RESOLVED          (105u)
/* 2xx Success */
#define HPS_HTTP_OK                         (200u)
#define HPS_HTTP_CREATED                    (201u)
#define HPS_HTTP_ACCEPTED                   (202u)
#define HPS_HTTP_NON_AUTHORITATIVE_INFO     (203u)
#define HPS_HTTP_NO_CONTENT                 (204u)
#define HPS_HTTP_RESET_CONTENT              (205u)
#define HPS_HTTP_PARTIAL_CONTENT            (206u)
#define HPS_HTTP_MULTI_STATUS               (207u)
#define HPS_HTTP_IM_USED                    (226u)
/* 3xx Redirection */
#define HPS_HTTP_MULTIPLE_CHOICES           (300u)
#define HPS_HTTP_MOVED_PERMANENTLY          (301u)
#define HPS_HTTP_MOVED_TEMPORARILY          (302u)
#define HPS_HTTP_SEE_OTHER                  (303u)
#define HPS_HTTP_NOT_MODIFIED               (304u)
#define HPS_HTTP_USE_PROXY                  (305u)
#define HPS_HTTP_RESERVED                   (306u)
#define HPS_HTTP_TEMPORARY_REDIRECT         (307u)
/* 4xx Client Error */
#define HPS_HTTP_BAD_REQUEST                (400u)
#define HPS_HTTP_UNAUTHORIZED               (401u)
#define HPS_HTTP_PAYMENT_REQUIRED           (402u)
#define HPS_HTTP_FORBIDDEN                  (403u)
#define HPS_HTTP_NOT_FOUND                  (404u)
#define HPS_HTTP_METHOD_NOT_ALLOWED         (405u)
#define HPS_HTTP_NOT_ACCEPTABLE             (406u)
#define HPS_HTTP_PROXY_AUTH_REQUIRED        (407u)
#define HPS_http_request_tIMEOUT            (408u)
#define HPS_HTTP_CONFLICT                   (409u)
#define HPS_HTTP_GONE                       (410u)
#define HPS_HTTP_LENGTH_REQUIRED            (411u)
#define HPS_HTTP_PRECONDITION_FAILED        (412u)
#define HPS_HTTP_REQUEST_ENTITY_TO_LARGE    (413u)
#define HPS_HTTP_REQUEST_URI_TO_LARGE       (414u)
#define HPS_HTTP_UNSUPORTED_MEDIA_TYPE      (415u)
#define HPS_HTTP_REQUESTED_RANGE_NOT_SAT    (416u)
#define HPS_HTTP_EXPECTATION_FAILED         (417u)
#define HPS_HTTP_I_AM_TEAPOT                (418u)
#define HPS_HTTP_UNPROCESSABLE_ENTITY       (422u)
#define HPS_HTTP_LOCKED                     (423u)
#define HPS_HTTP_FAILED_DEPENDENCY          (424u)
#define HPS_HTTP_UNORDERED_COLLETION        (425u)
#define HPS_HTTP_UPGRADE_REQUIRED           (426u)
#define HPS_HTTP_PRECONDITION_REQUIRED      (428u)
#define HPS_HTTP_TO_MANY_REQUESTS           (429u)
#define HPS_HTTP_REQ_HEADER_FIELDS_TO_LARGE (431u)
#define HPS_HTTP_REQUESTED_HOST_UNAVAILABLE (434u)
#define HPS_HTTP_RETRY_WITH                 (449u)
#define HPS_HTTP_UNAVAILABLE_FOR_LEG_REASON (451u)
#define HPS_HTTP_UNRECOVERABLE_ERROR        (456u)
/* 5xx Server Error */
#define HPS_HTTP_INTERNAL_SERVER_ERROR      (500u)
#define HPS_HTTP_NOT_IMPLEMENTED            (501u)
#define HPS_HTTP_SERVICE_UNAVAILABLE        (503u)
#define HPS_HTTP_GATEWAY_TIMEOUT            (504u)
#define HPS_HTTP_HTTP_VERSION_NOT_SUPPORTED (505u)
#define HPS_HTTP_VARIANT_ALSO_NEGOTIATES    (506u)
#define HPS_HTTP_INSUFFICIENT_STORAGE       (507u)
#define HPS_HTTP_LOOP_DETECTED              (508u)
#define HPS_HTTP_BANDWIGTH_LIMIT_EXCEEDED   (509u)
#define HPS_HTTP_NOT_EXTENDED               (510u)
#define HPS_HTTP_NETWORK_AUTH_REQUIRED      (511u)

/* HTTP Status groups */
#define HPS_HTTP_STATUS_INFORMAL            (1u)
#define HPS_HTTP_STATUS_SUCCESS             (2u)
#define HPS_HTTP_STATUS_REDIRECTION         (3u)
#define HPS_HTTP_STATUS_CLIENT_ERROR        (4u)
#define HPS_HTTP_STATUS_SERVER_ERROR        (5u)


/***************************************
*        Function Prototypes
***************************************/
void HpsInit(void);
void HpsCallBack(uint32_t event, void *eventParam);
void HpsPrintCharacteristic(cy_en_ble_hps_char_index_t charIndex);
void HpsHandleRequests(cy_stc_ble_conn_handle_t connHandle);
void HpsSendRequest(cy_en_ble_hps_http_request_t request, uint8_t reqParam);
void HpsPrintHttpStatus(uint16_t statusCode);
void HpsReadResponse(cy_stc_ble_conn_handle_t connHandle);
bool HpsIsConfigConfirmed(void);

/* [] END OF FILE */
