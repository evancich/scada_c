/**********************************************************************
--- Qt Architect generated file ---
File: MQTT_clientCommandData.cpp
Last generated: Thu Jan 4 16:13:32 2001
DO NOT EDIT!!!  This file will be automatically
regenerated by qtarch.  All changes will be lost.
*********************************************************************/
#include <qt.h>
#include "MQTT_clientCommandData.h"
MQTT_clientCommandData::MQTT_clientCommandData(QWidget *parent, const char *name)
: QDialog(parent, name, TRUE, 208)
{
	QLabel *qtarch_Label_7 = new QLabel(this, "Label_7");
	qtarch_Label_7->setGeometry(10, 30, 90, 30);
	qtarch_Label_7->setMinimumSize(0, 0);
	qtarch_Label_7->setMaximumSize(32767, 32767);
	qtarch_Label_7->setFocusPolicy(QWidget::NoFocus);
	qtarch_Label_7->setBackgroundMode(QWidget::PaletteBackground);
	#if QT_VERSION < 300
	qtarch_Label_7->setFontPropagation(QWidget::SameFont);
	qtarch_Label_7->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_Label_7->setFrameStyle( 0 );
	qtarch_Label_7->setLineWidth( 1 );
	qtarch_Label_7->setMidLineWidth( 0 );
	qtarch_Label_7->QFrame::setMargin( 0 );
	qtarch_Label_7->setText( tr( "Name" ) );
	qtarch_Label_7->setAlignment( AlignLeft|AlignVCenter|ExpandTabs );
	qtarch_Label_7->setMargin( 0 );
	Name = new QLabel(this, "Label_8");
	Name->setGeometry(120, 30, 330, 30);
	Name->setMinimumSize(0, 0);
	Name->setMaximumSize(32767, 32767);
	Name->setFocusPolicy(QWidget::NoFocus);
	Name->setBackgroundMode(QWidget::PaletteBackground);
	#if QT_VERSION < 300
	Name->setFontPropagation(QWidget::SameFont);
	Name->setPalettePropagation(QWidget::SameFont);
	#endif
	Name->setFrameStyle( 50 );
	Name->setLineWidth( 1 );
	Name->setMidLineWidth( 0 );
	Name->QFrame::setMargin( 0 );
	Name->setText( "" );
	Name->setAlignment( AlignLeft|AlignVCenter|ExpandTabs );
	Name->setMargin( 0 );
	
	QPushButton *qtarch_PushButton_1 = new QPushButton(this, "PushButton_1");
	qtarch_PushButton_1->setGeometry(20, 230, 100, 30);
	qtarch_PushButton_1->setMinimumSize(0, 0);
	qtarch_PushButton_1->setMaximumSize(32767, 32767);
	qtarch_PushButton_1->setFocusPolicy(QWidget::TabFocus);
	qtarch_PushButton_1->setBackgroundMode(QWidget::PaletteButton);
	#if QT_VERSION < 300
	qtarch_PushButton_1->setFontPropagation(QWidget::SameFont);
	qtarch_PushButton_1->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_PushButton_1->setText( tr( "Ok" ) );
	qtarch_PushButton_1->setAutoRepeat( FALSE );
	qtarch_PushButton_1->setAutoResize( FALSE );
	qtarch_PushButton_1->setToggleButton( FALSE );
	qtarch_PushButton_1->setDefault( FALSE );
	qtarch_PushButton_1->setAutoDefault( FALSE );
	qtarch_PushButton_1->setIsMenuButton( FALSE );
	connect(qtarch_PushButton_1, SIGNAL(clicked()), SLOT(OkClicked()));
	QPushButton *qtarch_PushButton_2 = new QPushButton(this, "PushButton_2");
	qtarch_PushButton_2->setGeometry(210, 230, 100, 30);
	qtarch_PushButton_2->setMinimumSize(0, 0);
	qtarch_PushButton_2->setMaximumSize(32767, 32767);
	qtarch_PushButton_2->setFocusPolicy(QWidget::TabFocus);
	qtarch_PushButton_2->setBackgroundMode(QWidget::PaletteButton);
	#if QT_VERSION < 300
	qtarch_PushButton_2->setFontPropagation(QWidget::SameFont);
	qtarch_PushButton_2->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_PushButton_2->setText( tr( "&Help" ) );
	qtarch_PushButton_2->setAutoRepeat( FALSE );
	qtarch_PushButton_2->setAutoResize( FALSE );
	qtarch_PushButton_2->setToggleButton( FALSE );
	qtarch_PushButton_2->setDefault( FALSE );
	qtarch_PushButton_2->setAutoDefault( FALSE );
	qtarch_PushButton_2->setIsMenuButton( FALSE );
	connect(qtarch_PushButton_2, SIGNAL(clicked()), SLOT(Help()));
	QPushButton *qtarch_PushButton_3 = new QPushButton(this, "PushButton_3");
	qtarch_PushButton_3->setGeometry(360, 230, 100, 30);
	qtarch_PushButton_3->setMinimumSize(0, 0);
	qtarch_PushButton_3->setMaximumSize(32767, 32767);
	qtarch_PushButton_3->setFocusPolicy(QWidget::TabFocus);
	qtarch_PushButton_3->setBackgroundMode(QWidget::PaletteButton);
	#if QT_VERSION < 300
	qtarch_PushButton_3->setFontPropagation(QWidget::SameFont);
	qtarch_PushButton_3->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_PushButton_3->setText( tr( "Cancel" ) );
	qtarch_PushButton_3->setAutoRepeat( FALSE );
	qtarch_PushButton_3->setAutoResize( FALSE );
	qtarch_PushButton_3->setToggleButton( FALSE );
	qtarch_PushButton_3->setDefault( FALSE );
	qtarch_PushButton_3->setAutoDefault( FALSE );
	qtarch_PushButton_3->setIsMenuButton( FALSE );
	connect(qtarch_PushButton_3, SIGNAL(clicked()), SLOT(reject()));

	Value = new QLineEdit(this, "User_2");
	Value->setGeometry(120, 80, 200, 30);
	Value->setMinimumSize(0, 0);
	Value->setMaximumSize(32767, 32767);
	Value->setFocusPolicy(QWidget::StrongFocus);
	Value->setBackgroundMode(QWidget::PaletteBackground);
	Value->setText("0");
	#if QT_VERSION < 300
	Value->setFontPropagation(QWidget::SameFont);
	Value->setPalettePropagation(QWidget::SameFont);
	Value->setEnabled(true);
	#endif


	QLabel *qtarch_Label_21 = new QLabel(this, "Label_21");
	qtarch_Label_21->setGeometry(10, 80, 100, 30);
	qtarch_Label_21->setMinimumSize(0, 0);
	qtarch_Label_21->setMaximumSize(32767, 32767);
	qtarch_Label_21->setFocusPolicy(QWidget::NoFocus);
	qtarch_Label_21->setBackgroundMode(QWidget::PaletteBackground);
	#if QT_VERSION < 300
	qtarch_Label_21->setFontPropagation(QWidget::SameFont);
	qtarch_Label_21->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_Label_21->setFrameStyle( 0 );
	qtarch_Label_21->setLineWidth( 1 );
	qtarch_Label_21->setMidLineWidth( 0 );
	qtarch_Label_21->QFrame::setMargin( 0 );
	qtarch_Label_21->setText( tr( "Value" ) );
	qtarch_Label_21->setAlignment( AlignLeft|AlignVCenter|ExpandTabs );
	qtarch_Label_21->setMargin( 0 );
	/////////end 28-10-09///////////////////////////////////////////////

	resize(480,280);
	setMinimumSize(0, 0);
	setMaximumSize(32767, 32767);
}
MQTT_clientCommandData::~MQTT_clientCommandData()
{
}

