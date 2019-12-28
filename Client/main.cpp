//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_main *Form_main;
WSAData g_wsaData;  //structure with information about library
WORD g_DLLVersion;    //version of library
typedef struct ip_server{
	char ch_ip_addr[50];
	int  i_port_server;
}Server;
std::list<Server> g_lst_Server_info;
BOOL CheckCorrectIp(char* ch_ip){////Check ip-address
	BOOL B_Correct = TRUE;
	SOCKADDR_IN ip_struct;
	if(inet_pton(AF_INET,ch_ip,&ip_struct.sin_addr) != 1){
		B_Correct = FALSE;
	}
	return B_Correct;
}

void CheckConnection(Server serv_info){
	char ch_buf[512] = " ",
	ch_msg[512] = " ",
	ch_hostname_client[512] = " ";
	SOCKET sConnect;
	SOCKADDR_IN serv_host;
	int i_SendRes = 0, //bytes sent
		i_BytesRecv = 0;  //bytes received

	gethostname(ch_hostname_client,512);//get hostname
	////////////////init socket
	sConnect = socket(AF_INET,SOCK_STREAM,0); //create socket
	if(sConnect != INVALID_SOCKET){//check for correct creation
		//////////////////Fill serv_host structure

		serv_host.sin_port=htons(serv_info.i_port_server); // set port of host-server
		serv_host.sin_family = AF_INET; //set family of Internet Protocols
		if(inet_pton(AF_INET,serv_info.ch_ip_addr,&serv_host.sin_addr) == 1){ // set ip-address of hos-server
			///Setup connection
			if(connect(sConnect,(SOCKADDR*)&serv_host,sizeof(serv_host))!= SOCKET_ERROR){
				//////////////Set info to screen about activity of server-host
				sprintf(ch_msg,"Server, which ip-address = <<%s>>and works on port = <<%d>> is ONLINE(active)!!!",serv_info.ch_ip_addr,serv_info.i_port_server);
				Form_main->Memo_Activity->Text = Form_main->Memo_Activity->Text + "\r\n<*************************>\r\n" + ch_msg;
				sprintf(ch_msg,"Hello Server-Host, which ip-address = <<%s>>and works on port = <<%d>>.This message from host, which name is <<%s>>!!!",serv_info.ch_ip_addr,serv_info.i_port_server,ch_hostname_client);
				/////////////
				////////////Send some text to server-host
				i_SendRes = send(sConnect,ch_msg,strlen(ch_msg)+1,0);
				///////////
				if(i_SendRes != SOCKET_ERROR ){///check for success send
					i_BytesRecv = recv(sConnect,ch_buf,512,NULL);
				}

				if(i_BytesRecv != 0){ ///check for success receive
					ShowMessage("Something was received from server-host!!!");
					Form_main->Memo_Activity->Text = Form_main->Memo_Activity->Text + "\r\nServer message:>> <<" + ch_buf + ">> ;\r\n<*************************>";
				}else{
					ShowMessage("Nothing was received!!!");
				}
			}else{
				sprintf(ch_msg,"Server, which ip-address = <<%s>>and works on port = <<%d>> is OFFLINE(not active)!!!",serv_info.ch_ip_addr,serv_info.i_port_server);
				ShowMessage("Server is not at network!!!");
				Form_main->Memo_Activity->Text = Form_main->Memo_Activity->Text + "\r\n<*************************>\r\n" + ch_msg + "\r\n<*************************>";
			}
			closesocket(sConnect);//Close socket
		}else{
			ShowMessage("Bad ip-address!!!");
		}
	}else{
		ShowMessage("Invalid create of Socket.Please reload program or remake data!!!");
	}

}

