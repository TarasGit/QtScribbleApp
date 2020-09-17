#include "scribblearea.h"
#include <QDebug>
#include <QFileDialog>

ScribbleArea::ScribbleArea() {}

void ScribbleArea::openImage(const QString &fileName) { image.load(fileName); }

void ScribbleArea::saveImage(const QString &path, const QByteArray array) {
  QString mypath(path);
  if (image.save(mypath.append(".").append(QString(array)),
                 QString(array).toUpper().toStdString().c_str())) {
    qDebug() << "Image saved: " << path << "." << QString(array);
    QMessageBox::information(this, tr("Save image"),
                             tr("Image successfully saved"));
  } else {
    qDebug() << "Could not save the image";
    QMessageBox::critical(this, tr("Save Image"), tr("Failed"));
  }
}

void ScribbleArea::setPenColor(QColor newColor) {
  this->penColor = newColor;
  qDebug() << "Scribble pen Color:" << newColor.name();
}

void ScribbleArea::setPenWidth(const int newWidth) {
  this->penWidth = newWidth;
}

void ScribbleArea::drawLineTo(QPoint point) {
  QPainter painter(&image);
  painter.setPen(
      QPen(penColor, penWidth, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
  painter.drawLine(startPos, point);
  startPos = point;
  update();
}

void ScribbleArea::paintEvent(QPaintEvent *event) {
  QPainter painter(this);
  painter.drawImage(event->rect(), image, event->rect());
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
  if (event->buttons() & Qt::LeftButton) {
    qDebug() << "Left button clicked";
    drawLineTo(event->pos());
  } else {
    qDebug() << "Not Left Button";
  }
  endPos = event->pos();
  repaint();
}
