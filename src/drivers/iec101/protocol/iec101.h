/*
 *                         IndigoSCADA
 *
 *   This software and documentation are Copyright 2002 to 2011 Enscada 
 *   Limited and its licensees. All rights reserved. See file:
 *
 *                     $HOME/LICENSE 
 *
 *   for full copyright notice and license terms. 
 *
 */
#ifndef __IEC101_H
#define __IEC101_H

#include "iec101_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define IEC_OBJECT_MAX	127 //Numero massimo di oggetti accodati o "impaccati" in un unico messaggio iec
#define IEC_TYPEID_LEN	3  //Type identification (1 ottetto) + variable structure qualifier (1 ottetto) + COT (1 ottetti)
#define IEC_101_MAX_EVENTS 70000 //numero massimo di eventi di ogni tipo bufferizzati dalle code

#define MAX_FIFO_SIZE_CONTROL_DIRECTION 65536 //2^16 since 24-08-2011
#define MAX_FIFO_SIZE_MONITOR_DIRECTION 65535

#define NUMBER_OF_QUEUED_ITEMS_IN_CONTROL_DIRECTION MAX_FIFO_SIZE_CONTROL_DIRECTION/(sizeof(struct iec_item))
#define NUMBER_OF_QUEUED_ITEMS_IN_MONITOR_DIRECTION MAX_FIFO_SIZE_MONITOR_DIRECTION/(sizeof(struct iec_item))


int iecasdu_parse(struct iec_object *obj, u_char *type, u_short *com_addr, 
	int *cnt, u_char *cause, u_char *test, u_char *pn, size_t ioa_len, 
	size_t ca_len, u_char *buf, size_t buflen);

void get_local_iec_time(struct cp56time2a* time);

void get_utc_iec_time(struct cp56time2a* time);

void process_timer_send_frame(struct iecserial *s, void *arg);

void process_data_received_hook(struct iecserial *s, struct iec_buf *b);

void send_items(struct iecserial *s, struct iec_item* items, int n_items);

//void general_interrogation_load_points(struct iecserial *s);

int get_items_from_producer(struct iecserial *s);

void iec_call_exit_handler(int line, char* file, char* reason);

void log_message(char* msg);

void __cdecl iec101SignalHandler(int signal);

int load_config_ini(char* numero_linea);

int alloc_queues(void);

void send_item_to_superior_scada(struct iec_item* p_queued_item);

int init_fifos(char* fifo_monitor_direction_name, char* fifo_control_direction_name, char* fifo_control_direction_name_ae);

void reset_state_machines(void);

void set_link_state(int state);

void clearing_ftwd(void);

void clearing_logs(void);

void send_lost_packet(void);

void get_iec_buf(struct iec_buf **c);

void free_iec_buf(struct iec_buf *b);

void iec101_run_send_queues(struct iecserial *s);

//#define CHECK_TIMEOUT_WITH_PARENT
int check_timeout_with_parent(int polling_time);

//////////////////////////////////////////////////////////////////////////////////////////////
extern u_short select_before_operate;
extern u_short gl_common_address_of_asdu;
extern u_short gl_link_address;
extern u_short gl_master_polling_time_in_milliseconds;
extern u_short gl_slave_polling_time_in_milliseconds;
extern int state_iec_101_link;
extern int gl_read_timeout_ms;

extern FILE *iec_protocol_log_stream;
extern char iec_optional_log_file_name[80];

//Interface to field//////////////////////////////////////////////////////////////////////////
//Multithread shared fifo
//extern fifo_h fifo_control_direction; //fifo in control direction: SCADA-------------> RTU DA server if s->type == IEC_SLAVE
//extern fifo_h fifo_monitor_direction; //fifo in monitor direction: SCADA<------------- RTU

enum iec101slave_states {
	SLAVE_NOT_INITIALIZED = 0,
	SLAVE_INITIALIZED,
	SLAVE_SENDING_DATA
};

enum database_states {
	DB_IDLE = 0,
	DB_STARTUP,
	LOAD_DATABASE,
	DATABASE_LOADED,
	DB_START_COUNT_DOWN_TIMER 
};

enum file_transfer_states {
	FT_IDLE  = 0,
	FT_ERROR,
	FT_SCAN_WORKING_DIRECTORY,
	FT_PREPARE_DIRECTORY,
	FT_DIRECTORY_SENT,
	FT_REMOVE_CONFIGURATION_FILE,
	FT_ENDED_ON_SENDER_SIDE,
	FT_RENAME_FILE_TRANSFERED,
	FT_REMOVE_TRANSFERED_FILE,
	FT_RECEIVING_FILE
};

enum gateway_states {
	GW_IDLE = 0,
	GW_SEND_NEW_CONFIG_FILE_TO_SLAVE,
	GW_SCAN_FOR_CONFIG_FILE,
	GW_STARTUP
};

enum general_interrogation_states {
	GI_IDLE = 0,
	GI_LOAD_POINTS,
	GI_REQUEST_GI_TO_FIELD,
	GI_REQUEST_GI_TO_FIELD_DONE,
	GI_POINTS_LOADED,
	GI_ACTIVATION,
	GI_CONFIRMATION,
	GI_WAIT_FOR_CONFIRMATION,
	GI_WAIT_FOR_TERMINATION,
	GI_NEG_CONFIRMATION,
	GI_TERMINATION,
	GI_NEG_TERMINATION,
	GI_ERROR
};

enum spontaneous_states {
	MSG_IDLE = 0,
	MSG_RECEIVE_MESSAGES_FROM_FIELD
};

enum commands_states {
	CMD_IDLE = 0,
	CMD_SEND_COMMANDS
};

enum clock_sincro_states {
	CLK_IDLE = 0,
	CLK_STATIONS_SYNCRONIZED
};

enum iec_101_link_states {
	LNK_IDLE = 0,
	LNK_CONNECTED
};

enum gl_logs_states {
	LOGS_IDLE = 0,
	LOGS_STARTUP,
	LOGS_WAIT_FOR_CHECK,
	LOGS_CHECK_AGE
};

struct alloc_iec_buf {
	struct iec_buf *c;
	u_char used;
};

extern struct alloc_iec_buf v_iec_buf[IEC_101_MAX_EVENTS];

#ifdef __cplusplus
}
#endif

#endif	/* __IEC101_H */
