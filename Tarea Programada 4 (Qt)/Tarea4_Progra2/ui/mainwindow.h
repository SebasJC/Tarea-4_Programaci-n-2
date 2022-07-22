#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <string>
#include "./../tienda/tienda.h"
#include "./../tienda/excepcionDatoEnBlanco.h"
#include "./../tienda/excepcionNumeroNegativo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void CargarInformacion(std::string nombre, std::string direccionInternet, std::string direccionFisica, std::string telefono);
    std::string ObtenerNombre();
    std::string ObtenerDireccionInternet();
    std::string ObtenerDireccionFisica();
    std::string ObtenerTelefono();


private slots:
    void on_pushButtonAceptarTienda_clicked();

    void on_pushButtonProductos_clicked();

    void on_pushButtonGuardar_clicked();

private:
    Ui::MainWindow *ui;
    Tienda *tienda;
};
#endif // MAINWINDOW_H
