/*
 * Model.h
 *
 *  Created on: 22 дек. 2021 г.
 *      Author: unyuu
 */

#ifndef MODEL_H_
#define MODEL_H_

#include <glm/glm.hpp>
#include <vector>
#include <fstream>
#include <string>

class Model
{
private:
	bool next_line(std::ifstream &file, std::string &line);

protected:
	std::vector<glm::vec3>              _vertices;
	std::vector<std::vector<unsigned>>  _faces;
	std::vector<glm::vec3>              _normals;
	std::vector<std::vector<glm::vec2>> _tex_coords;

public:
	Model(const char *filename);
	virtual ~Model() = default;

	void draw();
};

#endif /* MODEL_H_ */
