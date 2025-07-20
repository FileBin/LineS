#include "decl.hpp"
#include "core.hpp"

// This is the crucial include for the auto-generated UI code
#include "ui_mainwindow.h" // uic will generate this in the build directory
#include <QDebug>
#include <QHBoxLayout> // For layout management
#include <cstdint>

// Declarations for Rust functions
extern "C" {
    void greet_from_rust();
    int add_numbers(int a, int b);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) // Initialize the UI object
{
    // Set up the UI from the generated code
    ui->setupUi(this);
    button_text = ui->myButton->text();
    // Now, access widgets via the 'ui' pointer
    // ui->myButton->setText("Click Me (No Qt Creator)!");

    // Manually connect the button's clicked signal to our slot
    // Alternatively, if your slot is named on_<objectName>_<signalName>,
    // ui->setupUi() might automatically connect it.
    // connect(ui->myButton, &QPushButton::clicked, this, &MainWindow::on_myButton_clicked);

    // Create and add the OpenGL widget
    // openGLWidget = new OpenGLPipeline(this);
}

MainWindow::~MainWindow()
{
    delete ui; // Clean up the UI object
}

void MainWindow::on_myButton_clicked(bool checked)
{
    qDebug() << "Button clicked from Qt UI (no Qt Creator)!";
    int32_t counter = lines_core_increment_counter();
    ui->myButton->setText(button_text.arg(counter));
}