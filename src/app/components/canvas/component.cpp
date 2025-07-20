#include "canvas.hpp"
#include "canvas.hpp"
#include <QDebug>

Canvas::Canvas(QWidget *parent)
    : QOpenGLWidget(parent),
      vbo(QOpenGLBuffer::VertexBuffer),         // VBO type
      ebo(QOpenGLBuffer::IndexBuffer)           // EBO type
{
    shaderProgram = nullptr;
    setGeometry(0,0,800,600);
}

Canvas::~Canvas() {
    makeCurrent();

    delete shaderProgram;
    shaderProgram = nullptr;

    // Destroy the VAO, VBO, and EBO
    vbo.destroy();
    ebo.destroy(); // Destroy the EBO

    doneCurrent();
}

void Canvas::initializeGL() {
    initializeOpenGLFunctions();

    // 1. Create and compile shader program
    shaderProgram = new QOpenGLShaderProgram(this);
    shaderProgram->addShaderFromSourceCode(QOpenGLShader::Vertex,
        "#version 330 core\n"
        "layout (location = 0) in vec2 aPos;\n"
        "void main()\n"
        "{\n"
        "   gl_Position = vec4(aPos.x, aPos.y, 0, 1.0);\n"
        "}\0");
    shaderProgram->addShaderFromSourceCode(QOpenGLShader::Fragment,
        "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()\n"
        "{\n"
        "   FragColor = vec4(0.0f, 0.7f, 0.9f, 1.0f);\n" // Blue-ish color
        "}\n\0");

    if (!shaderProgram->link()) {
        qDebug() << "Shader program linking failed:" << shaderProgram->log();
        return;
    }

    // 2. Define UNIQUE vertices for a quad (4 vertices)
    GLfloat vertices[] = {
        -0.5f, -0.5f,
        0.5f,  -0.5f, 
        0.5f,  0.5f,  
        -0.5f, 0.5f,
    };

    // 3. Define indices to draw the quad using two triangles
    // Indices refer to the unique vertices defined above
    GLuint indices[] = {
        0, 1, 2, // First triangle
        0, 2, 3  // Second triangle
    };

    // 5. Create and bind Vertex Buffer Object (VBO)
    if (!vbo.create()) {
        qDebug() << "Failed to create VBO";
        return;
    }
    vbo.bind(); // Bind VBO
    vbo.allocate(vertices, sizeof(vertices)); // Allocate and copy vertex data

    // 6. Create and bind Element Buffer Object (EBO/IBO)
    // EBO stores the indices. It must be bound while the VAO is bound.
    if (!ebo.create()) {
        qDebug() << "Failed to create EBO";
        vbo.release();
        return;
    }
    ebo.bind(); // Bind EBO
    ebo.allocate(indices, sizeof(indices)); // Allocate and copy index data

    qDebug() << "OpenGL initialized and quad data prepared using EBO!";
}

void Canvas::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void Canvas::paintGL() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shaderProgram->bind();
    vbo.bind();
    ebo.bind();

    shaderProgram->enableAttributeArray(0);
    shaderProgram->setAttributeBuffer(0,GL_FLOAT,0,2, 2*sizeof(GLfloat));

    // Draw the quad using glDrawElements
    // GL_TRIANGLES: primitive type
    // 6: number of indices to draw
    // GL_UNSIGNED_INT: type of elements in the index buffer (matches GLuint)
    // (void*)0: offset into the index buffer (start from beginning)
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)0);
}