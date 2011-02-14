/*******************************************************************************

"A Collection of Useful C++ Classes for Digital Signal Processing"
 By Vincent Falco

Official project location:
http://code.google.com/p/dspfilterscpp/

See Documentation.cpp for contact information, notes, and bibliography.

--------------------------------------------------------------------------------

License: MIT License (http://www.opensource.org/licenses/mit-license.php)
Copyright (c) 2009 by Vincent Falco

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*******************************************************************************/

#ifndef DSPFILTERS_CUSTOM_H
#define DSPFILTERS_CUSTOM_H

#include "DspFilters/Common.h"
#include "DspFilters/Biquad.h"
#include "DspFilters/Design.h"
#include "DspFilters/Filter.h"

namespace Dsp {

/*
 * Single pole and Biquad with parameters allowing
 * for directly setting the poles and zeros
 *
 */

namespace Custom {

//
// Raw filters
//

struct OnePole : Biquad
{
  void setup (double scale,
              double pole,
              double zero);
};

struct TwoPole : Biquad
{
  void setup (double scale,
              double poleRho,
              double poleTheta,
              double zeroRho,
              double zeroTheta);
};

//------------------------------------------------------------------------------

//
// Gui-friendly Design layer
//

namespace Design {

struct OnePole : DesignBase, Custom::OnePole
{
  OnePole ()
  {
    addBuiltinParamInfo (idGain);
    addBuiltinParamInfo (idPoleReal);
    addBuiltinParamInfo (idZeroReal);
  }

  Kind getKind () const
  {
    return kindOther;
  }

  const char* getName() const
  {
    return "Custom One-Pole";
  }

  void setParams (const Params& params)
  {
    setup (pow (10., params[1]/20),
           params[2],
           params[3]);
  }
};

struct TwoPole : DesignBase, Custom::TwoPole
{
  TwoPole ()
  {
    addBuiltinParamInfo (idGain);
    addBuiltinParamInfo (idPoleRho);
    addBuiltinParamInfo (idPoleTheta);
    addBuiltinParamInfo (idZeroRho);
    addBuiltinParamInfo (idZeroTheta);
  }

  Kind getKind () const
  {
    return kindOther;
  }

  const char* getName() const
  {
    return "Custom Two-Pole";
  }

  void setParams (const Params& params)
  {
    setup (pow (10., params[1]/20),
           params[2],
           params[3],
           params[4],
           params[5]);
  }
};

}

}

}

#endif