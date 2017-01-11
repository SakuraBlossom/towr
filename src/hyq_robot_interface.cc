/**
 @file    hyq_robot_interface.cc
 @author  Alexander W. Winkler (winklera@ethz.ch)
 @date    Sep 6, 2016
 @brief   Brief description
 */

#include <xpp/hyq/hyq_robot_interface.h>

namespace xpp {
namespace hyq {

HyqRobotInterface::HyqRobotInterface ()
{
  // TODO Auto-generated constructor stub
}

HyqRobotInterface::~HyqRobotInterface ()
{
  // TODO Auto-generated destructor stub
}

HyqRobotInterface::PosXY
HyqRobotInterface::GetNominalStanceInBase (EndeffectorID leg_id) const
{
  const double x_nominal_b = 0.34; // 0.4
  const double y_nominal_b = 0.34; // 0.4

  switch (kMapOptToHyq.at(leg_id)) {
    case LF: return PosXY( x_nominal_b,   y_nominal_b); break;
    case RF: return PosXY( x_nominal_b,  -y_nominal_b); break;
    case LH: return PosXY(-x_nominal_b,   y_nominal_b); break;
    case RH: return PosXY(-x_nominal_b,  -y_nominal_b); break;
    default: assert(false); // this should never happen
  }
}

HyqRobotInterface::MaxDevXY
HyqRobotInterface::GetMaxDeviationXYFromNominal () const
{
  return {0.25, 0.15};
}

} /* namespace opt */
} /* namespace xpp */