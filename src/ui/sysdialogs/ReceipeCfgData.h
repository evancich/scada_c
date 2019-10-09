/**********************************************************************

	--- Qt Architect generated file ---

	File: ReceipeCfgData.h
	Last generated: Fri Dec 28 10:26:42 2001

	DO NOT EDIT!!!  This file will be automatically
	regenerated by qtarch.  All changes will be lost.

 *********************************************************************/

#ifndef ReceipeCfgData_included
#define ReceipeCfgData_included

#include <qdialog.h>
#include <qpushbutton.h>
#include <qlistview.h>
#include <qcombobox.h>
#include <qlineedit.h>

class ReceipeCfgData : public QDialog
{
    Q_OBJECT

public:

    ReceipeCfgData
    (
        QWidget* parent = NULL,
        const char* name = NULL
    );

    virtual ~ReceipeCfgData();

public slots:


protected slots:

    virtual void Help()=0;
    virtual void ClearAll()=0;
    virtual void Delete()=0;
    virtual void SetAll()=0;
    virtual void SelChanged(int)=0;
    virtual void Apply()=0;
    virtual void New()=0;
    virtual void ConfigureUnit()=0;
    virtual void AlarmLimits()=0;
	virtual void Exit()=0;

protected:
    QComboBox* Name;
    QLineEdit* Comment;
    QListView* UnitsList;
    QPushButton* UnitButton;
    QListView* SampleList;
    QPushButton* ApplyButton;
	QPushButton* ExitButton;
    QPushButton* NewButton;
    QPushButton* DeleteButton;
    QPushButton* LimitsButton;
};

#endif // ReceipeCfgData_included
