#include "scribblearea.h"
#include <QDebug>

ScribbleArea::ScribbleArea() {}

void ScribbleArea::openImage(const QString &fileName) {
  QImage image(fileName);
}

void ScribbleArea::paintEvent(QPaintEvent *event) {
  QPainter painter(this);

  QBrush br(Qt::blue, Qt::SolidPattern);

  painter.setBrush(br);
  painter.drawRect(20, endPos.y(), 100, 100);

  painter.setPen(Qt::red);
  // painter.drawLine(startPos, endPos);
}

void ScribbleArea::mousePressEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    startPos = event->pos();
    qDebug() << "Left Mouse pressed";
  } else {
    qDebug() << "Some mouse pressed";
  }
}

void ScribbleArea::mouseMoveEvent(QMouseEvent *event) {
  if (event->button() == Qt::LeftButton) {
    qDebug() << "Left button clicked";
  } else {
    qDebug() << "Not Left Button";
  }
  endPos = event->pos();
  repaint();
}
