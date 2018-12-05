#include "mouseaction.h"
#include <qvariant.h>
#include <qlabel.h>
#include <qlayout.h>
#include <qtooltip.h>
#include <qwhatsthis.h>
#include <qimage.h>
#include <qpixmap.h>

/*
 *  Constructs a mainForm as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 */
mainForm::mainForm( QWidget* parent, const char* name, Qt::WindowFlags fl )
    : QWidget( parent, name, fl )
{
    if ( !name )
    setName( "mainForm" );

    //setCaption("Qt Mouse Click Event Example");

    myPixmapLabel = new QLabel( this, "myPixmapLabel" );
    myPixmapLabel->setGeometry( QRect( 120, 60, 300, 270 ) );
    //放置一个图片，该图片应该在同一文件夹里，否则要指定路径
    myPixmapLabel->setPixmap( QPixmap::fromMimeSource( "about-to-install.png" ) );
    myPixmapLabel->setScaledContents( TRUE );
    languageChange();
    resize( QSize(600, 480).expandedTo(minimumSizeHint()) );
    connect( this, SIGNAL( clicked() ), this, SLOT( mousePressEventSlot() ) );   //信号连接
}

/*
 *  Destroys the object and frees any allocated resources
 */
mainForm::~mainForm()
{
    // no need to delete child widgets, Qt does it all for us
}
void mainForm::mousePressEvent(QMouseEvent *e)
{
    int x = e->x();
    int y = e->y();
    //假如在QRect( 120, 60, 200, 200 ) );这个区域里，就发出信号
    if (x>120 && x<200 && y>60 && y<200)
        emit clicked();
}
void mainForm::mousePressEventSlot()
{
    //该信号响应的曹
    //给出一个提示信息
    QMessageBox::about( this, "Qt Mouse Click Event Example",
                        "You haved clicked the prearranged position /nand the widget will be closed."
                        );
    close();  //关闭程序
}
/*
 *  Sets the strings of the subwidgets using the current
 *  language.
 */
void mainForm::languageChange()
{
    setCaption( tr( "Qt Mouse Click Event Example" ) );
}