BOOL ServerExists(Server Server_info,std::list<Server> lst_Server_info){//check for existence in List
	BOOL B_Exists = FALSE;
	if(!lst_Server_info.empty()){
		std::list<Server>::iterator iter = lst_Server_info.begin();
		for(;iter != lst_Server_info.end() ; iter++){
			if(strcmp((*iter).ch_ip_addr,Server_info.ch_ip_addr)== 0 && (*iter).i_port_server == Server_info.i_port_server){//check for equility
				B_Exists = TRUE;
				break;
			}
		}
	}
	return B_Exists;
}
//---------------------------------------------------------------------------
__fastcall TForm_main::TForm_main(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_main::Button_�heck_OneClick(TObject *Sender)
{
	if(ListBox_Hosts->ItemIndex != -1 && ListBox_Hosts->GetCount()!= 0 ){
		std::list<Server>::iterator iter = g_lst_Server_info.begin();
		int i = 0;
		for(;iter != g_lst_Server_info.end() ; iter++,i++){
			if(ListBox_Hosts->ItemIndex == i){
				CheckConnection((*iter)); //check connection
				break;
			}
		}
	}else{
		ShowMessage("Choose,Item in List or add new(if List is empty)!!!");
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm_main::N_InfoClick(TObject *Sender)
{
    Form_Info->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm_main::FormCreate(TObject *Sender)
{   Server serv_info;
	wchar_t wch_str[512] = L" ";
	String wstr_Format = L" ";
	ZeroMemory(&serv_info,sizeof(serv_info));
	FILE * fread = fopen("Hosts.txt","r");///////////////read data from file
	if(fread != NULL){
	   for(;;){
			if(fscanf(fread,"%s%d",serv_info.ch_ip_addr,&serv_info.i_port_server)!= EOF){
				mbstowcs(wch_str,serv_info.ch_ip_addr,strlen(serv_info.ch_ip_addr));///convert to wchar_t string
				wstr_Format = Format(L"Server-host(ip-address = <<%s>>)works on port %d ;",ARRAYOFCONST((wch_str,serv_info.i_port_server)));
				g_lst_Server_info.push_back(serv_info);// put to list server-host info
				ListBox_Hosts->Items->Add(wstr_Format);// put to view list
			}else{
                break;
			}
	   }
	}
	//////////////////////////////////////////////////////////
	g_DLLVersion = MAKEWORD(2,2);    //version of library
	if(WSAStartup(g_DLLVersion,&g_wsaData) != 0){// initialization of WSAData
		ShowMessage("Something was bad with load of winsock.Reload this application!!!");
	}else{
    	ShowMessage("Good load of Winsock DLL!!!");
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm_main::FormDestroy(TObject *Sender)
{   
    WSACleanup();
}
//---------------------------------------------------------------------------


void __fastcall TForm_main::Button_AddClick(TObject *Sender)
{   String wstr_Format = L" ";
	Server serv_info;
	ZeroMemory(&serv_info,sizeof(serv_info));
	wcstombs(serv_info.ch_ip_addr,LabeledEdit_Server_ipaddress->Text.c_str(),50);//convert to char string
	serv_info.i_port_server = StrToInt(LabeledEdit_Server_port->Text);///set number of port
	if(CheckCorrectIp(serv_info.ch_ip_addr)== TRUE){//check for correct ip
		if(ServerExists(serv_info,g_lst_Server_info)== FALSE || ListBox_Hosts->GetCount() == 0){ //check fo existence
            wstr_Format = Format(L"Server-host(ip-address = <<%s>>)works on %s ;",ARRAYOFCONST((LabeledEdit_Server_ipaddress->Text,LabeledEdit_Server_port->Text)));
			g_lst_Server_info.push_back(serv_info);// put to list server-host info
			ListBox_Hosts->Items->Add(wstr_Format);// put to view list
			ShowMessage("Item successfuly added");
			//////save to file server info
            FILE * fwrite;
			fwrite = fopen("Hosts.txt","ab");
			if( fwrite != NULL){ //save info about servers in file
				fprintf(fwrite,"%s\r\n%d\r\n",serv_info.ch_ip_addr,serv_info.i_port_server);
			}
			fclose(fwrite);
			/////////

		}else{
            ShowMessage("Item already exists!!!");
		}
	}else{
        ShowMessage("Please set good ip address!!!");
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm_main::Button_Check_AllClick(TObject *Sender)
{
    if( ListBox_Hosts->GetCount()!= 0 ){
		std::list<Server>::iterator iter = g_lst_Server_info.begin();
		for(;iter != g_lst_Server_info.end() ; iter++){
			CheckConnection((*iter)); //check connection
		}

	}else{
		ShowMessage("List is empty.Please add new items!!!");
	}
}
//---------------------------------------------------------------------------




