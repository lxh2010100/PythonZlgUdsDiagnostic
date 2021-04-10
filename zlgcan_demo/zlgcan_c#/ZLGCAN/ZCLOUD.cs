using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using ZLGCAN;

namespace ZLGCANDemo
{
    public partial class ZCLOUD : Form
    {
        private bool connected_ = false;
        private List<uint> deviceIndices_ = new List<uint>();
        private List<int> deviceStatus_ = new List<int>();
        private bool online_ = false;

        public ZCLOUD()
        {
            InitializeComponent();
        }

        public uint deviceIndex()
        {
            if (deviceList.Items.Count > 0)
            {
                return deviceIndices_[deviceList.SelectedIndices[0]];
            }
            else
            {
                return 0;
            }
        }

        private void ZCLOUD_Load(object sender, EventArgs e)
        {
            username.Text = "abc";
            password.Text = "abc";

            deviceList.Columns.Add("ID", deviceList.Width - 60, HorizontalAlignment.Left);
            deviceList.Columns.Add("状态", 50, HorizontalAlignment.Center);
            deviceList.View = System.Windows.Forms.View.Details;
            deviceList.FullRowSelect = true;

            notifyControl();
        }

        private void notifyControl()
        {
            httpAddr.Enabled = !connected_;
            httpPort.Enabled = !connected_;
            mqttAddr.Enabled = !connected_;
            mqttPort.Enabled = !connected_;
            username.Enabled = !connected_;
            password.Enabled = !connected_;
            connect.Enabled = !connected_;
            disconnect.Enabled = connected_;
            deviceList.Enabled = connected_;
            confirm.Enabled = online_;
        }

        private void connect_Click(object sender, EventArgs e)
        {
            Method.ZCLOUD_SetServerInfo(httpAddr.Text, Convert.ToUInt16(httpPort.Text),
                mqttAddr.Text, Convert.ToUInt16(mqttPort.Text));
            UInt32 ret = Method.ZCLOUD_ConnectServer(username.Text, password.Text);
            switch (ret)
            {
                case 1:
                    MessageBox.Show("连接服务器失败", "提示",
                        MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                    return;
                case 2:
                    MessageBox.Show("HTTP错误", "提示",
                        MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                    return;
                case 3:
                    MessageBox.Show("登录信息错误", "提示",
                        MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                    return;
                case 4:
                    MessageBox.Show("MQTT连接错误", "提示",
                        MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                    return;
                default:
                    break;
            }
            connected_ = true;
            //int index = -1;
            IntPtr ptr = Method.ZCLOUD_GetUserData();
            if (IntPtr.Zero == ptr)
            {
                MessageBox.Show("获取设备信息", "提示",
                    MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                return;
            }
            ZCLOUD_USER_DATA userData = (ZCLOUD_USER_DATA)Marshal.PtrToStructure(
                (IntPtr)((UInt32)ptr), typeof(ZCLOUD_USER_DATA));
            //ZCLOUD_DEVINFO
            int devSize = Marshal.SizeOf(typeof(ZCLOUD_DEVINFO));
            //int no = 0;
            for (uint j = 0; j < userData.devCnt; ++j)
            {
                //ZCLOUD_DEVINFO dev = (ZCLOUD_DEVINFO)Marshal.PtrToStructure(
                    //(IntPtr)((UInt32)userData.pDevices + j * devSize), typeof(ZCLOUD_DEVINFO));
                ZCLOUD_DEVINFO dev = userData.devices[j];
                ListViewItem item = new ListViewItem(new string(dev.id));
                item.SubItems.Add(dev.status == 0 ? "在线" : "离线");
                //if (index == -1 && dev.status == 0)
                //{
                //    index = no;
                //}
                deviceList.Items.Add(item);
                //++no;
                deviceIndices_.Add(Convert.ToUInt32(dev.devIndex));
                deviceStatus_.Add(dev.status);
            }
            //if (index != -1)
            //{
            //    deviceList.Items[index].EnsureVisible();
            //    deviceList.Items[index].Selected = true;
            //    online_ = true;
            //}
            notifyControl();
        }

        private void disconnect_Click(object sender, EventArgs e)
        {
            Method.ZCLOUD_DisconnectServer();
            deviceList.Items.Clear();
            deviceIndices_.Clear();
            deviceStatus_.Clear();
            connected_ = false;
            online_ = false;
            notifyControl();
        }

        private void deviceList_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (deviceList.SelectedIndices.Count == 0)
            {
                online_ = false;
            }
            else
            {
                int index = deviceList.SelectedIndices[0];
                online_ = deviceIndices_[index] == 0;
            }
            notifyControl();
        }

        private void confirm_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.OK;
        }

        private void cancel_Click(object sender, EventArgs e)
        {
            DialogResult = DialogResult.Cancel;
        }
    }
}
