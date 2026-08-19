#include "quad.h"
#include "vertex.h"

Quad::Quad(bool smooth)
{
    if(smooth)
    {    //Smooth shaded
                                    // Positions        // Colors / normals                         //UV
        mVertices.push_back(Vertex{-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,                          0.f, 0.f}); // Bottom Left
        mVertices.push_back(Vertex{0.5f, -0.5f, -0.2f,   0.123091f , -0.123091f , 0.984732f,         1.0f, 0.f}); // Bottom Right
        mVertices.push_back(Vertex{0.5f,  0.5f, 0.0f,    0.0f, 0.0f, 1.0f,                          1.0f, 1.f}); // Top Right

        mVertices.push_back(Vertex{-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,                          0.f, 0.f}); // Bottom Left
        mVertices.push_back(Vertex{0.5f,  0.5f, 0.0f,    0.0f, 0.0f, 1.0f,                          1.0f, 1.f}); // Top Right
        mVertices.push_back(Vertex{-0.5f, 0.5f, -0.2f,   -0.123091f , 0.123091f , 0.984732f,         0.0f, 1.f}); // Top Left
    }
    else
    {   //Flat shaded
                                    // Positions        // Colors / normals                         //UV
        mVertices.push_back(Vertex{-0.5f, -0.5f, 0.0f,   0.123091f , -0.123091f , 0.984732f,        0.f, 0.f}); // Bottom Left
        mVertices.push_back(Vertex{0.5f, -0.5f, -0.2f,   0.123091f , -0.123091f , 0.984732f,        1.0f, 0.f}); // Bottom Right
        mVertices.push_back(Vertex{0.5f,  0.5f, 0.0f,    0.123091f , -0.123091f , 0.984732f,        1.0f, 1.f}); // Top Right

        mVertices.push_back(Vertex{-0.5f, -0.5f, 0.0f,   -0.123091f , 0.123091f , 0.984732f,        0.f, 0.f}); // Bottom Left
        mVertices.push_back(Vertex{0.5f,  0.5f, 0.0f,    -0.123091f , 0.123091f , 0.984732f,        1.0f, 1.f}); // Top Right
    mVertices.push_back(Vertex{-0.5f, 0.5f, -0.2f,    -0.123091f , 0.123091f , 0.984732f,          0.0f, 1.f}); // Top Left
      }
}

Quad::~Quad()
{
}

void Quad::init()
{
    //must call this to use OpenGL functions
    initializeOpenGLFunctions();

    glGenVertexArrays( 1, &mVAO );
    glBindVertexArray( mVAO );

    //Vertex Buffer Object to hold vertices - VBO
    glGenBuffers( 1, &mVBO );
    glBindBuffer( GL_ARRAY_BUFFER, mVBO );

    //Vertex Buffer Object to hold vertices - VBO
    glBufferData( GL_ARRAY_BUFFER, mVertices.size()*sizeof( Vertex ), mVertices.data(), GL_STATIC_DRAW );

    // 1rst attribute buffer : vertices
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0  );          // array buffer offset
    glEnableVertexAttribArray(0);

    // 2nd attribute buffer : colors
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,  sizeof(Vertex),  (GLvoid*)(3 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(1);

    // 3rd attribute buffer : uvs
    glVertexAttribPointer(2, 2,  GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)( 6 * sizeof(GLfloat)) );
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);
}

void Quad::draw()
{
    glBindVertexArray( mVAO );
    glDrawArrays(GL_TRIANGLES, 0, mVertices.size());
    glBindVertexArray(0);
}
