/**********************************************************************
--- Qt Architect generated file ---
File: SystemCfgData.h
Last generated: Tue Feb 27 16:39:10 2001
DO NOT EDIT!!!  This file will be automatically
regenerated by qtarch.  All changes will be lost.
*********************************************************************/
#ifndef SystemCfgData_included
#define SystemCfgData_included
#include <qt.h>

class SystemCfgData : public QDialog
{
	Q_OBJECT
	public:
	SystemCfgData(QWidget *parent = NULL, const char *name = NULL);
	virtual ~SystemCfgData();
	protected slots:
	virtual void Help() =0;
	virtual void AutoLogoutToggled(bool) =0;
	virtual void OkClicked() =0;
	protected:
	QLineEdit *Name;
	QLineEdit *Comment;
	QComboBox *Language;
	QComboBox *AuditLevel;
	QCheckBox *AutoLogOut;
	QSpinBox *AutoLogOutTime;
	QCheckBox *MidnightReset;
};
#endif // SystemCfgData_included

