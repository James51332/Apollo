#ifndef OpenGLLoader_h
#define OpenGLLoader_h

#ifdef __cplusplus
extern "C"
{
#endif

  //From glcorearb.h
  typedef void GLvoid;
  typedef unsigned int GLenum;
  typedef float GLfloat;
  typedef int GLint;
  typedef int GLsizei;
  typedef unsigned int GLbitfield;
  typedef double GLdouble;
  typedef unsigned int GLuint;
  typedef unsigned char GLboolean;
  typedef GLboolean GLbool;
  typedef unsigned char GLubyte;
  typedef char GLchar;
  typedef long int GLsizeiptr;
  typedef signed int GLsint;

#define GL_DEPTH_BUFFER_BIT 0x00000100
#define GL_STENCIL_BUFFER_BIT 0x00000400
#define GL_COLOR_BUFFER_BIT 0x00004000
#define GL_FALSE 0
#define GL_TRUE 1
#define GL_POINTS 0x0000
#define GL_LINES 0x0001
#define GL_LINE_LOOP 0x0002
#define GL_LINE_STRIP 0x0003
#define GL_TRIANGLES 0x0004
#define GL_TRIANGLE_STRIP 0x0005
#define GL_TRIANGLE_FAN 0x0006
#define GL_ARRAY_BUFFER 0x8892
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406
#define GL_ELEMENT_ARRAY_BUFFER 0x8893
#define GL_STREAM_DRAW 0x88E0
#define GL_STREAM_READ 0x88E1
#define GL_STREAM_COPY 0x88E2
#define GL_STATIC_DRAW 0x88E4
#define GL_STATIC_READ 0x88E5
#define GL_STATIC_COPY 0x88E6
#define GL_DYNAMIC_DRAW 0x88E8
#define GL_DYNAMIC_READ 0x88E9
#define GL_DYNAMIC_COPY 0x88EA
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_DELETE_STATUS 0x8B80
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_VALIDATE_STATUS 0x8B83

#define GL_FUNCS                                                                                                  \
  GL_FUNC(GLvoid, glViewport, GLuint x, GLuint y, GLuint w, GLuint h)                                             \
  GL_FUNC(GLvoid, glClearColor, GLfloat r, GLfloat g, GLfloat b, GLfloat a)                                       \
  GL_FUNC(GLvoid, glClear, GLenum)                                                                                \
  GL_FUNC(GLvoid, glGenBuffers, GLsizei n, GLuint *buffers)                                                       \
  GL_FUNC(GLvoid, glBindBuffer, GLenum target, GLuint buffer)                                                     \
  GL_FUNC(GLvoid, glBufferData, GLenum target, GLsizei ptr, const GLvoid *, GLenum v2)                            \
  GL_FUNC(GLvoid, glDeleteBuffers, GLsizei v0, GLuint *v1)                                                        \
  GL_FUNC(GLvoid, glGenVertexArrays, GLsizei v0, GLuint *v1)                                                      \
  GL_FUNC(GLvoid, glBindVertexArray, GLuint v0)                                                                   \
  GL_FUNC(GLvoid, glEnableVertexAttribArray, GLuint v0)                                                           \
  GL_FUNC(GLvoid, glVertexAttribPointer, GLuint v0, GLsizei v1, GLenum v2, GLbool v3, GLuint v4, GLvoid *v5)      \
  GL_FUNC(GLvoid, glDeleteVertexArray, GLsizei v0, GLuint *v1)                                                    \
  GL_FUNC(GLuint, glCreateShader, GLenum v0)                                                                      \
  GL_FUNC(GLvoid, glShaderSource, GLuint shader, GLsizei count, const GLchar *const *string, const GLint *length) \
  GL_FUNC(GLvoid, glCompileShader, GLuint v0)                                                                     \
  GL_FUNC(GLbool, glGetShaderiv, GLuint shader, GLenum pname, GLint *prams)                                       \
  GL_FUNC(GLvoid, glGetShaderInfoLog, GLuint shader, GLsizei bufSize, GLsizei *length, GLchar *infoLog)           \
  GL_FUNC(GLvoid, glDeleteShader, GLuint v0)                                                                      \
  GL_FUNC(GLuint, glCreateProgram)                                                                                \
  GL_FUNC(GLvoid, glAttachShader, GLuint v0, GLuint v1)                                                           \
  GL_FUNC(GLvoid, glLinkProgram, GLuint v0)                                                                       \
  GL_FUNC(GLvoid, glGetProgramiv, GLuint program, GLenum pname, GLint *prams)                                     \
  GL_FUNC(GLvoid, glGetProgramInfoLog, GLuint program, GLsizei bufSize, GLsizei *length, GLchar *infoLog)         \
  GL_FUNC(GLvoid, glUseProgram, GLuint v0)                                                                        \
  GL_FUNC(GLvoid, glDeleteProgram, GLuint)                                                                        \
  GL_FUNC(GLvoid, glDrawElements, GLenum mode, GLsizei count, GLenum type, const GLvoid *indices)                 \
  GL_FUNC(GLsint, glGetUniformLocation, GLuint program, const GLchar *name);                                      \
  GL_FUNC(GLvoid, glUniformMatrix4fv, GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)

#define GL_FUNC(ret, name, ...)           \
  typedef ret (*name##proc)(__VA_ARGS__); \
  extern name##proc name;

  GL_FUNCS

#undef GL_FUNC

  void InitializeOpenGL();

#ifdef __cplusplus
}
#endif

#endif /* end of include guard: OpenGLLoader_h */