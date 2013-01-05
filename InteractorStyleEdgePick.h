/*
Copyright 2012, 2013
Author Nicolas Edh,
Nicolas.Edh@gmail.com,
or user "nsf" at cfd-online.com

This file is part of hexBlocker.

    hexBlocker is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    hexBlocker is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with hexBlocker.  If not, see <http://www.gnu.org/licenses/>.

    The license is included in the file COPYING.
*/

#ifndef INTERACTORSTYLEEDGEPICK_H
#define INTERACTORSTYLEEDGEPICK_H

#include <vtkSmartPointer.h>
#include <vtkInteractorStyleTrackballActor.h>
#include <QObject>

class vtkCollection;
//class vtkIdList;
class HexBC;

class InteractorStyleEdgePick : public QObject, public vtkInteractorStyleTrackballActor
{
    Q_OBJECT

    vtkTypeMacro(InteractorStyleEdgePick,vtkInteractorStyleTrackballActor);
protected:
    InteractorStyleEdgePick();
    ~InteractorStyleEdgePick();
    InteractorStyleEdgePick(InteractorStyleEdgePick&);// Not implemented in order to comply with vtkObject.
    void operator=(const InteractorStyleEdgePick&);// Not implemented in order to comply with vtkObject.


public:
    static InteractorStyleEdgePick* New();
    void PrintSelf(ostream &os, vtkIndent indent);

    void SetEdges(vtkSmartPointer<vtkCollection> edgs);
    virtual vtkIdType findClickedEdge(int x, int y);
    virtual void OnLeftButtonDown();
    virtual void OnLeftButtonUp(){}
    virtual void OnMiddleButtonDown(){}
    virtual void OnMiddleButtonUp();
    virtual void OnRightButtonDown(){}
    virtual void OnRightButtonUp();
    virtual void OnMouseMove(){}

    void OnChar(); //override from superclass

    vtkSmartPointer<vtkCollection> globalEdges;

signals:
    void selectionDone(vtkIdType selectedEdge);

private:
};

#endif // INTERACTORSTYLEEDGEPICK_H