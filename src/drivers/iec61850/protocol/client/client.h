/*
 *                         IndigoSCADA
 *
 *   This software and documentation are Copyright 2002 to 2014 Enscada 
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $HOME/LICENSE 
 *
 *   for full copyright notice and license terms. 
 *
 */
#ifndef IEC61850_CLIENT
#define IEC61850_CLIENT

#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include "itrace.h"
//////////////////////MMS/////////////////
typedef __int64  int64_t;
typedef unsigned __int64   uint64_t;

#ifdef __cplusplus
extern "C" {
#endif

#include "mms_client_connection.h"
#include "mms_types.h"

#ifdef __cplusplus
}
#endif
//////////////////////////////////////////

#include "iec_item_type.h" //Middleware
////////////////////////////Middleware///////////////////////////////////////////////////////
extern void onRegFail(void *param);
extern void recvCallBack(const ORTERecvInfo *info,void *vinstance, void *recvCallBackParam); 
/////////////////////////////////////////////////////////////////////////////////////////////

struct structItem
{
	char spname[200]; //Item ID of IEC61850 server, i.e. LLN0$ST$Health$stVal as C string
	unsigned int ioa_control_center;//unique inside CASDU
	unsigned int iec_104_type; //IEC 104 type
	float min_measure;
	float max_measure;
	unsigned char iec61850_type; //IEC61850 type
	unsigned int hClient; //index starting at 1
};

/*
typedef enum {
	MMS_ARRAY,
	MMS_STRUCTURE,
	MMS_BOOLEAN,
	MMS_BIT_STRING,
	MMS_INTEGER,
	MMS_UNSIGNED,
	MMS_FLOAT,
	MMS_OCTET_STRING,
	MMS_VISIBLE_STRING,
	MMS_GENERALIZED_TIME,
	MMS_BINARY_TIME,
	MMS_BCD,
	MMS_OBJ_ID,
	MMS_STRING,
	MMS_UTC_TIME
};
*/

enum client_states {
	CLIENT_NOT_INITIALIZED = 0,
	CLIENT_INITIALIZED,
	CLIENT_WAITING_FOR_FIRST_EVENT,
	CLIENT_ON_LINE
};

typedef enum {
	MMS_ERROR, MMS_INITIATE, MMS_CONFIRMED_REQUEST, MMS_OK, MMS_CONCLUDE
} MmsIndication;

struct sMmsValue {
	MmsType type;
	int deleteValue;
	union uMmsValue {
		struct {
			int size;
			MmsValue** components;
		} array;
		struct {
			int componentCount;
			MmsValue** components;
		} structure;
		int boolean;
		Asn1PrimitiveValue* integer;
		Asn1PrimitiveValue* unsignedInteger;
		struct {
			uint8_t exponentWidth;
			uint8_t formatWidth;
			uint8_t* buf;
		} floatingPoint;
		struct {
			int size;
			uint8_t* buf;
		} octetString;
		struct {
			int size;     /* Number of bits */
			uint8_t* buf;
		} bitString;
		char* mmsString;
		char* visibleString;
		uint8_t utcTime[8];
	} value;
};


////////////////////////////Middleware///////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

class IEC61850_client_imp
{
	public:
	
