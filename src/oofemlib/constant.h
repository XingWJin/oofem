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
 *               Copyright (C) 1993 - 2010   Borek Patzak
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

//   *******************************
//   *** CLASS CONSTANT FUNCTION ***
//   *******************************

#ifndef constant_h
#define constant_h

#include "loadtime.h"

namespace oofem {
/**
 * Class implementing time function that is constant in time; @f$ f(t) = C @f$.
 */
class ConstantFunction : public LoadTimeFunction
{
private:
    /// Value of receiver.
    double value;

public:
    /**
     * Constructor. Creates constant load time function with given number, belonging to given domain.
     * @param n load time function number
     * @param d domain to which new object will belongs.
     */
    ConstantFunction(int i, Domain *d) : LoadTimeFunction(i, d) { value = 0; }
    /// Destructor.
    ~ConstantFunction() { }

    /**
     * Returns value member of receiver.
     */
    double giveValue() { return value; }

    // Overloaded methods:
    virtual double __at(double) { return this->giveValue(); }

    IRResultType initializeFrom(InputRecord *ir);
    virtual int giveInputRecordString(std :: string &str, bool keyword = true);

    classType giveClassID() const { return ConstantFunctionClass; }
    const char *giveClassName() const { return "ConstantFunction"; }
    const char *giveInputRecordName() const { return "ConstantFunction"; }
};
} // end namespace oofem
#endif // constant_h
