#ifndef _ZUDS_H_
#define _ZUDS_H_

typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;
typedef unsigned long long uint64;
typedef uint32 ZUDS_HANDLE;
#define ZUDS_INVALID_HANDLE ((ZUDS_HANDLE)-1)

#define ZUDS_SI_DiagnosticSessionControl           0x10
#define ZUDS_SI_ECUReset                           0x11
#define ZUDS_SI_ClearDiagnosticInformation         0x14
#define ZUDS_SI_ReadDTCInformation                 0x19
#define ZUDS_SI_ReadDataByIdentifier               0x22
#define ZUDS_SI_ReadMemoryByAddress                0x23
#define ZUDS_SI_ReadScalingDataByIdentifier        0x24
#define ZUDS_SI_SecurityAccess                     0x27
#define ZUDS_SI_CommunicationControl               0x28
#define ZUDS_SI_ReadDataByPeriodicIdentifier       0x2A
#define ZUDS_SI_DynamicallyDefineDataIdentifier    0x2C
#define ZUDS_SI_WriteDataByIdentifier              0x2E
#define ZUDS_SI_InputOutputControlByIdentifier     0x2F
#define ZUDS_SI_RoutineControl                     0x31
#define ZUDS_SI_RequestDownload                    0x34
#define ZUDS_SI_RequestUpload                      0x35
#define ZUDS_SI_TransferData                       0x36
#define ZUDS_SI_RequestTransferExit                0x37
#define ZUDS_SI_WriteMemoryByAddress               0x3D
#define ZUDS_SI_TesterPresent                      0x3E
#define ZUDS_SI_AccessTimingParameter              0x83
#define ZUDS_SI_SecuredDataTransmission            0x84
#define ZUDS_SI_ControlDTCSetting                  0x85
#define ZUDS_SI_ResponseOnEvent                    0x86
#define ZUDS_SI_LinkControl                        0x87

typedef struct _ZUDS_REQUEST
{
    uint32 src_addr;
    uint32 dst_addr;
    uint8  suppress_response;    // 1:suppress
    uint8  sid;                  // service id of request
    uint8  *param;               // array, params of the service
    uint32 param_len;
    uint32 reserved;
}ZUDS_REQUEST;

typedef uint8 UDS_STATUS;
//status
#define ZUDS_ERROR_OK                   0 // no error
#define ZUDS_ERROR_TIMEOUT              1 // no response until timeout
#define ZUDS_ERROR_TRANSPORT            2 // link error
#define ZUDS_ERROR_CANCEL               3 // cancel request
#define ZUDS_ERROR_SUPPRESS_RESPONSE    4
#define ZUDS_ERROR_OTHTER               100

typedef uint8 RESPONSE_TYPE;
#define RT_POSITIVE 1
#define RT_NEGATIVE 0

typedef struct _ZUDS_RESPONSE
{
	UDS_STATUS status;
    RESPONSE_TYPE type; // RT_POSITIVE, RT_NEGATIVE
    union
    {
        struct
        {
            uint8  sid;                // service id of response
            uint8  *param;             // array, params of the service, don't free
            uint32 param_len;
        }positive;
        struct
        {
            uint8  neg_code;            // 0x7F
            uint8  sid;                 // service id of response
            uint8  error_code;         
        }negative;
    };
    uint32 reserved;
}ZUDS_RESPONSE;

typedef struct _ZUDS_FRAME
{
	uint32 id;
	uint8  extend;
	uint8  remote;
    uint8  data_len;
	uint8  data[64];
    uint32 reserved;
}ZUDS_FRAME;

typedef uint8 PARAM_TYPE;
#define PARAM_TYPE_SESSION   0 // ZUDS_SESSION_PARAM
#define PARAM_TYPE_ISO15765  1 // ZUDS_ISO15765_PARAM
#define PARAM_TYPE_TRANSPORT 2

typedef struct _ZUDS_SERSSION_PARAM
{
    uint16 timeout;           // ms, timeout to wait the response of the server
    uint16 enhanced_timeout;  // ms,timeout to wait after negative response: error code 0x78
    uint32 reserved0;
    uint32 reserved1;
}ZUDS_SESSION_PARAM;

#define VERSION_0 0
#define VERSION_1 1
typedef struct _ZUDS_ISO15765_PARAM
{
	uint8  version;           // VERSION_0, VERSION_1
	uint8  max_data_len;      // max data length, can:8, canfd:64
	uint8  st_min;            // ms, min time between two consecutive frames
	uint8  block_size;
	uint8  fill_byte;         // fill to invalid byte
    uint8  frame_type;        // 0:std 1:ext
	uint32 reserved;
}ZUDS_ISO15765_PARAM;

// tester settings
typedef struct _ZUDS_TESTER_PRESENT_PARAM
{
    uint32 addr;
    uint16 cycle;
    uint8  suppress_response;    // 1:suppress
    uint32 reserved;
}ZUDS_TESTER_PRESENT_PARAM;

#define TRANSPORT_OK    0
#define TRANSPORT_ERROR 1
// count: number of frames
typedef uint32 (*OnUDSTransmit)(void* ctx, const ZUDS_FRAME* frame, uint32 count);

#ifdef WIN32
	#define STDCALL __stdcall
#else
	#define STDCALL
#endif

typedef uint32 TP_TYPE; // transport protocol
#define DoCAN 0

#ifdef __cplusplus
extern "C" {
#endif
    ZUDS_HANDLE STDCALL ZUDS_Init(TP_TYPE type);
           void STDCALL ZUDS_Request(ZUDS_HANDLE handle, const ZUDS_REQUEST* request, ZUDS_RESPONSE *response);
           void STDCALL ZUDS_Stop(ZUDS_HANDLE handle);
           void STDCALL ZUDS_SetTransmitHandler(ZUDS_HANDLE handle, void* ctx, OnUDSTransmit transmittor);
           void STDCALL ZUDS_OnReceive(ZUDS_HANDLE handle, const ZUDS_FRAME* frame);
           void STDCALL ZUDS_SetParam(ZUDS_HANDLE handle, PARAM_TYPE type, void* param);
           void STDCALL ZUDS_SetTesterPresent(ZUDS_HANDLE handle, uint8 enable, const ZUDS_TESTER_PRESENT_PARAM* param);
           void STDCALL ZUDS_Release(ZUDS_HANDLE handle);

#ifdef __cplusplus
}
#endif

#endif // _ZUDS_H_
