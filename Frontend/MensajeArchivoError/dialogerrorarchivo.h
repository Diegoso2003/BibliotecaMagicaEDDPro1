#ifndef DIALOGERRORARCHIVO_H
#define DIALOGERRORARCHIVO_H

#include <QDialog>
#include <string>

namespace Ui {
class DialogErrorArchivo;
}

class DialogErrorArchivo : public QDialog
{
    Q_OBJECT

public:
    DialogErrorArchivo(QWidget *parent = nullptr, std::string mensaje = "");
    ~DialogErrorArchivo();

private:
    Ui::DialogErrorArchivo *ui;
};

#endif // DIALOGERRORARCHIVO_H
