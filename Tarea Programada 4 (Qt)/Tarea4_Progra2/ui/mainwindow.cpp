#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "./../calculadora_local/calculadora_local.h"
#include <QMessageBox>
#include <QFileDialog>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete tienda;
}



void MainWindow::on_botonLimpiar_clicked()
{
    this->ui->lineEditNombreTienda->setText("");
    this->ui->lineEditDireccionInternet->setText("");
    this->ui->lineEditDireccionFisica->setText("");
    this->ui->lineEditTelefono->setText("");

    this->ui->lineEditNombreTienda->setFocus();
}

void MainWindow::on_pushButtonAceptarTienda_clicked()
{

    try
    {
        QString stringNombreTienda = this->ui->lineEditNombreTienda->text();

        if (stringNombreTienda != "")
        {
            throw ExcepcionDatoEnBlanco;
        }

        QString stringDireccionInternet = this->ui->lineEditDireccionInternet->text();

        if (stringDireccionInternet != "")
        {
            throw ExcepcionDatoEnBlanco;
        }

        QString stringDireccionFisica = this->ui->lineEditDireccionFisica->text();

        if (stringDireccionFisica != "")
        {
            throw ExcepcionDatoEnBlanco;
        }

        QString stringTelefono = this->ui->lineEditTelefono->text();

        if (stringDireccionFisica != "")
        {
            throw ExcepcionDatoEnBlanco;
        }

        this->tienda = new Tienda(stringNombreTienda, stringDireccionInternet, stringDireccionFisica, stringTelefono);

    }
    catch (char const*message)
    {
        QMessageBox* msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Título del diálogo");
        msgbox->setText("No se puede dejar espacios en blanco.");
        msgbox->open();

        //this->ui->editResultado->setText("Error!");
    }

}


void MainWindow::on_pushButtonProductos_clicked()
{

    formProducto formProducto {this};
    int result = formProducto.exec();

    if (result == QDialog::Accepted) {

        int id = formProducto.ObtenerID();
        std::string nombre = formProducto.ObtenerNombre();
        int existencias = formProducto.ObtenerExistencias();

        try {
            this->tienda->AgregarProducto(id, nombre, existencias);

            if (id != "")
            {
                throw ExcepcionDatoEnBlanco;
            }

            if (nombre != "")
            {
                throw ExcepcionDatoEnBlanco;
            }

            if (existencias != "")
            {
                throw ExcepcionDatoEnBlanco;
            }

            if (id < 0)
            {
                throw ExcepcionNumeroNegativo;
            }

            if (existencias < 0)
            {
                throw ExcepcionNumeroNegativo;
            }



        }
        catch (ExcepcionDatoEnBlanco &e) {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Título del diálogo");
            msgbox->setText("No se puede dejar datos en blanco.");
            msgbox->open();
        }
        catch (ExcepcionNumeroNegativo &e) {
            QMessageBox *msgbox = new QMessageBox(this);
            msgbox->setWindowTitle("Título del diálogo");
            msgbox->setText("No se puede usar números negativos.");
            msgbox->open();
        }

        QMessageBox *msgbox = new QMessageBox(this);
        msgbox->setWindowTitle("Título del diálogo");
        msgbox->setText(QString::fromStdString(nombre));
        msgbox->open();
    }


}


void MainWindow::on_pushButtonGuardar_clicked()
{
    this->tienda->GuardarEnStreamBinario(ostream *streamSalida);
    this->tienda->GenerarArchivoBinario(tienda);
}

