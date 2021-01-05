/*
 * PointsViewer.cpp
 *
 *  Created on: 05 Jan 2021
 *      Author: Tim Spain
 */

#include "pointVis.hpp"

#include <vtkSmartPointer.h>
#include <vtkVertexGlyphFilter.h>

#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPointData.h>
#include <vtkCellArray.h>
#include <vtkUnsignedCharArray.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkProperty.h>

#include <vtkNamedColors.h>

#include <algorithm>

PointVis::PointVis() :
points(),
colours()
{
}

// Use the default destructor

void PointVis::addPoints(std::vector<std::array<double, nDim>> inPoints)
{
	// Copy each array into the member vector of points
	for (auto iter = inPoints.begin(); iter != inPoints.end(); iter++) {
		// Manually clone the array
		points.push_back({(*iter)[0], (*iter)[1], (*iter)[2]});
	}
}

void PointVis::setColours(std::vector<std::string> inColours)
{
	for (auto iter = inColours.begin(); iter != inColours.end(); iter++) {
		colours.push_back(std::string(*iter));
	}
}

int PointVis::size()
{
	return points.size();
}

void PointVis::clearAllPoints()
{
	points.clear();
}

int PointVis::run()
{
	// Load point data
	  vtkSmartPointer<vtkPoints> vPoints = vtkSmartPointer<vtkPoints>::New();
	  for (auto iter = points.begin(); iter != points.end(); iter++) {
		  vPoints->InsertNextPoint(iter->data());
	  }

	  vtkSmartPointer<vtkPolyData> pointsPolydata =
	    vtkSmartPointer<vtkPolyData>::New();

	  pointsPolydata->SetPoints(vPoints);

	  vtkSmartPointer<vtkVertexGlyphFilter> vertexFilter =
	    vtkSmartPointer<vtkVertexGlyphFilter>::New();
	  vertexFilter->SetInputData(pointsPolydata);
	  vertexFilter->Update();

	  vtkSmartPointer<vtkPolyData> polydata =
	    vtkSmartPointer<vtkPolyData>::New();
	  polydata->ShallowCopy(vertexFilter->GetOutput());

	// Setup colors
  vtkSmartPointer<vtkNamedColors> namedColors =
    vtkSmartPointer<vtkNamedColors>::New();

  vtkSmartPointer<vtkUnsignedCharArray> colors =
    vtkSmartPointer<vtkUnsignedCharArray>::New();
  colors->SetNumberOfComponents(3);
  colors->SetName ("Colors");
  // Loop over the defined colours until all points have a defined colour
  if (colours.empty()) {
	  colours.push_back("White");
  }
  for (size_t iPoint = 0; iPoint < points.size(); iPoint++) {
	  colors->InsertNextTypedTuple(namedColors->GetColor3ub(colours[iPoint % colours.size()]).GetData());
  }

  polydata->GetPointData()->SetScalars(colors);

	  // Visualisation
	  vtkSmartPointer<vtkPolyDataMapper> mapper =
	    vtkSmartPointer<vtkPolyDataMapper>::New();
	  mapper->SetInputData(polydata);

	  vtkSmartPointer<vtkActor> actor =
	    vtkSmartPointer<vtkActor>::New();
	  actor->SetMapper(mapper);
	  actor->GetProperty()->SetPointSize(10);

	  vtkSmartPointer<vtkRenderer> renderer =
	    vtkSmartPointer<vtkRenderer>::New();
	  vtkSmartPointer<vtkRenderWindow> renderWindow =
	    vtkSmartPointer<vtkRenderWindow>::New();
	  renderWindow->AddRenderer(renderer);
	  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
	    vtkSmartPointer<vtkRenderWindowInteractor>::New();
	  renderWindowInteractor->SetRenderWindow(renderWindow);

	  renderer->AddActor(actor);
	  renderer->SetBackground(namedColors->GetColor3d("Black").GetData());
	  renderWindow->Render();
	  renderWindowInteractor->Start();

	  return EXIT_SUCCESS;
}
