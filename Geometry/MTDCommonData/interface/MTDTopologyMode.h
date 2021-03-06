#ifndef Geometry_MTDCommonData_MTDTopologyMode_H
#define Geometry_MTDCommonData_MTDTopologyMode_H

#include "FWCore/Utilities/interface/Exception.h"
#include <map>
#include <string>
#include <algorithm>

namespace MTDTopologyMode {

  enum class Mode { undefined = 0, tile = 1, bar = 2, barzflat = 3, barphiflat = 4 };

  Mode MTDStringToEnumParser(const std::string&);

}  // namespace MTDTopologyMode

#endif  // Geometry_MTDCommonData_MTDTopologyMode_H
