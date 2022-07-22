#include "formproducto.h"
#include "ui_formproducto.h"
#include <iostream>
#include <cstring>
#include <fstream>

FormProducto::FormProducto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormProducto)
{
    ui->setupUi(this);
}

FormProducto::~FormProducto()
{
    delete ui;
}

void formProducto::CargarInformacion(int id, std::string nombre, int existencias)
{
    QString stringID = QString::number(id);
    this->ui->lineEditId->setText(stringID);
    this->ui->lineEditId->setReadOnly(true);

    QString stringNombre = QString::fromStdString(nombre);
    this->ui->lineEditNombreProducto->setText(stringNombre);

    QString stringExistencias = QString::number(existencias);
    this->ui->lineEditExistencias->setText(stringExistencias);
}

int formProducto::ObtenerID()
{
    QString stringID = this->ui->lineEditId->text();
    int id = stringID.toInt();
    return id;
}

std::string formProducto::ObtenerNombre()
{
    QString stringNombre = this->ui->lineEditNombreProducto->text();
    std::string nombre = stringNombre.toStdString();
    return nombre;
}

int formProducto::ObtenerExistencias()
{
    QString stringExistencias = this->ui->lineEditExistencias->text();
    int existencias = stringExistencias.toInt();
    return existencias;
}
