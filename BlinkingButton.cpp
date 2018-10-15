#include "BlinkingButton.h"

//BlinkingButton::BlinkingButton(QWidget *parent)
//{
//    BlinkingButton("Caption",parent);
//}

BlinkingButton::BlinkingButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent), m_backgroundColor(baseColor())
{
    setCheckable(true);
    m_timer.setInterval(200);
    connect(&m_timer, SIGNAL(timeout()), SLOT(changeColor()));
    connect(this, SIGNAL(toggled(bool)),SLOT(changeState(bool)));
}

BlinkingButton::~BlinkingButton()
{

}

void BlinkingButton::changeColor()
{
    m_backgroundColor = (m_backgroundColor == baseColor()) ? baseColor().lighter(170) : baseColor();
    update();
}

void BlinkingButton::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    painter.setBrush(QBrush(m_backgroundColor));

    int borderWidth = 2;
    QPen pen(baseColor().darker(), borderWidth);
    pen.setJoinStyle(Qt::MiterJoin);
    painter.setPen(pen);

    painter.setFont(font());

    painter.drawRect(rect() - QMargins(borderWidth, borderWidth, borderWidth, borderWidth));
    painter.drawText(rect(), Qt::AlignCenter, this->text());
}

void BlinkingButton::setPalette(const QPalette &palette)
{
    QWidget::setPalette(palette);
    m_backgroundColor = baseColor();
}

const QColor &BlinkingButton::baseColor()
{
    return palette().button().color();
}

void BlinkingButton::changeState(bool checked)
{
    if (checked){
        m_timer.start();
        changeColor();
    }
    else{
        m_timer.stop();
        m_backgroundColor = baseColor();
    }

}