	IEC61850_client_imp(char* server_address, char* server_tcp_port, char* polling_time, char* line_number)
	{ 
		IT_IT("IEC61850_client_imp::IEC61850_client_imp");

		strcpy(ServerIPAddress, server_address);
		tcpPort = atoi(server_tcp_port);
		pollingTime = atoi(polling_time);

		fExit = false;
		Item = NULL;
		client_state_variable = CLIENT_NOT_INITIALIZED;
		timer_starts_at_epoch = 0;
		nameList = NULL;
		g_dwNumItems = 0;
		is_connected = false;
		/////////////////////Middleware/////////////////////////////////////////////////////////////////
		int32_t                 strength = 1;
		NtpTime                 persistence, deadline, minimumSeparation, delay;
		IPAddress				smIPAddress = IPADDRESS_INVALID;
		ORTEDomainProp          dp; 
		ORTEDomainAppEvents     events;

		publisher = NULL;
		subscriber = NULL;

		ORTEInit();
		ORTEDomainPropDefaultGet(&dp);
		NTPTIME_BUILD(minimumSeparation,0); 
		NTPTIME_BUILD(delay,1); //1s

		//initiate event system
		ORTEDomainInitEvents(&events);

		events.onRegFail = onRegFail;

		//Create application     
		domain = ORTEDomainAppCreate(ORTE_DEFAULT_DOMAIN,&dp,&events,ORTE_FALSE);

		iec_item_type_type_register(domain);

		//Create publisher
		NTPTIME_BUILD(persistence,5);

		char fifo_monitor_name[150];
		strcpy(fifo_monitor_name,"fifo_monitor_direction");
		strcat(fifo_monitor_name, line_number);
		strcat(fifo_monitor_name, "iec61850");

		publisher = ORTEPublicationCreate(
		domain,
		fifo_monitor_name,
		"iec_item_type",
		&instanceSend,
		&persistence,
		strength,
		NULL,
		NULL,
		NULL);

		//if(publisher == NULL){} //check this error
		
		char fifo_control_name[150];
		strcpy(fifo_control_name,"fifo_control_direction");
		strcat(fifo_control_name, line_number);
		strcat(fifo_control_name, "iec61850");

		//Create subscriber
		NTPTIME_BUILD(deadline,3);

		subscriber = ORTESubscriptionCreate(
		domain,
		IMMEDIATE,
		BEST_EFFORTS,
		fifo_control_name,
		"iec_item_type",
		&instanceRecv,
		&deadline,
		&minimumSeparation,
		recvCallBack,
		this,
		smIPAddress);

		//if(subscriber == NULL){} //check this error
		///////////////////////////////////Middleware//////////////////////////////////////////////////
		IT_EXIT;
	};
		
	~IEC61850_client_imp()
	{
		IT_IT("IEC61850_client_imp::~IEC61850_client_imp");
		stop_thread();
		Sleep(1000);
		///////////////////////////////////Middleware//////////////////////////////////////////////////
		ORTEDomainAppDestroy(domain);
		domain = NULL;
		////////////////////////////////////Middleware//////////////////////////////////////////////////
		IT_EXIT;
	}

	 bool fExit;
	 int client_state_variable;
	 time_t timer_starts_at_epoch;
	 char ServerIPAddress[80];
	 struct structItem* Item; //IEC61850 client items vector, indexed from 0
	 unsigned int g_dwNumItems;
	 int pollingTime;
	 bool is_connected;
	/////////////////////MMS//////////////////////
	MmsValue* value;
	LinkedList nameList;
	MmsIndication indication;
	MmsConnection con;
	int tcpPort; //Default is 102
	MmsVariableSpecification* typeSpec;
	time_t now;
	char mmsDomain[100];
	//////////////////////////////////////////////

    /////////////////////Middleware/////////////////////////
    ORTEDomain              *domain;
    ORTEPublication			*publisher;
    ORTESubscription        *subscriber;
    iec_item_type			instanceSend;
    iec_item_type		    instanceRecv;
    //////////////////////////////end//Middleware///////////

    /////////////Middleware///////////////////////////////
    u_int n_msg_sent_monitor_dir;
    u_int n_msg_sent_control_dir;
    //////////////////////////////////////////////////////
	 int Start(char* Password);
	 int Stop();
	 int AddItems();
	 void LogMessage(HRESULT hr = S_OK, LPCSTR pszError = NULL, const char* name = NULL);
	 int sendEvents(void);
	 void pollServer(void);
	 void get_utc_host_time(struct cp56time2a* time);
	 time_t epoch_from_cp56time2a(const struct cp56time2a* time);
	 void epoch_to_cp56time2a(cp56time2a *time, signed __int64 epoch_in_millisec);
	 int check_connection_to_server(void);
	 short rescale_value(double V, double Vmin, double Vmax, int* error);
	 double rescale_value_inv(double A, double Vmin, double Vmax, int* error);
	 void CreateSqlConfigurationFile(void);
	 ////////////////////Middleware////////////////////////////////////////////////////
	 void check_for_commands(struct iec_item *item);
	 void alloc_command_resources(void);
	 void free_command_resources(void);
	 ////////////////////Middleware////////////////////////////////////////////////////
	
	 void stop_thread()
	 {
		fExit = true;
	 };
};

#endif //IEC61850_CLIENT