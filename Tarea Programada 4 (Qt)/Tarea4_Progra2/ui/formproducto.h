#ifndef FORMPRODUCTO_H
#define FORMPRODUCTO_H

#include <QDialog>
#include <string>

namespace Ui {
class formProducto;
}

class formProducto : public QDialog
{
    Q_OBJECT

public:
    explicit formProducto(QWidget *parent = nullptr);
    ~formProducto();

    void CargarInformacion(int id, std::string nombre, int existencias);
    int ObtenerID();
    std::string ObtenerNombre();
    int ObtenerExistencias();

private:
    Ui::formProducto *ui;
};

#endif // FORMPRODUCTO_H
