#include <ui/ColorBarDialog.h>
#include <QColor>
#include <QPaintEvent>
#include <QPainter>

ColorBarDialog::ColorBarDialog(QWidget* parent/* = Q_NULLPTR*/) : QDialog(parent)
{
	setWindowFlags(Qt::Popup | Qt::Dialog);
}

void ColorBarDialog::paintEvent(QPaintEvent *)
{
	QPainter painter(this);
	painter.setOpacity(0.9);
	painter.setRenderHint(QPainter::HighQualityAntialiasing);
	QLinearGradient gradient(0, 0, 0, height());
	QGradientStops stops;
	stops << QGradientStop(0, Qt::blue);
	stops << QGradientStop(1.0 / 5, Qt::cyan);
	stops << QGradientStop(2.0 / 5, Qt::green);
	stops << QGradientStop(3.0 / 5, Qt::yellow);
	stops << QGradientStop(1, Qt::red);
	gradient.setStops(stops);
	painter.fillRect(rect(), gradient);

	painter.setFont(QFont("Arial", 10));
	painter.drawText(QPoint(0, height()*0.08), "- 111");
	painter.drawText(QPoint(0, height()*0.25), "- 222");
	painter.drawText(QPoint(0, height()*0.50), "- 333");
	painter.drawText(QPoint(0, height()*0.75), "- 444");
	painter.drawText(QPoint(0, height()*0.98), "- 555");
}

