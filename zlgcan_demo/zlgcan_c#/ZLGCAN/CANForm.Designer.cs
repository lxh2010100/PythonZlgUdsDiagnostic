namespace ZLGCANDemo
{
    partial class CANForm
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.label_device = new System.Windows.Forms.Label();
            this.comboBox_device = new System.Windows.Forms.ComboBox();
            this.comboBox_index = new System.Windows.Forms.ComboBox();
            this.label_index = new System.Windows.Forms.Label();
            this.comboBox_channel = new System.Windows.Forms.ComboBox();
            this.label_channel = new System.Windows.Forms.Label();
            this.groupBox_param = new System.Windows.Forms.GroupBox();
            this.textBox_remoteport = new System.Windows.Forms.TextBox();
            this.label_remoteport = new System.Windows.Forms.Label();
            this.textBox_remoteaddr = new System.Windows.Forms.TextBox();
            this.label_remoteaddr = new System.Windows.Forms.Label();
            this.textBox_localport = new System.Windows.Forms.TextBox();
            this.label_localport = new System.Windows.Forms.Label();
            this.label_netmode = new System.Windows.Forms.Label();
            this.comboBox_netmode = new System.Windows.Forms.ComboBox();
            this.textBox_ABIT = new System.Windows.Forms.TextBox();
            this.label_endid = new System.Windows.Forms.Label();
            this.textBox_endid = new System.Windows.Forms.TextBox();
            this.label_startid = new System.Windows.Forms.Label();
            this.textBox_startid = new System.Windows.Forms.TextBox();
            this.comboBox_standard2 = new System.Windows.Forms.ComboBox();
            this.label_standard2 = new System.Windows.Forms.Label();
            this.label_baudprompt = new System.Windows.Forms.Label();
            this.checkBox_ABIT = new System.Windows.Forms.CheckBox();
            this.checkBox_resistance = new System.Windows.Forms.CheckBox();
            this.comboBox_ABIT2 = new System.Windows.Forms.ComboBox();
            this.label_ABIT2 = new System.Windows.Forms.Label();
            this.comboBox_ABIT = new System.Windows.Forms.ComboBox();
            this.label_ABIT = new System.Windows.Forms.Label();
            this.comboBox_mode = new System.Windows.Forms.ComboBox();
            this.label_mode = new System.Windows.Forms.Label();
            this.comboBox_standard = new System.Windows.Forms.ComboBox();
            this.label_standard = new System.Windows.Forms.Label();
            this.button_open = new System.Windows.Forms.Button();
            this.button_start = new System.Windows.Forms.Button();
            this.button_reset = new System.Windows.Forms.Button();
            this.button_init = new System.Windows.Forms.Button();
            this.button_close = new System.Windows.Forms.Button();
            this.groupBox_senddata = new System.Windows.Forms.GroupBox();
            this.button_send = new System.Windows.Forms.Button();
            this.comboBox_sendtype = new System.Windows.Forms.ComboBox();
            this.label_sendtype = new System.Windows.Forms.Label();
            this.label_senddata = new System.Windows.Forms.Label();
            this.textBox_senddata = new System.Windows.Forms.TextBox();
            this.comboBox_canfd_exp = new System.Windows.Forms.ComboBox();
            this.label_canfdexp = new System.Windows.Forms.Label();
            this.comboBox_protocol = new System.Windows.Forms.ComboBox();
            this.label_protocol = new System.Windows.Forms.Label();
            this.comboBox_frametype = new System.Windows.Forms.ComboBox();
            this.label_frametype = new System.Windows.Forms.Label();
            this.label_ID = new System.Windows.Forms.Label();
            this.textBox_ID = new System.Windows.Forms.TextBox();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.listBox = new System.Windows.Forms.ListBox();
            this.button_clear = new System.Windows.Forms.Button();
            this.comboBox_baud = new System.Windows.Forms.ComboBox();
            this.label_baud = new System.Windows.Forms.Label();
            this.groupBox_param.SuspendLayout();
            this.groupBox_senddata.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // label_device
            // 
            this.label_device.AutoSize = true;
            this.label_device.Location = new System.Drawing.Point(12, 14);
            this.label_device.Name = "label_device";
            this.label_device.Size = new System.Drawing.Size(65, 12);
            this.label_device.TabIndex = 0;
            this.label_device.Text = "设备类型：";
            // 
            // comboBox_device
            // 
            this.comboBox_device.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_device.FormattingEnabled = true;
            this.comboBox_device.Items.AddRange(new object[] {
            "USBCAN1",
            "USBCAN2",
            "USBCAN_E_U",
            "USBCAN_2E_U",
            "PCIECANFD-100U",
            "PCIECANFD-200U",
            "PCIECANFD-400U",
            "USBCANFD-200U",
            "USBCANFD-100U",
            "USBCANFD-MNI",
            "CANET-TCP",
            "CANET-UDP",
            "CLOUD"});
            this.comboBox_device.Location = new System.Drawing.Point(83, 10);
            this.comboBox_device.Name = "comboBox_device";
            this.comboBox_device.Size = new System.Drawing.Size(121, 20);
            this.comboBox_device.TabIndex = 1;
            this.comboBox_device.SelectedIndexChanged += new System.EventHandler(this.comboBox_device_SelectedIndexChanged);
            // 
            // comboBox_index
            // 
            this.comboBox_index.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_index.FormattingEnabled = true;
            this.comboBox_index.Location = new System.Drawing.Point(295, 10);
            this.comboBox_index.Name = "comboBox_index";
            this.comboBox_index.Size = new System.Drawing.Size(48, 20);
            this.comboBox_index.TabIndex = 3;
            // 
            // label_index
            // 
            this.label_index.AutoSize = true;
            this.label_index.Location = new System.Drawing.Point(224, 14);
            this.label_index.Name = "label_index";
            this.label_index.Size = new System.Drawing.Size(65, 12);
            this.label_index.TabIndex = 2;
            this.label_index.Text = "设备索引：";
            // 
            // comboBox_channel
            // 
            this.comboBox_channel.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_channel.FormattingEnabled = true;
            this.comboBox_channel.Location = new System.Drawing.Point(421, 10);
            this.comboBox_channel.Name = "comboBox_channel";
            this.comboBox_channel.Size = new System.Drawing.Size(44, 20);
            this.comboBox_channel.TabIndex = 5;
            this.comboBox_channel.SelectedIndexChanged += new System.EventHandler(this.comboBox_channel_SelectedIndexChanged);
            // 
            // label_channel
            // 
            this.label_channel.AutoSize = true;
            this.label_channel.Location = new System.Drawing.Point(372, 14);
            this.label_channel.Name = "label_channel";
            this.label_channel.Size = new System.Drawing.Size(41, 12);
            this.label_channel.TabIndex = 4;
            this.label_channel.Text = "通道：";
            // 
            // groupBox_param
            // 
            this.groupBox_param.Controls.Add(this.label_baud);
            this.groupBox_param.Controls.Add(this.comboBox_baud);
            this.groupBox_param.Controls.Add(this.textBox_remoteport);
            this.groupBox_param.Controls.Add(this.label_remoteport);
            this.groupBox_param.Controls.Add(this.textBox_remoteaddr);
            this.groupBox_param.Controls.Add(this.label_remoteaddr);
            this.groupBox_param.Controls.Add(this.textBox_localport);
            this.groupBox_param.Controls.Add(this.label_localport);
            this.groupBox_param.Controls.Add(this.label_netmode);
            this.groupBox_param.Controls.Add(this.comboBox_netmode);
            this.groupBox_param.Controls.Add(this.textBox_ABIT);
            this.groupBox_param.Controls.Add(this.label_endid);
            this.groupBox_param.Controls.Add(this.textBox_endid);
            this.groupBox_param.Controls.Add(this.label_startid);
            this.groupBox_param.Controls.Add(this.textBox_startid);
            this.groupBox_param.Controls.Add(this.comboBox_standard2);
            this.groupBox_param.Controls.Add(this.label_standard2);
            this.groupBox_param.Controls.Add(this.label_baudprompt);
            this.groupBox_param.Controls.Add(this.checkBox_ABIT);
            this.groupBox_param.Controls.Add(this.checkBox_resistance);
            this.groupBox_param.Controls.Add(this.comboBox_ABIT2);
            this.groupBox_param.Controls.Add(this.label_ABIT2);
            this.groupBox_param.Controls.Add(this.comboBox_ABIT);
            this.groupBox_param.Controls.Add(this.label_ABIT);
            this.groupBox_param.Controls.Add(this.comboBox_mode);
            this.groupBox_param.Controls.Add(this.label_mode);
            this.groupBox_param.Controls.Add(this.comboBox_standard);
            this.groupBox_param.Controls.Add(this.label_standard);
            this.groupBox_param.Location = new System.Drawing.Point(5, 36);
            this.groupBox_param.Name = "groupBox_param";
            this.groupBox_param.Size = new System.Drawing.Size(862, 149);
            this.groupBox_param.TabIndex = 6;
            this.groupBox_param.TabStop = false;
            this.groupBox_param.Text = "参数配置";
            // 
            // textBox_remoteport
            // 
            this.textBox_remoteport.Location = new System.Drawing.Point(713, 116);
            this.textBox_remoteport.MaxLength = 5;
            this.textBox_remoteport.Name = "textBox_remoteport";
            this.textBox_remoteport.Size = new System.Drawing.Size(122, 21);
            this.textBox_remoteport.TabIndex = 29;
            // 
            // label_remoteport
            // 
            this.label_remoteport.AutoSize = true;
            this.label_remoteport.Location = new System.Drawing.Point(644, 119);
            this.label_remoteport.Name = "label_remoteport";
            this.label_remoteport.Size = new System.Drawing.Size(65, 12);
            this.label_remoteport.TabIndex = 28;
            this.label_remoteport.Text = "远程端口：";
            // 
            // textBox_remoteaddr
            // 
            this.textBox_remoteaddr.Location = new System.Drawing.Point(713, 84);
            this.textBox_remoteaddr.MaxLength = 100;
            this.textBox_remoteaddr.Name = "textBox_remoteaddr";
            this.textBox_remoteaddr.Size = new System.Drawing.Size(122, 21);
            this.textBox_remoteaddr.TabIndex = 27;
            // 
            // label_remoteaddr
            // 
            this.label_remoteaddr.AutoSize = true;
            this.label_remoteaddr.Location = new System.Drawing.Point(644, 87);
            this.label_remoteaddr.Name = "label_remoteaddr";
            this.label_remoteaddr.Size = new System.Drawing.Size(65, 12);
            this.label_remoteaddr.TabIndex = 26;
            this.label_remoteaddr.Text = "远程地址：";
            // 
            // textBox_localport
            // 
            this.textBox_localport.Location = new System.Drawing.Point(713, 52);
            this.textBox_localport.MaxLength = 5;
            this.textBox_localport.Name = "textBox_localport";
            this.textBox_localport.Size = new System.Drawing.Size(122, 21);
            this.textBox_localport.TabIndex = 25;
            // 
            // label_localport
            // 
            this.label_localport.AutoSize = true;
            this.label_localport.Location = new System.Drawing.Point(644, 55);
            this.label_localport.Name = "label_localport";
            this.label_localport.Size = new System.Drawing.Size(65, 12);
            this.label_localport.TabIndex = 24;
            this.label_localport.Text = "本地端口：";
            // 
            // label_netmode
            // 
            this.label_netmode.AutoSize = true;
            this.label_netmode.Location = new System.Drawing.Point(644, 28);
            this.label_netmode.Name = "label_netmode";
            this.label_netmode.Size = new System.Drawing.Size(41, 12);
            this.label_netmode.TabIndex = 23;
            this.label_netmode.Text = "模式：";
            // 
            // comboBox_netmode
            // 
            this.comboBox_netmode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_netmode.FormattingEnabled = true;
            this.comboBox_netmode.Items.AddRange(new object[] {
            "服务器",
            "客户端"});
            this.comboBox_netmode.Location = new System.Drawing.Point(713, 23);
            this.comboBox_netmode.Name = "comboBox_netmode";
            this.comboBox_netmode.Size = new System.Drawing.Size(122, 20);
            this.comboBox_netmode.TabIndex = 22;
            this.comboBox_netmode.SelectedIndexChanged += new System.EventHandler(this.comboBox_netmode_SelectedIndexChanged);
            // 
            // textBox_ABIT
            // 
            this.textBox_ABIT.Location = new System.Drawing.Point(119, 84);
            this.textBox_ABIT.Name = "textBox_ABIT";
            this.textBox_ABIT.Size = new System.Drawing.Size(210, 21);
            this.textBox_ABIT.TabIndex = 21;
            // 
            // label_endid
            // 
            this.label_endid.AutoSize = true;
            this.label_endid.Location = new System.Drawing.Point(442, 119);
            this.label_endid.Name = "label_endid";
            this.label_endid.Size = new System.Drawing.Size(77, 12);
            this.label_endid.TabIndex = 20;
            this.label_endid.Text = "结束ID(0x)：";
            // 
            // textBox_endid
            // 
            this.textBox_endid.Location = new System.Drawing.Point(522, 115);
            this.textBox_endid.MaxLength = 8;
            this.textBox_endid.Name = "textBox_endid";
            this.textBox_endid.Size = new System.Drawing.Size(100, 21);
            this.textBox_endid.TabIndex = 19;
            // 
            // label_startid
            // 
            this.label_startid.AutoSize = true;
            this.label_startid.Location = new System.Drawing.Point(237, 119);
            this.label_startid.Name = "label_startid";
            this.label_startid.Size = new System.Drawing.Size(77, 12);
            this.label_startid.TabIndex = 18;
            this.label_startid.Text = "起始ID(0x)：";
            // 
            // textBox_startid
            // 
            this.textBox_startid.Location = new System.Drawing.Point(317, 115);
            this.textBox_startid.MaxLength = 8;
            this.textBox_startid.Name = "textBox_startid";
            this.textBox_startid.Size = new System.Drawing.Size(100, 21);
            this.textBox_startid.TabIndex = 17;
            // 
            // comboBox_standard2
            // 
            this.comboBox_standard2.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_standard2.FormattingEnabled = true;
            this.comboBox_standard2.Items.AddRange(new object[] {
            "标准帧",
            "扩展帧",
            "禁能"});
            this.comboBox_standard2.Location = new System.Drawing.Point(92, 115);
            this.comboBox_standard2.Name = "comboBox_standard2";
            this.comboBox_standard2.Size = new System.Drawing.Size(121, 20);
            this.comboBox_standard2.TabIndex = 16;
            // 
            // label_standard2
            // 
            this.label_standard2.AutoSize = true;
            this.label_standard2.Location = new System.Drawing.Point(18, 119);
            this.label_standard2.Name = "label_standard2";
            this.label_standard2.Size = new System.Drawing.Size(65, 12);
            this.label_standard2.TabIndex = 15;
            this.label_standard2.Text = "滤波模式：";
            // 
            // label_baudprompt
            // 
            this.label_baudprompt.AutoSize = true;
            this.label_baudprompt.Location = new System.Drawing.Point(337, 88);
            this.label_baudprompt.Name = "label_baudprompt";
            this.label_baudprompt.Size = new System.Drawing.Size(281, 12);
            this.label_baudprompt.TabIndex = 14;
            this.label_baudprompt.Text = "自定义波特率值请使用ZCANPRO目录下的baudcal生成";
            // 
            // checkBox_ABIT
            // 
            this.checkBox_ABIT.AutoSize = true;
            this.checkBox_ABIT.Location = new System.Drawing.Point(21, 86);
            this.checkBox_ABIT.Name = "checkBox_ABIT";
            this.checkBox_ABIT.Size = new System.Drawing.Size(96, 16);
            this.checkBox_ABIT.TabIndex = 12;
            this.checkBox_ABIT.Text = "自定义波特率";
            this.checkBox_ABIT.UseVisualStyleBackColor = true;
            // 
            // checkBox_resistance
            // 
            this.checkBox_resistance.AutoSize = true;
            this.checkBox_resistance.Location = new System.Drawing.Point(227, 24);
            this.checkBox_resistance.Name = "checkBox_resistance";
            this.checkBox_resistance.Size = new System.Drawing.Size(96, 16);
            this.checkBox_resistance.TabIndex = 10;
            this.checkBox_resistance.Text = "终端电阻使能";
            this.checkBox_resistance.UseVisualStyleBackColor = true;
            // 
            // comboBox_ABIT2
            // 
            this.comboBox_ABIT2.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_ABIT2.FormattingEnabled = true;
            this.comboBox_ABIT2.Items.AddRange(new object[] {
            "5Mbps 75%",
            "4Mbps 75%",
            "2Mbps 75%",
            "1Mbps 75%"});
            this.comboBox_ABIT2.Location = new System.Drawing.Point(510, 51);
            this.comboBox_ABIT2.Name = "comboBox_ABIT2";
            this.comboBox_ABIT2.Size = new System.Drawing.Size(100, 20);
            this.comboBox_ABIT2.TabIndex = 9;
            // 
            // label_ABIT2
            // 
            this.label_ABIT2.AutoSize = true;
            this.label_ABIT2.Location = new System.Drawing.Point(416, 55);
            this.label_ABIT2.Name = "label_ABIT2";
            this.label_ABIT2.Size = new System.Drawing.Size(89, 12);
            this.label_ABIT2.TabIndex = 8;
            this.label_ABIT2.Text = "数据域波特率：";
            // 
            // comboBox_ABIT
            // 
            this.comboBox_ABIT.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_ABIT.FormattingEnabled = true;
            this.comboBox_ABIT.Items.AddRange(new object[] {
            "1Mbps 80%",
            "800kbps 80%",
            "500kbps 80%",
            "250kbps 80%",
            "125kbps 80%",
            "100kbps 80%",
            "50kbps 80%"});
            this.comboBox_ABIT.Location = new System.Drawing.Point(301, 51);
            this.comboBox_ABIT.Name = "comboBox_ABIT";
            this.comboBox_ABIT.Size = new System.Drawing.Size(94, 20);
            this.comboBox_ABIT.TabIndex = 7;
            // 
            // label_ABIT
            // 
            this.label_ABIT.AutoSize = true;
            this.label_ABIT.Location = new System.Drawing.Point(210, 55);
            this.label_ABIT.Name = "label_ABIT";
            this.label_ABIT.Size = new System.Drawing.Size(89, 12);
            this.label_ABIT.TabIndex = 6;
            this.label_ABIT.Text = "仲裁域波特率：";
            // 
            // comboBox_mode
            // 
            this.comboBox_mode.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_mode.FormattingEnabled = true;
            this.comboBox_mode.Items.AddRange(new object[] {
            "正常",
            "只听"});
            this.comboBox_mode.Location = new System.Drawing.Point(84, 20);
            this.comboBox_mode.Name = "comboBox_mode";
            this.comboBox_mode.Size = new System.Drawing.Size(121, 20);
            this.comboBox_mode.TabIndex = 5;
            // 
            // label_mode
            // 
            this.label_mode.AutoSize = true;
            this.label_mode.Location = new System.Drawing.Point(19, 24);
            this.label_mode.Name = "label_mode";
            this.label_mode.Size = new System.Drawing.Size(65, 12);
            this.label_mode.TabIndex = 4;
            this.label_mode.Text = "工作模式：";
            // 
            // comboBox_standard
            // 
            this.comboBox_standard.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_standard.FormattingEnabled = true;
            this.comboBox_standard.Items.AddRange(new object[] {
            "CANFD ISO",
            "CANFD BOSCH"});
            this.comboBox_standard.Location = new System.Drawing.Point(92, 51);
            this.comboBox_standard.Name = "comboBox_standard";
            this.comboBox_standard.Size = new System.Drawing.Size(88, 20);
            this.comboBox_standard.TabIndex = 3;
            // 
            // label_standard
            // 
            this.label_standard.AutoSize = true;
            this.label_standard.Location = new System.Drawing.Point(21, 55);
            this.label_standard.Name = "label_standard";
            this.label_standard.Size = new System.Drawing.Size(71, 12);
            this.label_standard.TabIndex = 2;
            this.label_standard.Text = "CANFD标准：";
            // 
            // button_open
            // 
            this.button_open.Location = new System.Drawing.Point(285, 195);
            this.button_open.Name = "button_open";
            this.button_open.Size = new System.Drawing.Size(96, 23);
            this.button_open.TabIndex = 7;
            this.button_open.Text = "打开设备";
            this.button_open.UseVisualStyleBackColor = true;
            this.button_open.Click += new System.EventHandler(this.button_open_Click);
            // 
            // button_start
            // 
            this.button_start.Location = new System.Drawing.Point(525, 195);
            this.button_start.Name = "button_start";
            this.button_start.Size = new System.Drawing.Size(96, 23);
            this.button_start.TabIndex = 8;
            this.button_start.Text = "启动CAN";
            this.button_start.UseVisualStyleBackColor = true;
            this.button_start.Click += new System.EventHandler(this.button_start_Click);
            // 
            // button_reset
            // 
            this.button_reset.Location = new System.Drawing.Point(645, 195);
            this.button_reset.Name = "button_reset";
            this.button_reset.Size = new System.Drawing.Size(96, 23);
            this.button_reset.TabIndex = 9;
            this.button_reset.Text = "复位";
            this.button_reset.UseVisualStyleBackColor = true;
            this.button_reset.Click += new System.EventHandler(this.button_reset_Click);
            // 
            // button_init
            // 
            this.button_init.Location = new System.Drawing.Point(405, 195);
            this.button_init.Name = "button_init";
            this.button_init.Size = new System.Drawing.Size(96, 23);
            this.button_init.TabIndex = 10;
            this.button_init.Text = "初始化CAN";
            this.button_init.UseVisualStyleBackColor = true;
            this.button_init.Click += new System.EventHandler(this.button_init_Click);
            // 
            // button_close
            // 
            this.button_close.Location = new System.Drawing.Point(765, 195);
            this.button_close.Name = "button_close";
            this.button_close.Size = new System.Drawing.Size(96, 23);
            this.button_close.TabIndex = 11;
            this.button_close.Text = "关闭设备";
            this.button_close.UseVisualStyleBackColor = true;
            this.button_close.Click += new System.EventHandler(this.button_close_Click);
            // 
            // groupBox_senddata
            // 
            this.groupBox_senddata.Controls.Add(this.button_send);
            this.groupBox_senddata.Controls.Add(this.comboBox_sendtype);
            this.groupBox_senddata.Controls.Add(this.label_sendtype);
            this.groupBox_senddata.Controls.Add(this.label_senddata);
            this.groupBox_senddata.Controls.Add(this.textBox_senddata);
            this.groupBox_senddata.Controls.Add(this.comboBox_canfd_exp);
            this.groupBox_senddata.Controls.Add(this.label_canfdexp);
            this.groupBox_senddata.Controls.Add(this.comboBox_protocol);
            this.groupBox_senddata.Controls.Add(this.label_protocol);
            this.groupBox_senddata.Controls.Add(this.comboBox_frametype);
            this.groupBox_senddata.Controls.Add(this.label_frametype);
            this.groupBox_senddata.Controls.Add(this.label_ID);
            this.groupBox_senddata.Controls.Add(this.textBox_ID);
            this.groupBox_senddata.Location = new System.Drawing.Point(5, 230);
            this.groupBox_senddata.Name = "groupBox_senddata";
            this.groupBox_senddata.Size = new System.Drawing.Size(862, 110);
            this.groupBox_senddata.TabIndex = 12;
            this.groupBox_senddata.TabStop = false;
            this.groupBox_senddata.Text = "数据发送";
            // 
            // button_send
            // 
            this.button_send.Location = new System.Drawing.Point(676, 78);
            this.button_send.Name = "button_send";
            this.button_send.Size = new System.Drawing.Size(107, 23);
            this.button_send.TabIndex = 2;
            this.button_send.Text = "发送";
            this.button_send.UseVisualStyleBackColor = true;
            this.button_send.Click += new System.EventHandler(this.button_send_Click);
            // 
            // comboBox_sendtype
            // 
            this.comboBox_sendtype.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_sendtype.FormattingEnabled = true;
            this.comboBox_sendtype.Items.AddRange(new object[] {
            "正常发送",
            "单次发送",
            "自发自收",
            "单次自发自收"});
            this.comboBox_sendtype.Location = new System.Drawing.Point(153, 80);
            this.comboBox_sendtype.Name = "comboBox_sendtype";
            this.comboBox_sendtype.Size = new System.Drawing.Size(102, 20);
            this.comboBox_sendtype.TabIndex = 30;
            // 
            // label_sendtype
            // 
            this.label_sendtype.AutoSize = true;
            this.label_sendtype.Location = new System.Drawing.Point(82, 83);
            this.label_sendtype.Name = "label_sendtype";
            this.label_sendtype.Size = new System.Drawing.Size(65, 12);
            this.label_sendtype.TabIndex = 29;
            this.label_sendtype.Text = "发送方式：";
            // 
            // label_senddata
            // 
            this.label_senddata.AutoSize = true;
            this.label_senddata.Location = new System.Drawing.Point(10, 56);
            this.label_senddata.Name = "label_senddata";
            this.label_senddata.Size = new System.Drawing.Size(137, 12);
            this.label_senddata.TabIndex = 28;
            this.label_senddata.Text = "数据(0x, 以空格隔开)：";
            // 
            // textBox_senddata
            // 
            this.textBox_senddata.Location = new System.Drawing.Point(153, 50);
            this.textBox_senddata.Name = "textBox_senddata";
            this.textBox_senddata.Size = new System.Drawing.Size(630, 21);
            this.textBox_senddata.TabIndex = 27;
            // 
            // comboBox_canfd_exp
            // 
            this.comboBox_canfd_exp.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_canfd_exp.FormattingEnabled = true;
            this.comboBox_canfd_exp.Items.AddRange(new object[] {
            "否",
            "是"});
            this.comboBox_canfd_exp.Location = new System.Drawing.Point(676, 20);
            this.comboBox_canfd_exp.Name = "comboBox_canfd_exp";
            this.comboBox_canfd_exp.Size = new System.Drawing.Size(107, 20);
            this.comboBox_canfd_exp.TabIndex = 26;
            // 
            // label_canfdexp
            // 
            this.label_canfdexp.AutoSize = true;
            this.label_canfdexp.Location = new System.Drawing.Point(605, 24);
            this.label_canfdexp.Name = "label_canfdexp";
            this.label_canfdexp.Size = new System.Drawing.Size(71, 12);
            this.label_canfdexp.TabIndex = 25;
            this.label_canfdexp.Text = "CANFD加速：";
            // 
            // comboBox_protocol
            // 
            this.comboBox_protocol.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_protocol.FormattingEnabled = true;
            this.comboBox_protocol.Items.AddRange(new object[] {
            "CAN",
            "CANFD"});
            this.comboBox_protocol.Location = new System.Drawing.Point(491, 20);
            this.comboBox_protocol.Name = "comboBox_protocol";
            this.comboBox_protocol.Size = new System.Drawing.Size(99, 20);
            this.comboBox_protocol.TabIndex = 24;
            // 
            // label_protocol
            // 
            this.label_protocol.AutoSize = true;
            this.label_protocol.Location = new System.Drawing.Point(443, 24);
            this.label_protocol.Name = "label_protocol";
            this.label_protocol.Size = new System.Drawing.Size(41, 12);
            this.label_protocol.TabIndex = 23;
            this.label_protocol.Text = "协议：";
            // 
            // comboBox_frametype
            // 
            this.comboBox_frametype.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_frametype.FormattingEnabled = true;
            this.comboBox_frametype.Items.AddRange(new object[] {
            "标准帧",
            "扩展帧"});
            this.comboBox_frametype.Location = new System.Drawing.Point(334, 20);
            this.comboBox_frametype.Name = "comboBox_frametype";
            this.comboBox_frametype.Size = new System.Drawing.Size(92, 20);
            this.comboBox_frametype.TabIndex = 22;
            // 
            // label_frametype
            // 
            this.label_frametype.AutoSize = true;
            this.label_frametype.Location = new System.Drawing.Point(275, 24);
            this.label_frametype.Name = "label_frametype";
            this.label_frametype.Size = new System.Drawing.Size(53, 12);
            this.label_frametype.TabIndex = 21;
            this.label_frametype.Text = "帧类型：";
            // 
            // label_ID
            // 
            this.label_ID.AutoSize = true;
            this.label_ID.Location = new System.Drawing.Point(92, 26);
            this.label_ID.Name = "label_ID";
            this.label_ID.Size = new System.Drawing.Size(53, 12);
            this.label_ID.TabIndex = 20;
            this.label_ID.Text = "ID(0x)：";
            // 
            // textBox_ID
            // 
            this.textBox_ID.Location = new System.Drawing.Point(155, 20);
            this.textBox_ID.MaxLength = 8;
            this.textBox_ID.Name = "textBox_ID";
            this.textBox_ID.Size = new System.Drawing.Size(100, 21);
            this.textBox_ID.TabIndex = 19;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.listBox);
            this.groupBox1.Controls.Add(this.button_clear);
            this.groupBox1.Location = new System.Drawing.Point(5, 348);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(862, 194);
            this.groupBox1.TabIndex = 13;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "数据发送";
            // 
            // listBox
            // 
            this.listBox.FormattingEnabled = true;
            this.listBox.ItemHeight = 12;
            this.listBox.Location = new System.Drawing.Point(6, 21);
            this.listBox.Name = "listBox";
            this.listBox.Size = new System.Drawing.Size(777, 160);
            this.listBox.TabIndex = 2;
            // 
            // button_clear
            // 
            this.button_clear.Location = new System.Drawing.Point(789, 23);
            this.button_clear.Name = "button_clear";
            this.button_clear.Size = new System.Drawing.Size(67, 23);
            this.button_clear.TabIndex = 1;
            this.button_clear.Text = "清空";
            this.button_clear.UseVisualStyleBackColor = true;
            this.button_clear.Click += new System.EventHandler(this.button_clear_Click);
            // 
            // comboBox_baud
            // 
            this.comboBox_baud.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBox_baud.FormattingEnabled = true;
            this.comboBox_baud.Location = new System.Drawing.Point(410, 21);
            this.comboBox_baud.Name = "comboBox_baud";
            this.comboBox_baud.Size = new System.Drawing.Size(121, 20);
            this.comboBox_baud.TabIndex = 30;
            this.comboBox_baud.Items.AddRange(new object[] {
                "1Mbps",
                "800kbps",
                "500kbps",
                "250kbps",
                "125kbps",
                "100kbps",
                "50kbps",
                "20kbps",
                "10kbps",
                "5kbps"
            });
            // 
            // label_baud
            // 
            this.label_baud.AutoSize = true;
            this.label_baud.Location = new System.Drawing.Point(353, 26);
            this.label_baud.Name = "label_baud";
            this.label_baud.Size = new System.Drawing.Size(53, 12);
            this.label_baud.TabIndex = 31;
            this.label_baud.Text = "波特率：";
            // 
            // CANForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(872, 548);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.groupBox_senddata);
            this.Controls.Add(this.button_close);
            this.Controls.Add(this.button_init);
            this.Controls.Add(this.button_reset);
            this.Controls.Add(this.button_start);
            this.Controls.Add(this.button_open);
            this.Controls.Add(this.groupBox_param);
            this.Controls.Add(this.comboBox_channel);
            this.Controls.Add(this.label_channel);
            this.Controls.Add(this.comboBox_index);
            this.Controls.Add(this.label_index);
            this.Controls.Add(this.comboBox_device);
            this.Controls.Add(this.label_device);
            this.MaximizeBox = false;
            this.Name = "CANForm";
            this.Text = "ZLGCAN";
            this.FormClosed += new System.Windows.Forms.FormClosedEventHandler(this.CANForm_FormClosed);
            this.Load += new System.EventHandler(this.CANForm_Load);
            this.groupBox_param.ResumeLayout(false);
            this.groupBox_param.PerformLayout();
            this.groupBox_senddata.ResumeLayout(false);
            this.groupBox_senddata.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label_device;
        private System.Windows.Forms.ComboBox comboBox_device;
        private System.Windows.Forms.ComboBox comboBox_index;
        private System.Windows.Forms.Label label_index;
        private System.Windows.Forms.ComboBox comboBox_channel;
        private System.Windows.Forms.Label label_channel;
        private System.Windows.Forms.GroupBox groupBox_param;
        private System.Windows.Forms.Label label_endid;
        private System.Windows.Forms.TextBox textBox_endid;
        private System.Windows.Forms.Label label_startid;
        private System.Windows.Forms.TextBox textBox_startid;
        private System.Windows.Forms.ComboBox comboBox_standard2;
        private System.Windows.Forms.Label label_standard2;
        private System.Windows.Forms.Label label_baudprompt;
        private System.Windows.Forms.CheckBox checkBox_ABIT;
        private System.Windows.Forms.CheckBox checkBox_resistance;
        private System.Windows.Forms.ComboBox comboBox_ABIT2;
        private System.Windows.Forms.Label label_ABIT2;
        private System.Windows.Forms.ComboBox comboBox_ABIT;
        private System.Windows.Forms.Label label_ABIT;
        private System.Windows.Forms.ComboBox comboBox_mode;
        private System.Windows.Forms.Label label_mode;
        private System.Windows.Forms.ComboBox comboBox_standard;
        private System.Windows.Forms.Label label_standard;
        private System.Windows.Forms.Button button_open;
        private System.Windows.Forms.Button button_start;
        private System.Windows.Forms.Button button_reset;
        private System.Windows.Forms.Button button_init;
        private System.Windows.Forms.Button button_close;
        private System.Windows.Forms.GroupBox groupBox_senddata;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button button_clear;
        private System.Windows.Forms.Button button_send;
        private System.Windows.Forms.ComboBox comboBox_sendtype;
        private System.Windows.Forms.Label label_sendtype;
        private System.Windows.Forms.Label label_senddata;
        private System.Windows.Forms.TextBox textBox_senddata;
        private System.Windows.Forms.ComboBox comboBox_canfd_exp;
        private System.Windows.Forms.Label label_canfdexp;
        private System.Windows.Forms.ComboBox comboBox_protocol;
        private System.Windows.Forms.Label label_protocol;
        private System.Windows.Forms.ComboBox comboBox_frametype;
        private System.Windows.Forms.Label label_frametype;
        private System.Windows.Forms.Label label_ID;
        private System.Windows.Forms.TextBox textBox_ID;
        private System.Windows.Forms.TextBox textBox_ABIT;
        private System.Windows.Forms.ListBox listBox;
        private System.Windows.Forms.TextBox textBox_remoteport;
        private System.Windows.Forms.Label label_remoteport;
        private System.Windows.Forms.TextBox textBox_remoteaddr;
        private System.Windows.Forms.Label label_remoteaddr;
        private System.Windows.Forms.TextBox textBox_localport;
        private System.Windows.Forms.Label label_localport;
        private System.Windows.Forms.Label label_netmode;
        private System.Windows.Forms.ComboBox comboBox_netmode;
        private System.Windows.Forms.Label label_baud;
        private System.Windows.Forms.ComboBox comboBox_baud;
    }
}

