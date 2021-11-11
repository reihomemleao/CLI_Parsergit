#include "CLI_Parser.h"
#include "stdafx.h"
#include<QDialog>
#include<QtGui>
#include<QtCore>
#include <QMessageBox>

QString CLI_Parser::CLI_qtParser(QString datei) {

    QByteArray contenido;
    QFile b;

    int gef = 0;
    QString dim = "", test, coord = "";
    bool num = true;
    int count = 0;
    b.setFileName(datei);
    if (!b.exists()) {
        qDebug() << ("The file doesnt exist");
        return "Error";
    }
    else {
        b.open(QIODevice::ReadOnly | QIODevice::Text);
        if (!b.isOpen()) {
            qDebug() << ("the file could not be openned");
            return "Error";
        }
        else {
            contenido = b.readAll();
            qDebug() << contenido;
            QString all = contenido;
            for (int i = 0; i < all.size(); i++) {
                if (all.at(i) == 'D' && all.at(i + 1) == 'I' && all.at(i + 2) == 'M' && all.at(i + 3) == 'E' &&
                    all.at(i + 4) == 'N' && all.at(i + 5) == 'S' && all.at(i + 6) == 'I' && all.at(i + 7) == 'O' &&
                    all.at(i + 8) == 'N') {
                    gef = i;
                    for (int j = i; j <= (i + 9); j++) {
                        dim = dim + all.at(j);
                    }
                }
                if (i >= (gef + 10)) {
                    if (dim == "DIMENSION/") {
                        test = all.at(i);
                        if (num == true) {
                            if (all.at(i) == ',' || (all.at(i)).isDigit() || all.at(i) == '-' || all.at(i) == '.') {
                                coord = coord + all.at(i);
                            }
                            else
                                num = false;
                        }
                    }
                }
            }
            QList<QString> last = coord.split(",");
            vector<double> pointx, pointy, pointz;
            My3DPoint p;
            for (int i = 0; i < last.size(); i++) {
                qDebug() << last.at(i);
                
                
                if (i % 3 == 0) {
                    p.setX(last.at(i).toDouble());
                    //ponto.push_back(last.at(i).toDouble());
                    //ponto.at(i).setX(last.at(i).toDouble());                   
                }
                if (i % 3 == 1) {
                    p.setY(last.at(i).toDouble());
                    //ponto.at(i).setY(last.at(i).toDouble());                   
                }
                if (i % 3 == 2) {
                    p.setZ(last.at(i).toDouble());
                     ponto.push_back(p);
                         
                }
            }
            for (int i = 0; i < ponto.size(); i++) {
                ui.listWidget->addItem("Punkt Nummer :" + QString::number(i) + " X Koordinaten: " + QString::number(ponto.at(i).getX()) + " Y Koordinaten: " + QString::number(ponto.at(i).getY()) + " Z Koordinaten: " + QString::number(ponto.at(i).getZ()));
            }
            return dim;
        }
    }
}

CLI_Parser::CLI_Parser(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
    connect(ui.pbdat_w, &QPushButton::clicked, this, &CLI_Parser::Datei_waehlen);
   

}

void CLI_Parser::Datei_waehlen() {
    bool richtig = false;
    //temporary variables pyth and sk
    QString pyth, sk, path;
    QMessageBox msgBox;
    //msgBox.setText("Symcondrill ");
    std::string tst = "Bitte wählen Sie ein cli Datei";

    QString clidat;
    //std::string tst = "Please choose a Skript";
    //msgBox.setInformativeText(QString::fromLocal8Bit(tst.c_str()));
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret; //= msgBox.exec();

    bool cancel = false, cnl = false;
    //if (ret == QMessageBox::Ok) {

    do {
        tst = "Datei öffnen";
        clidat= QFileDialog::getOpenFileName(this, QString::fromLocal8Bit(tst.c_str()), QDir::homePath());
        if (clidat.size() == 0)
            cancel = true;
        else {
            //Hier wird gefragt ob die 3 lätzte buchstaben .py sind, wenn ja gehts weiter und wird was anders gewählt sonst muss man nochmal wählen 
            if (clidat.at(clidat.length() - 1) == 'i' && clidat.at(clidat.length() - 2) == 'l' && clidat.at(clidat.length() - 3) == 'c' && clidat.at(clidat.length() - 4) == '.') {
                richtig = true;
            }
            else {
                msgBox.setText("CLI Parser ");
                tst = "Die Datei muss .cli sein, bitte wählen sie nochmal ihre Datei:";
                tst = "The file should be a .cli file, please choose again";
                msgBox.setInformativeText(QString::fromLocal8Bit(tst.c_str()));

                ret = msgBox.exec();
                //We wont to know if the user pressed ok or cancel
                if (ret != QMessageBox::Ok) {
                    cancel = true;
                }

            }
        }
    } while (richtig == false && cancel == false);

    datei = clidat;
    CLI_qtParser(datei);
}

