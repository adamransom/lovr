#include "../glfw.h"
#include "../util.h"
#include "texture.h"

#ifndef LOVR_BUFFER_TYPES
#define LOVR_BUFFER_TYPES
typedef enum {
  BUFFER_POINTS = GL_POINTS,
  BUFFER_TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
  BUFFER_TRIANGLES = GL_TRIANGLES,
  BUFFER_TRIANGLE_FAN = GL_TRIANGLE_FAN
} BufferDrawMode;

typedef enum {
  BUFFER_STATIC = GL_STATIC_DRAW,
  BUFFER_DYNAMIC = GL_DYNAMIC_DRAW,
  BUFFER_STREAM = GL_STREAM_DRAW
} BufferUsage;

typedef enum {
  BUFFER_FLOAT = GL_FLOAT,
  BUFFER_BYTE = GL_BYTE,
  BUFFER_INT = GL_INT
} BufferAttributeType;

typedef struct {
  const char* name;
  BufferAttributeType type;
  int size;
} BufferAttribute;

typedef vec_t(BufferAttribute) BufferFormat;

typedef struct Buffer {
  int size;
  int stride;
  void* data;
  void* scratchVertex;
  BufferFormat format;
  BufferDrawMode drawMode;
  BufferUsage usage;
  GLuint vao;
  GLuint vbo;
  GLuint ibo;
  GLuint tbo;
  vec_uint_t map;
  char isRangeEnabled;
  int rangeStart;
  int rangeCount;
  Texture* texture;
} Buffer;
#endif

Buffer* lovrBufferCreate(int size, BufferFormat* format, BufferDrawMode drawMode, BufferUsage usage);
void lovrBufferDestroy(Buffer* buffer);
void lovrBufferDraw(Buffer* buffer);
void lovrBufferFeedback(Buffer* buffer, void* output, int size);
BufferFormat lovrBufferGetVertexFormat(Buffer* buffer);
BufferDrawMode lovrBufferGetDrawMode(Buffer* buffer);
int lovrBufferSetDrawMode(Buffer* buffer, BufferDrawMode drawMode);
int lovrBufferGetVertexCount(Buffer* buffer);
int lovrBufferGetVertexSize(Buffer* buffer);
void* lovrBufferGetScratchVertex(Buffer* buffer);
void lovrBufferGetVertex(Buffer* buffer, int index, void* dest);
void lovrBufferSetVertex(Buffer* buffer, int index, void* vertex);
void lovrBufferSetVertices(Buffer* buffer, void* vertices, int size);
unsigned int* lovrBufferGetVertexMap(Buffer* buffer, int* count);
void lovrBufferSetVertexMap(Buffer* buffer, unsigned int* map, int count);
char lovrBufferIsRangeEnabled(Buffer* buffer);
void lovrBufferSetRangeEnabled(Buffer* buffer, char isEnabled);
void lovrBufferGetDrawRange(Buffer* buffer, int* start, int* count);
int lovrBufferSetDrawRange(Buffer* buffer, int start, int count);
Texture* lovrBufferGetTexture(Buffer* buffer);
void lovrBufferSetTexture(Buffer* buffer, Texture* texture);
