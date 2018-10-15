#include "BlinkingButton.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget window;

    QPushButton btnMo("Понедельник");
    BlinkingButton btnTu("Вторник");
    BlinkingButton btnWe("Среда");
    BlinkingButton btnTh("Четверг");
    BlinkingButton btnFr("Пятница");
    BlinkingButton btnSa("Субота");
    BlinkingButton btnSu("Воскресение");

    btnMo.setSizePolicy(QSizePolicy::Expanding ,QSizePolicy::Expanding );
    btnTu.setSizePolicy(QSizePolicy::Expanding ,QSizePolicy::Expanding );
    btnWe.setSizePolicy(QSizePolicy::Expanding ,QSizePolicy::Expanding );
    btnTh.setSizePolicy(QSizePolicy::Expanding ,QSizePolicy::Expanding );
    btnFr.setSizePolicy(QSizePolicy::Expanding ,QSizePolicy::Expanding );
    btnSa.setSizePolicy(QSizePolicy::Expanding ,QSizePolicy::Expanding );
    btnSu.setSizePolicy(QSizePolicy::Expanding ,QSizePolicy::Expanding );

<<<<<<< HEAD

=======
    //Меняец цвета кнопок:
>>>>>>> 2ce82d7249140437efea76630ccf653f03beecb1
    QPalette pal1;
    pal1.setColor(QPalette::Button, Qt::green);
    btnSa.setPalette(pal1);

    QPalette pal2;
    pal2.setColor(QPalette::Button, Qt::red);
    btnSu.setPalette(pal2);

    //Меняем шрифт кнопки:
    QFont boldFont;
    boldFont.setBold(true);
    btnSu.setFont(boldFont);

    QVBoxLayout layout;
    layout.addWidget(&btnMo);
    layout.addWidget(&btnTu);
    layout.addWidget(&btnWe);
    layout.addWidget(&btnTh);
    layout.addWidget(&btnFr);
    layout.addWidget(&btnSa);
    layout.addWidget(&btnSu);

    window.setLayout(&layout);
    window.show();

    return a.exec();
}
