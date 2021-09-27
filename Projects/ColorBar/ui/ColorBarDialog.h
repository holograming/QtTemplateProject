#pragma once
#include <QDialog>

// reference https://stackoverflow.com/questions/50611762/how-to-use-qt-qcolormap-in-code

class ColorBarDialog final : public QDialog
{
	Q_OBJECT
public :
	explicit ColorBarDialog(QWidget *parent = Q_NULLPTR);
	virtual ~ColorBarDialog() = default;

public:
	void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;
};
