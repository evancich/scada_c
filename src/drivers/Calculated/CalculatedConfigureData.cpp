/**********************************************************************
--- Qt Architect generated file ---
File: CalculatedConfigureData.cpp
Last generated: Thu Jan 4 16:11:31 2001
DO NOT EDIT!!!  This file will be automatically
regenerated by qtarch.  All changes will be lost.
*********************************************************************/
#include <qpixmap.h>
#include <qlayout.h>
#include "CalculatedConfigureData.h"
#include <qlabel.h>
#include <qpushbutton.h>
CalculatedConfigureData::CalculatedConfigureData(QWidget *parent, const char *name)
: QDialog(parent, name, TRUE, 208)
{
	QPushButton *qtarch_PushButton_2 = new QPushButton(this, "PushButton_2");
	qtarch_PushButton_2->setGeometry(370, 120, 100, 30);
	qtarch_PushButton_2->setMinimumSize(0, 0);
	qtarch_PushButton_2->setMaximumSize(32767, 32767);
	qtarch_PushButton_2->setFocusPolicy(QWidget::TabFocus);
	qtarch_PushButton_2->setBackgroundMode(QWidget::PaletteButton);
	#if QT_VERSION < 300
	qtarch_PushButton_2->setFontPropagation(QWidget::SameFont);
	qtarch_PushButton_2->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_PushButton_2->setText( tr( "Cancel" ) );
	qtarch_PushButton_2->setAutoRepeat( FALSE );
	qtarch_PushButton_2->setAutoResize( FALSE );
	qtarch_PushButton_2->setToggleButton( FALSE );
	qtarch_PushButton_2->setDefault( FALSE );
	qtarch_PushButton_2->setAutoDefault( FALSE );
	qtarch_PushButton_2->setIsMenuButton( FALSE );
	connect(qtarch_PushButton_2, SIGNAL(clicked()), SLOT(reject()));
	QLabel *qtarch_Label_8 = new QLabel(this, "Label_8");
	qtarch_Label_8->setGeometry(20, 20, 90, 30);
	qtarch_Label_8->setMinimumSize(0, 0);
	qtarch_Label_8->setMaximumSize(32767, 32767);
	qtarch_Label_8->setFocusPolicy(QWidget::NoFocus);
	qtarch_Label_8->setBackgroundMode(QWidget::PaletteBackground);
	#if QT_VERSION < 300
	qtarch_Label_8->setFontPropagation(QWidget::SameFont);
	qtarch_Label_8->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_Label_8->setFrameStyle( 0 );
	qtarch_Label_8->setLineWidth( 1 );
	qtarch_Label_8->setMidLineWidth( 0 );
	qtarch_Label_8->QFrame::setMargin( 0 );
	qtarch_Label_8->setText( tr( "Name" ) );
	qtarch_Label_8->setAlignment( AlignLeft|AlignVCenter|ExpandTabs );
	qtarch_Label_8->setMargin( 0 );
	Name = new QLabel(this, "Label_9");
	Name->setGeometry(120, 20, 340, 30);
	Name->setMinimumSize(0, 0);
	Name->setMaximumSize(32767, 32767);
	Name->setFocusPolicy(QWidget::NoFocus);
	Name->setBackgroundMode(QWidget::PaletteBackground);
	#if QT_VERSION < 300
	Name->setFontPropagation(QWidget::SameFont);
	Name->setPalettePropagation(QWidget::SameFont);
	#endif
	Name->setFrameStyle( 51 );
	Name->setLineWidth( 1 );
	Name->setMidLineWidth( 0 );
	Name->QFrame::setMargin( 0 );
	Name->setText( "" );
	Name->setAlignment( AlignLeft|AlignVCenter|ExpandTabs );
	Name->setMargin( 0 );
	QLabel *qtarch_Label_10 = new QLabel(this, "Label_10");
	qtarch_Label_10->setGeometry(20, 60, 90, 50);
	qtarch_Label_10->setMinimumSize(0, 0);
	qtarch_Label_10->setMaximumSize(32767, 32767);
	qtarch_Label_10->setFocusPolicy(QWidget::NoFocus);
	qtarch_Label_10->setBackgroundMode(QWidget::PaletteBackground);
	#if QT_VERSION < 300
	qtarch_Label_10->setFontPropagation(QWidget::SameFont);
	qtarch_Label_10->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_Label_10->setFrameStyle( 0 );
	qtarch_Label_10->setLineWidth( 1 );
	qtarch_Label_10->setMidLineWidth( 0 );
	qtarch_Label_10->QFrame::setMargin( 0 );
	qtarch_Label_10->setText( tr( "Re-Calculate Interval" ) );
	qtarch_Label_10->setAlignment( AlignLeft|AlignVCenter|ExpandTabs|WordBreak );
	qtarch_Label_10->setMargin( 0 );
	ReCalculateInterval = new QSpinBox(this, "SpinBox_1");
	ReCalculateInterval->setGeometry(120, 70, 80, 30);
	ReCalculateInterval->setMinimumSize(0, 0);
	ReCalculateInterval->setMaximumSize(32767, 32767);
	ReCalculateInterval->setFocusPolicy(QWidget::StrongFocus);
	ReCalculateInterval->setBackgroundMode(QWidget::PaletteBackground);
	#if QT_VERSION < 300
	ReCalculateInterval->setFontPropagation(QWidget::SameFont);
	ReCalculateInterval->setPalettePropagation(QWidget::SameFont);
	ReCalculateInterval->setFrameStyle( 50 );
	ReCalculateInterval->setLineWidth( 2 );
	ReCalculateInterval->setMidLineWidth( 0 );
	ReCalculateInterval->QFrame::setMargin( 0 );
	#endif
	ReCalculateInterval->setRange( 1, 300 );
	ReCalculateInterval->setSteps( 1, 0 );
	ReCalculateInterval->setPrefix( "" );
	ReCalculateInterval->setSuffix( "" );
	ReCalculateInterval->setSpecialValueText( "" );
	ReCalculateInterval->setWrapping( TRUE );
	QPushButton *qtarch_PushButton_8 = new QPushButton(this, "PushButton_8");
	qtarch_PushButton_8->setGeometry(20, 120, 100, 30);
	qtarch_PushButton_8->setMinimumSize(0, 0);
	qtarch_PushButton_8->setMaximumSize(32767, 32767);
	qtarch_PushButton_8->setFocusPolicy(QWidget::TabFocus);
	qtarch_PushButton_8->setBackgroundMode(QWidget::PaletteButton);
	#if QT_VERSION < 300
	qtarch_PushButton_8->setFontPropagation(QWidget::SameFont);
	qtarch_PushButton_8->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_PushButton_8->setText( tr( "Ok" ) );
	qtarch_PushButton_8->setAutoRepeat( FALSE );
	qtarch_PushButton_8->setAutoResize( FALSE );
	qtarch_PushButton_8->setToggleButton( FALSE );
	qtarch_PushButton_8->setDefault( FALSE );
	qtarch_PushButton_8->setAutoDefault( FALSE );
	qtarch_PushButton_8->setIsMenuButton( FALSE );
	connect(qtarch_PushButton_8, SIGNAL(clicked()), SLOT(OkClicked()));
	QLabel *qtarch_Label_11 = new QLabel(this, "Label_11");
	qtarch_Label_11->setGeometry(210, 70, 80, 30);
	qtarch_Label_11->setMinimumSize(0, 0);
	qtarch_Label_11->setMaximumSize(32767, 32767);
	qtarch_Label_11->setFocusPolicy(QWidget::NoFocus);
	qtarch_Label_11->setBackgroundMode(QWidget::PaletteBackground);
	#if QT_VERSION < 300
	qtarch_Label_11->setFontPropagation(QWidget::SameFont);
	qtarch_Label_11->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_Label_11->setFrameStyle( 0 );
	qtarch_Label_11->setLineWidth( 1 );
	qtarch_Label_11->setMidLineWidth( 0 );
	qtarch_Label_11->QFrame::setMargin( 0 );
	qtarch_Label_11->setText( tr( "seconds" ) );
	qtarch_Label_11->setAlignment( AlignLeft|AlignVCenter|ExpandTabs );
	qtarch_Label_11->setMargin( 0 );
	QPushButton *qtarch_PushButton_9 = new QPushButton(this, "PushButton_9");
	qtarch_PushButton_9->setGeometry(200, 120, 100, 30);
	qtarch_PushButton_9->setMinimumSize(0, 0);
	qtarch_PushButton_9->setMaximumSize(32767, 32767);
	qtarch_PushButton_9->setFocusPolicy(QWidget::TabFocus);
	qtarch_PushButton_9->setBackgroundMode(QWidget::PaletteButton);
	#if QT_VERSION < 300
	qtarch_PushButton_9->setFontPropagation(QWidget::SameFont);
	qtarch_PushButton_9->setPalettePropagation(QWidget::SameFont);
	#endif
	qtarch_PushButton_9->setText( tr( "Help..." ) );
	qtarch_PushButton_9->setAutoRepeat( FALSE );
	qtarch_PushButton_9->setAutoResize( FALSE );
	qtarch_PushButton_9->setToggleButton( FALSE );
	qtarch_PushButton_9->setDefault( FALSE );
	qtarch_PushButton_9->setAutoDefault( FALSE );
	qtarch_PushButton_9->setIsMenuButton( FALSE );
	connect(qtarch_PushButton_9, SIGNAL(clicked()), SLOT(Help()));
	resize(480,160);
	setMinimumSize(0, 0);
	setMaximumSize(32767, 32767);
}
CalculatedConfigureData::~CalculatedConfigureData()
{
}

