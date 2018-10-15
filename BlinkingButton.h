#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>

class BlinkingButton : public QPushButton
{
    Q_OBJECT
public:
    BlinkingButton(const QString &text = "Caption", QWidget *parent = 0);
    ~BlinkingButton();
    void setPalette(const QPalette &);
public slots:
    void changeColor();
    void changeState(bool);
protected:
    void paintEvent(QPaintEvent *event);
private:
    QTimer m_timer;
    QColor m_backgroundColor;
    const QColor &baseColor();
};

#endif // WIDGET_H
