#pragma once

#include <QtWidgets/QDialog>
#include "ui_studyOpencv3.h"

class studyOpencv3 : public QDialog
{
    Q_OBJECT

public:
    studyOpencv3(QWidget *parent = Q_NULLPTR);

private:
    Ui::studyOpencv3Class ui;
};
