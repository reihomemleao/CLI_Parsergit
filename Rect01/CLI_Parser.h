#pragma once

#include <QtWidgets/QDialog>
#include "ui_rect01.h"
#include "My3DPoint.h"
#include<vector>

using namespace std;


class CLI_Parser : public QDialog
{
    Q_OBJECT

public:
    CLI_Parser(QWidget *parent = Q_NULLPTR);
    vector<My3DPoint> ponto;

    
    QString datei = "";

    QString CLI_qtParser(QString datei = "modelsection_001_s1_vk.cli");
    
private:
    Ui::Rect01Class ui;
protected:
    
public slots:
    void Datei_waehlen();
};
