object Form_main: TForm_main
  Left = 390
  Top = 219
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Server'
  ClientHeight = 299
  ClientWidth = 553
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object Label_Activity: TLabel
    Left = 264
    Top = 5
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
  object Memo_Activity: TMemo
    Left = 160
    Top = 34
    Width = 369
    Height = 151
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object Button_Start: TButton
    Left = 344
    Top = 215
    Width = 123
    Height = 49
    Caption = #1047#1072#1087#1091#1089#1090#1080#1090#1080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = Button_StartClick
  end
  object LabeledEdit_Port: TLabeledEdit
    Left = 16
    Top = 80
    Width = 121
    Height = 21
    EditLabel.Width = 115
    EditLabel.Height = 13
    EditLabel.Caption = #1042#1082#1072#1078#1110#1090#1100' '#1087#1086#1088#1090' '#1089#1077#1088#1074#1077#1088#1072':'
    TabOrder = 2
  end
  object Button_Port: TButton
    Left = 56
    Top = 215
    Width = 194
    Height = 49
    Caption = #1055#1086#1082#1072#1079#1072#1090#1080' '#1055#1086#1088#1090' '#1089#1077#1088#1074#1077#1088#1072
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = Button_PortClick
  end
  object MainMenu1: TMainMenu
    object N_Info: TMenuItem
      Caption = #1044#1086#1074#1110#1076#1082#1072
      OnClick = N_InfoClick
    end
  end
end
