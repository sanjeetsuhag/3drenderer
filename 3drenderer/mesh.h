#ifndef MESH_H
#define MESH_H

#include "triangle.h"
#include "vector.h"


#define N_CUBE_VERTICES 8
extern vec3_t cube_vertices[8];

#define N_CUBE_FACES 12
extern face_t cube_faces[12];

typedef struct {
	vec3_t* vertices;
	face_t* faces;
	vec3_t scale;
	vec3_t rotation;
	vec3_t translation;
} mesh_t;

extern mesh_t mesh;

void load_cube_mesh_data(void);
void load_obj_file_data(char* filename);

#endif