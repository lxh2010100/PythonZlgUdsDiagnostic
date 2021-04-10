object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'CANFD'
  ClientHeight = 534
  ClientWidth = 736
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object device_setting: TGroupBox
    Left = 8
    Top = 8
    Width = 441
    Height = 177
    Caption = #35774#22791#21442#25968
    TabOrder = 2
    object Label1: TLabel
      Left = 14
      Top = 27
      Width = 28
      Height = 13
      Caption = #22411#21495':'
    end
    object Label2: TLabel
      Left = 186
      Top = 27
      Width = 28
      Height = 13
      Caption = #32034#24341':'
    end
    object Label3: TLabel
      Left = 297
      Top = 27
      Width = 73
      Height = 13
      Caption = #31532#20960#20010'CAN'#21475':'
    end
    object Label5: TLabel
      Left = 14
      Top = 63
      Width = 52
      Height = 13
      Caption = #24037#20316#27169#24335':'
    end
    object Label6: TLabel
      Left = 297
      Top = 63
      Width = 62
      Height = 13
      Caption = 'CANFD'#26631#20934':'
    end
    object Label7: TLabel
      Left = 14
      Top = 101
      Width = 76
      Height = 13
      Caption = #20210#35009#22495#27874#29305#29575':'
    end
    object Label8: TLabel
      Left = 186
      Top = 101
      Width = 76
      Height = 13
      Caption = #25968#25454#22495#27874#29305#29575':'
    end
    object Label9: TLabel
      Left = 16
      Top = 159
      Width = 181
      Height = 13
      Caption = #20351#29992'ZCANPRO'#30446#24405#19979#30340'baudcal'#29983#25104
    end
    object device_index_box: TComboBox
      Left = 220
      Top = 24
      Width = 58
      Height = 21
      ItemHeight = 13
      TabOrder = 0
      Items.Strings = (
        '0'
        '1'
        '2'
        '3')
    end
    object can_index_box: TComboBox
      Left = 376
      Top = 24
      Width = 58
      Height = 21
      ItemHeight = 13
      TabOrder = 1
      Items.Strings = (
        '0'
        '1'
        '2'
        '3')
    end
    object mode_box: TComboBox
      Left = 72
      Top = 60
      Width = 87
      Height = 21
      ItemHeight = 13
      TabOrder = 2
      Items.Strings = (
        #27491#24120#27169#24335
        #21482#21548#27169#24335)
    end
    object resistance: TCheckBox
      Left = 189
      Top = 60
      Width = 66
      Height = 17
      Caption = #32456#31471#30005#38459
      Checked = True
      State = cbChecked
      TabOrder = 3
    end
    object canfd_standard_box: TComboBox
      Left = 376
      Top = 60
      Width = 58
      Height = 21
      ItemHeight = 13
      TabOrder = 4
      Items.Strings = (
        'ISO'
        'BOSCH')
    end
    object device_type_box: TComboBox
      Left = 48
      Top = 24
      Width = 111
      Height = 21
      ItemHeight = 13
      TabOrder = 5
      Items.Strings = (
        'ZCAN_USBCANFD_200U'
        'ZCAN_USBCANFD_100U'
        'ZCAN_USBCANFD_MINI')
    end
    object abit_baud_box: TEdit
      Left = 96
      Top = 98
      Width = 63
      Height = 21
      TabOrder = 6
      Text = '1000'
    end
    object dbit_baud_box: TEdit
      Left = 268
      Top = 98
      Width = 63
      Height = 21
      TabOrder = 7
      Text = '2000'
    end
    object custom_baud_edit: TEdit
      Left = 110
      Top = 134
      Width = 299
      Height = 21
      TabOrder = 8
      Text = '1.0Mbps(66%),4.0Mbps(66%),(60,04C00000,01000000)'
    end
    object custom_baud_check: TCheckBox
      Left = 14
      Top = 136
      Width = 99
      Height = 17
      Caption = #33258#23450#20041#27874#29305#29575':'
      TabOrder = 9
    end
  end
  object start_Button: TButton
    Left = 654
    Top = 43
    Width = 75
    Height = 25
    Caption = #21551#21160'CAN'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 0
    OnClick = start_ButtonClick
  end
  object reset_Button: TButton
    Left = 653
    Top = 74
    Width = 75
    Height = 25
    Caption = #22797#20301'CAN'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = reset_ButtonClick
  end
  object data_display: TGroupBox
    Left = 8
    Top = 296
    Width = 640
    Height = 233
    Caption = #25968#25454#26174#31034
    TabOrder = 3
    object ListBox1: TListBox
      Left = 3
      Top = 24
      Width = 628
      Height = 201
      ItemHeight = 13
      TabOrder = 0
    end
  end
  object data_sent_setting: TGroupBox
    Left = 8
    Top = 200
    Width = 640
    Height = 90
    Caption = #25968#25454#21457#36865
    TabOrder = 4
    object Label10: TLabel
      Left = 14
      Top = 59
      Width = 35
      Height = 13
      Caption = 'ID(0x):'
    end
    object Label11: TLabel
      Left = 14
      Top = 28
      Width = 40
      Height = 13
      Caption = #24103#31867#22411':'
    end
    object Label12: TLabel
      Left = 186
      Top = 60
      Width = 48
      Height = 13
      Caption = #25968#25454'(0x):'
    end
    object Label13: TLabel
      Left = 279
      Top = 28
      Width = 52
      Height = 13
      Caption = #21457#36865#26041#24335':'
    end
    object Label14: TLabel
      Left = 141
      Top = 28
      Width = 40
      Height = 13
      Caption = #24103#26684#24335':'
    end
    object Label4: TLabel
      Left = 424
      Top = 28
      Width = 28
      Height = 13
      Caption = #21327#35758':'
    end
    object id_edit: TEdit
      Left = 55
      Top = 56
      Width = 104
      Height = 21
      TabOrder = 0
      Text = '100'
    end
    object data_edit: TEdit
      Left = 240
      Top = 56
      Width = 375
      Height = 21
      TabOrder = 1
      Text = '11 22 33 44 55 66 77 88 '
    end
    object eff_box: TComboBox
      Left = 60
      Top = 24
      Width = 68
      Height = 21
      ItemHeight = 13
      TabOrder = 2
      Items.Strings = (
        #26631#20934#24103
        #25193#23637#24103)
    end
    object send_type_box: TComboBox
      Left = 337
      Top = 24
      Width = 71
      Height = 21
      ItemHeight = 13
      TabOrder = 3
      Items.Strings = (
        #27491#24120#21457#36865
        #21333#27425#21457#36865
        #33258#21457#33258#25910
        #21333#27425#33258#21457#33258#25910)
    end
    object rtr_box: TComboBox
      Left = 187
      Top = 24
      Width = 68
      Height = 21
      ItemHeight = 13
      TabOrder = 4
      Items.Strings = (
        #25968#25454#24103
        #36828#31243#24103)
    end
    object can_type_box: TComboBox
      Left = 458
      Top = 24
      Width = 58
      Height = 21
      ItemHeight = 13
      TabOrder = 5
      Items.Strings = (
        'CAN'
        'CANFD')
    end
    object canfd_brs: TCheckBox
      Left = 535
      Top = 26
      Width = 80
      Height = 17
      Caption = 'CANFD'#21152#36895
      TabOrder = 6
    end
  end
  object send_Button: TButton
    Left = 654
    Top = 249
    Width = 75
    Height = 25
    Caption = #21457#36865
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 5
    OnClick = send_ButtonClick
  end
  object filer_setting: TGroupBox
    Left = 455
    Top = 17
    Width = 193
    Height = 177
    Caption = #28388#27874#35774#32622
    TabOrder = 6
    object Label15: TLabel
      Left = 13
      Top = 57
      Width = 52
      Height = 13
      Caption = #28388#27874#27169#24335':'
    end
    object Label16: TLabel
      Left = 11
      Top = 92
      Width = 84
      Height = 13
      Caption = #28388#27874#36215#22987#24103'(0x):'
    end
    object Label17: TLabel
      Left = 13
      Top = 127
      Width = 84
      Height = 13
      Caption = #28388#27874#32467#26463#24103'(0x):'
    end
    object filter_check: TCheckBox
      Left = -7
      Top = 26
      Width = 83
      Height = 17
      BiDiMode = bdRightToLeft
      Caption = #21551#29992#28388#27874
      Color = clBtnFace
      ParentBiDiMode = False
      ParentColor = False
      TabOrder = 0
    end
    object filtermode_box: TComboBox
      Left = 71
      Top = 49
      Width = 73
      Height = 21
      ItemHeight = 13
      TabOrder = 1
      Items.Strings = (
        #26631#20934#24103
        #25193#23637#24103)
    end
    object filter_end_edit: TEdit
      Left = 103
      Top = 124
      Width = 73
      Height = 21
      TabOrder = 2
      Text = '200'
    end
    object filter_start_edit: TEdit
      Left = 101
      Top = 89
      Width = 73
      Height = 21
      TabOrder = 3
      Text = '100'
    end
  end
  object getdevinf_Button: TButton
    Left = 653
    Top = 105
    Width = 75
    Height = 25
    Caption = #35774#22791#20449#24687
    TabOrder = 7
    OnClick = getdevinf_ButtonClick
  end
  object data_clear_Button: TButton
    Left = 653
    Top = 320
    Width = 75
    Height = 25
    Caption = #28165#31354#26174#31034
    TabOrder = 8
    OnClick = data_clear_ButtonClick
  end
end
