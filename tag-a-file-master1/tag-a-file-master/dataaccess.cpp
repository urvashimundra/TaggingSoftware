#include "dataaccess.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQueryModel>


DataAccess::DataAccess(const QString dbname)
    : m_dbname(dbname)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
}

void DataAccess::OpenOrCreate()
{
    m_db.setDatabaseName(m_dbname);
    bool ok = m_db.open();

    if (!ok)
        QMessageBox::critical(nullptr, "Error opening database", m_db.lastError().text());

    CreateItemsTable();
    CreateTagsTable();
    CreateItemTagMapTable();
}

void DataAccess::InsertOrUpdate(const QString &item, const QStringList &tagList)
{
    if (tagList.isEmpty())
        return;

    ExecQuery("BEGIN TRANSACTION");

    InsertItem(item);
    int itemID = GetItemID(item);

    DeleteMappings(itemID);

    QList<int> tagIDs;
    for (QString tag : tagList)
    {
        InsertTag(tag);
        int tagID = GetTagID(tag);
        tagIDs.push_back(tagID);
    }

    InsertMappings(itemID, tagIDs);

    ExecQuery("COMMIT TRANSACTION");
}

QString toCsv(const QStringList &tagList)
{
    QString csv;
    for (QString tag : tagList)
        csv.append(QString("\'%1\',").arg(tag));
    if (csv.endsWith(','))
        csv.chop(1);

    return csv;
}


void DataAccess::RefreshSearchModel(QSqlQueryModel &model, const QStringList &tagList)
{


    QString csv = toCsv(tagList);



    QString sql_intersection = QString("SELECT items.content AS 'Filename' "
                                       "FROM item_tag_map mapping, items, tags "
                                       "WHERE mapping.tag_id = tags.id "
                                       "AND (tags.title IN (%1)) "
                                       "AND items.id = mapping.item_id "
                                       "GROUP BY items.id "
                                       "HAVING COUNT( items.id )=%2 ").arg(csv).arg(tagList.size());

    model.setQuery(sql_intersection);
}

QStringList DataAccess::GetTagsForItem(const QString &content)
{
    QString string = QString("SELECT `title` "
                             "FROM `tags` "
                             "INNER JOIN `item_tag_map` ON tags.id=item_tag_map.tag_id "
                             "INNER JOIN `items` ON items.id=item_tag_map.item_id "
                             "WHERE items.content='%1'").arg(content);

    return ExecReader(string);
}

void DataAccess::ExecQuery(const QString &string)
{
    if (m_db.isOpen())
    {
        QSqlQuery query;
        query.exec(string);
        if (query.lastError().isValid())
        {
            QMessageBox::critical(0, "Database error", query.lastError().text());
        }
    }
}

int DataAccess::ExecScalar(const QString &string)
{
    QSqlQuery query(string);
    if (query.next())
        return query.value(0).toInt();
    else
        return -1;
}

QString DataAccess::ExecScalarString(const QString &string)
{
    QSqlQuery query(string);
    if (query.next())
        return query.value(0).toString();
    else
        return "";
}

QStringList DataAccess::ExecReader(const QString &string)
{
    QStringList result;
    QSqlQuery query(string);
    while (query.next())
        result.push_back(query.value(0).toString());

    return result;
}

void DataAccess::CreateItemsTable()
{
    QString query = "CREATE TABLE IF NOT EXISTS `items` ( "
                    "`id` integer PRIMARY KEY, "
                    "`content` varchar(256) NOT NULL default '' );";
    ExecQuery(query);
}

void DataAccess::CreateTagsTable()
{
    QString query = "CREATE TABLE IF NOT EXISTS `tags` ( "
                    "`id` integer PRIMARY KEY, "
                    "`title` varchar(45) NOT NULL default '' );";
    ExecQuery(query);
}

void DataAccess::CreateItemTagMapTable()
{
    QString query = "CREATE TABLE IF NOT EXISTS `item_tag_map` ( "
                    "`item_id` integer NOT NULL default '0', "
                    "`tag_id` integer NOT NULL default '0', "
                    "PRIMARY KEY  (`item_id`,`tag_id`), "
                    "CONSTRAINT `item_fk` FOREIGN KEY (`item_id`) REFERENCES `items` (`item_id`), "
                    "CONSTRAINT `tag_fk` FOREIGN KEY (`tag_id`) REFERENCES `tags` (`tag_id`) );";
    ExecQuery(query);
}

