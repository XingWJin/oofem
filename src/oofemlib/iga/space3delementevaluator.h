/* $Header: /home/cvs/bp/oofem/oofemlib/src/element.h,v 1.27 2003/04/06 14:08:24 bp Exp $ */
/*
 *
 *                 #####    #####   ######  ######  ###   ###
 *               ##   ##  ##   ##  ##      ##      ## ### ##
 *              ##   ##  ##   ##  ####    ####    ##  #  ##
 *             ##   ##  ##   ##  ##      ##      ##     ##
 *            ##   ##  ##   ##  ##      ##      ##     ##
 *            #####    #####   ##      ######  ##     ##
 *
 *
 *             OOFEM : Object Oriented Finite Element Code
 *
 *               Copyright (C) 1993 - 2008   Borek Patzak
 *
 *
 *
 *       Czech Technical University, Faculty of Civil Engineering,
 *   Department of Structural Mechanics, 166 29 Prague, Czech Republic
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef space3delementevaluator_h
#define space3delementevaluator_h

#include "structuralelementevaluator.h"

namespace oofem {

/**
 * general purpose 3d structural element evaluator
 */
class Space3dStructuralElementEvaluator : public StructuralElementEvaluator
{
public:
    Space3dStructuralElementEvaluator() : StructuralElementEvaluator() { }

protected:

    /** Assemble interpolation matrix at given IP
     *  In case of IGAElements, N is assumed to contain only nonzero interpolation functions
     */
    void computeNMatrixAt(FloatMatrix &answer, GaussPoint *gp);
    /** Assembles the strain-displacement matrix of the receiver at given integration point
     *  In case of IGAElements, B is assumed to contain only contribution from nonzero interpolation functions
     */
    void computeBMatrixAt(FloatMatrix &answer, GaussPoint *gp);
    double computeVolumeAround(GaussPoint *gp);
    void giveDofManDofIDMask(int inode, EquationID u, IntArray &answer) const {
        answer.resize(3);
        answer.at(1) = D_u;
        answer.at(2) = D_v;
        answer.at(3) = D_w;
    }
}; // end of SpaceStructuralElementEvaluator definition

} // end namespace oofem
#endif //space3delementevaluator_h