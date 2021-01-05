/*
 * PointsViewer.h
 *
 *  Created on: 5 Jan 2021
 *      Author: Tim Spain
 */

#ifndef POINTVIS_H
#define POINTVIS_H

#include <vector>
#include <array>
#include <string>

class PointVis {
public:
	// Three dimensions
	static const int nDim = 3;

	PointVis();
	// use default destructor

	void addPoints(std::vector<std::array<double, nDim>>);
	void setColours(std::vector<std::string>);
	void setSizes(std::vector<int>);
	int size();
	void clearAllPoints();

	int run(); // Run until the window closes
protected:
	std::vector<std::array<double, nDim>> points;
	std::vector<std::string> colours;
	std::vector<int> sizes;
};

#endif /*ndef POINTVIS_H */
