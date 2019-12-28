//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include "Info.h"
#include <Vcl.ExtCtrls.hpp>
#pragma comment(lib,"ws2_32.lib")
#include <WS2tcpip.h>
#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <process.h>

//---------------------------------------------------------------------------
class TForm_main : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo_Activity;
	TLabel *Label_Activity;
	TButton *Button_Start;
	TMainMenu *MainMenu1;
	TMenuItem *N_Info;
	TLabeledEdit *LabeledEdit_Port;
	TButton *Button_Port;
	void __fastcall N_InfoClick(TObject *Sender);
	void __fastcall Button_StartClick(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button_PortClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm_main(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_main *Form_main;
//---------------------------------------------------------------------------
#endif
