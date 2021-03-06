#include "graphics/buffer.h"
#include "graphics/texture.h"
#include "matrix.h"
#include "glfw.h"
#include "util.h"
#include "vendor/vec/vec.h"

#ifndef LOVR_MODEL_TYPES
#define LOVR_MODEL_TYPES

typedef struct {
  float x;
  float y;
  float z;
} ModelVertex;

typedef vec_t(ModelVertex) vec_model_vertex_t;

typedef struct {
  unsigned int indices[3];
} ModelFace;

typedef vec_t(ModelFace) vec_model_face_t;

typedef struct {
  vec_model_face_t faces;
  vec_model_vertex_t vertices;
  vec_model_vertex_t normals;
  vec_model_vertex_t texCoords;
} ModelMesh;

typedef vec_t(ModelMesh*) vec_model_mesh_t;

typedef struct ModelNode {
  mat4 transform;
  vec_uint_t meshes;
  vec_void_t children;
} ModelNode;

typedef struct {
  Ref ref;
  ModelNode* root;
  vec_model_mesh_t meshes;
  int hasNormals;
  int hasTexCoords;
} ModelData;

typedef struct {
  Ref ref;
  ModelData* modelData;
  Buffer* buffer;
  Texture* texture;
} Model;

#endif

Model* lovrModelCreate(ModelData* modelData);
void lovrModelDestroy(const Ref* ref);
void lovrModelDataDestroy(ModelData* modelData);
void lovrModelDraw(Model* model, float x, float y, float z, float scale, float angle, float ax, float ay, float az);
Texture* lovrModelGetTexture(Model* model);
void lovrModelSetTexture(Model* model, Texture* texture);
