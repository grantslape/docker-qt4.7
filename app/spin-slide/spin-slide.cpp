#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	QWidget *window = new QWidget;
	window->setWindowTitle("Enter Your Age");
	QSpinBox *spinBox = new QSpinBox;
	QSlider *slider = new QSlider(Qt::Horizontal);
	spinBox->setRange(0, 130);
	slider->setRange(0, 130);
	spinBox->connect(SIGNAL(valueChanged(int)),
		slider, SLOT(setValue(int)));
	slider->connect(SIGNAL(valueChanged(int)),
	  spinBox, SLOT(setValue(int)));
	spinBox->setValue(35);
	QVBoxLayout *layout = new QVBoxLayout;
	layout->addWidget(spinBox);
	layout->addWidget(slider);
	window->setLayout(layout);
	window->show();
	return app.exec();
}