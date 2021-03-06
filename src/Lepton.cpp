#include "interface/Lepton.hpp"


Lepton::Lepton() : Object() {
    iso =-1; 
    charge = 0 ;
    isocut_ = 0.4;
    type=0;
    tightId=0;
    ptcut_=20;
    etacut_=2.5;
}

// Local Variables:
// mode:c++
// indent-tabs-mode:nil
// tab-width:4
// c-basic-offset:4
// End:
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4 
