#ifndef SCRIBBLE_H
#define SCRIBBLE_H
#include <QPoint>
#include <QtWidgets>

class ScribbleArea : public QWidget {
  Q_OBJECT
public:
  ScribbleArea();
  void openImage(const QString &filName);
  void saveImage(const QString &fileName);
  void setPenColor(const QColor newColor);
  void setPenWidth(const int newWidth);

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
