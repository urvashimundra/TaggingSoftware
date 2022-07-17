#ifndef EDITPAGE_H
#define EDITPAGE_H

#include <QWidget>

class DataAccess;
class QSqlQueryModel;
class QCompleter;


namespace Ui {
class EditPage;
}

class EditPage : public QWidget
{
    Q_OBJECT

public:
    explicit EditPage(DataAccess &dal, QWidget *parent = 0);
    ~EditPage();

    void setActive();
    void editContent(const QString &content);

private slots:
    void onFileBrowse();
    void resetTagList();
    void on_pushButton_clicked();

private:
    Ui::EditPage *ui;
    DataAccess &database_name;
    QSqlQueryModel *m_tagModel = nullptr;
};

#endif // EDITPAGE_H
