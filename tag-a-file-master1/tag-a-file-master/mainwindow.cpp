#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "editpage.h"
#include "searchpage.h"
#include "browsepage.h"
#include "dataaccess.h"
#include <QSettings>

#define VERSION "1.2"

MainWindow::MainWindow(DataAccess &database_value, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    database_name(database_value)
{
    ui->setupUi(this);

    setWindowTitle(QString("Tag a File %1").arg(VERSION));

    m_editPage = new EditPage(database_name, this);
    m_searchPage = new SearchPage(database_name, this);
    m_browsePage = new BrowsePage(database_name, this);

    ui->page1Layout->addWidget(m_editPage);
    ui->page2Layout->addWidget(m_searchPage);
    ui->page3Layout->addWidget(m_browsePage);

    ui->tabWidget->setCurrentIndex(0);

    QObject::connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabChanged(int)));
    QObject::connect(m_searchPage, SIGNAL(searchFile(int)), this, SLOT(onSearchFile(int)));
    QObject::connect(m_browsePage, SIGNAL(searchFile(int)), this, SLOT(onSearchFile(int)));
    QObject::connect(m_browsePage, SIGNAL(searchTag(int)), this, SLOT(onSearchTag(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::tabChanged(int index)
{
    switch (index)
    {
    case 0:
        m_editPage->setActive();
        break;
    case 1:
        m_searchPage->setActive();
        break;
    case 2:
        m_browsePage->setActive();
        break;
    }
}

void MainWindow::onSearchFile(int id)
{
    QString filename = database_name.GetItemContent(id);

    ui->tabWidget->setCurrentIndex(0);

    m_editPage->editContent(filename);
}

void MainWindow::onSearchTag(int id)
{
    QString tag = database_name.GetTagTitle(id);

    ui->tabWidget->setCurrentIndex(1);

    m_searchPage->searchTag(tag);
}


void MainWindow::writePositionSettings()
{
    QSettings settings( "Error101", "Tag a File" );

    settings.beginGroup( "MainWindow" );
    settings.setValue( "Geometry", saveGeometry() );
    settings.setValue( "Maximised", isMaximized() );

    if ( !isMaximized() )
    {
        settings.setValue( "Pos", pos() );
        settings.setValue( "Size", size() );
    }

    settings.endGroup();
}

void MainWindow::readPositionSettings()
{
    QSettings settings( "Error101", "Tag a File" );

    settings.beginGroup( "MainWindow" );
    restoreGeometry(settings.value( "Geometry", saveGeometry() ).toByteArray());
    move(settings.value( "Pos", pos() ).toPoint());
    resize(settings.value( "Size", size() ).toSize());

    if ( settings.value( "Maximised", isMaximized() ).toBool() )
        showMaximized();

    settings.endGroup();
}

void MainWindow::closeEvent( QCloseEvent* )
{
    writePositionSettings();
}
