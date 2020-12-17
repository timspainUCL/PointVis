/*
 * PointsViewer.h
 *
 *  Created on: 17 Dec 2020
 *      Author: Tim Spain
 */

#ifndef SRC_POINTSVIEWER_H_
#define SRC_POINTSVIEWER_H_

#include <vector>
#include <array>
#include <string>

class PointsViewer {
public:
	// Three dimensions
	static const int nDim = 3;

	PointsViewer();
//	virtual ~PointsViewer(); // Use default dtor

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

#endif /* SRC_POINTSVIEWER_H_ */