void DataAccess::InsertItem(const QString &item)
{
    QString query = QString("INSERT INTO `items` (`content`) "
                            "SELECT '%1' "
                            "WHERE NOT EXISTS ("
                            "SELECT 1 FROM `items` "
                            "WHERE `content` = '%2');").arg(item).arg(item);
    ExecQuery(query);
}

void DataAccess::InsertTag(const QString &tag)
{
    QString query = QString("INSERT INTO `tags` (`title`) "
                            "SELECT '%1' "
                            "WHERE NOT EXISTS ("
                            "SELECT 1 FROM `tags` "
                            "WHERE `title` = '%2' );").arg(tag).arg(tag);
    ExecQuery(query);
}

void DataAccess::InsertMappings(int itemID, const QList<int> &tagIDs)
{
    QString query = QString("INSERT INTO `item_tag_map` VALUES ");

    for (int i = 0; i < tagIDs.size(); ++i)
    {
        int tagID = tagIDs[i];
        if (i == 0)
            query.append(QString("(%1, %2)").arg(itemID).arg(tagID));
        else
            query.append(QString(", (%1, %2)").arg(itemID).arg(tagID));
    }

    ExecQuery(query);
}

void DataAccess::DeleteMappings(int itemID)
{
    QString query = QString("DELETE FROM `item_tag_map` "
                            "WHERE `item_id`='%1'").arg(itemID);
    ExecQuery(query);
}

int DataAccess::GetItemID(const QString &item)
{
    QString string = QString("SELECT `id` FROM `items` "
                             "WHERE `content` = '%1'").arg(item);
    return ExecScalar(string);
}

int DataAccess::GetTagID(const QString &tag)
{
    QString string = QString("SELECT `id` FROM `tags` "
                             "WHERE `title` = '%1'").arg(tag);
    return ExecScalar(string);
}

QString DataAccess::GetItemContent(int id)
{
    if (id == 0)
        return "";
    QString query = QString("SELECT `content` FROM `items` "
                            "WHERE `id`=%1").arg(id);
    return ExecScalarString(query);
}

QString DataAccess::GetTagTitle(int id)
{
    if (id == 0)
        return "";
    QString query = QString("SELECT `title` FROM `tags` "
                            "WHERE `id`=%1").arg(id);
    return ExecScalarString(query);
}

void DataAccess::RefreshItemsModel(QSqlQueryModel &model)
{
    model.setQuery("SELECT `id`, `content` AS 'Filename' FROM `items` ORDER BY `content`");
}

void DataAccess::RefreshTagsModel(QSqlQueryModel &model)
{
    QString selectAll = "SELECT `id`, `title` AS 'Tag' FROM `tags` ORDER BY `title`";



    model.setQuery(selectAll);
}

void DataAccess::DeleteItem(int id)
{
    if (id > 0)
    {
        ExecQuery("BEGIN TRANSACTION");
        ExecQuery(QString("DELETE FROM `items` WHERE `id`=%1").arg(id));
        ExecQuery(QString("DELETE FROM `item_tag_map` WHERE `item_id`=%1").arg(id));
        ExecQuery("END TRANSACTION");
    }
}

void DataAccess::DeleteTag(int id)
{
    if (id > 0)
    {
        ExecQuery("BEGIN TRANSACTION");
        ExecQuery(QString("DELETE FROM `tags` WHERE `id`=%1").arg(id));
        ExecQuery(QString("DELETE FROM `item_tag_map` WHERE `tag_id`=%1").arg(id));
        ExecQuery("END TRANSACTION");
    }
}

void DataAccess::SetItemContent(int id, const QString &content)
{
    QString update = QString("UPDATE `items` SET `content`='%1' WHERE `id`=%2").arg(content).arg(id);
    ExecQuery(update);
}

void DataAccess::SetTagTitle(int id, const QString &title)
{
    QString update = QString("UPDATE `tags` SET `title`='%1' WHERE `id`=%2").arg(title).arg(id);
    ExecQuery(update);
}
