/**********************************************************************
--- Qt Architect generated file ---
File: CheckTagEntriesData.cpp
Last generated: Thu Nov 30 08:47:27 2000
DO NOT EDIT!!!  This file will be automatically
regenerated by qtarch.  All changes will be lost.
*********************************************************************/
#include <qt.h>
#include "CheckTagEntriesData.h"
CheckTagEntriesData::CheckTagEntriesData(QWidget *parent, const char *name)
: QDialog(parent, name, TRUE, 208)
{
	Messages = new QListBox(this, "ListBox_1");
	Messages->setGeometry(20, 20, 440, 400);
	Messages->setMinimumSize(0, 0);
	Messages->setMaximumSize(32767, 32767);
	Messages->setFocusPolicy(QWidget::TabFocus);
	Messages->setBackgroundMode(QWidget::PaletteBackground);
#if QT_VERSION < 300
	Messages->setFontPropagation(QWidget::SameFont);
	Messages->setPalettePropagation(QWidget::SameFont);
		#endif
	Messages->setFrameStyle( 51 );
	Messages->setLineWidth( 2 );
	Messages->setMidLineWidth( 0 );
	Messages->QFrame::setMargin( 0 );
	Messages->setDragSelect( TRUE );
	Messages->setAutoScroll( TRUE );
	Messages->setScrollBar( TRUE );
	Messages->setAutoScrollBar( TRUE );
	Messages->setBottomScrollBar( TRUE );
	Messages->setAutoBottomScrollBar( TRUE );
	Messages->setSmoothScrolling( FALSE );
	Messages->setMultiSelection( FALSE );
	Messages->setAutoUpdate( TRUE );
	resize(480,440);
	setMinimumSize(0, 0);
	setMaximumSize(32767, 32767);
}
CheckTagEntriesData::~CheckTagEntriesData()
{
}
