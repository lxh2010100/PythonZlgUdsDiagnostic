using System;
using System.Runtime.InteropServices;

namespace ZLGCAN
{
    [StructLayout(LayoutKind.Sequential)]
    public struct ZCAN
    {
        public uint acc_code;
        public uint acc_mask;
        public uint reserved;
        public byte filter;
        public byte timing0;
        public byte timing1;
        public byte mode;
    };

    [StructLayout(LayoutKind.Sequential)]
    public struct CANFD
    {
        public uint acc_code;
        public uint acc_mask;
        public uint abit_timing;
        public uint dbit_timing;
        public uint brp;
        public byte filter;
        public byte mode;
        public UInt16 pad;
        public uint reserved;
    };

    [StructLayout(LayoutKind.Sequential)]
    public struct can_frame
    {
        public uint can_id;  /* 32 bit MAKE_CAN_ID + EFF/RTR/ERR flags */
        public byte can_dlc; /* frame payload length in byte (0 .. CAN_MAX_DLEN) */
        public byte __pad;   /* padding */
        public byte __res0;  /* reserved / padding */
        public byte __res1;  /* reserved / padding */
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 8)]
        public byte[] data/* __attribute__((aligned(8)))*/;
    };

    [StructLayout(LayoutKind.Sequential)]
    public struct canfd_frame
    {
        public uint can_id;  /* 32 bit MAKE_CAN_ID + EFF/RTR/ERR flags */
        public byte len;     /* frame payload length in byte */
        public byte flags;   /* additional flags for CAN FD,i.e error code */
        public byte __res0;  /* reserved / padding */
        public byte __res1;  /* reserved / padding */
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
        public byte[] data/* __attribute__((aligned(8)))*/;
    };

    [StructLayout(LayoutKind.Explicit)]
    public struct ZCAN_CHANNEL_INIT_CONFIG
    {
        [FieldOffset(0)]
        public uint can_type; //type:TYPE_CAN TYPE_CANFD

        [FieldOffset(4)]
        public ZCAN can;

        [FieldOffset(4)]
        public CANFD canfd;
    };

    [StructLayout(LayoutKind.Sequential)]
    public struct ZCAN_Transmit_Data
    {
        public can_frame frame;
        public uint transmit_type;
    };

    [StructLayout(LayoutKind.Sequential)]
    public struct ZCAN_Receive_Data
    {
        public can_frame frame;
        public UInt64 timestamp;//us
    };

    [StructLayout(LayoutKind.Sequential)]
    public struct ZCAN_TransmitFD_Data
    {
        public canfd_frame frame;
        public uint transmit_type;
    };

    public struct DeviceInfo
    {
        public uint device_type;  //设备类型
        public uint channel_count;//设备的通道个数
        public DeviceInfo(uint type, uint count)
        {
            device_type = type;
            channel_count = count;
        }
    };

    [StructLayout(LayoutKind.Sequential)]
    public struct ZCAN_ReceiveFD_Data
    {
        public canfd_frame frame;
        public UInt64 timestamp;//us
    };

    [StructLayout(LayoutKind.Sequential)]
    public struct ZCAN_CHANNEL_ERROR_INFO
    {
        public uint error_code;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 3)]
        public byte[] passive_ErrData;
        public byte arLost_ErrData;
    } ;

    //for zlg cloud
    [StructLayout(LayoutKind.Sequential)]
    public struct ZCLOUD_DEVINFO
    {
        public int devIndex;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
        public char[] type;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
        public char[] id;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
        public char[] owner;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
        public char[] model;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
        public char[] fwVer;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
        public char[] hwVer;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
        public char[] serial;
        public byte canNum;
        public int status;             // 0:online, 1:offline
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
        public byte[] bCanUploads;   // each channel enable can upload
        public byte bGpsUpload;
    };

    //[StructLayout(LayoutKind.Sequential)]
    //public struct ZCLOUD_DEV_GROUP_INFO
    //{
    //    [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
    //    public char[] groupName;
    //    [MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
    //    public char[] desc;
    //    [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
    //    public char[] groupId;
    //    //public ZCLOUD_DEVINFO *pDevices;
    //    public IntPtr pDevices;
    //    public uint devSize;
    //};

    [StructLayout(LayoutKind.Sequential)]
    public struct ZCLOUD_USER_DATA
    {
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
        public char[] username;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
        public char[] mobile;
        //[MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
        // public char[] email;
        // public IntPtr pDevGroups;
        // public uint devGroupSize;
        [MarshalAs(UnmanagedType.ByValArray, SizeConst = 100)]
        public ZCLOUD_DEVINFO[] devices;
        public uint devCnt;
    };

    public class Define
    {
        public const int TYPE_CAN = 0;
        public const int TYPE_CANFD = 1;

        public const int ZCAN_USBCAN1 = 3;
        public const int ZCAN_USBCAN2 = 4;
        public const int ZCAN_CANETUDP = 12;
        public const int ZCAN_CANETTCP = 17;
        public const int ZCAN_USBCAN_E_U = 20;
        public const int ZCAN_USBCAN_2E_U = 21;
        public const int ZCAN_PCIECANFD_100U = 38;
        public const int ZCAN_PCIECANFD_200U = 39;
        public const int ZCAN_PCIECANFD_400U = 40;
        public const int ZCAN_USBCANFD_200U = 41;
        public const int ZCAN_USBCANFD_100U = 42;
        public const int ZCAN_USBCANFD_MINI = 43;
        public const int ZCAN_CLOUD = 46;

        public const int STATUS_ERR = 0;
        public const int STATUS_OK = 1;
    };

    public class Method
    {
        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern IntPtr ZCAN_OpenDevice(uint device_type, uint device_index, uint reserved);

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern uint ZCAN_CloseDevice(IntPtr device_handle);

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        // pInitConfig -> ZCAN_CHANNEL_INIT_CONFIG
        public static extern IntPtr ZCAN_InitCAN(IntPtr device_handle, uint can_index, IntPtr pInitConfig);

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern uint ZCAN_StartCAN(IntPtr channel_handle);

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern uint ZCAN_ResetCAN(IntPtr channel_handle);

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        // pTransmit -> ZCAN_Transmit_Data
        public static extern uint ZCAN_Transmit(IntPtr channel_handle, IntPtr pTransmit, uint len);

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        // pTransmit -> ZCAN_TransmitFD_Data
        public static extern uint ZCAN_TransmitFD(IntPtr channel_handle, IntPtr pTransmit, uint len);

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern uint ZCAN_GetReceiveNum(IntPtr channel_handle, byte type);

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern uint ZCAN_Receive(IntPtr channel_handle, IntPtr data, uint len, int wait_time = -1);

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern uint ZCAN_ReceiveFD(IntPtr channel_handle, IntPtr data, uint len, int wait_time = -1);

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        // pErrInfo -> ZCAN_CHANNEL_ERROR_INFO
        public static extern uint ZCAN_ReadChannelErrInfo(IntPtr channel_handle, IntPtr pErrInfo);

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern IntPtr GetIProperty(IntPtr device_handle);

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern bool ZCLOUD_IsConnected();

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern void ZCLOUD_SetServerInfo(string httpAddr, ushort httpPort,
            string mqttAddr, ushort mqttPort);

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern uint ZCLOUD_ConnectServer(string username, string password);

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern uint ZCLOUD_DisconnectServer();

        [DllImport("zlgcan.dll", CallingConvention = CallingConvention.StdCall)]
        public static extern IntPtr ZCLOUD_GetUserData();
    }

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate int SetValueFunc(string path, string value);

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate string GetValueFunc(string path, string value);

    [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
    public delegate IntPtr GetPropertysFunc(string path, string value);

    public struct IProperty
    {
        public SetValueFunc SetValue;
        public GetValueFunc GetValue;
        public GetPropertysFunc GetPropertys;
    };
}
