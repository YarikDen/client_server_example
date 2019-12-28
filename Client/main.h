//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Info.h"
#include <Vcl.Menus.hpp>
#include <Vcl.ExtCtrls.hpp>
#pragma comment(lib,"ws2_32.lib")
#include <WS2tcpip.h>
#include <stdio.h>
#include <list>
#include <iterator>
//---------------------------------------------------------------------------
class TForm_main : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N_Info;
	TMemo *Memo_Activity;
	TLabel *Label1;
	TButton *Button_Ñheck_One;
	TLabeledEdit *LabeledEdit_Server_port;
	TLabeledEdit *LabeledEdit_Server_ipaddress;
	TListBox *ListBox_Hosts;
	TButton *Button_Check_All;
	TLabel *Label_Host_list;
	TButton *Button_Add;
	void __fastcall Button_Ñheck_OneClick(TObject *Sender);
	void __fastcall N_InfoClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall Button_AddClick(TObject *Sender);
	void __fastcall Button_Check_AllClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm_main(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_main *Form_main;
//---------------------------------------------------------------------------
#endif
