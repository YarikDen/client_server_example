//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_main *Form_main;
bool g_b_Stop = false;
HANDLE g_h_Thread;
unsigned g_u_idThread;
int g_i_Port;
WSAData g_wsaData;
WORD g_DLLVersion;
bool g_b_setupThread;
typedef struct thread{
	SOCKET sListen;
	SOCKADDR_IN server_info;
    TMemo * pMemo;

}Thread_param;
//---------------------------------------------------------------------------
__fastcall TForm_main::TForm_main(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_main::N_InfoClick(TObject *Sender)
{
	  Form_Info->ShowModal();
}
//---------------------------------------------------------------------------

  unsigned _stdcall thread_socket(void * pArguments);//thread function

void __fastcall TForm_main::Button_StartClick(TObject *Sender)
{
   ///////////////
   if(g_b_setupThread == false){
		g_i_Port = StrToInt(LabeledEdit_Port->Text);
		if(g_i_Port <=0 ){
           g_i_Port = 1111;
		}
		SOCKET sListen;
		SOCKADDR_IN server_info;
		sListen = socket(AF_INET,SOCK_STREAM,NULL);
		if(sListen != INVALID_SOCKET){
			server_info.sin_addr.s_addr = INADDR_ANY;///also can use function inet_pton
			server_info.sin_port=htons(g_i_Port);
			server_info.sin_family = AF_INET;
			if(bind(sListen,(SOCKADDR*)&server_info,sizeof(server_info)) == 0 ){
				Thread_param * pParam = (Thread_param *) calloc(1,sizeof(Thread_param));
				pParam->sListen = sListen;
                Button_Start->Enabled = false;
				pParam->server_info = server_info;
                pParam->pMemo = Memo_Activity;
				g_h_Thread = (HANDLE)_beginthreadex( NULL, 0, &thread_socket, pParam, 0, &g_u_idThread );
				ShowMessage("Server was successfuly turned on!!!");
                g_b_setupThread = true;
			}else{
                ShowMessage("Please set other port for server. It can be busy by other service!!!");
			}

		}
   }
}
//---------------------------------------------------------------------------


  unsigned _stdcall thread_socket(void * pArguments){
	/////
	Thread_param thr_params = *((Thread_param*)pArguments);
	free(((Thread_param *) pArguments));//clean dynamic alloc memory
	///////Client data
	SOCKADDR_IN Client_info;
	SOCKET client_socket;
	//////////
	int i_sizeof_server = 0,
		i_sizeof_client = 0,
		i_Bytesrecv = 0,
		i_SendBytes = 0;
	WORD DLLVersion = MAKEWORD(2,2); //version of library
	WSAData wsaData;
	char ch_service_client[NI_MAXHOST], //service(port) the client is connect on
		 ch_hostname_client[NI_MAXHOST], //ip address of client
		 ch_service_serv[NI_MAXHOST] ,
		 ch_hostname_serv[NI_MAXHOST] ,//server hostname
		 ch_buffer[1024],//message from client
		 ch_msg[1024];//message of server
	 ///////////Clear unknown data
	ZeroMemory(ch_service_client,sizeof(ch_service_client));
	ZeroMemory(ch_hostname_client,sizeof(ch_hostname_client));
	ZeroMemory(ch_service_serv,sizeof(ch_service_serv));
	ZeroMemory(ch_hostname_serv,sizeof(ch_hostname_serv));
	ZeroMemory(ch_buffer,sizeof(ch_buffer));
	ZeroMemory(ch_msg,sizeof(ch_msg));
    i_sizeof_server = sizeof(thr_params.server_info);
	getnameinfo((SOCKADDR*)&thr_params.server_info,i_sizeof_server,ch_hostname_serv,NI_MAXHOST,ch_service_serv,NI_MAXSERV,0);//get server info
	///////////////
	listen(thr_params.sListen,
				SOMAXCONN);//max amount of tcp-connections

	i_sizeof_client = sizeof(Client_info);

    			/////////Wait for connection
	while(true){

		client_socket = accept(thr_params.sListen,(SOCKADDR*)&Client_info,&i_sizeof_client);// client was successfully connected
		getnameinfo((SOCKADDR*)&Client_info,sizeof(Client_info),ch_hostname_client,NI_MAXHOST,ch_service_client,NI_MAXSERV,0); //get info about client

			//////////////////while accept message from client and send message to client

				///////Wait for client to send data
		i_Bytesrecv = recv(client_socket,ch_buffer,1024,0);
		if(i_Bytesrecv != SOCKET_ERROR){
			if(strlen(ch_buffer)> 0){
                inet_ntop(AF_INET,&Client_info.sin_addr,ch_hostname_client,35); //get ip address in char presentation
				sprintf(ch_msg,"Hello client! This message from server-host,which name is = <<%s>>.Server works on port = <<%s>>.Your ip-address = <<%s>> and you work on port = <<%s>>\r\nYour message was <<%s>>",ch_hostname_serv,ch_service_serv,ch_hostname_client,ch_service_client,ch_buffer);///make format message to client
				thr_params.pMemo->Text = thr_params.pMemo->Text + "\r\n<*************************>\r\nMessage from Client(ip-address = " + ch_hostname_client + " ):>>>" + ch_buffer + "\r\n<*************************>";
				send(client_socket,ch_msg,strlen(ch_msg),0);//////Send message to client
			}
		}else{
			ShowMessage("Error recv");
		}
		closesocket(client_socket);
	}
	closesocket(thr_params.sListen);
    _endthreadex(0);//clear memory and finish work of thread
    return 0;
  }

void __fastcall TForm_main::FormDestroy(TObject *Sender)
{   TerminateThread(g_h_Thread,0);
	CloseHandle(g_h_Thread);
	WSACleanup();

}
//---------------------------------------------------------------------------

void __fastcall TForm_main::FormCreate(TObject *Sender)
{
	g_DLLVersion = MAKEWORD(2,2);
	if(WSAStartup(g_DLLVersion,&g_wsaData) == 0){
		ShowMessage("Good load of DLL!!!");
	}else{
        ShowMessage("Bad load of DLL!!!");
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm_main::Button_PortClick(TObject *Sender)
{
	ShowMessage(g_i_Port);
}
//---------------------------------------------------------------------------

