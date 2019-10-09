/**********************************************************************
--- Qt Architect generated file ---
File: Opc_client_daInput.cpp
Last generated: Mon May 22 17:08:25 2000
*********************************************************************/
#include <qt.h>
#include "opc_client_daInput.h"
#include "opc_client_da.h"
#include "opc_client_da_instance.h"
#include "opc_client_dadriverthread.h"

#define Inherited Opc_client_daInputData

Opc_client_daInput::Opc_client_daInput
(
QWidget* parent,
const char* name
)
:
Inherited( parent, name ),Name(name)
{
	// add FP validators to Low and High
	//Low->setValidator(new QDoubleValidator(-100000.0,100000.0,3,Low));
	//High->setValidator(new QDoubleValidator(-100000.0,100000.0,3,High));
}

Opc_client_daInput::~Opc_client_daInput()
{
}

void Opc_client_daInput::Load(const QString &s)// load the configuration
{
	/*
	if(GetConfigureDb()->GetNumberResults() > 0)
	{
		QString s = GetConfigureDb()->GetString("PARAMS");
		ItemID->setText(s);
	}
	else
	{
		
	}
	*/
	
	if(GetConfigureDb()->GetNumberResults()) // it is a given that the correct properties record has been selected
	{ 
		QString s = UndoEscapeSQLText(GetConfigureDb()->GetString("PARAMS"));
		QTextIStream is (&s);
		//
		QString a;
		is >> a;
		ItemID->setText(a.stripWhiteSpace());
		ItemID->setEnabled(false);
		//
		is >> a;
		OPCType->setText(a.stripWhiteSpace());
		OPCType->setEnabled(false);
		//
		is >> a;
		QString check(a.stripWhiteSpace());
		IsWriteble->setChecked (check.toInt());
		IsWriteble->setEnabled(false);
	}
	else
	{
		ItemID->setText("");
		OPCType->setText("");
		IsWriteble->setChecked(0);
	};
	
};

void Opc_client_daInput::Save(const QString &s)// save the configuration
{
	//
	// save from fields to properties
	// 
	/*
	QString cmd = "delete from PROPS where SKEY ='SAMPLEPROPS' and IKEY='"+s+"';";
	GetConfigureDb()->DoExec(0,cmd,0);
	//
	QString t;
	t =  Interval->text() + " " + Low->text() + " " + High->text();
	//
	cmd = "insert into PROPS values('SAMPLEPROPS','"+s+"','"+t.stripWhiteSpace()+"');";
	GetConfigureDb()->DoExec(0,cmd,0);
	*/
	//
};
