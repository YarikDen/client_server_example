﻿object Form_main: TForm_main
  Left = 0
  Top = 0
  Caption = 'Client'
  ClientHeight = 398
  ClientWidth = 574
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 280
    Top = 4
    Width = 168
    Height = 23
    Caption = #1042#1110#1082#1085#1086' '#1087#1086#1074#1110#1076#1086#1084#1083#1077#1085#1100':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label_Host_list: TLabel
    Left = 312
    Top = 203
    Width = 131
    Height = 23
    Caption = #1057#1087#1080#1089#1086#1082' '#1093#1086#1089#1090#1110#1074' :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Memo_Activity: TMemo
    Left = 194
    Top = 33
    Width = 372
    Height = 164
    Color = clMenuText
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindow
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object Button_Сheck_One: TButton
    Left = 11
    Top = 184
    Width = 177
    Height = 25
    Caption = #1055#1077#1088#1077#1074#1110#1088#1080#1090#1080' '#1086#1073#1088#1072#1085#1080#1081' '#1089#1077#1088#1074#1077#1088'-'#1093#1086#1089#1090
    TabOrder = 1
    OnClick = Button_Сheck_OneClick
  end
  object LabeledEdit_Server_port: TLabeledEdit
    Left = 8
    Top = 72
    Width = 180
    Height = 21
    EditLabel.Width = 147
    EditLabel.Height = 13
    EditLabel.Caption = #1042#1074#1077#1076#1110#1090#1100' '#1087#1086#1088#1090' '#1089#1077#1088#1074#1077#1088#1072'-'#1093#1086#1089#1090#1072':'
    TabOrder = 2
  end
  object LabeledEdit_Server_ipaddress: TLabeledEdit
    Left = 8
    Top = 128
    Width = 180
    Height = 21
    EditLabel.Width = 174
    EditLabel.Height = 13
    EditLabel.Caption = #1042#1082#1072#1078#1110#1090#1100' IP-'#1072#1076#1088#1077#1089#1091' '#1089#1077#1088#1074#1077#1088#1072'-'#1093#1086#1089#1090#1072':'
    TabOrder = 3
  end
  object ListBox_Hosts: TListBox
    Left = 200
    Top = 232
    Width = 366
    Height = 153
    Color = clMoneyGreen
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = []
    ItemHeight = 15
    ParentFont = False
    TabOrder = 4
  end
  object Button_Check_All: TButton
    Left = 43
    Top = 215
    Width = 119
    Height = 25
    Caption = #1055#1077#1088#1077#1074#1110#1088#1080#1090#1080' '#1074#1089#1110' '#1093#1086#1089#1090#1080
    TabOrder = 5
    OnClick = Button_Check_AllClick
  end
  object Button_Add: TButton
    Left = 43
    Top = 246
    Width = 119
    Height = 25
    Caption = #1044#1086#1076#1072#1090#1080' '#1093#1086#1089#1090
    TabOrder = 6
    OnClick = Button_AddClick
  end
  object MainMenu1: TMainMenu
    object N_Info: TMenuItem
      Caption = #1044#1086#1074#1110#1076#1082#1072
      OnClick = N_InfoClick
    end
  end
end
