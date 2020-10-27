#include "date.h"
#include <QDate>


Date::Date(QObject *parent)
    : QObject(parent)
{
}

QString& Date::GetCurrentDate()
{
    auto date = QDate::currentDate();
    dateText = date.toString("yyyy년MM월dd일");

    return dateText;
}
