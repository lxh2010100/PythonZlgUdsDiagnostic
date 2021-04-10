using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Threading;
using System.IO;
using ZLGCAN;

namespace ZLGCANDemo
{
    //接收数据线程类
    class recvdatathread
    {
        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void RecvCANDataEventHandler(ZCAN_Receive_Data[] data, uint len);//CAN数据接收事件委托

        [UnmanagedFunctionPointer(CallingConvention.StdCall)]
        public delegate void RecvFDDataEventHandler(ZCAN_ReceiveFD_Data[] data, uint len);//CANFD数据接收事件委托

        const int TYPE_CAN = 0;
        const int TYPE_CANFD = 1;

        bool m_bStart;
        IntPtr channel_handle_;
        Thread recv_thread_;
        static object locker = new object();
        public static RecvCANDataEventHandler OnRecvCANDataEvent;
        public static RecvFDDataEventHandler OnRecvFDDataEvent;
        public recvdatathread()
        {
        }

        public event RecvCANDataEventHandler RecvCANData
        {
            add { OnRecvCANDataEvent += new RecvCANDataEventHandler(value); }
            remove { OnRecvCANDataEvent -= new RecvCANDataEventHandler(value); }
        }

        public event RecvFDDataEventHandler RecvFDData
        {
            add { OnRecvFDDataEvent += new RecvFDDataEventHandler(value); }
            remove { OnRecvFDDataEvent -= new RecvFDDataEventHandler(value); }
        }

        public void setStart(bool start)
        {
            m_bStart = start;
            if (start)
            {
                recv_thread_ = new Thread(RecvDataFunc);
                recv_thread_.IsBackground = true;
                recv_thread_.Start();
            }
            else
            {
                recv_thread_.Join();
                recv_thread_ = null;
            }
        }

        public void setChannelHandle(IntPtr channel_handle)
        {
            lock(locker)
            {
                channel_handle_ = channel_handle;
            }
        }

        //数据接收函数
        protected void RecvDataFunc()
        {
            ZCAN_Receive_Data[] can_data = new ZCAN_Receive_Data[100];
            ZCAN_ReceiveFD_Data[] canfd_data = new ZCAN_ReceiveFD_Data[100];
            uint len;
            while (m_bStart)
            {
                lock (locker)
                {
                    len = Method.ZCAN_GetReceiveNum(channel_handle_, TYPE_CAN);
                    if (len > 0)
                    {
                        int size = Marshal.SizeOf(typeof(ZCAN_Receive_Data));
                        IntPtr ptr = Marshal.AllocHGlobal((int)len * size);
                        len = Method.ZCAN_Receive(channel_handle_, ptr, len, 50);
                        for (int i = 0; i < len; ++i)
                        {
                            can_data[i] = (ZCAN_Receive_Data)Marshal.PtrToStructure(
                                (IntPtr)((UInt32)ptr+i*size), typeof(ZCAN_Receive_Data));
                        }
                        OnRecvCANDataEvent(can_data, len);
                        Marshal.FreeHGlobal(ptr);
                    }

                    len = Method.ZCAN_GetReceiveNum(channel_handle_, TYPE_CANFD);
                    if (len > 0)
                    {
                        int size = Marshal.SizeOf(typeof(ZCAN_ReceiveFD_Data));
                        IntPtr ptr = Marshal.AllocHGlobal((int)len * size);
                        len = Method.ZCAN_ReceiveFD(channel_handle_, ptr, len, 50);
                        for (int i = 0; i < len; ++i)
                        {
                            canfd_data[i] = (ZCAN_ReceiveFD_Data)Marshal.PtrToStructure(
                                (IntPtr)((UInt32)ptr+i*size), typeof(ZCAN_ReceiveFD_Data));
                        }
                        OnRecvFDDataEvent(canfd_data, len);
                        Marshal.FreeHGlobal(ptr);
                    }
                }

                Thread.Sleep(10);
            }
        }
    }
}
