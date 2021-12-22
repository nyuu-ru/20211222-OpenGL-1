/*
 * Model.cc
 *
 *  Created on: 22 дек. 2021 г.
 *      Author: unyuu
 */

#include "Model.h"
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cstring>
#include <cerrno>
#include <GL/gl.h>

bool Model::next_line(std::ifstream &file, std::string &line)
{
	do {
		std::getline(file, line);
	} while (not file.fail() and line[0] == '#');
	return not file.fail();
}

Model::Model(const char *filename)
{
	std::ifstream file { filename };
	if (not file)
		throw std::runtime_error(
				std::string("Не удалось загрузить модель ") +
				std::string(filename) +
				std::string(": ") +
				std::string(strerror(errno)));

	std::string line;
	// TODO: надо бы сделать обработку ошибок

	next_line(file, line);
	int vertex_count, face_count;
	{
		std::stringstream ss(line);
		ss >> vertex_count >> face_count;
	}

	_vertices.resize(vertex_count);
	for (auto &&v: _vertices) {
		next_line(file, line);
		std::stringstream ss(line);
		ss >> v.x >> v.y >> v.z;
	}

	_faces.resize(face_count);
	for (auto &&f: _faces) {
		next_line(file, line);
		std::stringstream ss(line);
		int face_vertices;
		ss >> face_vertices;
		f.resize(face_vertices);
		for (auto &&fv: f) ss >> fv;
	}

	_normals.resize(face_count);
	for (auto &&n: _normals) {
		next_line(file, line);
		std::stringstream ss(line);
		ss >> n.x >> n.y >> n.z;
	}

	_tex_coords.resize(face_count);
	int face = 0;
	for (auto &&f: _tex_coords) {
		next_line(file, line);
		std::stringstream ss(line);
		f.resize(_faces[face].size());
		for (auto &&fv: f) { ss >> fv.s >> fv.t; }
		++face;
	}

	file.close();
}

void Model::draw()
{
	auto face_count   = _faces.size();

	for (unsigned face_index = 0;
			face_index < face_count;
			++face_index) {
		glBegin(GL_POLYGON);
		glNormal3fv(&_normals[face_index][0]);
		unsigned face_vertex_count = _faces[face_index].size();
		for (unsigned vertex_index = 0;
				vertex_index < face_vertex_count;
				++vertex_index) {
			glTexCoord2fv(&_tex_coords[face_index][vertex_index][0]);
			glVertex3fv(&_vertices[_faces[face_index][vertex_index]][0]);
		}
		glEnd();
	}
}
