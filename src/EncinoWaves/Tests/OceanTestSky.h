//-*****************************************************************************
// Copyright 2015 Christopher Jon Horvath
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//-*****************************************************************************

//-*****************************************************************************
// The basic architecture of these Waves is based on the TweakWaves application
// written by Chris Horvath for Tweak Films in 2001.  This, in turn, was based
// on the SIGGRAPH papers and courses by Jerry Tessendorf, and by the paper
// "A Simple Fluid Solver based on the FTT" by Jos Stam.
//
// The TMA, JONSWAP, and Pierson Moskowitz Wave Spectra, as well as the
// directional spreading functions are formulated based on the descriptions
// given in "Ocean Waves: The Stochastic Approach",
// by Michel K. Ochi, published by Cambridge Ocean Technology Series, 1998,2005.
//
// This library is written as a working implementation of the paper:
// Christopher J. Horvath. 2015.
// Empirical directional wave spectra for computer graphics.
// In Proceedings of the 2015 Symposium on Digital Production (DigiPro '15),
// Los Angeles, Aug. 8, 2015, pp. 29-39.
//-*****************************************************************************

#ifndef _EncinoWaves_OceanTestSky_h_
#define _EncinoWaves_OceanTestSky_h_

#include "OceanTestFoundation.h"

namespace OceanTest {

//-*****************************************************************************
class Sky {
public:
  struct Parameters {
    std::string filename;
    double time;
    double day;
    double latitude;
    double longitude;
    double GMT_offset;
    double turbidity;

    Parameters()
      : filename("")
      , time(23.0)           // 24 hour clock
      , day(235.0)           // day out of 365
      , latitude(37.783)     // san francisco
      , longitude(122.4167)  // san francisco
      , GMT_offset(17.0)     // san francisco is GMT-7
      , turbidity(0.9) {}
  };

  Sky(const Parameters& i_params)
    : m_params(i_params) {}

  void setUniforms(GeepGLFW::Program& i_program) const;

protected:
  Parameters m_params;
};

}  // namespace OceanTest

#endif
