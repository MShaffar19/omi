//===============================================================
// Copyright (c) Microsoft Corporation.  All rights reserved.
//===============================================================
//#include "precomp.h"
//#include "WSManUtils.h"
//#include "WSManParam.h"
#include "MI.h"
#include "common.h"
#include "pal/strings.h"
#include "wstags.h"
#include "wsmanerrorhandling.h"

//=============================================================================
// NOTE: ORDERED BASED ON DMTF VERSION OF WS-MAN SPEC VERSION 0.95 
// PLEASE KEEP IT ORDERED 
//=============================================================================
SOAP_FAULT_INFORMATION g_SoapFaults[]=
{
    {
        ERROR_WSMAN_SOAP_VERSION_MISMATCH,
        SOAP_FAULT_VERSION_MISMATCH,
        NULL,
        NULL,
        WSMANTAG_ACTION_FAULT_ADDRESSING
    },
    {
        ERROR_WSMAN_SOAP_FAULT_MUST_UNDERSTAND,
        SOAP_FAULT_MUST_UNDERSTAND,
        NULL,
        NULL,
        WSMANTAG_ACTION_FAULT_ADDRESSING
    },
    {
        ERROR_ACCESS_DENIED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ACCESS_DENIED,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_ACTION_MISMATCH,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ACTION_NOT_SUPPORTED,
        SOAP_FAULT_WSMAN_DETAIL_ACTION_MISMATCH,
        WSMANTAG_ACTION_FAULT_ADDRESSING
    },
    {
        ERROR_WSMAN_ACTION_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ACTION_NOT_SUPPORTED,
        NULL,
        WSMANTAG_ACTION_FAULT_ADDRESSING
    },
    {
        ERROR_WSMAN_INVALID_ACTIONURI,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ACTION_NOT_SUPPORTED,
        NULL,
        WSMANTAG_ACTION_FAULT_ADDRESSING
    },
    {
        ERROR_WSMAN_ALREADY_EXISTS,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ALREADY_EXISTS,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_ENUMERATE_CANNOT_PROCESS_FILTER,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENUMERATE_CANNOT_PROCESS_FILTER,
        NULL,
        WSMANTAG_ACTION_FAULT_ENUMERATION
    },    
    {
        ERROR_WSMAN_CONCURRENCY,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_CONCURRENCY,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_EVENTING_DELIVERY_MODE_REQUESTED_UNAVAILABLE,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTING_DELIVERY_MODE_REQUESTED_UNAVAILABLE,
        NULL,
        WSMANTAG_ACTION_FAULT_EVENTING
    },   
    {
        ERROR_WSMAN_DELIVERY_REFUSED,
        SOAP_FAULT_RECEIVER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_DELIVERY_REFUSED,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_INVALID_RESOURCE_URI,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_DESTINATION_UNREACHABLE,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_RESOURCE_URI,
        WSMANTAG_ACTION_FAULT_ADDRESSING
    },
    {
        ERROR_WSMAN_RESOURCE_NOT_FOUND,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_DESTINATION_UNREACHABLE,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_RESOURCE_URI,
        WSMANTAG_ACTION_FAULT_ADDRESSING
    },
    {
        ERROR_WSMAN_DESTINATION_UNREACHABLE,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_DESTINATION_UNREACHABLE,
        NULL,
        WSMANTAG_ACTION_FAULT_ADDRESSING
    },
    {
        ERROR_WSMAN_URI_LIMIT,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENCODING_LIMIT,
        SOAP_FAULT_WSMAN_DETAIL_URI_LIMIT_EXCEEDED,
        WSMANTAG_ACTION_FAULT_WSMAN
    },                                         
    {
        ERROR_WSMAN_MIN_ENVELOPE_SIZE,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENCODING_LIMIT,
        SOAP_FAULT_WSMAN_DETAIL_MIN_ENVELOPE_LIMIT,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_MAX_ENVELOPE_SIZE,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENCODING_LIMIT,
        SOAP_FAULT_WSMAN_DETAIL_MAX_ENVELOPE_SIZE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_MAX_ENVELOPE_SIZE_EXCEEDED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENCODING_LIMIT,
        SOAP_FAULT_WSMAN_DETAIL_MAX_ENVELOPE_SIZE_EXCEEDED,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_SERVER_ENVELOPE_LIMIT,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENCODING_LIMIT,
        SOAP_FAULT_WSMAN_DETAIL_SERVICE_ENVELOPE_LIMIT,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_SELECTOR_LIMIT,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENCODING_LIMIT,
        SOAP_FAULT_WSMAN_DETAIL_SELECTOR_LIMIT,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_OPTION_LIMIT,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENCODING_LIMIT,
        SOAP_FAULT_WSMAN_DETAIL_OPTION_LIMIT,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_CHARACTER_SET,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENCODING_LIMIT,
        SOAP_FAULT_WSMAN_DETAIL_CHARACTER_SET,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_UNREPORTABLE_SUCCESS,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENCODING_LIMIT,
        SOAP_FAULT_WSMAN_DETAIL_UNREPORTABLE_SUCCESS,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_WHITESPACE,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENCODING_LIMIT,
        SOAP_FAULT_WSMAN_DETAIL_WHITESPACE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_ENCODING_TYPE,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENCODING_LIMIT,
        SOAP_FAULT_WSMAN_DETAIL_ENCODING_TYPE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_ENCODING_LIMIT,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENCODING_LIMIT,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_INVALID_RESOURCE_URI,
        SOAP_FAULT_RECEIVER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENDPOINT_UNAVAILABLE,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_RESOURCE_URI,
        WSMANTAG_ACTION_FAULT_ADDRESSING
    },    
    {
        ERROR_WSMAN_ENDPOINT_UNAVAILABLE_INVALID_VALUE,
        SOAP_FAULT_RECEIVER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENDPOINT_UNAVAILABLE,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_VALUES,
        WSMANTAG_ACTION_FAULT_ADDRESSING
    },    
    {
        ERROR_WSMAN_ENDPOINT_UNAVAILABLE,
        SOAP_FAULT_RECEIVER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENDPOINT_UNAVAILABLE,
        NULL,
        WSMANTAG_ACTION_FAULT_ADDRESSING
    },    
    {
        ERROR_WSMAN_EVENTING_LOOPBACK_TESTFAILED,
        SOAP_FAULT_SENDER,
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTING_SOURCE_UNABLE_TO_PROCESS,
        SOAP_FAULT_WSMAN_DETAIL_UNUSABLE_ADDRESS,
        WSMANTAG_ACTION_FAULT_EVENTING
    },
    {
        ERROR_WSMAN_EVENTING_SOURCE_UNABLE_TO_PROCESS,
        SOAP_FAULT_RECEIVER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTING_SOURCE_UNABLE_TO_PROCESS,
        NULL,
        WSMANTAG_ACTION_FAULT_EVENTING
    },
    {
        ERROR_WSMAN_ENUMERATE_FILTER_DIALECT_REQUESTED_UNAVAILABLE,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENUMERATE_FILTER_DIALECT_REQUESTED_UNAVAILABLE,
        NULL,
        WSMANTAG_ACTION_FAULT_ENUMERATION
    },    
    {
        ERROR_WSMAN_EVENTING_FILTERING_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTING_FILTERING_NOT_SUPPORTED,
        NULL,
        WSMANTAG_ACTION_FAULT_EVENTING
    },                                
    {
        ERROR_WSMAN_ENUMERATE_FILTERING_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENUMERATE_FILTERING_NOT_SUPPORTED,
        NULL,
        WSMANTAG_ACTION_FAULT_ENUMERATION
    },
    {
        ERROR_WSMAN_CANNOT_PROCESS_FILTER,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_CANNOT_PROCESS_FILTER,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_FILTERING_REQUIRED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTING_FILTERING_REQUESTED_UNAVAILABLE,
        SOAP_FAULT_WSMAN_DETAIL_FILTERING_REQUIRED,
        WSMANTAG_ACTION_FAULT_EVENTING
    },    
    {
        ERROR_WSMAN_EVENTING_FILTERING_REQUESTED_UNAVAILABLE,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTING_FILTERING_REQUESTED_UNAVAILABLE,
        NULL,
        WSMANTAG_ACTION_FAULT_EVENTING
    },                                
    {
        ERROR_INTERNAL_ERROR,
        SOAP_FAULT_RECEIVER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INTERNAL_ERROR,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_INVALID_TIMEOUT_HEADER,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_MESSAGE_INFORMATION_HEADER,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_TIMEOUT,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_FRAGMENT_DIALECT_REQUESTED_UNAVAILABLE,
        SOAP_FAULT_RECEIVER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_FRAGMENT_DIALECT_NOT_SUPPORTED,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_INVALID_FRAGMENT_PATH,
        SOAP_FAULT_SENDER,
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_CANNOT_PROCESS_FILTER,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN        
    },
    {
        ERROR_WSMAN_BOOKMARK_EXPIRED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_BOOKMARK,
        SOAP_FAULT_WSMAN_DETAIL_EXPIRED,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_INVALID_BOOKMARK,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_BOOKMARK,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_ENUMERATE_INVALID_ENUMERATION_CONTEXT,
        SOAP_FAULT_RECEIVER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENUMERATE_INVALID_ENUMERATION_CONTEXT,
        NULL,
        WSMANTAG_ACTION_FAULT_ENUMERATION
    },    
    {
        ERROR_WSMAN_EVENTING_INVALID_EXPIRATION_TIME,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTING_INVALID_EXPIRATION_TIME,
        NULL,
        WSMANTAG_ACTION_FAULT_ENUMERATION
    },
    {
        ERROR_WSMAN_ENUMERATE_INVALID_EXPIRATION_TIME,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENUMERATE_INVALID_EXPIRATION_TIME,
        NULL,
        WSMANTAG_ACTION_FAULT_ENUMERATION
    },
    {
        ERROR_WSMAN_EVENTING_DELIVERY_MODE_REQUESTED_INVALID,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTING_INVALID_MESSAGE,
        NULL,
        WSMANTAG_ACTION_FAULT_EVENTING
    },  
    {
        ERROR_WSMAN_INVALID_MESSAGE_INFORMATION_HEADER,
        SOAP_FAULT_SENDER,
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_MESSAGE_INFORMATION_HEADER,
        NULL,
        WSMANTAG_ACTION_FAULT_ADDRESSING

    },
    {
        ERROR_WSMAN_OPTIONS_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_OPTIONS,
        SOAP_FAULT_WSMAN_DETAIL_NOT_SUPPORTED,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_UNSUPPORTED_FEATURE_OPTIONS,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_OPTIONS,
        SOAP_FAULT_WSMAN_DETAIL_NOT_SUPPORTED,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_OPTIONS_INVALID_NAME,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_OPTIONS,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_NAME,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_OPTIONS_INVALID_VALUE,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_OPTIONS,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_VALUE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_INVALID_OPTIONS,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_OPTIONS,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_PARAMETER_TYPE_MISMATCH,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_PARAMETER,
        SOAP_FAULT_WSMAN_DETAIL_TYPE_MISMATCH,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_INVALID_PARAMETER_NAME,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_PARAMETER,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_NAME,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_INVALID_PARAMETER,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_PARAMETER,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_INVALID_XML_VALUES,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_REPRESENTATION,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_VALUES,
        WSMANTAG_ACTION_FAULT_TRANSFER
    },
    {
        ERROR_WSMAN_INVALID_XML_MISSING_VALUES,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_REPRESENTATION,
        SOAP_FAULT_WSMAN_DETAIL_MISSING_VALUES,
        WSMANTAG_ACTION_FAULT_TRANSFER
    },
    {
        ERROR_WSMAN_INVALID_XML_NAMESPACE,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_REPRESENTATION,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_NAMESPACE,
        WSMANTAG_ACTION_FAULT_TRANSFER
    },
    {
        ERROR_WSMAN_INVALID_XML_FRAGMENT,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_REPRESENTATION,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_FRAGMENT,
        WSMANTAG_ACTION_FAULT_TRANSFER
    },
    {
        ERROR_WSMAN_INVALID_REPRESENTATION,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_REPRESENTATION,
        NULL,
        WSMANTAG_ACTION_FAULT_TRANSFER
    },    
    {
        ERROR_WSMAN_INSUFFCIENT_SELECTORS,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_SELECTORS,
        SOAP_FAULT_WSMAN_DETAIL_SELECTORS_INSUFFICIENT,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_INVALID_URI_WMI_SINGLETON,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_SELECTORS,
        SOAP_FAULT_WSMAN_DETAIL_SELECTORS_INSUFFICIENT,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_UNEXPECTED_SELECTORS,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_SELECTORS,
        SOAP_FAULT_WSMAN_DETAIL_SELECTORS_UNEXPECTED,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_SELECTOR_TYPEMISMATCH,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_SELECTORS,
        SOAP_FAULT_WSMAN_DETAIL_TYPE_MISMATCH,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_INVALID_SELECTOR_VALUE,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_SELECTORS,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_VALUE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_AMBIGUOUS_SELECTORS,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_SELECTORS,
        SOAP_FAULT_WSMAN_DETAIL_SELECTORS_AMBIGUOUS,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_DUPLICATE_SELECTORS,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_SELECTORS,
        SOAP_FAULT_WSMAN_DETAIL_SELECTORS_DUPLICATE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_INVALID_SELECTORS,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_SELECTORS,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_MESSAGE_INFORMATION_HEADER_REQUIRED,
        SOAP_FAULT_SENDER,
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_MESSAGE_INFORMATION_HEADER_REQUIRED,
        NULL,
        WSMANTAG_ACTION_FAULT_ADDRESSING
    },
    {
        ERROR_WSMAN_NO_ACK,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_NO_ACK,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_QUOTA_LIMIT,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_QUOTA_LIMIT,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_QUOTA_MAX_SHELLS,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_QUOTA_LIMIT,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_SCHEMA_VALIDATION_ERROR,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_SCHEMA_VALIDATION_ERROR,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },        
    {
        ERROR_WSMAN_ENUMERATE_TIMED_OUT,
        SOAP_FAULT_RECEIVER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENUMERATE_TIMED_OUT,
        NULL,
        WSMANTAG_ACTION_FAULT_ENUMERATION
    },        
    {
        ERROR_WSMAN_OPERATION_TIMEDOUT,
        SOAP_FAULT_RECEIVER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_OPERATION_TIMEDOUT,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },                             
    {
        ERROR_WSMAN_EVENTING_UNABLE_TO_RENEW,
        SOAP_FAULT_RECEIVER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTING_UNABLE_TO_RENEW,
        NULL,
        WSMANTAG_ACTION_FAULT_EVENTING
    },                                        
    {
        ERROR_WSMAN_EVENTING_UNSUPPORTED_EXPIRATION_TYPE,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTING_UNSUPPORTED_EXPIRATION_TYPE,
        NULL,
        WSMANTAG_ACTION_FAULT_EVENTING
    },                        
    {
        ERROR_WSMAN_ENUMERATE_UNSUPPORTED_EXPIRATION_TYPE,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENUMERATE_UNSUPPORTED_EXPIRATION_TYPE,
        NULL,
        WSMANTAG_ACTION_FAULT_ENUMERATION
    },                        
    {
        ERROR_WSMAN_AUTHORIZATION_MODE_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_AUTHORIZATION_MODE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_UNSUPPORTED_ADDRESSING_MODE,
        SOAP_FAULT_SENDER,
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_ADDRESSING_MODE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_ACK_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_ACK,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_OPERATION_TIMEOUT_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_OPERATION_TIMEOUT,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_MUSTUNDERSTAND_ON_LOCALE_UNSUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_LOCALE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_ENUMERATION_MODE_UNSUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_ENUMERATION_MODE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },        
    {
        ERROR_WSMAN_EXPIRATION_TIME_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_EXPIRATION_TIME,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_FRAGMENT_TRANSFER_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_FRAGMENT_TRANSFER,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_DELIVERY_RETRIES_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_DELIVERY_RETRIES,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_HEARTBEATS_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_HEARTBEATS,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_BOOKMARKS_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_BOOKMARKS,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_MAX_ELEMENTS_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_MAX_ELEMENTS,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_MAXTIME_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_MAXTIME,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_MAXENVELOPE_SIZE_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_MAXENVELOPE_SIZE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_MAXENVELOPE_POLICY_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_MAXENVELOPE_POLICY,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_FILTERING_REQUIRED_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_FILTERING_REQUIRED,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_INSECURE_ADDRESS_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_INSECURE_ADDRESS,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_FORMAT_MISMATCH_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_FORMAT_MISMATCH,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_FORMAT_SECURITY_TOKEN_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_FORMAT_SECURITY_TOKEN,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_UNKNOWN_FEATURE /*????*/,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_ASYNCHRONOUS_REQUEST,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_UNKNOWN_FEATURE /*????*/,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_MISSING_VALUES,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_UNKNOWN_FEATURE /*????*/,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_VALUES,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_UNKNOWN_FEATURE /*????*/,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_NAMESPACE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_UNKNOWN_FEATURE /*????*/,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_FEATURE_OPTIONS,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },

//extra error messages that are mapped to specific faults
    {
        ERROR_WSMAN_EVENTING_MISSING_LOCALE_IN_DELIVERY,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_SCHEMA_VALIDATION_ERROR,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },


//==============================================================        
//==============================================================        
//==============================================================        
// NEED TO CONFIRM IF THESE ARE ALL STILL NEEDED
    {
        ERROR_WSMAN_ENDPOINT_UNAVAILABLE,
        SOAP_FAULT_RECEIVER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENDPOINT_UNAVAILABLE,
        NULL,
        WSMANTAG_ACTION_FAULT_ADDRESSING
    },    
    {
        ERROR_WSMAN_EVENTING_INVALID_HEARTBEAT,
        SOAP_FAULT_SENDER,
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTING_INVALID_MESSAGE,
        NULL,
        WSMANTAG_ACTION_FAULT_EVENTING
    },
    {
        ERROR_WSMAN_EVENTING_INVALID_MESSAGE,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTING_INVALID_MESSAGE,
        NULL,
        WSMANTAG_ACTION_FAULT_EVENTING
    },                                            
    {
        ERROR_WSMAN_EVENTING_MISSING_NOTIFYTO,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTING_INVALID_MESSAGE,
        NULL,
        WSMANTAG_ACTION_FAULT_EVENTING
    },                                            
    {
        ERROR_WSMAN_EVENTING_MISSING_NOTIFYTO_ADDRESSS,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTING_INVALID_MESSAGE,
        NULL,
        WSMANTAG_ACTION_FAULT_EVENTING
    },                                            
    {
        ERROR_WSMAN_EVENTING_INVALID_NOTIFYTO_ADDRESSS,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTING_INVALID_MESSAGE,
        NULL,
        WSMANTAG_ACTION_FAULT_EVENTING
    },
    {
        ERROR_WSMAN_SCHEMA_VALIDATION_ERROR,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_SCHEMA_VALIDATION_ERROR,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_URI_LIMIT,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_ENCODING_LIMIT,
        SOAP_FAULT_WSMAN_DETAIL_URI_LIMIT_EXCEEDED,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_INVALID_XML,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INTERNAL_ERROR,
        SOAP_FAULT_WSMAN_DETAIL_INVALID,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_ACK_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_AUTHORIZATION_MODE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_LOCALE_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_LOCALE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_MAXTIME_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_MAXTIME,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_MAXENVELOPE_SIZE_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_MAXENVELOPE_SIZE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_MAXENVELOPE_POLICY_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_MAXENVELOPE_POLICY,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_FRAGMENT_TRANSFER_NOT_SUPPORTED,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_FRAGMENT_TRANSFER,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_INVALID_PARAMETER_2,
        SOAP_FAULT_SENDER,        
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_PARAMETER,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_VALUE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_EVENTING_INCOMPATIBLE_BATCHPARAMS_AND_DELIVERYMODE,
        SOAP_FAULT_SENDER,
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_FORMAT_MISMATCH,
        WSMANTAG_ACTION_FAULT_ADDRESSING
    },
    {
        ERROR_WSMAN_EVENTING_INVALID_ENDTO_ADDRESSS,
        SOAP_FAULT_SENDER,
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_ADDRESSING_MODE,
        WSMANTAG_ACTION_FAULT_ADDRESSING
    },
    {
        ERROR_WSMAN_EVENTING_SUBSCRIPTIONCLOSED_BYREMOTESERVICE,
        SOAP_FAULT_RECEIVER,
        SUBSCRIPTION_END_STATUS_SOURCEDOWN,
        NULL,
        WSMANTAG_ACTION_EVENTING
    },
    {
        ERROR_WSMAN_EVENTING_DELIVERYFAILED_FROMSOURCE,
        SOAP_FAULT_RECEIVER,
        SUBSCRIPTION_END_STATUS_DELIVERYFAILURE,
        NULL,
        WSMANTAG_ACTION_EVENTING
    },
    {
        ERROR_WSMAN_EVENTING_SUBSCRIPTION_CANCELLED_BYSOURCE,
        SOAP_FAULT_RECEIVER,
        SUBSCRIPTION_END_STATUS_SOURCECANCELLING,
        NULL,
        WSMANTAG_ACTION_EVENTING
    },
    {
        ERROR_WSMAN_EVENTING_INVALID_LOCALE_IN_DELIVERY,
        SOAP_FAULT_SENDER,
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_INVALID_PARAMETER,
        SOAP_FAULT_WSMAN_DETAIL_UNSUPPORTED_LOCALE,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_REQUEST_NOT_SUPPORTED_AT_SERVICE,
        SOAP_FAULT_SENDER,
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_UNSUPPORTED_FEATURE,
        SOAP_FAULT_WSMAN_DETAIL_INVALID_RESOURCE_URI,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_POLICY_TOO_COMPLEX,
        SOAP_FAULT_RECEIVER,
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTDELIVERTOUNUSABLE,
        SOAP_FAULT_WSMAN_DETAIL_POLICY_TOO_COMPLEX,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
    {
        ERROR_WSMAN_POLICY_CANNOT_COMPLY,
        SOAP_FAULT_RECEIVER,
        SOAP_FAULT_SUBCODE_ERROR_WSMAN_EVENTDELIVERTOUNUSABLE,
        SOAP_FAULT_WSMAN_DETAIL_CANNOT_COMPLY_WITH_POLICY,
        WSMANTAG_ACTION_FAULT_WSMAN
    },
// END - NEED TO CONFIRM IF THESE ARE ALL STILL NEEDED
    {
        ERROR_WSMAN_POLYMORPHISM_MODE_UNSUPPORTED,
        SOAP_FAULT_RECEIVER,
        SOAP_FAULT_SUBCODE_ERROR_WSMB_POLYMORPHISM_MODE_UNSUPPORTED,
        NULL,
        WSMANTAG_ACTION_FAULT_WSMAN
    }
//===============================================================
//===============================================================
//===============================================================

};

SOAP_FAULT_INFORMATION g_defaultFault = 
{
    ERROR_INTERNAL_ERROR,
    SOAP_FAULT_RECEIVER,        
    SOAP_FAULT_SUBCODE_ERROR_WSMAN_INTERNAL_ERROR,
    NULL,
    WSMANTAG_ACTION_FAULT_WSMAN
};

/*++
 Gets soap fault information assoicated with wsman error code
--*/
SOAP_FAULT_INFORMATION*
GetFaultInformation(
    MI_Uint32 errorCode)
{
    int i;
    for(i= 0; i < sizeof(g_SoapFaults)/sizeof(SOAP_FAULT_INFORMATION); i++)
    {
        if ( errorCode == g_SoapFaults[i].WSManErrorCode)
        {
            return &(g_SoapFaults[i]);
        }
    }
    return &g_defaultFault;
}

int ActionIsFault(MI_Uint32 action)
{
    //check uri against all faults
    if (action == WSMANTAG_ACTION_FAULT_ADDRESSING ||
        action == WSMANTAG_ACTION_FAULT_WSMAN ||
        action == WSMANTAG_ACTION_FAULT_ENUMERATION ||
        action == WSMANTAG_ACTION_FAULT_EVENTING ||
        action == WSMANTAG_ACTION_FAULT_TRANSFER)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*++
 Gets wsman error code from soap fault code and subcode strings.
--*/
MI_Result GetWsmanErrorFromSoapFault(
    MI_Char *soapFaultCode, 
    MI_Char *soapFaultSubcode, 
    MI_Char *wsmanDetail, 
    ERROR_TYPES *wsmanError)
{
    DEBUG_ASSERT(NULL != soapFaultCode);
    DEBUG_ASSERT(NULL != wsmanError);

    int i;
    for(i= 0; i < sizeof(g_SoapFaults)/sizeof(SOAP_FAULT_INFORMATION); i++)
    {
        SOAP_FAULT_INFORMATION *faultInfo = &g_SoapFaults[i];

        if (Tcscmp(faultInfo->SoapCode, soapFaultCode) == 0) {
            // Items in the fault table w/ no subcode match even
            // if the fault contains a subcode
            if (NULL == faultInfo->SoapSubcode) {
                *wsmanError = faultInfo->WSManErrorCode;
                return MI_RESULT_OK;
            }
            
            if ((NULL != soapFaultSubcode) &&
                (Tcscmp(faultInfo->SoapSubcode, soapFaultSubcode) == 0))
            {
                if ((NULL == wsmanDetail) 
                    && (NULL == faultInfo->WSManFaultDetail))
                {
                    *wsmanError = faultInfo->WSManErrorCode;
                    return MI_RESULT_OK;
                }

                if ((NULL != wsmanDetail) 
                    && (NULL != faultInfo->WSManFaultDetail)
                    && (Tcscmp(faultInfo->WSManFaultDetail, wsmanDetail) == 0))
                {
                    *wsmanError = faultInfo->WSManErrorCode;
                    return MI_RESULT_OK;
                }
            }
        }
    }

    if (NULL != wsmanDetail) {
        // No match found using detail, so try again w/o
        return GetWsmanErrorFromSoapFault(soapFaultCode, soapFaultSubcode,
                                          NULL, wsmanError);
    } else {
        return MI_RESULT_FAILED;
    }
}