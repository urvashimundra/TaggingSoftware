#include "editpage.h"
#include "dataaccess.h"
#include "ui_editpage.h"
#include <QFileDialog>
#include <QCompleter>
#include <QFileSystemModel>
#include <QSqlQueryModel>
#include <QAction>

EditPage::EditPage(DataAccess &database_value, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditPage),
    database_name(database_value)
{
    ui->setupUi(this);

    ui->tagEdit->setBuddyList(ui->tagList);
    ui->tagEdit->setPlaceholderText("Enter to accept");

    m_tagModel = new QSqlQueryModel(this);
    database_name.RefreshTagsModel(*m_tagModel);
    ui->tagEdit->setTagCompleter(*m_tagModel);

    QFileSystemModel *model = new QFileSystemModel(this);
    QCompleter *completer = new QCompleter(model, this);
    model->setRootPath("C:\\");
    completer->setModelSorting(QCompleter::CaseSensitivelySortedModel);
    ui->lineEdit->setCompleter(completer);

    QAction *browseAction = ui->lineEdit->addAction(QIcon(":/file-browse.png"), QLineEdit::TrailingPosition);

    QObject::connect(browseAction, SIGNAL(triggered()), this, SLOT(onFileBrowse()));
    QObject::connect(ui->lineEdit, SIGNAL(returnPressed()), this, SLOT(resetTagList()));
}

EditPage::~EditPage()
{
    delete ui;
}

void EditPage::setActive()
{
    ui->lineEdit->clear();
    ui->tagList->clear();
}

void EditPage::onFileBrowse()
{
    QString filename = QFileDialog::getOpenFileName(this, "Select File", "", "");

    if (!filename.isEmpty())
    {
        ui->lineEdit->setText(QDir::toNativeSeparators(filename));
        resetTagList();
    }
}

void EditPage::resetTagList()
{
    ui->tagList->clear();

    QString filename = ui->lineEdit->text();

    if (!filename.isEmpty())
    {
        QStringList tags = database_name.GetTagsForItem(filename);
        ui->tagList->addTagItems(tags);

        if (!tags.isEmpty())
            ui->pushButton->setText("Update");
    }
}

void EditPage::on_pushButton_clicked()
{
    QString item = ui->lineEdit->text();
    QStringList tags = ui->tagList->toStringList();

    database_name.InsertOrUpdate(item, tags);
    database_name.RefreshTagsModel(*m_tagModel);

    ui->lineEdit->clear();
    ui->tagEdit->clear();
    ui->tagList->clear();
    ui->lineEdit->setFocus();
    ui->tagEdit->setTagCompleter(*m_tagModel);
    ui->pushButton->setText("Add");
}

void EditPage::editContent(const QString &content)
{
    ui->lineEdit->setText(content);

    resetTagList();
}
