#ifndef SCRIBBLE_H
#define SCRIBBLE_H
#include <QPoint>
#include <QtWidgets>

class ScribbleArea : public QWidget {
  Q_OBJECT
public:
  ScribbleArea();
  void openImage(const QString &filName);
  void saveImage(const QString &path, const QByteArray format);
  void setPenColor(QColor newColor);
  void setPenWidth(const int newWidth);
  void drawLineTo(QPoint point);

  // QWidget interface
protected:
  void mousePressEvent(QMouseEvent *event);
  void mouseMoveEvent(QMouseEvent *event);
  void paintEvent(QPaintEvent *event);

private:
  QImage image;
  int penWidth;
  QColor penColor;
  QPoint startPos;
  QPoint endPos;
};

#endif // SCRIBBLE_H
